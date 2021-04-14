#pragma once
#include "./get_MOD.cpp"
#include <vector>
#include <string>
#include <utility>
#include <queue>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)
#define rfor(i, m, n) for (int i = (m); i >= (n); --i)
#define loop(n) rep(i##__COUNTER__, n)
#define unless(c) if (!(c))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define range_it(a, l, r) (a).begin() + (l), (a).begin() + (r)

using ll = long long;
using LD = long double;
using VB = std::vector<bool>;
using VVB = std::vector<VB>;
using VI = std::vector<int>;
using VVI = std::vector<VI>;
using VL = std::vector<ll>;
using VVL = std::vector<VL>;
using VS = std::vector<std::string>;
using VD = std::vector<LD>;
using PII = std::pair<int, int>;
using VP = std::vector<PII>;
using PLL = std::pair<ll, ll>;
using VPL = std::vector<PLL>;
template <class T> using PQ = std::priority_queue<T>;
template <class T> using PQS = std::priority_queue<T, std::vector<T>, std::greater<T>>;

constexpr int inf = 1000000000;
constexpr long long inf_ll = 1000000000000000000ll, MOD = get_MOD();
constexpr long double PI = 3.14159265358979323846, tau = PI * 2, EPS = 1e-12;
