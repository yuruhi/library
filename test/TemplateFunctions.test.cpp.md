---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/functions.cpp
    title: template/functions.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/TemplateFunctions.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n#line 2 \"template/functions.cpp\"\n#include <algorithm>\n#include <numeric>\n\
    #include <cmath>\n#include <vector>\n#include <cassert>\nusing namespace std;\n\
    \ntemplate <class T = long long> constexpr T TEN(size_t n) {\n\tT result = 1;\n\
    \tfor (size_t i = 0; i < n; ++i) result *= 10;\n\treturn result;\n}\ntemplate\
    \ <class T, class U,\n          enable_if_t<is_integral_v<T> && is_integral_v<U>,\
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
    \ int BIT(T x, int i) {\n\treturn (x & (T(1) << i)) ? 1 : 0;\n}\ntemplate <class\
    \ T> constexpr int Sgn(T x) {\n\treturn (0 < x) - (0 > x);\n}\ntemplate <class\
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
    \ init);\n}\n#line 3 \"test/TemplateFunctions.test.cpp\"\n#include <iostream>\n\
    using namespace std;\n\nint main() {\n\t{\n\t\tstatic_assert(div_ceil(9, 3) ==\
    \ 3);\n\t\tstatic_assert(div_ceil(10, 3) == 4);\n\t\tstatic_assert(div_ceil(11,\
    \ 3) == 4);\n\t\tstatic_assert(div_ceil(12, 3) == 4);\n\t\tstatic_assert(div_ceil(13,\
    \ 3) == 5);\n\t\tstatic_assert(div_ceil(1000000000000000000ll, 3) == 333333333333333334ll);\n\
    \t\tstatic_assert(div_ceil(3, 1000000000000000000ll) == 1);\n\t\tstatic_assert(div_ceil(1000000000000000000ll,\
    \ 300000000000000000) == 4);\n\t}\n\t{\n\t\tstatic_assert(div_ceil2(9, 3) == 9);\n\
    \t\tstatic_assert(div_ceil2(10, 3) == 12);\n\t\tstatic_assert(div_ceil2(11, 3)\
    \ == 12);\n\t\tstatic_assert(div_ceil2(12, 3) == 12);\n\t\tstatic_assert(div_ceil2(13,\
    \ 3) == 15);\n\t\tstatic_assert(div_ceil2(1000000000000000000ll, 3) == 1000000000000000002ll);\n\
    \t\tstatic_assert(div_ceil2(3, 1000000000000000000ll) == 1000000000000000000ll);\n\
    \t\tstatic_assert(div_ceil2(1000000000000000000ll, 300000000000000000) ==\n\t\t\
    \              1200000000000000000ll);\n\t}\n\t{\n\t\tstatic_assert(triangle(0)\
    \ == 0);\n\t\tstatic_assert(triangle(1) == 1);\n\t\tstatic_assert(triangle(2)\
    \ == 3);\n\t\tstatic_assert(triangle(3) == 6);\n\t\tstatic_assert(triangle(1000000000ll)\
    \ == 500000000500000000ll);\n\t\tstatic_assert(triangle(4000000000ll) == 8000000002000000000ll);\n\
    \t}\n\t{\n\t\tstatic_assert(nC2(0) == 0);\n\t\tstatic_assert(nC2(1) == 0);\n\t\
    \tstatic_assert(nC2(2) == 1);\n\t\tstatic_assert(nC2(3) == 3);\n\t\tstatic_assert(nC2(1000000000ll)\
    \ == 499999999500000000ll);\n\t\tstatic_assert(nC2(4000000000ll) == 7999999998000000000ll);\n\
    \t}\n\t{\n\t\tstatic_assert(middle(-10, 10) == 0);\n\t\tstatic_assert(middle(10,\
    \ 10) == 10);\n\t\tstatic_assert(middle(10, 15) == 12);\n\t\tstatic_assert(middle(0,\
    \ 1000000000000000000ll) == 500000000000000000ll);\n\t\tstatic_assert(middle(1000000000000000000ll,\
    \ 3000000000000000000ll) ==\n\t\t              2000000000000000000ll);\n\t}\n\t\
    {\n\t\tstatic_assert(!in_range(-1, 0, 20));\n\t\tstatic_assert(in_range(0, 0,\
    \ 20));\n\t\tstatic_assert(in_range(19, 0, 20));\n\t\tstatic_assert(!in_range(20,\
    \ 0, 20));\n\t\tstatic_assert(!in_range(-1, 0, 1000000000000000000ll));\n\t\t\
    static_assert(in_range(0, 0, 1000000000000000000ll));\n\t\tstatic_assert(in_range(999999999999999999ll,\
    \ 0, 1000000000000000000ll));\n\t\tstatic_assert(!in_range(1000000000000000000ll,\
    \ 0, 1000000000000000000ll));\n\t}\n\t{\n\t\tstatic_assert(!is_square(15));\n\t\
    \tstatic_assert(is_square(16));\n\t\tstatic_assert(!is_square(17));\n\t\tstatic_assert(!is_square(996491788296388608ll));\n\
    \t\tstatic_assert(is_square(996491788296388609ll));\n\t\tstatic_assert(!is_square(996491788296388610ll));\n\
    \t}\n\t{\n\t\tstatic_assert(BIT<int>(0) == 1);\n\t\tstatic_assert(BIT<int>(1)\
    \ == 2);\n\t\tstatic_assert(BIT(0) == 1);\n\t\tstatic_assert(BIT(1) == 2);\n\t\
    \tstatic_assert(BIT(32) == 4294967296ll);\n\t\tstatic_assert(BIT(62) == 4611686018427387904ll);\n\
    \t}\n\t{\n\t\tstatic_assert(Pow(0, 0) == 1);\n\t\tstatic_assert(Pow(1000000000000000000ll,\
    \ 0) == 1);\n\t\tstatic_assert(Pow(0, 1) == 0);\n\t\tstatic_assert(Pow(1000000000000000000ll,\
    \ 1) == 1000000000000000000ll);\n\t\tstatic_assert(Pow(2, 10) == 1024);\n\t\t\
    static_assert(Pow(2ll, 62) == 4611686018427387904ll);\n\t\tstatic_assert(Pow(10,\
    \ 9) == 1000000000);\n\t\tstatic_assert(Pow(10ll, 18) == 1000000000000000000ll);\n\
    \t}\n\t{\n\t\tstatic_assert(Powmod(0, 0, 2) == 1);\n\t\tstatic_assert(Powmod(1000000000000000000ll,\
    \ 0, 2ll) == 1);\n\t\tstatic_assert(Powmod(0, 1, 2) == 0);\n\t\tstatic_assert(Powmod(1000000000000000000ll,\
    \ 1, 3ll) == 1);\n\t\tstatic_assert(Powmod(2, 10, 1000000000) == 1024);\n\t\t\
    static_assert(Powmod(2ll, 998244353, 1000000007ll) == 213467670);\n\t\tstatic_assert(Powmod(10ll,\
    \ 998244353998244353ll, 1000000007ll) == 821601853);\n\t\tstatic_assert(Powmod(998244353998244353ll,\
    \ 998244353998244353ll, 1000000007ll) ==\n\t\t              55266312);\n\t}\n\t\
    {\n\t\tstatic_assert(TEN<int>(0) == 1);\n\t\tstatic_assert(TEN<int>(1) == 10);\n\
    \t\tstatic_assert(TEN<int>(9) == 1000000000);\n\t\tstatic_assert(TEN(0) == 1);\n\
    \t\tstatic_assert(TEN(1) == 10);\n\t\tstatic_assert(TEN(9) == 1000000000);\n\t\
    \tstatic_assert(TEN(18) == 1000000000000000000);\n\t}\n\n\tcout << \"Hello World\"\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n#include \"./../template/functions.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\t{\n\t\tstatic_assert(div_ceil(9, 3) == 3);\n\t\tstatic_assert(div_ceil(10,\
    \ 3) == 4);\n\t\tstatic_assert(div_ceil(11, 3) == 4);\n\t\tstatic_assert(div_ceil(12,\
    \ 3) == 4);\n\t\tstatic_assert(div_ceil(13, 3) == 5);\n\t\tstatic_assert(div_ceil(1000000000000000000ll,\
    \ 3) == 333333333333333334ll);\n\t\tstatic_assert(div_ceil(3, 1000000000000000000ll)\
    \ == 1);\n\t\tstatic_assert(div_ceil(1000000000000000000ll, 300000000000000000)\
    \ == 4);\n\t}\n\t{\n\t\tstatic_assert(div_ceil2(9, 3) == 9);\n\t\tstatic_assert(div_ceil2(10,\
    \ 3) == 12);\n\t\tstatic_assert(div_ceil2(11, 3) == 12);\n\t\tstatic_assert(div_ceil2(12,\
    \ 3) == 12);\n\t\tstatic_assert(div_ceil2(13, 3) == 15);\n\t\tstatic_assert(div_ceil2(1000000000000000000ll,\
    \ 3) == 1000000000000000002ll);\n\t\tstatic_assert(div_ceil2(3, 1000000000000000000ll)\
    \ == 1000000000000000000ll);\n\t\tstatic_assert(div_ceil2(1000000000000000000ll,\
    \ 300000000000000000) ==\n\t\t              1200000000000000000ll);\n\t}\n\t{\n\
    \t\tstatic_assert(triangle(0) == 0);\n\t\tstatic_assert(triangle(1) == 1);\n\t\
    \tstatic_assert(triangle(2) == 3);\n\t\tstatic_assert(triangle(3) == 6);\n\t\t\
    static_assert(triangle(1000000000ll) == 500000000500000000ll);\n\t\tstatic_assert(triangle(4000000000ll)\
    \ == 8000000002000000000ll);\n\t}\n\t{\n\t\tstatic_assert(nC2(0) == 0);\n\t\t\
    static_assert(nC2(1) == 0);\n\t\tstatic_assert(nC2(2) == 1);\n\t\tstatic_assert(nC2(3)\
    \ == 3);\n\t\tstatic_assert(nC2(1000000000ll) == 499999999500000000ll);\n\t\t\
    static_assert(nC2(4000000000ll) == 7999999998000000000ll);\n\t}\n\t{\n\t\tstatic_assert(middle(-10,\
    \ 10) == 0);\n\t\tstatic_assert(middle(10, 10) == 10);\n\t\tstatic_assert(middle(10,\
    \ 15) == 12);\n\t\tstatic_assert(middle(0, 1000000000000000000ll) == 500000000000000000ll);\n\
    \t\tstatic_assert(middle(1000000000000000000ll, 3000000000000000000ll) ==\n\t\t\
    \              2000000000000000000ll);\n\t}\n\t{\n\t\tstatic_assert(!in_range(-1,\
    \ 0, 20));\n\t\tstatic_assert(in_range(0, 0, 20));\n\t\tstatic_assert(in_range(19,\
    \ 0, 20));\n\t\tstatic_assert(!in_range(20, 0, 20));\n\t\tstatic_assert(!in_range(-1,\
    \ 0, 1000000000000000000ll));\n\t\tstatic_assert(in_range(0, 0, 1000000000000000000ll));\n\
    \t\tstatic_assert(in_range(999999999999999999ll, 0, 1000000000000000000ll));\n\
    \t\tstatic_assert(!in_range(1000000000000000000ll, 0, 1000000000000000000ll));\n\
    \t}\n\t{\n\t\tstatic_assert(!is_square(15));\n\t\tstatic_assert(is_square(16));\n\
    \t\tstatic_assert(!is_square(17));\n\t\tstatic_assert(!is_square(996491788296388608ll));\n\
    \t\tstatic_assert(is_square(996491788296388609ll));\n\t\tstatic_assert(!is_square(996491788296388610ll));\n\
    \t}\n\t{\n\t\tstatic_assert(BIT<int>(0) == 1);\n\t\tstatic_assert(BIT<int>(1)\
    \ == 2);\n\t\tstatic_assert(BIT(0) == 1);\n\t\tstatic_assert(BIT(1) == 2);\n\t\
    \tstatic_assert(BIT(32) == 4294967296ll);\n\t\tstatic_assert(BIT(62) == 4611686018427387904ll);\n\
    \t}\n\t{\n\t\tstatic_assert(Pow(0, 0) == 1);\n\t\tstatic_assert(Pow(1000000000000000000ll,\
    \ 0) == 1);\n\t\tstatic_assert(Pow(0, 1) == 0);\n\t\tstatic_assert(Pow(1000000000000000000ll,\
    \ 1) == 1000000000000000000ll);\n\t\tstatic_assert(Pow(2, 10) == 1024);\n\t\t\
    static_assert(Pow(2ll, 62) == 4611686018427387904ll);\n\t\tstatic_assert(Pow(10,\
    \ 9) == 1000000000);\n\t\tstatic_assert(Pow(10ll, 18) == 1000000000000000000ll);\n\
    \t}\n\t{\n\t\tstatic_assert(Powmod(0, 0, 2) == 1);\n\t\tstatic_assert(Powmod(1000000000000000000ll,\
    \ 0, 2ll) == 1);\n\t\tstatic_assert(Powmod(0, 1, 2) == 0);\n\t\tstatic_assert(Powmod(1000000000000000000ll,\
    \ 1, 3ll) == 1);\n\t\tstatic_assert(Powmod(2, 10, 1000000000) == 1024);\n\t\t\
    static_assert(Powmod(2ll, 998244353, 1000000007ll) == 213467670);\n\t\tstatic_assert(Powmod(10ll,\
    \ 998244353998244353ll, 1000000007ll) == 821601853);\n\t\tstatic_assert(Powmod(998244353998244353ll,\
    \ 998244353998244353ll, 1000000007ll) ==\n\t\t              55266312);\n\t}\n\t\
    {\n\t\tstatic_assert(TEN<int>(0) == 1);\n\t\tstatic_assert(TEN<int>(1) == 10);\n\
    \t\tstatic_assert(TEN<int>(9) == 1000000000);\n\t\tstatic_assert(TEN(0) == 1);\n\
    \t\tstatic_assert(TEN(1) == 10);\n\t\tstatic_assert(TEN(9) == 1000000000);\n\t\
    \tstatic_assert(TEN(18) == 1000000000000000000);\n\t}\n\n\tcout << \"Hello World\"\
    \ << endl;\n}"
  dependsOn:
  - template/functions.cpp
  isVerificationFile: true
  path: test/TemplateFunctions.test.cpp
  requiredBy: []
  timestamp: '2020-12-21 16:46:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/TemplateFunctions.test.cpp
layout: document
redirect_from:
- /verify/test/TemplateFunctions.test.cpp
- /verify/test/TemplateFunctions.test.cpp.html
title: test/TemplateFunctions.test.cpp
---
