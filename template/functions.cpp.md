---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/BabystepGiantstep.cpp
    title: Math/BabystepGiantstep.cpp
  - icon: ':warning:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/functions.cpp\"\n#include <algorithm>\n#include\
    \ <numeric>\n#include <cmath>\n#include <vector>\nusing namespace std;\n\ntemplate\
    \ <class T, class U> inline int Lower(const T& a, const U& v) {\n\treturn lower_bound(all(a),\
    \ v) - a.begin();\n}\ntemplate <class T, class U> inline int Upper(const T& a,\
    \ const U& v) {\n\treturn upper_bound(all(a), v) - a.begin();\n}\ntemplate <class\
    \ T> inline auto Slice(const T& v, size_t i, size_t len) {\n\treturn i < v.size()\
    \ ? T(v.begin() + i, v.begin() + min(i + len, v.size())) : T();\n}\ntemplate <class\
    \ T> inline T Ceil(T n, T m) {\n\treturn (n + m - 1) / m;\n}\ntemplate <class\
    \ T> inline T Ceil2(T n, T m) {\n\treturn Ceil(n, m) * m;\n}\ntemplate <class\
    \ T> inline T Tri(T n) {\n\treturn (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);\n\
    }\ntemplate <class T> inline T nC2(T n) {\n\treturn (n & 1) ? (n - 1) / 2 * n\
    \ : n / 2 * (n - 1);\n}\ntemplate <class T> inline T Mid(const T& l, const T&\
    \ r) {\n\treturn l + (r - l) / 2;\n}\ntemplate <class T> inline bool chmax(T&\
    \ a, const T& b) {\n\tif (a < b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn\
    \ false;\n}\ntemplate <class T> inline bool chmin(T& a, const T& b) {\n\tif (a\
    \ > b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate <class\
    \ T> inline bool inRange(const T& v, const T& min, const T& max) {\n\treturn min\
    \ <= v && v < max;\n}\ntemplate <class T> inline bool isSquere(T n) {\n\tT s =\
    \ sqrt(n);\n\treturn s * s == n || (s + 1) * (s + 1) == n;\n}\ntemplate <class\
    \ T = long long> inline T BIT(int b) {\n\treturn T(1) << b;\n}\ntemplate <class\
    \ T, class U = typename T::value_type> inline U Gcdv(const T& v) {\n\treturn accumulate(next(v.begin()),\
    \ v.end(), U(*v.begin()), gcd<U, U>);\n}\ntemplate <class T, class U = typename\
    \ T::value_type> inline U Lcmv(const T& v) {\n\treturn accumulate(next(v.begin()),\
    \ v.end(), U(*v.begin()), lcm<U, U>);\n}\ntemplate <class T> inline T Pow(T a,\
    \ T n) {\n\tT r = 1;\n\twhile (n > 0) {\n\t\tif (n & 1) r *= a;\n\t\ta *= a;\n\
    \t\tn /= 2;\n\t}\n\treturn r;\n}\ntemplate <class T> inline T Powmod(T a, T n,\
    \ T m = MOD) {\n\tT r = 1;\n\twhile (n > 0) {\n\t\tif (n & 1)\n\t\t\tr = r * a\
    \ % m, n--;\n\t\telse\n\t\t\ta = a * a % m, n /= 2;\n\t}\n\treturn r;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <cmath>\n\
    #include <vector>\nusing namespace std;\n\ntemplate <class T, class U> inline\
    \ int Lower(const T& a, const U& v) {\n\treturn lower_bound(all(a), v) - a.begin();\n\
    }\ntemplate <class T, class U> inline int Upper(const T& a, const U& v) {\n\t\
    return upper_bound(all(a), v) - a.begin();\n}\ntemplate <class T> inline auto\
    \ Slice(const T& v, size_t i, size_t len) {\n\treturn i < v.size() ? T(v.begin()\
    \ + i, v.begin() + min(i + len, v.size())) : T();\n}\ntemplate <class T> inline\
    \ T Ceil(T n, T m) {\n\treturn (n + m - 1) / m;\n}\ntemplate <class T> inline\
    \ T Ceil2(T n, T m) {\n\treturn Ceil(n, m) * m;\n}\ntemplate <class T> inline\
    \ T Tri(T n) {\n\treturn (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);\n}\ntemplate\
    \ <class T> inline T nC2(T n) {\n\treturn (n & 1) ? (n - 1) / 2 * n : n / 2 *\
    \ (n - 1);\n}\ntemplate <class T> inline T Mid(const T& l, const T& r) {\n\treturn\
    \ l + (r - l) / 2;\n}\ntemplate <class T> inline bool chmax(T& a, const T& b)\
    \ {\n\tif (a < b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate\
    \ <class T> inline bool chmin(T& a, const T& b) {\n\tif (a > b) {\n\t\ta = b;\n\
    \t\treturn true;\n\t}\n\treturn false;\n}\ntemplate <class T> inline bool inRange(const\
    \ T& v, const T& min, const T& max) {\n\treturn min <= v && v < max;\n}\ntemplate\
    \ <class T> inline bool isSquere(T n) {\n\tT s = sqrt(n);\n\treturn s * s == n\
    \ || (s + 1) * (s + 1) == n;\n}\ntemplate <class T = long long> inline T BIT(int\
    \ b) {\n\treturn T(1) << b;\n}\ntemplate <class T, class U = typename T::value_type>\
    \ inline U Gcdv(const T& v) {\n\treturn accumulate(next(v.begin()), v.end(), U(*v.begin()),\
    \ gcd<U, U>);\n}\ntemplate <class T, class U = typename T::value_type> inline\
    \ U Lcmv(const T& v) {\n\treturn accumulate(next(v.begin()), v.end(), U(*v.begin()),\
    \ lcm<U, U>);\n}\ntemplate <class T> inline T Pow(T a, T n) {\n\tT r = 1;\n\t\
    while (n > 0) {\n\t\tif (n & 1) r *= a;\n\t\ta *= a;\n\t\tn /= 2;\n\t}\n\treturn\
    \ r;\n}\ntemplate <class T> inline T Powmod(T a, T n, T m = MOD) {\n\tT r = 1;\n\
    \twhile (n > 0) {\n\t\tif (n & 1)\n\t\t\tr = r * a % m, n--;\n\t\telse\n\t\t\t\
    a = a * a % m, n /= 2;\n\t}\n\treturn r;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: template/functions.cpp
  requiredBy:
  - template/template.cpp
  - Math/BabystepGiantstep.cpp
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/functions.cpp
layout: document
redirect_from:
- /library/template/functions.cpp
- /library/template/functions.cpp.html
title: template/functions.cpp
---
