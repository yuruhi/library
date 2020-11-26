#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <utility>
#include <queue>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)
#define rfor(i, m, n) for (int i = (m); i >= (n); --i)
#define unless(c) if (!(c))
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
constexpr int inf = 1000000000;
constexpr long long inf_ll = 1000000000000000000ll, MOD = 1000000007;
constexpr long double PI = 3.14159265358979323846, EPS = 1e-12;
namespace CharacterClass {
	constexpr string_view
	    digit = "0123456789",
	    xdigit = "0123456789ABCDEFabcdef", lower = "abcdefghijklmnopqrstuvwxyz",
	    upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
	    alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",
	    alnum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",
	    word = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz",
	    punct = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~",
	    graph =
	        "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~",
	    print =
	        " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~",
	    blank = " \t", space = " \t\n\r\f\v";
}  // namespace CharacterClass