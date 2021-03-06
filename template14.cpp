#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)
#define rfor(i, m, n) for (int i = (m); i >= (n); --i)
#define unless(c) if (!(c))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define range_it(a, l, r) (a).begin() + (l), (a).begin() + (r)

using namespace std;
using ll = long long;
using LD = long double;
using VB = vector<bool>;
using VVB = vector<VB>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using VS = vector<string>;
using VD = vector<LD>;
using PII = pair<int, int>;
using VP = vector<PII>;
using PLL = pair<ll, ll>;
using VPL = vector<PLL>;
template <class T> using PQ = priority_queue<T>;
template <class T> using PQS = priority_queue<T, vector<T>, greater<T>>;
constexpr int inf = 1e9;
constexpr long long inf_ll = 1e18, MOD = 1000000007;
constexpr long double PI = M_PI, EPS = 1e-12;

// --- input --- //
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#define fwrite_unlocked fwrite
#define fflush_unlocked fflush
#endif
class Scanner {
	static int gc() {
		return getchar_unlocked();
	}
	static char next_char() {
		char c;
		read(c);
		return c;
	}
	template <class T> static void read(T& v) {
		cin >> v;
	}
	static void read(char& v) {
		while (isspace(v = gc()))
			;
	}
	static void read(bool& v) {
		v = next_char() != '0';
	}
	static void read(string& v) {
		v.clear();
		for (char c = next_char(); !isspace(c); c = gc()) v += c;
	}
	static void read(int& v) {
		v = 0;
		bool neg = false;
		char c = next_char();
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; isdigit(c); c = gc()) v = v * 10 + (c - '0');
		if (neg) v = -v;
	}
	static void read(long long& v) {
		v = 0;
		bool neg = false;
		char c = next_char();
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; isdigit(c); c = gc()) v = v * 10 + (c - '0');
		if (neg) v = -v;
	}
	static void read(double& v) {
		v = 0;
		double dp = 1;
		bool neg = false, after_dp = false;
		char c = next_char();
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; isdigit(c) || c == '.'; c = gc()) {
			if (c == '.') {
				after_dp = true;
			} else if (after_dp) {
				v += (c - '0') * (dp *= 0.1);
			} else {
				v = v * 10 + (c - '0');
			}
		}
		if (neg) v = -v;
	}
	static void read(long double& v) {
		v = 0;
		long double dp = 1;
		bool neg = false, after_dp = false;
		char c = next_char();
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; isdigit(c) || c == '.'; c = gc()) {
			if (c == '.') {
				after_dp = true;
			} else if (after_dp) {
				v += (c - '0') * (dp *= 0.1);
			} else {
				v = v * 10 + (c - '0');
			}
		}
		if (neg) v = -v;
	}
	template <class T, class U> static void read(pair<T, U>& v) {
		read(v.first);
		read(v.second);
	}
	template <class T> static void read(vector<T>& v) {
		for (auto& e : v) read(e);
	}
	struct ReadVectorHelper {
		size_t n;
		ReadVectorHelper(size_t _n) : n(_n) {}
		template <class T> operator vector<T>() {
			vector<T> v(n);
			read(v);
			return v;
		}
	};
	struct Read2DVectorHelper {
		size_t n, m;
		Read2DVectorHelper(const pair<size_t, size_t>& nm) : n(nm.first), m(nm.second) {}
		template <class T> operator vector<vector<T>>() {
			vector<vector<T>> v(n, vector<T>(m));
			read(v);
			return v;
		}
	};

public:
	string read_line() const {
		string v;
		for (char c = gc(); c != '\n' && c != '\0'; c = gc()) v += c;
		return v;
	}
	template <class T> T read() const {
		T v;
		read(v);
		return v;
	}
	template <class T> vector<T> read_vector(size_t n) const {
		vector<T> a(n);
		read(a);
		return a;
	}
	template <class T> operator T() const {
		return read<T>();
	}
	int operator--(int) const {
		return read<int>() - 1;
	}
	ReadVectorHelper operator[](size_t n) const {
		return ReadVectorHelper(n);
	}
	Read2DVectorHelper operator[](const pair<size_t, size_t>& nm) const {
		return Read2DVectorHelper(nm);
	}
	void operator()() const {}
	template <class H, class... T> void operator()(H&& h, T&&... t) const {
		read(h);
		operator()(forward<T>(t)...);
	}
} in;
#define inputs(T, ...) \
	T __VA_ARGS__;     \
	in(__VA_ARGS__)
