---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: template/functions.cpp
    title: template/functions.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/functions.cpp\"\n#include <algorithm>\n#include\
    \ <numeric>\n#include <cmath>\n#include <vector>\nusing namespace std;\n\ntemplate\
    \ <class T> int sz(const T& v) {\n\treturn v.size();\n}\ntemplate <class T, class\
    \ U> int Lower(const T& a, const U& v) {\n\treturn lower_bound(all(a), v) - a.begin();\n\
    }\ntemplate <class T, class U> int Upper(const T& a, const U& v) {\n\treturn upper_bound(all(a),\
    \ v) - a.begin();\n}\ntemplate <class T> auto Slice(const T& v, size_t i, size_t\
    \ len) {\n\treturn i < v.size() ? T(v.begin() + i, v.begin() + min(i + len, v.size()))\
    \ : T();\n}\ntemplate <class T> T Ceil(T n, T m) {\n\treturn (n + m - 1) / m;\n\
    }\ntemplate <class T> T Ceil2(T n, T m) {\n\treturn Ceil(n, m) * m;\n}\ntemplate\
    \ <class T> T Tri(T n) {\n\treturn (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);\n\
    }\ntemplate <class T> T nC2(T n) {\n\treturn (n & 1) ? (n - 1) / 2 * n : n / 2\
    \ * (n - 1);\n}\ntemplate <class T> T Mid(const T& l, const T& r) {\n\treturn\
    \ l + (r - l) / 2;\n}\ntemplate <class T> bool chmax(T& a, const T& b) {\n\tif\
    \ (a < b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate <class\
    \ T> bool chmin(T& a, const T& b) {\n\tif (a > b) {\n\t\ta = b;\n\t\treturn true;\n\
    \t}\n\treturn false;\n}\ntemplate <class T> bool inRange(const T& v, const T&\
    \ min, const T& max) {\n\treturn min <= v && v < max;\n}\ntemplate <class T> bool\
    \ isSquere(T n) {\n\tT s = sqrt(n);\n\treturn s * s == n || (s + 1) * (s + 1)\
    \ == n;\n}\ntemplate <class T = long long> T BIT(int b) {\n\treturn T(1) << b;\n\
    }\ntemplate <class T, class U = typename T::value_type> U Gcdv(const T& v) {\n\
    \treturn accumulate(next(v.begin()), v.end(), U(*v.begin()), gcd<U, U>);\n}\n\
    template <class T, class U = typename T::value_type> U Lcmv(const T& v) {\n\t\
    return accumulate(next(v.begin()), v.end(), U(*v.begin()), lcm<U, U>);\n}\ntemplate\
    \ <class T> T Pow(T a, T n) {\n\tT r = 1;\n\twhile (n > 0) {\n\t\tif (n & 1) r\
    \ *= a;\n\t\ta *= a;\n\t\tn /= 2;\n\t}\n\treturn r;\n}\ntemplate <class T> T Powmod(T\
    \ a, T n, T m = MOD) {\n\tT r = 1;\n\twhile (n > 0) {\n\t\tif (n & 1)\n\t\t\t\
    r = r * a % m, n--;\n\t\telse\n\t\t\ta = a * a % m, n /= 2;\n\t}\n\treturn r;\n\
    }\nnamespace internal {\n\ttemplate <class T, size_t N> auto make_vector(vector<int>&\
    \ sizes, const T& init) {\n\t\tif constexpr (N == 1) {\n\t\t\treturn vector(sizes[0],\
    \ init);\n\t\t} else {\n\t\t\tint size = sizes[N - 1];\n\t\t\tsizes.pop_back();\n\
    \t\t\treturn vector(size, make_vector<T, N - 1>(sizes, init));\n\t\t}\n\t}\n}\
    \  // namespace internal\ntemplate <class T, size_t N>\nauto make_vector(const\
    \ int (&sizes)[N], const T& init = T()) {\n\tvector s(rbegin(sizes), rend(sizes));\n\
    \treturn internal::make_vector<T, N>(s, init);\n}\n#line 4 \"Math/BabystepGiantstep.cpp\"\
    \n#include <unordered_map>\n#line 6 \"Math/BabystepGiantstep.cpp\"\nusing namespace\
    \ std;\n\nint64_t BabystepGiantstep(uint64_t g, uint64_t h,\n                \
    \          uint64_t mod) {  // g ^ result = h (mod mod)\n\tconst uint64_t m =\
    \ ceil(sqrt(mod));\n\tunordered_map<uint64_t, uint64_t> table;\n\tuint64_t e =\
    \ 1;\n\tfor (uint64_t i = 0; i < m; ++i) {\n\t\ttable[e] = i;\n\t\te = e * g %\
    \ mod;\n\t}\n\te = h;\n\tfor (uint64_t f = Powmod(g, mod - m - 1, mod), i = 0;\
    \ i < m; ++i) {\n\t\tif (table.count(e)) {\n\t\t\treturn i * m + table[e];\n\t\
    \t}\n\t\te = (e * f) % mod;\n\t}\n\treturn -1;\n}\n"
  code: "#pragma once\n#include \"./../template/functions.cpp\"\n#include <vector>\n\
    #include <unordered_map>\n#include <cmath>\nusing namespace std;\n\nint64_t BabystepGiantstep(uint64_t\
    \ g, uint64_t h,\n                          uint64_t mod) {  // g ^ result = h\
    \ (mod mod)\n\tconst uint64_t m = ceil(sqrt(mod));\n\tunordered_map<uint64_t,\
    \ uint64_t> table;\n\tuint64_t e = 1;\n\tfor (uint64_t i = 0; i < m; ++i) {\n\t\
    \ttable[e] = i;\n\t\te = e * g % mod;\n\t}\n\te = h;\n\tfor (uint64_t f = Powmod(g,\
    \ mod - m - 1, mod), i = 0; i < m; ++i) {\n\t\tif (table.count(e)) {\n\t\t\treturn\
    \ i * m + table[e];\n\t\t}\n\t\te = (e * f) % mod;\n\t}\n\treturn -1;\n}\n"
  dependsOn:
  - template/functions.cpp
  isVerificationFile: false
  path: Math/BabystepGiantstep.cpp
  requiredBy: []
  timestamp: '2020-11-23 14:52:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/BabystepGiantstep.cpp
layout: document
redirect_from:
- /library/Math/BabystepGiantstep.cpp
- /library/Math/BabystepGiantstep.cpp.html
title: Math/BabystepGiantstep.cpp
---
