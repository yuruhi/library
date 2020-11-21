#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

template <class T> class ImosLinear {
public:
	using value_type = T;
	using data_type = vector<value_type>;

private:
	size_t n;
	data_type X, A, B;
	bool builded = false;

public:
	ImosLinear(size_t _n) : n(_n), X(_n), A(_n + 1), B(_n + 1) {}
	void add(size_t l, size_t r, value_type a,
	         value_type b) {  // [l, r) += a + (i - l) * b
		if (l >= r) return;
		assert(!builded);
		l = max(min(l, n), 0);
		r = max(min(r, n), 0);
		A[l] += a - b * l;
		B[l] += b;
		A[r] -= a - b * l;
		B[r] -= b;
	}
	void build() {
		builded = true;
		for (size_t i = 0; i < n; ++i) {
			X[i] = A[i] + B[i] * i;
			A[i + 1] += A[i];
			B[i + 1] += B[i];
		}
	}
	value_type operator[](size_t i) const {
		assert(builded);
		return X[i];
	}
	const data_type& to_a() const {
		assert(builded);
		return X;
	}
};
