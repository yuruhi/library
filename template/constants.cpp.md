---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/template.cpp
    title: template/template.cpp
  - icon: ':warning:'
    path: template/template_no_Ruby.cpp
    title: template/template_no_Ruby.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/constants.cpp\"\n#include <vector>\n#include <string>\n\
    #include <string_view>\n#include <utility>\n#include <queue>\n\n#define rep(i,\
    \ n) for (int i = 0; i < (n); ++i)\n#define FOR(i, m, n) for (int i = (m); i <\
    \ (n); ++i)\n#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)\n#define rfor(i,\
    \ m, n) for (int i = (m); i >= (n); --i)\n#define unless(c) if (!(c))\n#define\
    \ all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n#define\
    \ range_it(a, l, r) (a).begin() + (l), (a).begin() + (r)\n\nusing namespace std;\n\
    using ll = long long;\nusing LD = long double;\nusing VB = vector<bool>;\nusing\
    \ VVB = vector<VB>;\nusing VI = vector<int>;\nusing VVI = vector<VI>;\nusing VL\
    \ = vector<ll>;\nusing VVL = vector<VL>;\nusing VS = vector<string>;\nusing VD\
    \ = vector<LD>;\nusing PII = pair<int, int>;\nusing VP = vector<PII>;\nusing PLL\
    \ = pair<ll, ll>;\nusing VPL = vector<PLL>;\ntemplate <class T> using PQ = priority_queue<T>;\n\
    template <class T> using PQS = priority_queue<T, vector<T>, greater<T>>;\nconstexpr\
    \ int inf = 1000000000;\nconstexpr long long inf_ll = 1000000000000000000ll, MOD\
    \ = 1000000007;\nconstexpr long double PI = 3.14159265358979323846, EPS = 1e-12;\n\
    namespace CharacterClass {\n\tconstexpr string_view\n\t    digit = \"0123456789\"\
    ,\n\t    xdigit = \"0123456789ABCDEFabcdef\", lower = \"abcdefghijklmnopqrstuvwxyz\"\
    ,\n\t    upper = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\",\n\t    alpha = \"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\"\
    ,\n\t    alnum = \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\"\
    ,\n\t    word = \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz\"\
    ,\n\t    punct = R\"(!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~)\",\n\t    graph =\n\t\
    \        R\"(!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~)\"\
    ,\n\t    print =\n\t        R\"( !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\\
    ]^_`abcdefghijklmnopqrstuvwxyz{|}~)\",\n\t    blank = \" \\t\", space = \" \\\
    t\\n\\r\\f\\v\";\n}  // namespace CharacterClass\n"
  code: "#pragma once\n#include <vector>\n#include <string>\n#include <string_view>\n\
    #include <utility>\n#include <queue>\n\n#define rep(i, n) for (int i = 0; i <\
    \ (n); ++i)\n#define FOR(i, m, n) for (int i = (m); i < (n); ++i)\n#define rrep(i,\
    \ n) for (int i = (n)-1; i >= 0; --i)\n#define rfor(i, m, n) for (int i = (m);\
    \ i >= (n); --i)\n#define unless(c) if (!(c))\n#define all(x) (x).begin(), (x).end()\n\
    #define rall(x) (x).rbegin(), (x).rend()\n#define range_it(a, l, r) (a).begin()\
    \ + (l), (a).begin() + (r)\n\nusing namespace std;\nusing ll = long long;\nusing\
    \ LD = long double;\nusing VB = vector<bool>;\nusing VVB = vector<VB>;\nusing\
    \ VI = vector<int>;\nusing VVI = vector<VI>;\nusing VL = vector<ll>;\nusing VVL\
    \ = vector<VL>;\nusing VS = vector<string>;\nusing VD = vector<LD>;\nusing PII\
    \ = pair<int, int>;\nusing VP = vector<PII>;\nusing PLL = pair<ll, ll>;\nusing\
    \ VPL = vector<PLL>;\ntemplate <class T> using PQ = priority_queue<T>;\ntemplate\
    \ <class T> using PQS = priority_queue<T, vector<T>, greater<T>>;\nconstexpr int\
    \ inf = 1000000000;\nconstexpr long long inf_ll = 1000000000000000000ll, MOD =\
    \ 1000000007;\nconstexpr long double PI = 3.14159265358979323846, EPS = 1e-12;\n\
    namespace CharacterClass {\n\tconstexpr string_view\n\t    digit = \"0123456789\"\
    ,\n\t    xdigit = \"0123456789ABCDEFabcdef\", lower = \"abcdefghijklmnopqrstuvwxyz\"\
    ,\n\t    upper = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\",\n\t    alpha = \"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\"\
    ,\n\t    alnum = \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\"\
    ,\n\t    word = \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz\"\
    ,\n\t    punct = R\"(!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~)\",\n\t    graph =\n\t\
    \        R\"(!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~)\"\
    ,\n\t    print =\n\t        R\"( !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\\
    ]^_`abcdefghijklmnopqrstuvwxyz{|}~)\",\n\t    blank = \" \\t\", space = \" \\\
    t\\n\\r\\f\\v\";\n}  // namespace CharacterClass\n"
  dependsOn: []
  isVerificationFile: false
  path: template/constants.cpp
  requiredBy:
  - template/template.cpp
  - template/template_no_Ruby.cpp
  timestamp: '2020-11-29 16:12:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/constants.cpp
layout: document
redirect_from:
- /library/template/constants.cpp
- /library/template/constants.cpp.html
title: template/constants.cpp
---
