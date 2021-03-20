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
    path: test/TemplateFunctions.test.cpp
    title: test/TemplateFunctions.test.cpp
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
  bundledCode: "#line 2 \"Utility/functions.cpp\"\n#include <algorithm>\n#include\
    \ <numeric>\n#include <cmath>\n#include <vector>\n#include <tuple>\n#include <cassert>\n\
    \ntemplate <class T = long long> constexpr T TEN(std::size_t n) {\n\tT result\
    \ = 1;\n\tfor (std::size_t i = 0; i < n; ++i) result *= 10;\n\treturn result;\n\
    }\ntemplate <\n    class T, class U,\n    std::enable_if_t<std::is_integral_v<T>\
    \ && std::is_integral_v<U>, std::nullptr_t> = nullptr>\nconstexpr auto div_ceil(T\
    \ n, U m) {\n\treturn (n + m - 1) / m;\n}\ntemplate <class T, class U> constexpr\
    \ auto div_ceil2(T n, U m) {\n\treturn div_ceil(n, m) * m;\n}\ntemplate <class\
    \ T> constexpr T triangle(T n) {\n\treturn (n & 1) ? (n + 1) / 2 * n : n / 2 *\
    \ (n + 1);\n}\ntemplate <class T> constexpr T nC2(T n) {\n\treturn (n & 1) ? (n\
    \ - 1) / 2 * n : n / 2 * (n - 1);\n}\ntemplate <class T, class U> constexpr auto\
    \ middle(const T& l, const U& r) {\n\treturn l + (r - l) / 2;\n}\ntemplate <class\
    \ T, class U, class V>\nconstexpr bool in_range(const T& v, const U& lower, const\
    \ V& upper) {\n\treturn lower <= v && v < upper;\n}\ntemplate <class T, std::enable_if_t<std::is_integral_v<T>,\
    \ std::nullptr_t> = nullptr>\nconstexpr bool is_square(T n) {\n\tT s = std::sqrt(n);\n\
    \treturn s * s == n || (s + 1) * (s + 1) == n;\n}\ntemplate <class T = long long>\
    \ constexpr T BIT(int b) {\n\treturn T(1) << b;\n}\ntemplate <class T> constexpr\
    \ int BIT(T x, int i) {\n\treturn (x & (T(1) << i)) ? 1 : 0;\n}\ntemplate <class\
    \ T> constexpr int Sgn(T x) {\n\treturn (0 < x) - (0 > x);\n}\ntemplate <class\
    \ T> bool is_leap(T year) {\n\treturn !(year % 4) && (year % 100 || !(year % 400));\n\
    }\ntemplate <class T, class U, std::enable_if_t<std::is_integral_v<U>, std::nullptr_t>\
    \ = nullptr>\nconstexpr T Pow(T a, U n) {\n\tassert(n >= 0);\n\tT result = 1;\n\
    \twhile (n > 0) {\n\t\tif (n & 1) {\n\t\t\tresult *= a;\n\t\t\tn--;\n\t\t} else\
    \ {\n\t\t\ta *= a;\n\t\t\tn >>= 1;\n\t\t}\n\t}\n\treturn result;\n}\ntemplate\
    \ <class T, class U, std::enable_if_t<std::is_integral_v<U>, std::nullptr_t> =\
    \ nullptr>\nconstexpr T Powmod(T a, U n, T mod) {\n\tassert(n >= 0);\n\tif (a\
    \ > mod) a %= mod;\n\tT result = 1;\n\twhile (n > 0) {\n\t\tif (n & 1) {\n\t\t\
    \tresult = result * a % mod;\n\t\t\tn--;\n\t\t} else {\n\t\t\ta = a * a % mod;\n\
    \t\t\tn >>= 1;\n\t\t}\n\t}\n\treturn result;\n}\ntemplate <class T> bool chmax(T&\
    \ a, const T& b) {\n\treturn a < b ? a = b, true : false;\n}\ntemplate <class\
    \ T> bool chmin(T& a, const T& b) {\n\treturn a > b ? a = b, true : false;\n}\n\
    template <class T> int sz(const T& v) {\n\treturn v.size();\n}\ntemplate <class\
    \ T, class U> int lower_index(const T& a, const U& v) {\n\treturn std::lower_bound(a.begin(),\
    \ a.end(), v) - a.begin();\n}\ntemplate <class T, class U> int upper_index(const\
    \ T& a, const U& v) {\n\treturn std::upper_bound(a.begin(), a.end(), v) - a.begin();\n\
    }\ntemplate <class T, class U = typename T::value_type> U Gcdv(const T& v) {\n\
    \treturn std::accumulate(std::next(v.begin()), v.end(), U(*v.begin()), std::gcd<U,\
    \ U>);\n}\ntemplate <class T, class U = typename T::value_type> U Lcmv(const T&\
    \ v) {\n\treturn std::accumulate(std::next(v.begin()), v.end(), U(*v.begin()),\
    \ std::lcm<U, U>);\n}\nnamespace internal {\n\ttemplate <class T, std::size_t\
    \ N>\n\tauto make_vector(std::vector<int>& sizes, const T& init) {\n\t\tif constexpr\
    \ (N == 1) {\n\t\t\treturn std::vector(sizes[0], init);\n\t\t} else {\n\t\t\t\
    int size = sizes[N - 1];\n\t\t\tsizes.pop_back();\n\t\t\treturn std::vector(size,\
    \ make_vector<T, N - 1>(sizes, init));\n\t\t}\n\t}\n}  // namespace internal\n\
    template <class T, std::size_t N>\nauto make_vector(const int (&sizes)[N], const\
    \ T& init = T()) {\n\tstd::vector s(std::rbegin(sizes), std::rend(sizes));\n\t\
    return internal::make_vector<T, N>(s, init);\n}\n\nnamespace lambda {\n\tauto\
    \ char_to_int = [](char c) {\n\t\treturn c - '0';\n\t};\n\tauto lower_to_int =\
    \ [](char c) {\n\t\treturn c - 'a';\n\t};\n\tauto upper_to_int = [](char c) {\n\
    \t\treturn c - 'A';\n\t};\n\tauto int_to_char = [](int i) -> char {\n\t\treturn\
    \ '0' + i;\n\t};\n\tauto int_to_lower = [](int i) -> char {\n\t\treturn 'a' +\
    \ i;\n\t};\n\tauto int_to_upper = [](int i) -> char {\n\t\treturn 'A' + i;\n\t\
    };\n\tauto is_odd = [](auto n) {\n\t\treturn n % 2 == 1;\n\t};\n\tauto is_even\
    \ = [](auto n) {\n\t\treturn n % 2 == 0;\n\t};\n\tauto is_positive = [](auto n)\
    \ {\n\t\treturn n > 0;\n\t};\n\tauto is_negative = [](auto n) {\n\t\treturn n\
    \ < 0;\n\t};\n\tauto increment = [](auto n) {\n\t\treturn ++n;\n\t};\n\tauto decrement\
    \ = [](auto n) {\n\t\treturn --n;\n\t};\n\tauto yield_self = [](const auto& n)\
    \ {\n\t\treturn n;\n\t};\n\tauto first = [](const auto& n) {\n\t\treturn n.first;\n\
    \t};\n\tauto second = [](const auto& n) {\n\t\treturn n.second;\n\t};\n\ttemplate\
    \ <class T> auto cast() {\n\t\treturn [](const auto& n) {\n\t\t\treturn static_cast<T>(n);\n\
    \t\t};\n\t};\n\ttemplate <class T> auto equal_to(const T& x) {\n\t\treturn [x](auto\
    \ y) {\n\t\t\treturn x == y;\n\t\t};\n\t}\n\ttemplate <std::size_t I> auto get()\
    \ {\n\t\treturn [](const auto& n) {\n\t\t\treturn std::get<I>(n);\n\t\t};\n\t\
    }\n\ttemplate <class F> auto cmp(F&& f) {\n\t\treturn [f](const auto& a, const\
    \ auto& b) {\n\t\t\treturn f(a) < f(b);\n\t\t};\n\t}\n}  // namespace lambda\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <cmath>\n\
    #include <vector>\n#include <tuple>\n#include <cassert>\n\ntemplate <class T =\
    \ long long> constexpr T TEN(std::size_t n) {\n\tT result = 1;\n\tfor (std::size_t\
    \ i = 0; i < n; ++i) result *= 10;\n\treturn result;\n}\ntemplate <\n    class\
    \ T, class U,\n    std::enable_if_t<std::is_integral_v<T> && std::is_integral_v<U>,\
    \ std::nullptr_t> = nullptr>\nconstexpr auto div_ceil(T n, U m) {\n\treturn (n\
    \ + m - 1) / m;\n}\ntemplate <class T, class U> constexpr auto div_ceil2(T n,\
    \ U m) {\n\treturn div_ceil(n, m) * m;\n}\ntemplate <class T> constexpr T triangle(T\
    \ n) {\n\treturn (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);\n}\ntemplate <class\
    \ T> constexpr T nC2(T n) {\n\treturn (n & 1) ? (n - 1) / 2 * n : n / 2 * (n -\
    \ 1);\n}\ntemplate <class T, class U> constexpr auto middle(const T& l, const\
    \ U& r) {\n\treturn l + (r - l) / 2;\n}\ntemplate <class T, class U, class V>\n\
    constexpr bool in_range(const T& v, const U& lower, const V& upper) {\n\treturn\
    \ lower <= v && v < upper;\n}\ntemplate <class T, std::enable_if_t<std::is_integral_v<T>,\
    \ std::nullptr_t> = nullptr>\nconstexpr bool is_square(T n) {\n\tT s = std::sqrt(n);\n\
    \treturn s * s == n || (s + 1) * (s + 1) == n;\n}\ntemplate <class T = long long>\
    \ constexpr T BIT(int b) {\n\treturn T(1) << b;\n}\ntemplate <class T> constexpr\
    \ int BIT(T x, int i) {\n\treturn (x & (T(1) << i)) ? 1 : 0;\n}\ntemplate <class\
    \ T> constexpr int Sgn(T x) {\n\treturn (0 < x) - (0 > x);\n}\ntemplate <class\
    \ T> bool is_leap(T year) {\n\treturn !(year % 4) && (year % 100 || !(year % 400));\n\
    }\ntemplate <class T, class U, std::enable_if_t<std::is_integral_v<U>, std::nullptr_t>\
    \ = nullptr>\nconstexpr T Pow(T a, U n) {\n\tassert(n >= 0);\n\tT result = 1;\n\
    \twhile (n > 0) {\n\t\tif (n & 1) {\n\t\t\tresult *= a;\n\t\t\tn--;\n\t\t} else\
    \ {\n\t\t\ta *= a;\n\t\t\tn >>= 1;\n\t\t}\n\t}\n\treturn result;\n}\ntemplate\
    \ <class T, class U, std::enable_if_t<std::is_integral_v<U>, std::nullptr_t> =\
    \ nullptr>\nconstexpr T Powmod(T a, U n, T mod) {\n\tassert(n >= 0);\n\tif (a\
    \ > mod) a %= mod;\n\tT result = 1;\n\twhile (n > 0) {\n\t\tif (n & 1) {\n\t\t\
    \tresult = result * a % mod;\n\t\t\tn--;\n\t\t} else {\n\t\t\ta = a * a % mod;\n\
    \t\t\tn >>= 1;\n\t\t}\n\t}\n\treturn result;\n}\ntemplate <class T> bool chmax(T&\
    \ a, const T& b) {\n\treturn a < b ? a = b, true : false;\n}\ntemplate <class\
    \ T> bool chmin(T& a, const T& b) {\n\treturn a > b ? a = b, true : false;\n}\n\
    template <class T> int sz(const T& v) {\n\treturn v.size();\n}\ntemplate <class\
    \ T, class U> int lower_index(const T& a, const U& v) {\n\treturn std::lower_bound(a.begin(),\
    \ a.end(), v) - a.begin();\n}\ntemplate <class T, class U> int upper_index(const\
    \ T& a, const U& v) {\n\treturn std::upper_bound(a.begin(), a.end(), v) - a.begin();\n\
    }\ntemplate <class T, class U = typename T::value_type> U Gcdv(const T& v) {\n\
    \treturn std::accumulate(std::next(v.begin()), v.end(), U(*v.begin()), std::gcd<U,\
    \ U>);\n}\ntemplate <class T, class U = typename T::value_type> U Lcmv(const T&\
    \ v) {\n\treturn std::accumulate(std::next(v.begin()), v.end(), U(*v.begin()),\
    \ std::lcm<U, U>);\n}\nnamespace internal {\n\ttemplate <class T, std::size_t\
    \ N>\n\tauto make_vector(std::vector<int>& sizes, const T& init) {\n\t\tif constexpr\
    \ (N == 1) {\n\t\t\treturn std::vector(sizes[0], init);\n\t\t} else {\n\t\t\t\
    int size = sizes[N - 1];\n\t\t\tsizes.pop_back();\n\t\t\treturn std::vector(size,\
    \ make_vector<T, N - 1>(sizes, init));\n\t\t}\n\t}\n}  // namespace internal\n\
    template <class T, std::size_t N>\nauto make_vector(const int (&sizes)[N], const\
    \ T& init = T()) {\n\tstd::vector s(std::rbegin(sizes), std::rend(sizes));\n\t\
    return internal::make_vector<T, N>(s, init);\n}\n\nnamespace lambda {\n\tauto\
    \ char_to_int = [](char c) {\n\t\treturn c - '0';\n\t};\n\tauto lower_to_int =\
    \ [](char c) {\n\t\treturn c - 'a';\n\t};\n\tauto upper_to_int = [](char c) {\n\
    \t\treturn c - 'A';\n\t};\n\tauto int_to_char = [](int i) -> char {\n\t\treturn\
    \ '0' + i;\n\t};\n\tauto int_to_lower = [](int i) -> char {\n\t\treturn 'a' +\
    \ i;\n\t};\n\tauto int_to_upper = [](int i) -> char {\n\t\treturn 'A' + i;\n\t\
    };\n\tauto is_odd = [](auto n) {\n\t\treturn n % 2 == 1;\n\t};\n\tauto is_even\
    \ = [](auto n) {\n\t\treturn n % 2 == 0;\n\t};\n\tauto is_positive = [](auto n)\
    \ {\n\t\treturn n > 0;\n\t};\n\tauto is_negative = [](auto n) {\n\t\treturn n\
    \ < 0;\n\t};\n\tauto increment = [](auto n) {\n\t\treturn ++n;\n\t};\n\tauto decrement\
    \ = [](auto n) {\n\t\treturn --n;\n\t};\n\tauto yield_self = [](const auto& n)\
    \ {\n\t\treturn n;\n\t};\n\tauto first = [](const auto& n) {\n\t\treturn n.first;\n\
    \t};\n\tauto second = [](const auto& n) {\n\t\treturn n.second;\n\t};\n\ttemplate\
    \ <class T> auto cast() {\n\t\treturn [](const auto& n) {\n\t\t\treturn static_cast<T>(n);\n\
    \t\t};\n\t};\n\ttemplate <class T> auto equal_to(const T& x) {\n\t\treturn [x](auto\
    \ y) {\n\t\t\treturn x == y;\n\t\t};\n\t}\n\ttemplate <std::size_t I> auto get()\
    \ {\n\t\treturn [](const auto& n) {\n\t\t\treturn std::get<I>(n);\n\t\t};\n\t\
    }\n\ttemplate <class F> auto cmp(F&& f) {\n\t\treturn [f](const auto& a, const\
    \ auto& b) {\n\t\t\treturn f(a) < f(b);\n\t\t};\n\t}\n}  // namespace lambda\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/functions.cpp
  requiredBy:
  - template_no_Ruby.cpp
  - template.cpp
  timestamp: '2021-03-19 16:49:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/TemplateFunctions.test.cpp
  - test/template.test.cpp
  - test/template_no_Ruby.test.cpp
documentation_of: Utility/functions.cpp
layout: document
redirect_from:
- /library/Utility/functions.cpp
- /library/Utility/functions.cpp.html
title: Utility/functions.cpp
---
