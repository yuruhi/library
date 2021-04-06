#pragma once
#include <memory>
#include <vector>
#include <cassert>

template <class T> class PersistentStack {
public:
	using value_type = T;
	using const_reference = const value_type&;

private:
	class node_type;
	using node_ptr = std::shared_ptr<const node_type>;
	struct node_type {
		node_ptr next;
		value_type value;
		node_type(node_ptr _next, const value_type& _value) : next(_next), value(_value) {}
	};

	node_ptr root;
	std::size_t size_m;
	PersistentStack(node_ptr _root, std::size_t _size_m) : root(_root), size_m(_size_m) {}

public:
	PersistentStack() : size_m(0) {}
	bool empty() const {
		return !root;
	}
	std::size_t size() const {
		return size_m;
	}
	const_reference top() const {
		return root->value;
	}
	PersistentStack push(const_reference value) const {
		return PersistentStack(std::make_shared<node_type>(root, value), size_m + 1);
	}
	PersistentStack pop() const {
		assert(!empty());
		return PersistentStack(root->next, size_m - 1);
	}
	std::vector<value_type> to_a() const {
		std::vector<value_type> result;
		for (node_ptr node = root; node; node = node->next) {
			result.push_back(node->value);
		}
		return result;
	}
};
