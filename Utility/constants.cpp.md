---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  - icon: ':warning:'
    path: template_no_Ruby.cpp
    title: template_no_Ruby.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/template.test.cpp
    title: test/template.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/template_no_Ruby.test.cpp
    title: test/template_no_Ruby.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "Utility/constants.cpp"

    #include <vector>

    #include <string>

    #include <utility>

    #include <queue>


    #define rep(i, n) for (int i = 0; i < (n); ++i)

    #define FOR(i, m, n) for (int i = (m); i < (n); ++i)

    #define rrep(i, n) for (int i = (n) - 1; i >= 0; --i)

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

    '
  code: '#pragma once

    #include <vector>

    #include <string>

    #include <utility>

    #include <queue>


    #define rep(i, n) for (int i = 0; i < (n); ++i)

    #define FOR(i, m, n) for (int i = (m); i < (n); ++i)

    #define rrep(i, n) for (int i = (n) - 1; i >= 0; --i)

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

    '
  dependsOn: []
  isVerificationFile: false
  path: Utility/constants.cpp
  requiredBy:
  - template_no_Ruby.cpp
  - template.cpp
  timestamp: '2021-03-01 12:36:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/template_no_Ruby.test.cpp
  - test/template.test.cpp
documentation_of: Utility/constants.cpp
layout: document
redirect_from:
- /library/Utility/constants.cpp
- /library/Utility/constants.cpp.html
title: Utility/constants.cpp
---
