#pragma once
#include <vector>
#include <cassert>
using namespace std;

template <class T> class BinaryIndexedTree {
public:
	using value_type = T;

private:
	int n, n2;
	vector<value_type> a;

public:
	BinaryIndexedTree(int n_) : n(n_), n2(1), a(n_ + 1) {
		while (n2 < n) n2 *= 2;
		n2 /= 2;
	}
	value_type operator()(int i) const {  // [0, i]
		assert(0 < ++i);
		value_type result = 0;
		for (; i > 0; i -= i & -i) {
			result += a[i];
		}
		return result;
	}
	value_type operator()(int i, int j) const {  // [i, j]
		return operator()(j) - (i ? operator()(i - 1) : 0);
	}
	value_type operator[](int i) const {
		return operator()(i, i);
	}
	void add(int i, value_type x) {
		assert(0 < ++i);
		for (; i <= n; i += i & -i) {
			a[i] += x;
		}
	}
	int lower_bound(value_type k) const {
		if (k <= 0) return 0;
		int result = 0;
		for (int i = n2; i > 0; i /= 2) {
			if (result + i <= n && a[result + i] < k) {
				k -= a[result + i];
				result += i;
			}
		}
		return result;
	}
	vector<value_type> to_a() const {
		vector<value_type> result(n);
		for (int i = 0; i < n; ++i) {
			result[i] = operator()(i, i);
		}
		return result;
	}
};
