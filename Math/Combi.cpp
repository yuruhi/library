// description : 前処理 O(N) クエリ処理 O(1)
template <int MOD> class Combi {
	using T = modint<MOD>;
	int Max;
	vector<T> fac, finv, inv;

public:
	Combi(int _Max = 300009) : Max(_Max), fac(_Max), finv(_Max), inv(_Max) {
		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		inv[1] = 1;
		for (int i = 2; i < Max; ++i) {
			fac[i] = fac[i - 1] * i;
			inv[i] = T(MOD) - inv[MOD % i] * (MOD / i);
			finv[i] = finv[i - 1] * inv[i];
		}
	}
	T P(int n, int r) const {
		return (n < r || n < 0 || r < 0) ? 0 : fac[n] * finv[n - r];
	}
	T C(int n, int r) const {
		return (n < r || n < 0 || r < 0) ? 0 : fac[n] * finv[r] * finv[n - r];
	}
	T H(int n, int r) const {
		return (n < 0 || r < 0) ? 0 : r == 0 ? 1 : C(n + r - 1, r);
	}
	T fact(int n) const {
		return fac[n];
	}
};