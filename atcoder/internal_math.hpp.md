---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':warning:'
    path: atcoder/math.hpp
    title: atcoder/math.hpp
  - icon: ':warning:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/Barrett_reduction
  bundledCode: "#line 1 \"atcoder/internal_math.hpp\"\n\n\n\n#include <utility>\n\n\
    namespace atcoder {\n\n\tnamespace internal {\n\n\t\t// @param m `1 <= m`\n\t\t\
    // @return x mod m\n\t\tconstexpr long long safe_mod(long long x, long long m)\
    \ {\n\t\t\tx %= m;\n\t\t\tif (x < 0) x += m;\n\t\t\treturn x;\n\t\t}\n\n\t\t//\
    \ Fast moduler by barrett reduction\n\t\t// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n\
    \t\t// NOTE: reconsider after Ice Lake\n\t\tstruct barrett {\n\t\t\tunsigned int\
    \ _m;\n\t\t\tunsigned long long im;\n\n\t\t\t// @param m `1 <= m`\n\t\t\tbarrett(unsigned\
    \ int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}\n\n\t\t\t// @return\
    \ m\n\t\t\tunsigned int umod() const {\n\t\t\t\treturn _m;\n\t\t\t}\n\n\t\t\t\
    // @param a `0 <= a < m`\n\t\t\t// @param b `0 <= b < m`\n\t\t\t// @return `a\
    \ * b % m`\n\t\t\tunsigned int mul(unsigned int a, unsigned int b) const {\n\t\
    \t\t\t// [1] m = 1\n\t\t\t\t// a = b = im = 0, so okay\n\n\t\t\t\t// [2] m >=\
    \ 2\n\t\t\t\t// im = ceil(2^64 / m)\n\t\t\t\t// -> im * m = 2^64 + r (0 <= r <\
    \ m)\n\t\t\t\t// let z = a*b = c*m + d (0 <= c, d < m)\n\t\t\t\t// a*b * im =\
    \ (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r + d*im\n\t\t\t\t// c*r + d*im\
    \ < m * m + m * im < m * m + 2^64 + m <= 2^64 + m * (m + 1) < 2^64 * 2\n\t\t\t\
    \t// ((ab * im) >> 64) == c or c + 1\n\t\t\t\tunsigned long long z = a;\n\t\t\t\
    \tz *= b;\n#ifdef _MSC_VER\n\t\t\t\tunsigned long long x;\n\t\t\t\t_umul128(z,\
    \ im, &x);\n#else\n\t\t\t\tunsigned long long x = (unsigned long long)(((unsigned\
    \ __int128)(z)*im) >> 64);\n#endif\n\t\t\t\tunsigned int v = (unsigned int)(z\
    \ - x * _m);\n\t\t\t\tif (_m <= v) v += _m;\n\t\t\t\treturn v;\n\t\t\t}\n\t\t\
    };\n\n\t\t// @param n `0 <= n`\n\t\t// @param m `1 <= m`\n\t\t// @return `(x **\
    \ n) % m`\n\t\tconstexpr long long pow_mod_constexpr(long long x, long long n,\
    \ int m) {\n\t\t\tif (m == 1) return 0;\n\t\t\tunsigned int _m = (unsigned int)(m);\n\
    \t\t\tunsigned long long r = 1;\n\t\t\tunsigned long long y = safe_mod(x, m);\n\
    \t\t\twhile (n) {\n\t\t\t\tif (n & 1) r = (r * y) % _m;\n\t\t\t\ty = (y * y) %\
    \ _m;\n\t\t\t\tn >>= 1;\n\t\t\t}\n\t\t\treturn r;\n\t\t}\n\n\t\t// Reference:\n\
    \t\t// M. Forisek and J. Jancina,\n\t\t// Fast Primality Testing for Integers\
    \ That Fit into a Machine Word\n\t\t// @param n `0 <= n`\n\t\tconstexpr bool is_prime_constexpr(int\
    \ n) {\n\t\t\tif (n <= 1) return false;\n\t\t\tif (n == 2 || n == 7 || n == 61)\
    \ return true;\n\t\t\tif (n % 2 == 0) return false;\n\t\t\tlong long d = n - 1;\n\
    \t\t\twhile (d % 2 == 0)\n\t\t\t\td /= 2;\n\t\t\tfor (long long a : {2, 7, 61})\
    \ {\n\t\t\t\tlong long t = d;\n\t\t\t\tlong long y = pow_mod_constexpr(a, t, n);\n\
    \t\t\t\twhile (t != n - 1 && y != 1 && y != n - 1) {\n\t\t\t\t\ty = y * y % n;\n\
    \t\t\t\t\tt <<= 1;\n\t\t\t\t}\n\t\t\t\tif (y != n - 1 && t % 2 == 0) {\n\t\t\t\
    \t\treturn false;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn true;\n\t\t}\n\t\ttemplate\
    \ <int n> constexpr bool is_prime = is_prime_constexpr(n);\n\n\t\t// @param b\
    \ `1 <= b`\n\t\t// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <=\
    \ x < b/g\n\t\tconstexpr std::pair<long long, long long> inv_gcd(long long a,\
    \ long long b) {\n\t\t\ta = safe_mod(a, b);\n\t\t\tif (a == 0) return {b, 0};\n\
    \n\t\t\t// Contracts:\n\t\t\t// [1] s - m0 * a = 0 (mod b)\n\t\t\t// [2] t - m1\
    \ * a = 0 (mod b)\n\t\t\t// [3] s * |m1| + t * |m0| <= b\n\t\t\tlong long s =\
    \ b, t = a;\n\t\t\tlong long m0 = 0, m1 = 1;\n\n\t\t\twhile (t) {\n\t\t\t\tlong\
    \ long u = s / t;\n\t\t\t\ts -= t * u;\n\t\t\t\tm0 -= m1 * u;  // |m1 * u| <=\
    \ |m1| * s <= b\n\n\t\t\t\t// [3]:\n\t\t\t\t// (s - t * u) * |m1| + t * |m0 -\
    \ m1 * u|\n\t\t\t\t// <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)\n\t\t\
    \t\t// = s * |m1| + t * |m0| <= b\n\n\t\t\t\tauto tmp = s;\n\t\t\t\ts = t;\n\t\
    \t\t\tt = tmp;\n\t\t\t\ttmp = m0;\n\t\t\t\tm0 = m1;\n\t\t\t\tm1 = tmp;\n\t\t\t\
    }\n\t\t\t// by [3]: |m0| <= b/g\n\t\t\t// by g != b: |m0| < b/g\n\t\t\tif (m0\
    \ < 0) m0 += b / s;\n\t\t\treturn {s, m0};\n\t\t}\n\n\t\t// Compile time primitive\
    \ root\n\t\t// @param m must be prime\n\t\t// @return primitive root (and minimum\
    \ in now)\n\t\tconstexpr int primitive_root_constexpr(int m) {\n\t\t\tif (m ==\
    \ 2) return 1;\n\t\t\tif (m == 167772161) return 3;\n\t\t\tif (m == 469762049)\
    \ return 3;\n\t\t\tif (m == 754974721) return 11;\n\t\t\tif (m == 998244353) return\
    \ 3;\n\t\t\tint divs[20] = {};\n\t\t\tdivs[0] = 2;\n\t\t\tint cnt = 1;\n\t\t\t\
    int x = (m - 1) / 2;\n\t\t\twhile (x % 2 == 0)\n\t\t\t\tx /= 2;\n\t\t\tfor (int\
    \ i = 3; (long long)(i)*i <= x; i += 2) {\n\t\t\t\tif (x % i == 0) {\n\t\t\t\t\
    \tdivs[cnt++] = i;\n\t\t\t\t\twhile (x % i == 0) {\n\t\t\t\t\t\tx /= i;\n\t\t\t\
    \t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (x > 1) {\n\t\t\t\tdivs[cnt++] = x;\n\t\t\t\
    }\n\t\t\tfor (int g = 2;; g++) {\n\t\t\t\tbool ok = true;\n\t\t\t\tfor (int i\
    \ = 0; i < cnt; i++) {\n\t\t\t\t\tif (pow_mod_constexpr(g, (m - 1) / divs[i],\
    \ m) == 1) {\n\t\t\t\t\t\tok = false;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\
    \t}\n\t\t\t\tif (ok) return g;\n\t\t\t}\n\t\t}\n\t\ttemplate <int m> constexpr\
    \ int primitive_root = primitive_root_constexpr(m);\n\n\t}  // namespace internal\n\
    \n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_INTERNAL_MATH_HPP\n#define ATCODER_INTERNAL_MATH_HPP 1\n\n\
    #include <utility>\n\nnamespace atcoder {\n\n\tnamespace internal {\n\n\t\t//\
    \ @param m `1 <= m`\n\t\t// @return x mod m\n\t\tconstexpr long long safe_mod(long\
    \ long x, long long m) {\n\t\t\tx %= m;\n\t\t\tif (x < 0) x += m;\n\t\t\treturn\
    \ x;\n\t\t}\n\n\t\t// Fast moduler by barrett reduction\n\t\t// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n\
    \t\t// NOTE: reconsider after Ice Lake\n\t\tstruct barrett {\n\t\t\tunsigned int\
    \ _m;\n\t\t\tunsigned long long im;\n\n\t\t\t// @param m `1 <= m`\n\t\t\tbarrett(unsigned\
    \ int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}\n\n\t\t\t// @return\
    \ m\n\t\t\tunsigned int umod() const {\n\t\t\t\treturn _m;\n\t\t\t}\n\n\t\t\t\
    // @param a `0 <= a < m`\n\t\t\t// @param b `0 <= b < m`\n\t\t\t// @return `a\
    \ * b % m`\n\t\t\tunsigned int mul(unsigned int a, unsigned int b) const {\n\t\
    \t\t\t// [1] m = 1\n\t\t\t\t// a = b = im = 0, so okay\n\n\t\t\t\t// [2] m >=\
    \ 2\n\t\t\t\t// im = ceil(2^64 / m)\n\t\t\t\t// -> im * m = 2^64 + r (0 <= r <\
    \ m)\n\t\t\t\t// let z = a*b = c*m + d (0 <= c, d < m)\n\t\t\t\t// a*b * im =\
    \ (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r + d*im\n\t\t\t\t// c*r + d*im\
    \ < m * m + m * im < m * m + 2^64 + m <= 2^64 + m * (m + 1) < 2^64 * 2\n\t\t\t\
    \t// ((ab * im) >> 64) == c or c + 1\n\t\t\t\tunsigned long long z = a;\n\t\t\t\
    \tz *= b;\n#ifdef _MSC_VER\n\t\t\t\tunsigned long long x;\n\t\t\t\t_umul128(z,\
    \ im, &x);\n#else\n\t\t\t\tunsigned long long x = (unsigned long long)(((unsigned\
    \ __int128)(z)*im) >> 64);\n#endif\n\t\t\t\tunsigned int v = (unsigned int)(z\
    \ - x * _m);\n\t\t\t\tif (_m <= v) v += _m;\n\t\t\t\treturn v;\n\t\t\t}\n\t\t\
    };\n\n\t\t// @param n `0 <= n`\n\t\t// @param m `1 <= m`\n\t\t// @return `(x **\
    \ n) % m`\n\t\tconstexpr long long pow_mod_constexpr(long long x, long long n,\
    \ int m) {\n\t\t\tif (m == 1) return 0;\n\t\t\tunsigned int _m = (unsigned int)(m);\n\
    \t\t\tunsigned long long r = 1;\n\t\t\tunsigned long long y = safe_mod(x, m);\n\
    \t\t\twhile (n) {\n\t\t\t\tif (n & 1) r = (r * y) % _m;\n\t\t\t\ty = (y * y) %\
    \ _m;\n\t\t\t\tn >>= 1;\n\t\t\t}\n\t\t\treturn r;\n\t\t}\n\n\t\t// Reference:\n\
    \t\t// M. Forisek and J. Jancina,\n\t\t// Fast Primality Testing for Integers\
    \ That Fit into a Machine Word\n\t\t// @param n `0 <= n`\n\t\tconstexpr bool is_prime_constexpr(int\
    \ n) {\n\t\t\tif (n <= 1) return false;\n\t\t\tif (n == 2 || n == 7 || n == 61)\
    \ return true;\n\t\t\tif (n % 2 == 0) return false;\n\t\t\tlong long d = n - 1;\n\
    \t\t\twhile (d % 2 == 0)\n\t\t\t\td /= 2;\n\t\t\tfor (long long a : {2, 7, 61})\
    \ {\n\t\t\t\tlong long t = d;\n\t\t\t\tlong long y = pow_mod_constexpr(a, t, n);\n\
    \t\t\t\twhile (t != n - 1 && y != 1 && y != n - 1) {\n\t\t\t\t\ty = y * y % n;\n\
    \t\t\t\t\tt <<= 1;\n\t\t\t\t}\n\t\t\t\tif (y != n - 1 && t % 2 == 0) {\n\t\t\t\
    \t\treturn false;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn true;\n\t\t}\n\t\ttemplate\
    \ <int n> constexpr bool is_prime = is_prime_constexpr(n);\n\n\t\t// @param b\
    \ `1 <= b`\n\t\t// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <=\
    \ x < b/g\n\t\tconstexpr std::pair<long long, long long> inv_gcd(long long a,\
    \ long long b) {\n\t\t\ta = safe_mod(a, b);\n\t\t\tif (a == 0) return {b, 0};\n\
    \n\t\t\t// Contracts:\n\t\t\t// [1] s - m0 * a = 0 (mod b)\n\t\t\t// [2] t - m1\
    \ * a = 0 (mod b)\n\t\t\t// [3] s * |m1| + t * |m0| <= b\n\t\t\tlong long s =\
    \ b, t = a;\n\t\t\tlong long m0 = 0, m1 = 1;\n\n\t\t\twhile (t) {\n\t\t\t\tlong\
    \ long u = s / t;\n\t\t\t\ts -= t * u;\n\t\t\t\tm0 -= m1 * u;  // |m1 * u| <=\
    \ |m1| * s <= b\n\n\t\t\t\t// [3]:\n\t\t\t\t// (s - t * u) * |m1| + t * |m0 -\
    \ m1 * u|\n\t\t\t\t// <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)\n\t\t\
    \t\t// = s * |m1| + t * |m0| <= b\n\n\t\t\t\tauto tmp = s;\n\t\t\t\ts = t;\n\t\
    \t\t\tt = tmp;\n\t\t\t\ttmp = m0;\n\t\t\t\tm0 = m1;\n\t\t\t\tm1 = tmp;\n\t\t\t\
    }\n\t\t\t// by [3]: |m0| <= b/g\n\t\t\t// by g != b: |m0| < b/g\n\t\t\tif (m0\
    \ < 0) m0 += b / s;\n\t\t\treturn {s, m0};\n\t\t}\n\n\t\t// Compile time primitive\
    \ root\n\t\t// @param m must be prime\n\t\t// @return primitive root (and minimum\
    \ in now)\n\t\tconstexpr int primitive_root_constexpr(int m) {\n\t\t\tif (m ==\
    \ 2) return 1;\n\t\t\tif (m == 167772161) return 3;\n\t\t\tif (m == 469762049)\
    \ return 3;\n\t\t\tif (m == 754974721) return 11;\n\t\t\tif (m == 998244353) return\
    \ 3;\n\t\t\tint divs[20] = {};\n\t\t\tdivs[0] = 2;\n\t\t\tint cnt = 1;\n\t\t\t\
    int x = (m - 1) / 2;\n\t\t\twhile (x % 2 == 0)\n\t\t\t\tx /= 2;\n\t\t\tfor (int\
    \ i = 3; (long long)(i)*i <= x; i += 2) {\n\t\t\t\tif (x % i == 0) {\n\t\t\t\t\
    \tdivs[cnt++] = i;\n\t\t\t\t\twhile (x % i == 0) {\n\t\t\t\t\t\tx /= i;\n\t\t\t\
    \t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (x > 1) {\n\t\t\t\tdivs[cnt++] = x;\n\t\t\t\
    }\n\t\t\tfor (int g = 2;; g++) {\n\t\t\t\tbool ok = true;\n\t\t\t\tfor (int i\
    \ = 0; i < cnt; i++) {\n\t\t\t\t\tif (pow_mod_constexpr(g, (m - 1) / divs[i],\
    \ m) == 1) {\n\t\t\t\t\t\tok = false;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\
    \t}\n\t\t\t\tif (ok) return g;\n\t\t\t}\n\t\t}\n\t\ttemplate <int m> constexpr\
    \ int primitive_root = primitive_root_constexpr(m);\n\n\t}  // namespace internal\n\
    \n}  // namespace atcoder\n\n#endif  // ATCODER_INTERNAL_MATH_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/internal_math.hpp
  requiredBy:
  - atcoder/math.hpp
  - atcoder/modint.hpp
  - atcoder/convolution.hpp
  timestamp: '2020-10-30 19:21:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: atcoder/internal_math.hpp
layout: document
redirect_from:
- /library/atcoder/internal_math.hpp
- /library/atcoder/internal_math.hpp.html
title: atcoder/internal_math.hpp
---