#define ini(...) inputs(int, __VA_ARGS__)
#define inl(...) inputs(long long, __VA_ARGS__)
#define ins(...) inputs(string, __VA_ARGS__)

// --- output --- //
struct BoolStr {
	const char *t, *f;
	BoolStr(const char* _t, const char* _f) : t(_t), f(_f) {}
} Yes("Yes", "No"), yes("yes", "no"), YES("YES", "NO"), Int("1", "0");
struct DivStr {
	const char *d, *l;
	DivStr(const char* _d, const char* _l) : d(_d), l(_l) {}
} spc(" ", "\n"), no_spc("", "\n"), end_line("\n", "\n"), comma(",", "\n"),
    no_endl(" ", "");
class Printer {
	BoolStr B{Yes};
	DivStr D{spc};

public:
	void print(int v) const {
		if (v < 0) putchar_unlocked('-'), v = -v;
		char b[10];
		int i = 0;
		while (v) b[i++] = '0' + v % 10, v /= 10;
		if (!i) b[i++] = '0';
		while (i--) putchar_unlocked(b[i]);
	}
	void print(long long v) const {
		if (v < 0) putchar_unlocked('-'), v = -v;
		char b[20];
		int i = 0;
		while (v) b[i++] = '0' + v % 10, v /= 10;
		if (!i) b[i++] = '0';
		while (i--) putchar_unlocked(b[i]);
	}
	void print(bool v) const {
		print(v ? B.t : B.f);
	}
	void print(vector<bool>::reference v) const {
		print(v ? B.t : B.f);
	}
	void print(char v) const {
		putchar_unlocked(v);
	}
	void print(const char* v) const {
		fwrite_unlocked(v, 1, strlen(v), stdout);
	}
	void print(double v) const {
		printf("%.20f", v);
	}
	void print(long double v) const {
		printf("%.20Lf", v);
	}
	template <class T> void print(const T& v) const {
		cout << v;
	}
	template <class T, class U> void print(const pair<T, U>& v) const {
		print(v.first);
		print(D.d);
		print(v.second);
	}
	template <class InputIterater>
	void print_range(const InputIterater& begin, const InputIterater& end) const {
		for (InputIterater i = begin; i != end; ++i) {
			if (i != begin) print(D.d);
			print(*i);
		}
	}
	template <class T> void print(const vector<T>& v) const {
		print_range(v.begin(), v.end());
	}
	template <class T, size_t N> void print(const array<T, N>& v) const {
		print_range(v.begin(), v.end());
	}
	template <class T> void print(const vector<vector<T>>& v) const {
		for (size_t i = 0; i < v.size(); ++i) {
			if (i) print(D.l);
			print(v[i]);
		}
	}

	Printer() = default;
	Printer(const BoolStr& _boolstr, const DivStr& _divstr) : B(_boolstr), D(_divstr) {}
	Printer& operator()() {
		print(D.l);
		return *this;
	}
	template <class H> Printer& operator()(H&& h) {
		print(h);
		print(D.l);
		return *this;
	}
	template <class H, class... T> Printer& operator()(H&& h, T&&... t) {
		print(h);
		print(D.d);
		return operator()(forward<T>(t)...);
	}
	template <class InputIterator>
	Printer& range(const InputIterator& begin, const InputIterator& end) {
		print_range(begin, end);
		print(D.l);
		return *this;
	}
	template <class T> Printer& range(const T& a) {
		range(a.begin(), a.end());
		return *this;
	}
	template <class... T> void exit(T&&... t) {
		operator()(forward<T>(t)...);
		std::exit(EXIT_SUCCESS);
	}
	Printer& flush() {
		fflush_unlocked(stdout);
		return *this;
	}
	Printer& set(const BoolStr& b) {
		B = b;
		return *this;
	}
	Printer& set(const DivStr& d) {
		D = d;
		return *this;
	}
	Printer& set(const char* t, const char* f) {
		B = BoolStr(t, f);
		return *this;
	}
} out;

