#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

template <class T> class ImosLinear {
public:
	using value_type = T;

private:
	const int N;
	vector<value_type> X, A, B;
	bool builded = false;

public:
	ImosLinear(int _n) : N(_n), X(_n), A(_n + 1), B(_n + 1) {}
	void add(int l, int r, value_type a, value_type b) {  // [l, r) += a + (i - l) * b
		if (l >= r) return;
		assert(!builded);
		l = max(min(l, N), 0);
		r = max(min(r, N), 0);
		A[l] += a - b * l;
		B[l] += b;
		A[r] -= a - b * l;
		B[r] -= b;
	}
	void build() {
		builded = true;
		for (int i = 0; i < N; ++i) {
			X[i] = A[i] + B[i] * i;
			A[i + 1] += A[i];
			B[i + 1] += B[i];
		}
	}
	value_type operator[](int i) const {
		assert(builded);
		return X[i];
	}
	const vector<value_type>& to_a() const {
		assert(builded);
		return X;
	}
};
