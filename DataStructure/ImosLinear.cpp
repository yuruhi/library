#pragma once
#include <vector>
#include <algorithm>
#include <cassert>

template <class T> class ImosLinear {
public:
	using value_type = T;
	using data_type = std::vector<value_type>;

private:
	std::size_t n;
	data_type X, A, B;
	bool builded = false;

public:
	ImosLinear(std::size_t _n) : n(_n), X(_n), A(_n + 1), B(_n + 1) {}
	void add(std::size_t l, std::size_t r, value_type a,
	         value_type b) {  // [l, r) += a + (i - l) * b
		if (l >= r) return;
		assert(!builded);
		l = std::min(l, n);
		r = std::min(r, n);
		A[l] += a - b * l;
		B[l] += b;
		A[r] -= a - b * l;
		B[r] -= b;
	}
	void build() {
		builded = true;
		for (std::size_t i = 0; i < n; ++i) {
			X[i] = A[i] + B[i] * i;
			A[i + 1] += A[i];
			B[i + 1] += B[i];
		}
	}
	value_type operator[](std::size_t i) const {
		assert(builded);
		return X[i];
	}
	const data_type& to_a() const {
		assert(builded);
		return X;
	}
};