// --- step --- //
template <class T> struct Step {
	class It {
		T a, b, c;

	public:
		constexpr It() : a(T()), b(T()), c(T()) {}
		constexpr It(T _b, T _c, T _s) : a(_b), b(_c), c(_s) {}
		constexpr It& operator++() {
			--b;
			a += c;
			return *this;
		}
		constexpr It operator++(int) {
			It tmp = *this;
			--b;
			a += c;
			return tmp;
		}
		constexpr const T& operator*() const {
			return a;
		}
		constexpr const T* operator->() const {
			return &a;
		}
		constexpr bool operator==(const It& i) const {
			return b == i.b;
		}
		constexpr bool operator!=(const It& i) const {
			return !(b == i.b);
		}
		constexpr T start() const {
			return a;
		}
		constexpr T count() const {
			return b;
		}
		constexpr T step() const {
			return c;
		}
	};
	constexpr Step(T b, T c, T s) : be(b, c, s) {}
	constexpr It begin() const {
		return be;
	}
	constexpr It end() const {
		return en;
	}
	constexpr T start() const {
		return be.start();
	}
	constexpr T count() const {
		return be.count();
	}
	constexpr T step() const {
		return be.step();
	}
	constexpr T sum() const {
		return start() * count() + step() * (count() * (count() - 1) / 2);
	}
	operator vector<T>() const {
		return to_a();
	}
	template <class F> void each(const F& f) const {
		for (T i : *this) f(i);
	}
	auto to_a() const {
		vector<T> res;
		res.reserve(count());
		each([&](T i) { res.push_back(i); });
		return res;
	}
	template <class F, class U = decay_t<result_of_t<F(T)>>> auto map(const F& f) const {
		vector<U> res;
		res.reserve(count());
		each([&](T i) { res.push_back(f(i)); });
		return res;
	}
	template <class F> auto select(const F& f) const {
		vector<T> res;
		each([&](T i) {
			if (f(i)) res.push_back(i);
		});
		return res;
	}
	template <class F> int count_if(const F& f) const {
		int res = 0;
		each([&](T i) {
			if (f(i)) ++res;
		});
		return res;
	}
	template <class F> T find_if(const F& f) const {
		for (T i : *this)
			if (f(i)) return i;
		return 0;
	}
	template <class F> auto max_by(const F& f) const {
		auto v = map(f);
		return *max_element(v.begin(), v.end());
	}
	template <class F> auto min_by(const F& f) const {
		auto v = map(f);
		return *min_element(v.begin(), v.end());
	}
	template <class F> bool all_of(const F& f) const {
		for (T i : *this)
			if (!f(i)) return false;
		return true;
	}
	template <class F> bool any_of(const F& f) const {
		for (T i : *this)
			if (f(i)) return true;
		return false;
	}
	template <class F, class U = decay_t<result_of_t<F(T)>>> auto sum(const F& f) const {
		U res = 0;
		each([&](T i) { res += static_cast<U>(f(i)); });
		return res;
	}
	using value_type = T;
	using iterator = It;

private:
	It be, en;
};
template <class T> constexpr auto step(T a) {
	return Step<T>(0, a, 1);
}
template <class T> constexpr auto step(T a, T b) {
	return Step<T>(a, b - a, 1);
}
template <class T> constexpr auto step(T a, T b, T c) {
	return Step<T>(a, a < b ? (b - a - 1) / c + 1 : 0, c);
}

