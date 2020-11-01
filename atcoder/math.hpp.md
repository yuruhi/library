---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/math.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <tuple>\n#include <vector>\n#line 1 \"atcoder/internal_math.hpp\"\
    \n\n\n\n#include <utility>\n\nnamespace atcoder {\n\n\tnamespace internal {\n\n\
    \t\t// @param m `1 <= m`\n\t\t// @return x mod m\n\t\tconstexpr long long safe_mod(long\
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
    \n}  // namespace atcoder\n\n\n#line 9 \"atcoder/math.hpp\"\n\nnamespace atcoder\
    \ {\n\n\tlong long pow_mod(long long x, long long n, int m) {\n\t\tassert(0 <=\
    \ n && 1 <= m);\n\t\tif (m == 1) return 0;\n\t\tinternal::barrett bt((unsigned\
    \ int)(m));\n\t\tunsigned int r = 1, y = (unsigned int)(internal::safe_mod(x,\
    \ m));\n\t\twhile (n) {\n\t\t\tif (n & 1) r = bt.mul(r, y);\n\t\t\ty = bt.mul(y,\
    \ y);\n\t\t\tn >>= 1;\n\t\t}\n\t\treturn r;\n\t}\n\n\tlong long inv_mod(long long\
    \ x, long long m) {\n\t\tassert(1 <= m);\n\t\tauto z = internal::inv_gcd(x, m);\n\
    \t\tassert(z.first == 1);\n\t\treturn z.second;\n\t}\n\n\t// (rem, mod)\n\tstd::pair<long\
    \ long, long long> crt(const std::vector<long long>& r, const std::vector<long\
    \ long>& m) {\n\t\tassert(r.size() == m.size());\n\t\tint n = int(r.size());\n\
    \t\t// Contracts: 0 <= r0 < m0\n\t\tlong long r0 = 0, m0 = 1;\n\t\tfor (int i\
    \ = 0; i < n; i++) {\n\t\t\tassert(1 <= m[i]);\n\t\t\tlong long r1 = internal::safe_mod(r[i],\
    \ m[i]), m1 = m[i];\n\t\t\tif (m0 < m1) {\n\t\t\t\tstd::swap(r0, r1);\n\t\t\t\t\
    std::swap(m0, m1);\n\t\t\t}\n\t\t\tif (m0 % m1 == 0) {\n\t\t\t\tif (r0 % m1 !=\
    \ r1) return {0, 0};\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\t// assume: m0 > m1, lcm(m0,\
    \ m1) >= 2 * max(m0, m1)\n\n\t\t\t// (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0, m1));\n\
    \t\t\t// r2 % m0 = r0\n\t\t\t// r2 % m1 = r1\n\t\t\t// -> (r0 + x*m0) % m1 = r1\n\
    \t\t\t// -> x*u0*g % (u1*g) = (r1 - r0) (u0*g = m0, u1*g = m1)\n\t\t\t// -> x\
    \ = (r1 - r0) / g * inv(u0) (mod u1)\n\n\t\t\t// im = inv(u0) (mod u1) (0 <= im\
    \ < u1)\n\t\t\tlong long g, im;\n\t\t\tstd::tie(g, im) = internal::inv_gcd(m0,\
    \ m1);\n\n\t\t\tlong long u1 = (m1 / g);\n\t\t\t// |r1 - r0| < (m0 + m1) <= lcm(m0,\
    \ m1)\n\t\t\tif ((r1 - r0) % g) return {0, 0};\n\n\t\t\t// u1 * u1 <= m1 * m1\
    \ / g / g <= m0 * m1 / g = lcm(m0, m1)\n\t\t\tlong long x = (r1 - r0) / g % u1\
    \ * im % u1;\n\n\t\t\t// |r0| + |m0 * x|\n\t\t\t// < m0 + m0 * (u1 - 1)\n\t\t\t\
    // = m0 + m0 * m1 / g - m0\n\t\t\t// = lcm(m0, m1)\n\t\t\tr0 += x * m0;\n\t\t\t\
    m0 *= u1;  // -> lcm(m0, m1)\n\t\t\tif (r0 < 0) r0 += m0;\n\t\t}\n\t\treturn {r0,\
    \ m0};\n\t}\n\n\tlong long floor_sum(long long n, long long m, long long a, long\
    \ long b) {\n\t\tlong long ans = 0;\n\t\tif (a >= m) {\n\t\t\tans += (n - 1) *\
    \ n * (a / m) / 2;\n\t\t\ta %= m;\n\t\t}\n\t\tif (b >= m) {\n\t\t\tans += n *\
    \ (b / m);\n\t\t\tb %= m;\n\t\t}\n\n\t\tlong long y_max = (a * n + b) / m, x_max\
    \ = (y_max * m - b);\n\t\tif (y_max == 0) return ans;\n\t\tans += (n - (x_max\
    \ + a - 1) / a) * y_max;\n\t\tans += floor_sum(y_max, a, m, (a - x_max % a) %\
    \ a);\n\t\treturn ans;\n\t}\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_MATH_HPP\n#define ATCODER_MATH_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <tuple>\n#include <vector>\n#include \"./internal_math.hpp\"\
    \n\nnamespace atcoder {\n\n\tlong long pow_mod(long long x, long long n, int m)\
    \ {\n\t\tassert(0 <= n && 1 <= m);\n\t\tif (m == 1) return 0;\n\t\tinternal::barrett\
    \ bt((unsigned int)(m));\n\t\tunsigned int r = 1, y = (unsigned int)(internal::safe_mod(x,\
    \ m));\n\t\twhile (n) {\n\t\t\tif (n & 1) r = bt.mul(r, y);\n\t\t\ty = bt.mul(y,\
    \ y);\n\t\t\tn >>= 1;\n\t\t}\n\t\treturn r;\n\t}\n\n\tlong long inv_mod(long long\
    \ x, long long m) {\n\t\tassert(1 <= m);\n\t\tauto z = internal::inv_gcd(x, m);\n\
    \t\tassert(z.first == 1);\n\t\treturn z.second;\n\t}\n\n\t// (rem, mod)\n\tstd::pair<long\
    \ long, long long> crt(const std::vector<long long>& r, const std::vector<long\
    \ long>& m) {\n\t\tassert(r.size() == m.size());\n\t\tint n = int(r.size());\n\
    \t\t// Contracts: 0 <= r0 < m0\n\t\tlong long r0 = 0, m0 = 1;\n\t\tfor (int i\
    \ = 0; i < n; i++) {\n\t\t\tassert(1 <= m[i]);\n\t\t\tlong long r1 = internal::safe_mod(r[i],\
    \ m[i]), m1 = m[i];\n\t\t\tif (m0 < m1) {\n\t\t\t\tstd::swap(r0, r1);\n\t\t\t\t\
    std::swap(m0, m1);\n\t\t\t}\n\t\t\tif (m0 % m1 == 0) {\n\t\t\t\tif (r0 % m1 !=\
    \ r1) return {0, 0};\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\t// assume: m0 > m1, lcm(m0,\
    \ m1) >= 2 * max(m0, m1)\n\n\t\t\t// (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0, m1));\n\
    \t\t\t// r2 % m0 = r0\n\t\t\t// r2 % m1 = r1\n\t\t\t// -> (r0 + x*m0) % m1 = r1\n\
    \t\t\t// -> x*u0*g % (u1*g) = (r1 - r0) (u0*g = m0, u1*g = m1)\n\t\t\t// -> x\
    \ = (r1 - r0) / g * inv(u0) (mod u1)\n\n\t\t\t// im = inv(u0) (mod u1) (0 <= im\
    \ < u1)\n\t\t\tlong long g, im;\n\t\t\tstd::tie(g, im) = internal::inv_gcd(m0,\
    \ m1);\n\n\t\t\tlong long u1 = (m1 / g);\n\t\t\t// |r1 - r0| < (m0 + m1) <= lcm(m0,\
    \ m1)\n\t\t\tif ((r1 - r0) % g) return {0, 0};\n\n\t\t\t// u1 * u1 <= m1 * m1\
    \ / g / g <= m0 * m1 / g = lcm(m0, m1)\n\t\t\tlong long x = (r1 - r0) / g % u1\
    \ * im % u1;\n\n\t\t\t// |r0| + |m0 * x|\n\t\t\t// < m0 + m0 * (u1 - 1)\n\t\t\t\
    // = m0 + m0 * m1 / g - m0\n\t\t\t// = lcm(m0, m1)\n\t\t\tr0 += x * m0;\n\t\t\t\
    m0 *= u1;  // -> lcm(m0, m1)\n\t\t\tif (r0 < 0) r0 += m0;\n\t\t}\n\t\treturn {r0,\
    \ m0};\n\t}\n\n\tlong long floor_sum(long long n, long long m, long long a, long\
    \ long b) {\n\t\tlong long ans = 0;\n\t\tif (a >= m) {\n\t\t\tans += (n - 1) *\
    \ n * (a / m) / 2;\n\t\t\ta %= m;\n\t\t}\n\t\tif (b >= m) {\n\t\t\tans += n *\
    \ (b / m);\n\t\t\tb %= m;\n\t\t}\n\n\t\tlong long y_max = (a * n + b) / m, x_max\
    \ = (y_max * m - b);\n\t\tif (y_max == 0) return ans;\n\t\tans += (n - (x_max\
    \ + a - 1) / a) * y_max;\n\t\tans += floor_sum(y_max, a, m, (a - x_max % a) %\
    \ a);\n\t\treturn ans;\n\t}\n\n}  // namespace atcoder\n\n#endif  // ATCODER_MATH_HPP\n"
  dependsOn:
  - atcoder/internal_math.hpp
  isVerificationFile: false
  path: atcoder/math.hpp
  requiredBy: []
  timestamp: '2020-10-30 19:21:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: atcoder/math.hpp
layout: document
redirect_from:
- /library/atcoder/math.hpp
- /library/atcoder/math.hpp.html
title: atcoder/math.hpp
---
