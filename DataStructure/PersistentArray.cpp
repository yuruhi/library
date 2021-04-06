#pragma once
#include <array>
#include <vector>
#include <memory>

template <class T, std::size_t LOG> class PersistentArray {
public:
	using value_type = T;
	using const_reference = const value_type&;
	static constexpr std::size_t CHILD_SIZE = 1 << LOG;

private:
	struct node_type;
	using node_ptr = std::shared_ptr<node_type>;
	struct node_type {
		value_type value;
		std::array<node_ptr, CHILD_SIZE> child;
	};

	static value_type get(std::size_t i, node_ptr p) {
		if (!p) {
			return value_type();
		} else if (i == 0) {
			return p->value;
		} else {
			return get(i >> LOG, p->child[i & (CHILD_SIZE - 1)]);
		}
	}
	static node_ptr set(std::size_t i, const_reference val, node_ptr p) {
		node_ptr result = p ? std::make_shared<node_type>(*p) : std::make_shared<node_type>();
		if (i == 0) {
			result->value = val;
		} else {
			std::size_t index = i & (CHILD_SIZE - 1);
			result->child[index] = set(i >> LOG, val, result->child[index]);
		}
		return result;
	}
	static void destructive_set(std::size_t i, const_reference val, node_ptr& p) {
		if (!p) {
			p = std::make_shared<node_type>();
		}
		if (i == 0) {
			p->value = val;
		} else {
			std::size_t index = i & (CHILD_SIZE - 1);
			destructive_set(i >> LOG, val, p->child[index]);
		}
	}

	node_ptr root;
	PersistentArray(node_ptr _root) : root(_root) {}

public:
	PersistentArray() : root() {}
	PersistentArray(const std::vector<value_type>& v) : root() {
		for (std::size_t i = 0; i < v.size(); ++i) {
			destructive_set(i, v[i]);
		}
	}
	value_type get(std::size_t i) const {
		return get(i, root);
	}
	value_type operator[](std::size_t i) const {
		return get(i);
	}
	std::vector<value_type> to_a(std::size_t n) const {
		std::vector<value_type> result(n);
		for (std::size_t i = 0; i < n; ++i) {
			result[i] = get(i);
		}
		return result;
	}
	PersistentArray set(std::size_t i, const_reference val) const {
		return PersistentArray(set(i, val, root));
	}
	void destructive_set(std::size_t i, const_reference val) {
		destructive_set(i, val, root);
	}
};
