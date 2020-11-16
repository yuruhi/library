#pragma once
#include <array>
#include <vector>
#include <memory>
using namespace std;

template <class T, size_t LOG> class PersistentArray {
public:
	using value_type = T;
	using const_reference = const value_type&;

private:
	struct node_type;
	using node_ptr = shared_ptr<node_type>;
	static constexpr size_t CHILD_SIZE = 1 << LOG;
	struct node_type {
		value_type value;
		array<node_ptr, CHILD_SIZE> child;
	};

	node_ptr root;

	PersistentArray(node_ptr _root) : root(_root) {}
	value_type get(size_t i, node_ptr p) const {
		if (!p) {
			return value_type();
		} else if (i == 0) {
			return p->value;
		} else {
			return get(i >> LOG, p->child[i & (CHILD_SIZE - 1)]);
		}
	}
	node_ptr set(size_t i, const_reference val, node_ptr p) {
		node_ptr result = p ? make_shared<node_type>(*p) : make_shared<node_type>();
		if (i == 0) {
			result->value = val;
		} else {
			size_t index = i & (CHILD_SIZE - 1);
			result->child[index] = set(i >> LOG, val, result->child[index]);
		}
		return result;
	}
	void destructive_set(size_t i, const_reference val, node_ptr& p) {
		if (!p) {
			p = make_shared<node_type>();
		}
		if (i == 0) {
			p->value = val;
		} else {
			size_t index = i & (CHILD_SIZE - 1);
			destructive_set(i >> LOG, val, p->child[index]);
		}
	}

public:
	PersistentArray() : root() {}
	PersistentArray(const vector<value_type>& v) : root() {
		for (size_t i = 0; i < v.size(); ++i) {
			destructive_set(i, v[i]);
		}
	}
	value_type get(size_t i) const {
		return get(i, root);
	}
	value_type operator[](size_t i) const {
		return get(i);
	}
	vector<value_type> to_a(size_t n) const {
		vector<value_type> result(n);
		for (size_t i = 0; i < n; ++i) {
			result[i] = get(i);
		}
		return result;
	}
	PersistentArray set(size_t i, const_reference val) {
		return PersistentArray(set(i, val, root));
	}
	void destructive_set(size_t i, const_reference val) {
		destructive_set(i, val, root);
	}
};
