// description : 前処理 O(N) クエリ処理 O(1)
template <int MOD, size_t size> class Combi {
	using T = modint<MOD>;
	array<T, size + 1> fac, finv, inv;

public:
	constexpr Combi() {
		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		inv[1] = 1;
		for (size_t i = 2; i <= size; ++i) {
			fac[i] = fac[i - 1] * i;
			inv[i] = -inv[MOD % i] * (MOD / i);
			finv[i] = finv[i - 1] * inv[i];
		}
	}
	constexpr T P(int n, int r) const {
		return (n < r || n < 0 || r < 0) ? 0 : fac[n] * finv[n - r];
	}
	constexpr T C(int n, int r) const {
		return (n < r || n < 0 || r < 0) ? 0 : fac[n] * finv[r] * finv[n - r];
	}
	constexpr T H(int n, int r) const {
		return (n < 0 || r < 0) ? 0 : r == 0 ? 1 : C(n + r - 1, r);
	}
	constexpr T fact(int n) const {
		return fac[n];
	}
};