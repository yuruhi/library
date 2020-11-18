#pragma once
#include <memory>
#include <vector>
#include <cassert>
using namespace std;

template <class T> class PersistentStack {
public:
	using value_type = T;
	using const_reference = const value_type&;

private:
	class node_type;
	using node_ptr = shared_ptr<const node_type>;
	struct node_type {
		value_type value;
		node_ptr next;
		node_type(node_ptr _next, const value_type& _value) : next(_next), value(_value) {}
	};

	node_ptr root;
	PersistentStack(node_ptr _root) : root(_root) {}

public:
	PersistentStack() = default;
	bool empty() const {
		return !root;
	}
	const_reference top() const {
		return root->value;
	}
	PersistentStack push(const_reference value) const {
		return PersistentStack(make_shared<node_type>(root, value));
	}
	PersistentStack pop() const {
		assert(!empty());
		return PersistentStack(root->next);
	}
	vector<value_type> to_a() const {
		vector<value_type> result;
		for (node_ptr node = root; node; node = node->next) {
			result.push_back(node->value);
		}
		return result;
	}
};
