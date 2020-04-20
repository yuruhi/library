// shortcut : modintRuntime
// description : 実行時に法が決まる modint
struct mint {
	using T = long long;
	static int MOD;
	T n;
public:
	static void set_mod(int _MOD) { MOD = _MOD; }
	mint(T x = 0) :n(x% MOD) { if (n < 0)n += MOD; }
	mint operator+()const { return *this; }
	mint operator-()const { return n ? MOD - n : 0; }
	mint& operator++() { if (MOD <= ++n)n = 0; return *this; }
	mint& operator--() { if (n <= 0)n = MOD; n--; return *this; }
	mint operator++(int) { mint t = *this; ++* this; return t; }
	mint operator--(int) { mint t = *this; --* this; return t; }
	mint next()const { return ++mint(*this); }
	mint pred()const { return --mint(*this); }
	mint operator+(const mint& m)const { return mint(*this) += m; }
	mint operator-(const mint& m)const { return mint(*this) -= m; }
	mint operator*(const mint& m)const { return mint(*this) *= m; }
	mint operator/(const mint& m)const { return mint(*this) /= m; }
	mint& operator+=(const mint& m) { n += m.n; if (n >= MOD)n -= MOD; return *this; }
	mint& operator-=(const mint& m) { n -= m.n; if (n < 0)n += MOD; return *this; }
	mint& operator*=(const mint& m) { n = n * m.n % MOD; return *this; }
	mint& operator/=(const mint& m) {
		T a = m.n, b = MOD, u = 1, v = 0;
		while (b) {
			T t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		n = n * u % MOD;
		if (n < 0)n += MOD;
		return *this;
	}
	bool operator==(const mint& m)const { return n == m.n; }
	bool operator!=(const mint& m)const { return n != m.n; }
	mint pow(mint m)const {
		mint t = n, res = 1; while (m.n > 0) { if (m.n & 1)res *= t; t *= t; m.n >>= 1; } return res;
	}
	mint operator^(mint m)const { return pow(m); }
};
int mint::MOD = 1000000007;
using VM = vector<mint>;
inline ostream& operator<<(ostream& os, const mint& m) { return os << m.n; }
inline istream& operator>>(istream& is, mint& m) { return is >> m.n; }
inline mint operator""_m(unsigned long long n) { return n; }