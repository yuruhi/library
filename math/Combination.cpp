#pragma once
#include "./modint.cpp"
#include <array>
using namespace std;

template <int MOD, size_t N> class Combination {
	using value_type = modint<MOD>;
	array<value_type, N + 1> fac, finv, inv;

public:
	constexpr Combination() {
		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		inv[1] = 1;
		for (size_t i = 2; i <= N; ++i) {
			fac[i] = fac[i - 1] * i;
			inv[i] = -inv[MOD % i] * (MOD / i);
			finv[i] = finv[i - 1] * inv[i];
		}
	}
	constexpr value_type P(int n, int r) const {
		return (n < r || n < 0 || r < 0) ? 0 : fac[n] * finv[n - r];
	}
	constexpr value_type C(int n, int r) const {
		return (n < r || n < 0 || r < 0) ? 0 : fac[n] * finv[r] * finv[n - r];
	}
	constexpr value_type H(int n, int r) const {
		return (n < 0 || r < 0) ? 0 : r == 0 ? 1 : C(n + r - 1, r);
	}
	constexpr value_type fact(int n) const {
		return fac[n];
	}
};
