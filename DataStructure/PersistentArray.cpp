#pragma once
#include <array>
#include <memory>
using namespace std;

template <class T, int LOG> class PersistentArray {
public:
	using value_type = T;
	using const_reference = const value_type&;

private:
	struct node_type;
	using node_ptr = shared_ptr<node_type>;
	struct node_type {
		value_type value;
		array<node_ptr, 1 << LOG> child;
	};

	node_ptr root;

	PersistentArray(node_ptr _root) : root(_root) {}
	value_type get(int i, node_ptr p) const {
		if (!p) {
			return value_type();
		} else if (i == 0) {
			return p->value;
		} else {
			return get(i >> LOG, p->child[i & ((1 << LOG) - 1)]);
		}
	}
	node_ptr set(int i, const value_type& val, node_ptr p) {
		node_ptr result = p ? make_shared<node_type>(*p) : make_shared<node_type>();
		if (i == 0) {
			result->value = val;
		} else {
			int index = i & ((1 << LOG) - 1);
			result->child[index] = set(i >> LOG, val, result->child[index]);
		}
		return result;
	}

public:
	PersistentArray() : root() {}
	value_type get(int i) const {
		return get(i, root);
	}
	value_type operator[](int i) const {
		return get(i);
	}
	PersistentArray set(int i, const value_type& val) {
		return PersistentArray(set(i, val, root));
	}
};
