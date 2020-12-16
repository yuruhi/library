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
  - icon: ':warning:'
    path: template/template_no_Ruby.cpp
    title: template/template_no_Ruby.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/TemplateFunctions.test.cpp
    title: test/TemplateFunctions.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/functions.cpp\"\n#include <algorithm>\n#include\
    \ <numeric>\n#include <cmath>\n#include <vector>\n#include <cassert>\nusing namespace\
    \ std;\n\ntemplate <class T = long long> constexpr T TEN(size_t n) {\n\tT result\
    \ = 1;\n\tfor (size_t i = 0; i < n; ++i) result *= 10;\n\treturn result;\n}\n\
    template <class T, class U,\n          enable_if_t<is_integral_v<T> && is_integral_v<U>,\
    \ nullptr_t> = nullptr>\nconstexpr auto div_ceil(T n, U m) {\n\treturn (n + m\
    \ - 1) / m;\n}\ntemplate <class T, class U> constexpr auto div_ceil2(T n, U m)\
    \ {\n\treturn div_ceil(n, m) * m;\n}\ntemplate <class T> constexpr T triangle(T\
    \ n) {\n\treturn (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);\n}\ntemplate <class\
    \ T> constexpr T nC2(T n) {\n\treturn (n & 1) ? (n - 1) / 2 * n : n / 2 * (n -\
    \ 1);\n}\ntemplate <class T, class U> constexpr auto middle(const T& l, const\
    \ U& r) {\n\treturn l + (r - l) / 2;\n}\ntemplate <class T, class U, class V>\n\
    constexpr bool in_range(const T& v, const U& lower, const V& upper) {\n\treturn\
    \ lower <= v && v < upper;\n}\ntemplate <class T, enable_if_t<is_integral_v<T>,\
    \ nullptr_t> = nullptr>\nconstexpr bool is_square(T n) {\n\tT s = sqrt(n);\n\t\
    return s * s == n || (s + 1) * (s + 1) == n;\n}\ntemplate <class T = long long>\
    \ constexpr T BIT(int b) {\n\treturn T(1) << b;\n}\ntemplate <class T> constexpr\
    \ int BIT(T x, int i) {\n\treturn (x & (1 << i)) ? 1 : 0;\n}\ntemplate <class\
    \ T, class U, enable_if_t<is_integral_v<U>, nullptr_t> = nullptr>\nconstexpr T\
    \ Pow(T a, U n) {\n\tassert(n >= 0);\n\tT result = 1;\n\twhile (n > 0) {\n\t\t\
    if (n & 1) {\n\t\t\tresult *= a;\n\t\t\tn--;\n\t\t} else {\n\t\t\ta *= a;\n\t\t\
    \tn >>= 1;\n\t\t}\n\t}\n\treturn result;\n}\ntemplate <class T, class U, enable_if_t<is_integral_v<U>,\
    \ nullptr_t> = nullptr>\nconstexpr T Powmod(T a, U n, T mod) {\n\tassert(n >=\
    \ 0);\n\tif (a > mod) a %= mod;\n\tT result = 1;\n\twhile (n > 0) {\n\t\tif (n\
    \ & 1) {\n\t\t\tresult = result * a % mod;\n\t\t\tn--;\n\t\t} else {\n\t\t\ta\
    \ = a * a % mod;\n\t\t\tn >>= 1;\n\t\t}\n\t}\n\treturn result;\n}\ntemplate <class\
    \ T> bool chmax(T& a, const T& b) {\n\tif (a < b) {\n\t\ta = b;\n\t\treturn true;\n\
    \t}\n\treturn false;\n}\ntemplate <class T> bool chmin(T& a, const T& b) {\n\t\
    if (a > b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate\
    \ <class T> int sz(const T& v) {\n\treturn v.size();\n}\ntemplate <class T, class\
    \ U> int lower_index(const T& a, const U& v) {\n\treturn lower_bound(all(a), v)\
    \ - a.begin();\n}\ntemplate <class T, class U> int upper_index(const T& a, const\
    \ U& v) {\n\treturn upper_bound(all(a), v) - a.begin();\n}\ntemplate <class T>\
    \ auto Slice(const T& v, size_t i, size_t len) {\n\treturn i < v.size() ? T(v.begin()\
    \ + i, v.begin() + min(i + len, v.size())) : T();\n}\ntemplate <class T, class\
    \ U = typename T::value_type> U Gcdv(const T& v) {\n\treturn accumulate(next(v.begin()),\
    \ v.end(), U(*v.begin()), gcd<U, U>);\n}\ntemplate <class T, class U = typename\
    \ T::value_type> U Lcmv(const T& v) {\n\treturn accumulate(next(v.begin()), v.end(),\
    \ U(*v.begin()), lcm<U, U>);\n}\nnamespace internal {\n\ttemplate <class T, size_t\
    \ N> auto make_vector(vector<int>& sizes, const T& init) {\n\t\tif constexpr (N\
    \ == 1) {\n\t\t\treturn vector(sizes[0], init);\n\t\t} else {\n\t\t\tint size\
    \ = sizes[N - 1];\n\t\t\tsizes.pop_back();\n\t\t\treturn vector(size, make_vector<T,\
    \ N - 1>(sizes, init));\n\t\t}\n\t}\n}  // namespace internal\ntemplate <class\
    \ T, size_t N>\nauto make_vector(const int (&sizes)[N], const T& init = T()) {\n\
    \tvector s(rbegin(sizes), rend(sizes));\n\treturn internal::make_vector<T, N>(s,\
    \ init);\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <cmath>\n\
    #include <vector>\n#include <cassert>\nusing namespace std;\n\ntemplate <class\
    \ T = long long> constexpr T TEN(size_t n) {\n\tT result = 1;\n\tfor (size_t i\
    \ = 0; i < n; ++i) result *= 10;\n\treturn result;\n}\ntemplate <class T, class\
    \ U,\n          enable_if_t<is_integral_v<T> && is_integral_v<U>, nullptr_t> =\
    \ nullptr>\nconstexpr auto div_ceil(T n, U m) {\n\treturn (n + m - 1) / m;\n}\n\
    template <class T, class U> constexpr auto div_ceil2(T n, U m) {\n\treturn div_ceil(n,\
    \ m) * m;\n}\ntemplate <class T> constexpr T triangle(T n) {\n\treturn (n & 1)\
    \ ? (n + 1) / 2 * n : n / 2 * (n + 1);\n}\ntemplate <class T> constexpr T nC2(T\
    \ n) {\n\treturn (n & 1) ? (n - 1) / 2 * n : n / 2 * (n - 1);\n}\ntemplate <class\
    \ T, class U> constexpr auto middle(const T& l, const U& r) {\n\treturn l + (r\
    \ - l) / 2;\n}\ntemplate <class T, class U, class V>\nconstexpr bool in_range(const\
    \ T& v, const U& lower, const V& upper) {\n\treturn lower <= v && v < upper;\n\
    }\ntemplate <class T, enable_if_t<is_integral_v<T>, nullptr_t> = nullptr>\nconstexpr\
    \ bool is_square(T n) {\n\tT s = sqrt(n);\n\treturn s * s == n || (s + 1) * (s\
    \ + 1) == n;\n}\ntemplate <class T = long long> constexpr T BIT(int b) {\n\treturn\
    \ T(1) << b;\n}\ntemplate <class T> constexpr int BIT(T x, int i) {\n\treturn\
    \ (x & (1 << i)) ? 1 : 0;\n}\ntemplate <class T, class U, enable_if_t<is_integral_v<U>,\
    \ nullptr_t> = nullptr>\nconstexpr T Pow(T a, U n) {\n\tassert(n >= 0);\n\tT result\
    \ = 1;\n\twhile (n > 0) {\n\t\tif (n & 1) {\n\t\t\tresult *= a;\n\t\t\tn--;\n\t\
    \t} else {\n\t\t\ta *= a;\n\t\t\tn >>= 1;\n\t\t}\n\t}\n\treturn result;\n}\ntemplate\
    \ <class T, class U, enable_if_t<is_integral_v<U>, nullptr_t> = nullptr>\nconstexpr\
    \ T Powmod(T a, U n, T mod) {\n\tassert(n >= 0);\n\tif (a > mod) a %= mod;\n\t\
    T result = 1;\n\twhile (n > 0) {\n\t\tif (n & 1) {\n\t\t\tresult = result * a\
    \ % mod;\n\t\t\tn--;\n\t\t} else {\n\t\t\ta = a * a % mod;\n\t\t\tn >>= 1;\n\t\
    \t}\n\t}\n\treturn result;\n}\ntemplate <class T> bool chmax(T& a, const T& b)\
    \ {\n\tif (a < b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate\
    \ <class T> bool chmin(T& a, const T& b) {\n\tif (a > b) {\n\t\ta = b;\n\t\treturn\
    \ true;\n\t}\n\treturn false;\n}\ntemplate <class T> int sz(const T& v) {\n\t\
    return v.size();\n}\ntemplate <class T, class U> int lower_index(const T& a, const\
    \ U& v) {\n\treturn lower_bound(all(a), v) - a.begin();\n}\ntemplate <class T,\
    \ class U> int upper_index(const T& a, const U& v) {\n\treturn upper_bound(all(a),\
    \ v) - a.begin();\n}\ntemplate <class T> auto Slice(const T& v, size_t i, size_t\
    \ len) {\n\treturn i < v.size() ? T(v.begin() + i, v.begin() + min(i + len, v.size()))\
    \ : T();\n}\ntemplate <class T, class U = typename T::value_type> U Gcdv(const\
    \ T& v) {\n\treturn accumulate(next(v.begin()), v.end(), U(*v.begin()), gcd<U,\
    \ U>);\n}\ntemplate <class T, class U = typename T::value_type> U Lcmv(const T&\
    \ v) {\n\treturn accumulate(next(v.begin()), v.end(), U(*v.begin()), lcm<U, U>);\n\
    }\nnamespace internal {\n\ttemplate <class T, size_t N> auto make_vector(vector<int>&\
    \ sizes, const T& init) {\n\t\tif constexpr (N == 1) {\n\t\t\treturn vector(sizes[0],\
    \ init);\n\t\t} else {\n\t\t\tint size = sizes[N - 1];\n\t\t\tsizes.pop_back();\n\
    \t\t\treturn vector(size, make_vector<T, N - 1>(sizes, init));\n\t\t}\n\t}\n}\
    \  // namespace internal\ntemplate <class T, size_t N>\nauto make_vector(const\
    \ int (&sizes)[N], const T& init = T()) {\n\tvector s(rbegin(sizes), rend(sizes));\n\
    \treturn internal::make_vector<T, N>(s, init);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: template/functions.cpp
  requiredBy:
  - template/template_no_Ruby.cpp
  - template/template.cpp
  - Math/BabystepGiantstep.cpp
  timestamp: '2020-12-16 21:28:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/TemplateFunctions.test.cpp
documentation_of: template/functions.cpp
layout: document
redirect_from:
- /library/template/functions.cpp
- /library/template/functions.cpp.html
title: template/functions.cpp
---
