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

    #define rrep(i, n) for (int i = (n)-1; i >= 0; --i)

    #define rfor(i, m, n) for (int i = (m); i >= (n); --i)

    #define unless(c) if (!(c))

    #define all(x) (x).begin(), (x).end()

    #define rall(x) (x).rbegin(), (x).rend()

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

    #define rrep(i, n) for (int i = (n)-1; i >= 0; --i)

    #define rfor(i, m, n) for (int i = (m); i >= (n); --i)

    #define unless(c) if (!(c))

    #define all(x) (x).begin(), (x).end()

    #define rall(x) (x).rbegin(), (x).rend()

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

    constexpr long long inf_ll = 1000000000000000000ll, MOD = 1000000007;

    constexpr long double PI = 3.14159265358979323846, EPS = 1e-12;

    '
  dependsOn: []
  isVerificationFile: false
  path: Utility/constants.cpp
  requiredBy:
  - template_no_Ruby.cpp
  - template.cpp
  timestamp: '2021-03-07 15:06:12+09:00'
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
