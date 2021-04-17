---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/get_MOD.cpp
    title: Utility/get_MOD.cpp
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
  bundledCode: "#line 2 \"Utility/get_MOD.cpp\"\nconstexpr long long get_MOD() {\n\
    #ifdef SET_MOD\n\treturn SET_MOD;\n#else\n\treturn 1000000007;\n#endif\n}\n#line\
    \ 3 \"Utility/constants.cpp\"\n#include <vector>\n#include <string>\n#include\
    \ <utility>\n#include <queue>\n\n#define rep(i, n) for (int i = 0; i < (n); ++i)\n\
    #define FOR(i, m, n) for (int i = (m); i < (n); ++i)\n#define rrep(i, n) for (int\
    \ i = (n)-1; i >= 0; --i)\n#define rfor(i, m, n) for (int i = (m); i >= (n); --i)\n\
    #define INTERNAL_CAT_IMPL(s1, s2) s1##s2\n#define INTERNAL_CAT(s1, s2) INTERNAL_CAT_IMPL(s1,\
    \ s2)\n#ifdef __COUNTER__\n#define loop(n) rep(INTERNAL_CAT(_i, __COUNTER__),\
    \ n)\n#else\n#define loop(n) rep(INTERNAL_CAT(_i, __COUNTER__), n)\n#endif\n#define\
    \ unless(c) if (!(c))\n#define ALL(x) (x).begin(), (x).end()\n#define RALL(x)\
    \ (x).rbegin(), (x).rend()\n#define range_it(a, l, r) (a).begin() + (l), (a).begin()\
    \ + (r)\n\nusing ll = long long;\nusing LD = long double;\nusing VB = std::vector<bool>;\n\
    using VVB = std::vector<VB>;\nusing VI = std::vector<int>;\nusing VVI = std::vector<VI>;\n\
    using VL = std::vector<ll>;\nusing VVL = std::vector<VL>;\nusing VS = std::vector<std::string>;\n\
    using VD = std::vector<LD>;\nusing PII = std::pair<int, int>;\nusing VP = std::vector<PII>;\n\
    using PLL = std::pair<ll, ll>;\nusing VPL = std::vector<PLL>;\ntemplate <class\
    \ T> using PQ = std::priority_queue<T>;\ntemplate <class T> using PQS = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n\nconstexpr int inf = 1000000000;\nconstexpr\
    \ long long inf_ll = 1000000000000000000ll, MOD = get_MOD();\nconstexpr long double\
    \ PI = 3.14159265358979323846, tau = PI * 2, EPS = 1e-12;\n"
  code: '#pragma once

    #include "./get_MOD.cpp"

    #include <vector>

    #include <string>

    #include <utility>

    #include <queue>


    #define rep(i, n) for (int i = 0; i < (n); ++i)

    #define FOR(i, m, n) for (int i = (m); i < (n); ++i)

    #define rrep(i, n) for (int i = (n)-1; i >= 0; --i)

    #define rfor(i, m, n) for (int i = (m); i >= (n); --i)

    #define INTERNAL_CAT_IMPL(s1, s2) s1##s2

    #define INTERNAL_CAT(s1, s2) INTERNAL_CAT_IMPL(s1, s2)

    #ifdef __COUNTER__

    #define loop(n) rep(INTERNAL_CAT(_i, __COUNTER__), n)

    #else

    #define loop(n) rep(INTERNAL_CAT(_i, __COUNTER__), n)

    #endif

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

    '
  dependsOn:
  - Utility/get_MOD.cpp
  isVerificationFile: false
  path: Utility/constants.cpp
  requiredBy:
  - template.cpp
  - template_no_Ruby.cpp
  timestamp: '2021-04-16 16:53:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/template.test.cpp
  - test/template_no_Ruby.test.cpp
documentation_of: Utility/constants.cpp
layout: document
redirect_from:
- /library/Utility/constants.cpp
- /library/Utility/constants.cpp.html
title: Utility/constants.cpp
---
