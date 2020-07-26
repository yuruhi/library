// description : modint
template <int MOD> struct modint {
	using T = long long;
	T n;
	constexpr modint(const T x = 0) : n(x % MOD) {
		if (n < 0) n += MOD;
	}
	constexpr int get_mod() const {
		return MOD;
	}
	constexpr modint operator+() const {
		return *this;
	}
	constexpr modint operator-() const {
		return n ? MOD - n : 0;
	}
	constexpr modint &operator++() {
		if (MOD <= ++n) n = 0;
		return *this;
	}
	constexpr modint &operator--() {
		if (n <= 0) n = MOD;
		n--;
		return *this;
	}
	constexpr modint operator++(int) {
		modint t = *this;
		++*this;
		return t;
	}
	constexpr modint operator--(int) {
		modint t = *this;
		--*this;
		return t;
	}
	constexpr modint next() const {
		return ++modint(*this);
	}
	constexpr modint pred() const {
		return --modint(*this);
	}
	constexpr modint operator+(const modint &m) const {
		return modint(*this) += m;
	}
	constexpr modint operator-(const modint &m) const {
		return modint(*this) -= m;
	}
	constexpr modint operator*(const modint &m) const {
		return modint(*this) *= m;
	}
	constexpr modint operator/(const modint &m) const {
		return modint(*this) /= m;
	}
	constexpr modint &operator+=(const modint &m) {
		n += m.n;
		if (n >= MOD) n -= MOD;
		return *this;
	}
	constexpr modint &operator-=(const modint &m) {
		n -= m.n;
		if (n < 0) n += MOD;
		return *this;
	}
	constexpr modint &operator*=(const modint &m) {
		n = n * m.n % MOD;
		return *this;
	}
	constexpr modint &operator/=(const modint &m) {
		T a = m.n, b = MOD, u = 1, v = 0;
		while (b) {
			T t = a / b;
			a -= t * b;
			swap(a, b);
			u -= t * v;
			swap(u, v);
		}
		n = n * u % MOD;
		if (n < 0) n += MOD;
		return *this;
	}
	constexpr bool operator==(const modint &m) const {
		return n == m.n;
	}
	constexpr bool operator!=(const modint &m) const {
		return n != m.n;
	}
	constexpr modint pow(T m) const {
		modint t = n, res = 1;
		while (m > 0) {
			if (m & 1) res *= t;
			t *= t;
			m >>= 1;
		}
		return res;
	}
	constexpr modint operator^(T m) const {
		return pow(m);
	}
	friend ostream &operator<<(ostream &os, const modint<MOD> &m) {
		return os << m.n;
	}
	friend istream &operator>>(istream &is, modint<MOD> &m) {
		long long x;
		cin >> x;
		m = modint(x);
		return is;
	}
};
using mint = modint<1000000007>;
using VM = vector<mint>;
inline mint operator""_m(unsigned long long n) {
	return n;
}