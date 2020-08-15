// description : C++11用テンプレート
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

// --- functions --- //
inline namespace {
	template <class T> inline void Sort(T& a) {
		sort(all(a));
	}
	template <class T> inline void RSort(T& a) {
		sort(rall(a));
	}
	template <class T, class F> inline void Sort(T& a, const F& f) {
		sort(all(a), f);
	}
	template <class T, class F> inline void RSort(T& a, const F& f) {
		sort(rall(a), f);
	}
	template <class T> inline T Sorted(T a) {
		Sort(a);
		return a;
	}
	template <class T> inline T RSorted(T a) {
		RSort(a);
		return a;
	}
	template <class T, class F> inline T Sorted(T& a, const F& f) {
		Sort(a, f);
		return a;
	}
	template <class T, class F> inline T RSorted(T& a, const F& f) {
		RSort(a, f);
		return a;
	}
	template <class T> inline void Reverse(T& a) {
		reverse(all(a));
	}
	template <class T> inline void Unique(T& a) {
		a.erase(unique(all(a)), a.end());
	}
	template <class T> inline void Uniq(T& a) {
		Sort(a);
		Unique(a);
	}
	template <class T> inline void Rotate(T& a, int left) {
		rotate(a.begin(), a.begin() + left, a.end());
	}
	template <class T> inline T Reversed(T a) {
		Reverse(a);
		return a;
	}
	template <class T> inline T Uniqued(T a) {
		Unique(a);
		return a;
	}
	template <class T> inline T Uniqed(T a) {
		Uniq(a);
		return a;
	}
	template <class T> inline T Rotated(T a, int left) {
		Rotate(a, left);
		return a;
	}
	template <class T> inline T Ceil(T n, T m) {
		return (n + m - 1) / m;
	}
	template <class T> inline T Ceil2(T n, T m) {
		return Ceil(n, m) * m;
	}
	template <class T> inline T Tri(T n) {
		return (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);
	}
	template <class T> inline T nC2(T n) {
		return (n & 1) ? (n - 1) / 2 * n : n / 2 * (n - 1);
	}
	template <class T> inline T Mid(const T& l, const T& r) {
		return l + (r - l) / 2;
	}
	template <class T> inline bool chmax(T& a, const T& b) {
		if (a < b) {
			a = b;
			return true;
		}
		return false;
	}
	template <class T> inline bool chmin(T& a, const T& b) {
		if (a > b) {
			a = b;
			return true;
		}
		return false;
	}
	template <class T> inline bool inRange(const T& v, const T& min, const T& max) {
		return min <= v && v < max;
	}
	template <class T> inline bool isSquere(T n) {
		T s = sqrt(n);
		return s * s == n || (s + 1) * (s + 1) == n;
	}
	template <class T = long long> inline T BIT(int b) {
		return T(1) << b;
	}
	template <class T> inline T Gcd(T n, T m) {
		return m ? Gcd(m, n % m) : n;
	}
	template <class T> inline T Lcm(T n, T m) {
		return n / Gcd(n, m) * m;
	}
	template <class T, class U = typename T::value_type> inline U Gcdv(const T& v) {
		return accumulate(next(v.begin()), v.end(), U(*v.begin()), Gcd<U>);
	}
	template <class T, class U = typename T::value_type> inline U Lcmv(const T& v) {
		return accumulate(next(v.begin()), v.end(), U(*v.begin()), Lcm<U>);
	}
	template <class T> inline T Pow(T a, T n) {
		T r = 1;
		while (n > 0) {
			if (n & 1) r *= a;
			a *= a;
			n /= 2;
		}
		return r;
	}
	template <class T> inline T Powmod(T a, T n, T m = MOD) {
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
#if __has_include("/home/yuruhiya/contest/library/dump.hpp")
#include "/home/yuruhiya/contest/library/dump.hpp"
#else
#define dump(...) ((void)0)
#endif

// ---------------------------------------------------------------- //

int main() {}