// --- functions --- //
inline namespace {
	template <class T> void Sort(T& a) {
		sort(all(a));
	}
	template <class T> void RSort(T& a) {
		sort(rall(a));
	}
	template <class T, class F> void Sort(T& a, const F& f) {
		sort(all(a), f);
	}
	template <class T, class F> void RSort(T& a, const F& f) {
		sort(rall(a), f);
	}
	template <class T> T Sorted(T a) {
		Sort(a);
		return a;
	}
	template <class T> T RSorted(T a) {
		RSort(a);
		return a;
	}
	template <class T, class F> T Sorted(T& a, const F& f) {
		Sort(a, f);
		return a;
	}
	template <class T, class F> T RSorted(T& a, const F& f) {
		RSort(a, f);
		return a;
	}
	template <class T, class F> void SortBy(T& a, const F& f) {
		sort(all(a), [&](const auto& x, const auto& y) { return f(x) < f(y); });
	}
	template <class T, class F> void RSortBy(T& a, const F& f) {
		sort(rall(a), [&](const auto& x, const auto& y) { return f(x) < f(y); });
	}
	template <class T> void Reverse(T& a) {
		reverse(all(a));
	}
	template <class T> void Unique(T& a) {
		a.erase(unique(all(a)), a.end());
	}
	template <class T> void Uniq(T& a) {
		Sort(a);
		Unique(a);
	}
	template <class T> void Rotate(T& a, int left) {
		rotate(a.begin(), a.begin() + left, a.end());
	}
	template <class T> T Reversed(T a) {
		Reverse(a);
		return a;
	}
	template <class T> T Uniqued(T a) {
		Unique(a);
		return a;
	}
	template <class T> T Uniqed(T a) {
		Uniq(a);
		return a;
	}
	template <class T> T Rotated(T a, int left) {
		Rotate(a, left);
		return a;
	}
	template <class T> auto Max(const T& a) {
		return *max_element(all(a));
	}
	template <class T> auto Min(const T& a) {
		return *min_element(all(a));
	}
	template <class T> int MaxPos(const T& a) {
		return max_element(all(a)) - a.begin();
	}
	template <class T> int MinPos(const T& a) {
		return min_element(all(a)) - a.begin();
	}
	template <class T, class F> auto MaxBy(const T& a, const F& f) {
		return *max_element(all(a),
		                    [&](const auto& x, const auto& y) { return f(x) < f(y); });
	}
	template <class T, class F> auto MinBy(const T& a, const F& f) {
		return *min_element(all(a),
		                    [&](const auto& x, const auto& y) { return f(x) < f(y); });
	}
	template <class T, class F> auto MaxOf(const T& a, const F& f) {
		return Max(Map(a, f));
	}
	template <class T, class F> auto MinOf(const T& a, const F& f) {
		return Min(Map(a, f));
	}
	template <class T, class U> int Count(const T& a, const U& v) {
		return count(all(a), v);
	}
	template <class T, class F> int CountIf(const T& a, const F& f) {
		return count_if(all(a), f);
	}
	template <class T, class U> int Find(const T& a, const U& v) {
		return find(all(a), v) - a.begin();
	}
	template <class T, class F> int FindIf(const T& a, const F& f) {
		return find_if(all(a), f) - a.begin();
	}
	template <class T, class U = typename T::value_type> U Sum(const T& a) {
		return accumulate(all(a), U());
	}
	template <class T, class U> bool Includes(const T& a, const U& v) {
		return find(all(a), v) != a.end();
	}
	template <class T, class F> auto Sum(const T& v, const F& f) {
		return accumulate(next(v.begin()), v.end(), f(*v.begin()),
		                  [&](auto a, auto b) { return a + f(b); });
	}
	template <class T, class U> int Lower(const T& a, const U& v) {
		return lower_bound(all(a), v) - a.begin();
	}
	template <class T, class U> int Upper(const T& a, const U& v) {
		return upper_bound(all(a), v) - a.begin();
	}
	template <class T, class F> void RemoveIf(T& a, const F& f) {
		a.erase(remove_if(all(a), f), a.end());
	}
	template <class F> auto Vector(size_t size, const F& f) {
		vector<decay_t<result_of_t<F(size_t)>>> res(size);
		for (size_t i = 0; i < size; ++i) res[i] = f(i);
		return res;
	}
	template <class T> auto Grid(size_t h, size_t w, const T& v = T()) {
		return vector<vector<T>>(h, vector<T>(w, v));
	}
	template <class T> auto Slice(const T& v, size_t i, size_t len) {
		return i < v.size() ? T(v.begin() + i, v.begin() + min(i + len, v.size())) : T();
	}
	template <class T, class F> auto Each(const T& v, F&& f) {
		for (auto& i : v) f(i);
	}
	template <class T, class F> auto Select(const T& v, const F& f) {
		T res;
		for (const auto& e : v)
			if (f(e)) res.push_back(e);
		return res;
	}
	template <class T, class F> auto Map(const T& v, F&& f) {
		vector<decay_t<result_of_t<F(typename T::value_type)>>> res(v.size());
		size_t i = 0;
		for (const auto& e : v) res[i++] = f(e);
		return res;
	}
	template <class T, class F> auto MapIndex(const T& v, const F& f) {
		vector<decay_t<result_of_t<F(size_t, typename T::value_type)>>> res(v.size());
		size_t i = 0;
		for (auto it = v.begin(); it != v.end(); ++it, ++i) res[i] = f(i, *it);
		return res;
	}
	template <class T, class F> auto TrueIndex(const T& v, const F& f) {
		vector<size_t> res;
		for (size_t i = 0; i < v.size(); ++i)
			if (f(v[i])) res.push_back(i);
		return res;
	}
	template <class T, class U = typename T::value_type> auto Indexed(const T& v) {
		vector<pair<U, int>> res(v.size());
		for (int i = 0; i < (int)v.size(); ++i)
			res[i] = make_pair(static_cast<U>(v[i]), i);
		return res;
	}
	auto operator*(string s, size_t n) {
		string res;
		for (size_t i = 0; i < n; ++i) res += s;
		return res;
	}
	template <class T> auto& operator<<(vector<T>& v, const vector<T>& v2) {
		v.insert(v.end(), all(v2));
		return v;
	}
	template <class T> T Ceil(T n, T m) {
		return (n + m - 1) / m;
	}
	template <class T> T Ceil2(T n, T m) {
		return Ceil(n, m) * m;
	}
	template <class T> T Tri(T n) {
		return (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);
	}
	template <class T> T nC2(T n) {
		return (n & 1) ? (n - 1) / 2 * n : n / 2 * (n - 1);
	}
	template <class T> T Mid(const T& l, const T& r) {
		return l + (r - l) / 2;
	}
	template <class T> bool chmax(T& a, const T& b) {
		if (a < b) {
			a = b;
			return true;
		}
		return false;
	}
	template <class T> bool chmin(T& a, const T& b) {
		if (a > b) {
			a = b;
			return true;
		}
		return false;
	}
	template <class T> bool inRange(const T& v, const T& min, const T& max) {
		return min <= v && v < max;
	}
	template <class T> bool isSquere(T n) {
		T s = sqrt(n);
		return s * s == n || (s + 1) * (s + 1) == n;
	}
	template <class T = long long> T BIT(int b) {
		return T(1) << b;
	}
	template <class T> T Gcd(T n, T m) {
		return m ? Gcd(m, n % m) : n;
	}
	template <class T> T Lcm(T n, T m) {
		return n / Gcd(n, m) * m;
	}
	template <class T, class U = typename T::value_type> U Gcdv(const T& v) {
		return accumulate(next(v.begin()), v.end(), U(*v.begin()), Gcd<U>);
	}
	template <class T, class U = typename T::value_type> U Lcmv(const T& v) {
		return accumulate(next(v.begin()), v.end(), U(*v.begin()), Lcm<U>);
	}
	template <class T> T Pow(T a, T n) {
		T r = 1;
		while (n > 0) {
			if (n & 1) r *= a;
			a *= a;
			n /= 2;
		}
		return r;
	}
	template <class T> T Powmod(T a, T n, T m = MOD) {
		T r = 1;
		while (n > 0) {
			if (n & 1)
				r = r * a % m, n--;
			else
				a = a * a % m, n /= 2;
		}
		return r;
	}
}  // namespace

// --- dump --- //
#if __has_include(<library/dump.hpp>)
#include <library/dump.hpp>
#else
#define dump(...) ((void)0)
#endif

// ---------------------------------------------------------------- //
