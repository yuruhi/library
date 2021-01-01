---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':warning:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':warning:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':warning:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/convolution.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <array>\n#line 1 \"atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n\
    #include <intrin.h>\n#endif\n\nnamespace atcoder {\n\n\tnamespace internal {\n\
    \n\t\t// @param n `0 <= n`\n\t\t// @return minimum non-negative `x` s.t. `n <=\
    \ 2**x`\n\t\tint ceil_pow2(int n) {\n\t\t\tint x = 0;\n\t\t\twhile ((1U << x)\
    \ < (unsigned int)(n))\n\t\t\t\tx++;\n\t\t\treturn x;\n\t\t}\n\n\t\t// @param\
    \ n `1 <= n`\n\t\t// @return minimum non-negative `x` s.t. `(n & (1 << x)) !=\
    \ 0`\n\t\tint bsf(unsigned int n) {\n#ifdef _MSC_VER\n\t\t\tunsigned long index;\n\
    \t\t\t_BitScanForward(&index, n);\n\t\t\treturn index;\n#else\n\t\t\treturn __builtin_ctz(n);\n\
    #endif\n\t\t}\n\n\t}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line\
    \ 1 \"atcoder/modint.hpp\"\n\n\n\n#line 1 \"atcoder/internal_math.hpp\"\n\n\n\n\
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
    \n}  // namespace atcoder\n\n\n#line 1 \"atcoder/internal_type_traits.hpp\"\n\n\
    \n\n#include <cassert>\n#include <numeric>\n#include <type_traits>\n\nnamespace\
    \ atcoder {\n\n\tnamespace internal {\n\n#ifndef _MSC_VER\n\t\ttemplate <class\
    \ T>\n\t\tusing is_signed_int128 =\n\t\t    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value || std::is_same<T, __int128>::value,\n\t\t              \
    \                std::true_type, std::false_type>::type;\n\n\t\ttemplate <class\
    \ T>\n\t\tusing is_unsigned_int128 =\n\t\t    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value || std::is_same<T, unsigned __int128>::value,\n\t\t    \
    \                          std::true_type, std::false_type>::type;\n\n\t\ttemplate\
    \ <class T>\n\t\tusing make_unsigned_int128 =\n\t\t    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value, __uint128_t, unsigned __int128>;\n\n\t\ttemplate <class\
    \ T>\n\t\tusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ || is_signed_int128<T>::value ||\n\t\t                                     \
    \             is_unsigned_int128<T>::value,\n\t\t                            \
    \                  std::true_type, std::false_type>::type;\n\n\t\ttemplate <class\
    \ T>\n\t\tusing is_signed_int =\n\t\t    typename std::conditional<(is_integral<T>::value\
    \ && std::is_signed<T>::value) || is_signed_int128<T>::value,\n\t\t          \
    \                    std::true_type, std::false_type>::type;\n\n\t\ttemplate <class\
    \ T>\n\t\tusing is_unsigned_int = typename std::conditional<(is_integral<T>::value\
    \ && std::is_unsigned<T>::value) ||\n\t\t                                    \
    \                  is_unsigned_int128<T>::value,\n\t\t                       \
    \                           std::true_type, std::false_type>::type;\n\n\t\ttemplate\
    \ <class T>\n\t\tusing to_unsigned =\n\t\t    typename std::conditional<is_signed_int128<T>::value,\
    \ make_unsigned_int128<T>,\n\t\t                              typename std::conditional<std::is_signed<T>::value,\
    \ std::make_unsigned<T>,\n\t\t                                               \
    \         std::common_type<T>>::type>::type;\n\n#else\n\n\t\ttemplate <class T>\
    \ using is_integral = typename std::is_integral<T>;\n\n\t\ttemplate <class T>\n\
    \t\tusing is_signed_int = typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \t\t                                                std::true_type, std::false_type>::type;\n\
    \n\t\ttemplate <class T>\n\t\tusing is_unsigned_int = typename std::conditional<is_integral<T>::value\
    \ && std::is_unsigned<T>::value,\n\t\t                                       \
    \           std::true_type, std::false_type>::type;\n\n\t\ttemplate <class T>\n\
    \t\tusing to_unsigned =\n\t\t    typename std::conditional<is_signed_int<T>::value,\
    \ std::make_unsigned<T>, std::common_type<T>>::type;\n\n#endif\n\n\t\ttemplate\
    \ <class T> using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \n\t\ttemplate <class T> using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \n\t\ttemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\
    \n\t}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 9 \"atcoder/modint.hpp\"\
    \n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\n\t\
    namespace internal {\n\n\t\tstruct modint_base {};\n\t\tstruct static_modint_base\
    \ : modint_base {};\n\n\t\ttemplate <class T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\n\t\ttemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n\t}  // namespace internal\n\n\ttemplate <int m, std::enable_if_t<(1 <= m)>*\
    \ = nullptr> struct static_modint : internal::static_modint_base {\n\t\tusing\
    \ mint = static_modint;\n\n\tpublic:\n\t\tstatic constexpr int mod() {\n\t\t\t\
    return m;\n\t\t}\n\t\tstatic mint raw(int v) {\n\t\t\tmint x;\n\t\t\tx._v = v;\n\
    \t\t\treturn x;\n\t\t}\n\n\t\tstatic_modint() : _v(0) {}\n\t\ttemplate <class\
    \ T, internal::is_signed_int_t<T>* = nullptr> static_modint(T v) {\n\t\t\tlong\
    \ long x = (long long)(v % (long long)(umod()));\n\t\t\tif (x < 0) x += umod();\n\
    \t\t\t_v = (unsigned int)(x);\n\t\t}\n\t\ttemplate <class T, internal::is_unsigned_int_t<T>*\
    \ = nullptr> static_modint(T v) {\n\t\t\t_v = (unsigned int)(v % umod());\n\t\t\
    }\n\t\tstatic_modint(bool v) {\n\t\t\t_v = ((unsigned int)(v) % umod());\n\t\t\
    }\n\n\t\tunsigned int val() const {\n\t\t\treturn _v;\n\t\t}\n\n\t\tmint& operator++()\
    \ {\n\t\t\t_v++;\n\t\t\tif (_v == umod()) _v = 0;\n\t\t\treturn *this;\n\t\t}\n\
    \t\tmint& operator--() {\n\t\t\tif (_v == 0) _v = umod();\n\t\t\t_v--;\n\t\t\t\
    return *this;\n\t\t}\n\t\tmint operator++(int) {\n\t\t\tmint result = *this;\n\
    \t\t\t++*this;\n\t\t\treturn result;\n\t\t}\n\t\tmint operator--(int) {\n\t\t\t\
    mint result = *this;\n\t\t\t--*this;\n\t\t\treturn result;\n\t\t}\n\n\t\tmint&\
    \ operator+=(const mint& rhs) {\n\t\t\t_v += rhs._v;\n\t\t\tif (_v >= umod())\
    \ _v -= umod();\n\t\t\treturn *this;\n\t\t}\n\t\tmint& operator-=(const mint&\
    \ rhs) {\n\t\t\t_v -= rhs._v;\n\t\t\tif (_v >= umod()) _v += umod();\n\t\t\treturn\
    \ *this;\n\t\t}\n\t\tmint& operator*=(const mint& rhs) {\n\t\t\tunsigned long\
    \ long z = _v;\n\t\t\tz *= rhs._v;\n\t\t\t_v = (unsigned int)(z % umod());\n\t\
    \t\treturn *this;\n\t\t}\n\t\tmint& operator/=(const mint& rhs) {\n\t\t\treturn\
    \ *this = *this * rhs.inv();\n\t\t}\n\n\t\tmint operator+() const {\n\t\t\treturn\
    \ *this;\n\t\t}\n\t\tmint operator-() const {\n\t\t\treturn mint() - *this;\n\t\
    \t}\n\n\t\tmint pow(long long n) const {\n\t\t\tassert(0 <= n);\n\t\t\tmint x\
    \ = *this, r = 1;\n\t\t\twhile (n) {\n\t\t\t\tif (n & 1) r *= x;\n\t\t\t\tx *=\
    \ x;\n\t\t\t\tn >>= 1;\n\t\t\t}\n\t\t\treturn r;\n\t\t}\n\t\tmint inv() const\
    \ {\n\t\t\tif (prime) {\n\t\t\t\tassert(_v);\n\t\t\t\treturn pow(umod() - 2);\n\
    \t\t\t} else {\n\t\t\t\tauto eg = internal::inv_gcd(_v, m);\n\t\t\t\tassert(eg.first\
    \ == 1);\n\t\t\t\treturn eg.second;\n\t\t\t}\n\t\t}\n\n\t\tfriend mint operator+(const\
    \ mint& lhs, const mint& rhs) {\n\t\t\treturn mint(lhs) += rhs;\n\t\t}\n\t\tfriend\
    \ mint operator-(const mint& lhs, const mint& rhs) {\n\t\t\treturn mint(lhs) -=\
    \ rhs;\n\t\t}\n\t\tfriend mint operator*(const mint& lhs, const mint& rhs) {\n\
    \t\t\treturn mint(lhs) *= rhs;\n\t\t}\n\t\tfriend mint operator/(const mint& lhs,\
    \ const mint& rhs) {\n\t\t\treturn mint(lhs) /= rhs;\n\t\t}\n\t\tfriend bool operator==(const\
    \ mint& lhs, const mint& rhs) {\n\t\t\treturn lhs._v == rhs._v;\n\t\t}\n\t\tfriend\
    \ bool operator!=(const mint& lhs, const mint& rhs) {\n\t\t\treturn lhs._v !=\
    \ rhs._v;\n\t\t}\n\n\tprivate:\n\t\tunsigned int _v;\n\t\tstatic constexpr unsigned\
    \ int umod() {\n\t\t\treturn m;\n\t\t}\n\t\tstatic constexpr bool prime = internal::is_prime<m>;\n\
    \t};\n\n\ttemplate <int id> struct dynamic_modint : internal::modint_base {\n\t\
    \tusing mint = dynamic_modint;\n\n\tpublic:\n\t\tstatic int mod() {\n\t\t\treturn\
    \ (int)(bt.umod());\n\t\t}\n\t\tstatic void set_mod(int m) {\n\t\t\tassert(1 <=\
    \ m);\n\t\t\tbt = internal::barrett(m);\n\t\t}\n\t\tstatic mint raw(int v) {\n\
    \t\t\tmint x;\n\t\t\tx._v = v;\n\t\t\treturn x;\n\t\t}\n\n\t\tdynamic_modint()\
    \ : _v(0) {}\n\t\ttemplate <class T, internal::is_signed_int_t<T>* = nullptr>\
    \ dynamic_modint(T v) {\n\t\t\tlong long x = (long long)(v % (long long)(mod()));\n\
    \t\t\tif (x < 0) x += mod();\n\t\t\t_v = (unsigned int)(x);\n\t\t}\n\t\ttemplate\
    \ <class T, internal::is_unsigned_int_t<T>* = nullptr> dynamic_modint(T v) {\n\
    \t\t\t_v = (unsigned int)(v % mod());\n\t\t}\n\t\tdynamic_modint(bool v) {\n\t\
    \t\t_v = ((unsigned int)(v) % mod());\n\t\t}\n\n\t\tunsigned int val() const {\n\
    \t\t\treturn _v;\n\t\t}\n\n\t\tmint& operator++() {\n\t\t\t_v++;\n\t\t\tif (_v\
    \ == umod()) _v = 0;\n\t\t\treturn *this;\n\t\t}\n\t\tmint& operator--() {\n\t\
    \t\tif (_v == 0) _v = umod();\n\t\t\t_v--;\n\t\t\treturn *this;\n\t\t}\n\t\tmint\
    \ operator++(int) {\n\t\t\tmint result = *this;\n\t\t\t++*this;\n\t\t\treturn\
    \ result;\n\t\t}\n\t\tmint operator--(int) {\n\t\t\tmint result = *this;\n\t\t\
    \t--*this;\n\t\t\treturn result;\n\t\t}\n\n\t\tmint& operator+=(const mint& rhs)\
    \ {\n\t\t\t_v += rhs._v;\n\t\t\tif (_v >= umod()) _v -= umod();\n\t\t\treturn\
    \ *this;\n\t\t}\n\t\tmint& operator-=(const mint& rhs) {\n\t\t\t_v += mod() -\
    \ rhs._v;\n\t\t\tif (_v >= umod()) _v -= umod();\n\t\t\treturn *this;\n\t\t}\n\
    \t\tmint& operator*=(const mint& rhs) {\n\t\t\t_v = bt.mul(_v, rhs._v);\n\t\t\t\
    return *this;\n\t\t}\n\t\tmint& operator/=(const mint& rhs) {\n\t\t\treturn *this\
    \ = *this * rhs.inv();\n\t\t}\n\n\t\tmint operator+() const {\n\t\t\treturn *this;\n\
    \t\t}\n\t\tmint operator-() const {\n\t\t\treturn mint() - *this;\n\t\t}\n\n\t\
    \tmint pow(long long n) const {\n\t\t\tassert(0 <= n);\n\t\t\tmint x = *this,\
    \ r = 1;\n\t\t\twhile (n) {\n\t\t\t\tif (n & 1) r *= x;\n\t\t\t\tx *= x;\n\t\t\
    \t\tn >>= 1;\n\t\t\t}\n\t\t\treturn r;\n\t\t}\n\t\tmint inv() const {\n\t\t\t\
    auto eg = internal::inv_gcd(_v, mod());\n\t\t\tassert(eg.first == 1);\n\t\t\t\
    return eg.second;\n\t\t}\n\n\t\tfriend mint operator+(const mint& lhs, const mint&\
    \ rhs) {\n\t\t\treturn mint(lhs) += rhs;\n\t\t}\n\t\tfriend mint operator-(const\
    \ mint& lhs, const mint& rhs) {\n\t\t\treturn mint(lhs) -= rhs;\n\t\t}\n\t\tfriend\
    \ mint operator*(const mint& lhs, const mint& rhs) {\n\t\t\treturn mint(lhs) *=\
    \ rhs;\n\t\t}\n\t\tfriend mint operator/(const mint& lhs, const mint& rhs) {\n\
    \t\t\treturn mint(lhs) /= rhs;\n\t\t}\n\t\tfriend bool operator==(const mint&\
    \ lhs, const mint& rhs) {\n\t\t\treturn lhs._v == rhs._v;\n\t\t}\n\t\tfriend bool\
    \ operator!=(const mint& lhs, const mint& rhs) {\n\t\t\treturn lhs._v != rhs._v;\n\
    \t\t}\n\n\tprivate:\n\t\tunsigned int _v;\n\t\tstatic internal::barrett bt;\n\t\
    \tstatic unsigned int umod() {\n\t\t\treturn bt.umod();\n\t\t}\n\t};\n\ttemplate\
    \ <int id> internal::barrett dynamic_modint<id>::bt = 998244353;\n\n\tusing modint998244353\
    \ = static_modint<998244353>;\n\tusing modint1000000007 = static_modint<1000000007>;\n\
    \tusing modint = dynamic_modint<-1>;\n\n\tnamespace internal {\n\n\t\ttemplate\
    \ <class T> using is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\n\t\ttemplate <class T> using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \n\t\ttemplate <class> struct is_dynamic_modint : public std::false_type {};\n\
    \t\ttemplate <int id> struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type\
    \ {};\n\n\t\ttemplate <class T> using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;\n\
    \n\t}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 10 \"atcoder/convolution.hpp\"\
    \n#include <vector>\n\nnamespace atcoder {\n\n\tnamespace internal {\n\n\t\ttemplate\
    \ <class mint, internal::is_static_modint_t<mint>* = nullptr> void butterfly(std::vector<mint>&\
    \ a) {\n\t\t\tstatic constexpr int g = internal::primitive_root<mint::mod()>;\n\
    \t\t\tint n = int(a.size());\n\t\t\tint h = internal::ceil_pow2(n);\n\n\t\t\t\
    static bool first = true;\n\t\t\tstatic mint sum_e[30];  // sum_e[i] = ies[0]\
    \ * ... * ies[i - 1] * es[i]\n\t\t\tif (first) {\n\t\t\t\tfirst = false;\n\t\t\
    \t\tmint es[30], ies[30];  // es[i]^(2^(2+i)) == 1\n\t\t\t\tint cnt2 = bsf(mint::mod()\
    \ - 1);\n\t\t\t\tmint e = mint(g).pow((mint::mod() - 1) >> cnt2), ie = e.inv();\n\
    \t\t\t\tfor (int i = cnt2; i >= 2; i--) {\n\t\t\t\t\t// e^(2^i) == 1\n\t\t\t\t\
    \tes[i - 2] = e;\n\t\t\t\t\ties[i - 2] = ie;\n\t\t\t\t\te *= e;\n\t\t\t\t\tie\
    \ *= ie;\n\t\t\t\t}\n\t\t\t\tmint now = 1;\n\t\t\t\tfor (int i = 0; i < cnt2 -\
    \ 2; i++) {\n\t\t\t\t\tsum_e[i] = es[i] * now;\n\t\t\t\t\tnow *= ies[i];\n\t\t\
    \t\t}\n\t\t\t}\n\t\t\tfor (int ph = 1; ph <= h; ph++) {\n\t\t\t\tint w = 1 <<\
    \ (ph - 1), p = 1 << (h - ph);\n\t\t\t\tmint now = 1;\n\t\t\t\tfor (int s = 0;\
    \ s < w; s++) {\n\t\t\t\t\tint offset = s << (h - ph + 1);\n\t\t\t\t\tfor (int\
    \ i = 0; i < p; i++) {\n\t\t\t\t\t\tauto l = a[i + offset];\n\t\t\t\t\t\tauto\
    \ r = a[i + offset + p] * now;\n\t\t\t\t\t\ta[i + offset] = l + r;\n\t\t\t\t\t\
    \ta[i + offset + p] = l - r;\n\t\t\t\t\t}\n\t\t\t\t\tnow *= sum_e[bsf(~(unsigned\
    \ int)(s))];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\ttemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr> void butterfly_inv(std::vector<mint>& a) {\n\t\t\tstatic constexpr\
    \ int g = internal::primitive_root<mint::mod()>;\n\t\t\tint n = int(a.size());\n\
    \t\t\tint h = internal::ceil_pow2(n);\n\n\t\t\tstatic bool first = true;\n\t\t\
    \tstatic mint sum_ie[30];  // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]\n\t\
    \t\tif (first) {\n\t\t\t\tfirst = false;\n\t\t\t\tmint es[30], ies[30];  // es[i]^(2^(2+i))\
    \ == 1\n\t\t\t\tint cnt2 = bsf(mint::mod() - 1);\n\t\t\t\tmint e = mint(g).pow((mint::mod()\
    \ - 1) >> cnt2), ie = e.inv();\n\t\t\t\tfor (int i = cnt2; i >= 2; i--) {\n\t\t\
    \t\t\t// e^(2^i) == 1\n\t\t\t\t\tes[i - 2] = e;\n\t\t\t\t\ties[i - 2] = ie;\n\t\
    \t\t\t\te *= e;\n\t\t\t\t\tie *= ie;\n\t\t\t\t}\n\t\t\t\tmint now = 1;\n\t\t\t\
    \tfor (int i = 0; i < cnt2 - 2; i++) {\n\t\t\t\t\tsum_ie[i] = ies[i] * now;\n\t\
    \t\t\t\tnow *= es[i];\n\t\t\t\t}\n\t\t\t}\n\n\t\t\tfor (int ph = h; ph >= 1; ph--)\
    \ {\n\t\t\t\tint w = 1 << (ph - 1), p = 1 << (h - ph);\n\t\t\t\tmint inow = 1;\n\
    \t\t\t\tfor (int s = 0; s < w; s++) {\n\t\t\t\t\tint offset = s << (h - ph + 1);\n\
    \t\t\t\t\tfor (int i = 0; i < p; i++) {\n\t\t\t\t\t\tauto l = a[i + offset];\n\
    \t\t\t\t\t\tauto r = a[i + offset + p];\n\t\t\t\t\t\ta[i + offset] = l + r;\n\t\
    \t\t\t\t\ta[i + offset + p] = (unsigned long long)(mint::mod() + l.val() - r.val())\
    \ * inow.val();\n\t\t\t\t\t}\n\t\t\t\t\tinow *= sum_ie[bsf(~(unsigned int)(s))];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t}  // namespace internal\n\n\ttemplate <class mint,\
    \ internal::is_static_modint_t<mint>* = nullptr>\n\tstd::vector<mint> convolution(std::vector<mint>\
    \ a, std::vector<mint> b) {\n\t\tint n = int(a.size()), m = int(b.size());\n\t\
    \tif (!n || !m) return {};\n\t\tif (std::min(n, m) <= 60) {\n\t\t\tif (n < m)\
    \ {\n\t\t\t\tstd::swap(n, m);\n\t\t\t\tstd::swap(a, b);\n\t\t\t}\n\t\t\tstd::vector<mint>\
    \ ans(n + m - 1);\n\t\t\tfor (int i = 0; i < n; i++) {\n\t\t\t\tfor (int j = 0;\
    \ j < m; j++) {\n\t\t\t\t\tans[i + j] += a[i] * b[j];\n\t\t\t\t}\n\t\t\t}\n\t\t\
    \treturn ans;\n\t\t}\n\t\tint z = 1 << internal::ceil_pow2(n + m - 1);\n\t\ta.resize(z);\n\
    \t\tinternal::butterfly(a);\n\t\tb.resize(z);\n\t\tinternal::butterfly(b);\n\t\
    \tfor (int i = 0; i < z; i++) {\n\t\t\ta[i] *= b[i];\n\t\t}\n\t\tinternal::butterfly_inv(a);\n\
    \t\ta.resize(n + m - 1);\n\t\tmint iz = mint(z).inv();\n\t\tfor (int i = 0; i\
    \ < n + m - 1; i++)\n\t\t\ta[i] *= iz;\n\t\treturn a;\n\t}\n\n\ttemplate <unsigned\
    \ int mod = 998244353, class T, std::enable_if_t<internal::is_integral<T>::value>*\
    \ = nullptr>\n\tstd::vector<T> convolution(const std::vector<T>& a, const std::vector<T>&\
    \ b) {\n\t\tint n = int(a.size()), m = int(b.size());\n\t\tif (!n || !m) return\
    \ {};\n\n\t\tusing mint = static_modint<mod>;\n\t\tstd::vector<mint> a2(n), b2(m);\n\
    \t\tfor (int i = 0; i < n; i++) {\n\t\t\ta2[i] = mint(a[i]);\n\t\t}\n\t\tfor (int\
    \ i = 0; i < m; i++) {\n\t\t\tb2[i] = mint(b[i]);\n\t\t}\n\t\tauto c2 = convolution(move(a2),\
    \ move(b2));\n\t\tstd::vector<T> c(n + m - 1);\n\t\tfor (int i = 0; i < n + m\
    \ - 1; i++) {\n\t\t\tc[i] = c2[i].val();\n\t\t}\n\t\treturn c;\n\t}\n\n\tstd::vector<long\
    \ long> convolution_ll(const std::vector<long long>& a, const std::vector<long\
    \ long>& b) {\n\t\tint n = int(a.size()), m = int(b.size());\n\t\tif (!n || !m)\
    \ return {};\n\n\t\tstatic constexpr unsigned long long MOD1 = 754974721;  //\
    \ 2^24\n\t\tstatic constexpr unsigned long long MOD2 = 167772161;  // 2^25\n\t\
    \tstatic constexpr unsigned long long MOD3 = 469762049;  // 2^26\n\t\tstatic constexpr\
    \ unsigned long long M2M3 = MOD2 * MOD3;\n\t\tstatic constexpr unsigned long long\
    \ M1M3 = MOD1 * MOD3;\n\t\tstatic constexpr unsigned long long M1M2 = MOD1 * MOD2;\n\
    \t\tstatic constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;\n\n\t\tstatic\
    \ constexpr unsigned long long i1 = internal::inv_gcd(MOD2 * MOD3, MOD1).second;\n\
    \t\tstatic constexpr unsigned long long i2 = internal::inv_gcd(MOD1 * MOD3, MOD2).second;\n\
    \t\tstatic constexpr unsigned long long i3 = internal::inv_gcd(MOD1 * MOD2, MOD3).second;\n\
    \n\t\tauto c1 = convolution<MOD1>(a, b);\n\t\tauto c2 = convolution<MOD2>(a, b);\n\
    \t\tauto c3 = convolution<MOD3>(a, b);\n\n\t\tstd::vector<long long> c(n + m -\
    \ 1);\n\t\tfor (int i = 0; i < n + m - 1; i++) {\n\t\t\tunsigned long long x =\
    \ 0;\n\t\t\tx += (c1[i] * i1) % MOD1 * M2M3;\n\t\t\tx += (c2[i] * i2) % MOD2 *\
    \ M1M3;\n\t\t\tx += (c3[i] * i3) % MOD3 * M1M2;\n\t\t\t// B = 2^63, -B <= x, r(real\
    \ value) < B\n\t\t\t// (x, x - M, x - 2M, or x - 3M) = r (mod 2B)\n\t\t\t// r\
    \ = c1[i] (mod MOD1)\n\t\t\t// focus on MOD1\n\t\t\t// r = x, x - M', x - 2M',\
    \ x - 3M' (M' = M % 2^64) (mod 2B)\n\t\t\t// r = x,\n\t\t\t//     x - M' + (0\
    \ or 2B),\n\t\t\t//     x - 2M' + (0, 2B or 4B),\n\t\t\t//     x - 3M' + (0, 2B,\
    \ 4B or 6B) (without mod!)\n\t\t\t// (r - x) = 0, (0)\n\t\t\t//           - M'\
    \ + (0 or 2B), (1)\n\t\t\t//           -2M' + (0 or 2B or 4B), (2)\n\t\t\t// \
    \          -3M' + (0 or 2B or 4B or 6B) (3) (mod MOD1)\n\t\t\t// we checked that\n\
    \t\t\t//   ((1) mod MOD1) mod 5 = 2\n\t\t\t//   ((2) mod MOD1) mod 5 = 3\n\t\t\
    \t//   ((3) mod MOD1) mod 5 = 4\n\t\t\tlong long diff = c1[i] - internal::safe_mod((long\
    \ long)(x), (long long)(MOD1));\n\t\t\tif (diff < 0) diff += MOD1;\n\t\t\tstatic\
    \ constexpr unsigned long long offset[5] = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\n\
    \t\t\tx -= offset[diff % 5];\n\t\t\tc[i] = x;\n\t\t}\n\n\t\treturn c;\n\t}\n\n\
    }  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_CONVOLUTION_HPP\n#define ATCODER_CONVOLUTION_HPP 1\n\n#include\
    \ <algorithm>\n#include <array>\n#include \"./internal_bit.hpp\"\n#include \"\
    ./modint.hpp\"\n#include <cassert>\n#include <type_traits>\n#include <vector>\n\
    \nnamespace atcoder {\n\n\tnamespace internal {\n\n\t\ttemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr> void butterfly(std::vector<mint>& a) {\n\t\t\tstatic constexpr int\
    \ g = internal::primitive_root<mint::mod()>;\n\t\t\tint n = int(a.size());\n\t\
    \t\tint h = internal::ceil_pow2(n);\n\n\t\t\tstatic bool first = true;\n\t\t\t\
    static mint sum_e[30];  // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]\n\t\t\t\
    if (first) {\n\t\t\t\tfirst = false;\n\t\t\t\tmint es[30], ies[30];  // es[i]^(2^(2+i))\
    \ == 1\n\t\t\t\tint cnt2 = bsf(mint::mod() - 1);\n\t\t\t\tmint e = mint(g).pow((mint::mod()\
    \ - 1) >> cnt2), ie = e.inv();\n\t\t\t\tfor (int i = cnt2; i >= 2; i--) {\n\t\t\
    \t\t\t// e^(2^i) == 1\n\t\t\t\t\tes[i - 2] = e;\n\t\t\t\t\ties[i - 2] = ie;\n\t\
    \t\t\t\te *= e;\n\t\t\t\t\tie *= ie;\n\t\t\t\t}\n\t\t\t\tmint now = 1;\n\t\t\t\
    \tfor (int i = 0; i < cnt2 - 2; i++) {\n\t\t\t\t\tsum_e[i] = es[i] * now;\n\t\t\
    \t\t\tnow *= ies[i];\n\t\t\t\t}\n\t\t\t}\n\t\t\tfor (int ph = 1; ph <= h; ph++)\
    \ {\n\t\t\t\tint w = 1 << (ph - 1), p = 1 << (h - ph);\n\t\t\t\tmint now = 1;\n\
    \t\t\t\tfor (int s = 0; s < w; s++) {\n\t\t\t\t\tint offset = s << (h - ph + 1);\n\
    \t\t\t\t\tfor (int i = 0; i < p; i++) {\n\t\t\t\t\t\tauto l = a[i + offset];\n\
    \t\t\t\t\t\tauto r = a[i + offset + p] * now;\n\t\t\t\t\t\ta[i + offset] = l +\
    \ r;\n\t\t\t\t\t\ta[i + offset + p] = l - r;\n\t\t\t\t\t}\n\t\t\t\t\tnow *= sum_e[bsf(~(unsigned\
    \ int)(s))];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\ttemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr> void butterfly_inv(std::vector<mint>& a) {\n\t\t\tstatic constexpr\
    \ int g = internal::primitive_root<mint::mod()>;\n\t\t\tint n = int(a.size());\n\
    \t\t\tint h = internal::ceil_pow2(n);\n\n\t\t\tstatic bool first = true;\n\t\t\
    \tstatic mint sum_ie[30];  // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]\n\t\
    \t\tif (first) {\n\t\t\t\tfirst = false;\n\t\t\t\tmint es[30], ies[30];  // es[i]^(2^(2+i))\
    \ == 1\n\t\t\t\tint cnt2 = bsf(mint::mod() - 1);\n\t\t\t\tmint e = mint(g).pow((mint::mod()\
    \ - 1) >> cnt2), ie = e.inv();\n\t\t\t\tfor (int i = cnt2; i >= 2; i--) {\n\t\t\
    \t\t\t// e^(2^i) == 1\n\t\t\t\t\tes[i - 2] = e;\n\t\t\t\t\ties[i - 2] = ie;\n\t\
    \t\t\t\te *= e;\n\t\t\t\t\tie *= ie;\n\t\t\t\t}\n\t\t\t\tmint now = 1;\n\t\t\t\
    \tfor (int i = 0; i < cnt2 - 2; i++) {\n\t\t\t\t\tsum_ie[i] = ies[i] * now;\n\t\
    \t\t\t\tnow *= es[i];\n\t\t\t\t}\n\t\t\t}\n\n\t\t\tfor (int ph = h; ph >= 1; ph--)\
    \ {\n\t\t\t\tint w = 1 << (ph - 1), p = 1 << (h - ph);\n\t\t\t\tmint inow = 1;\n\
    \t\t\t\tfor (int s = 0; s < w; s++) {\n\t\t\t\t\tint offset = s << (h - ph + 1);\n\
    \t\t\t\t\tfor (int i = 0; i < p; i++) {\n\t\t\t\t\t\tauto l = a[i + offset];\n\
    \t\t\t\t\t\tauto r = a[i + offset + p];\n\t\t\t\t\t\ta[i + offset] = l + r;\n\t\
    \t\t\t\t\ta[i + offset + p] = (unsigned long long)(mint::mod() + l.val() - r.val())\
    \ * inow.val();\n\t\t\t\t\t}\n\t\t\t\t\tinow *= sum_ie[bsf(~(unsigned int)(s))];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t}  // namespace internal\n\n\ttemplate <class mint,\
    \ internal::is_static_modint_t<mint>* = nullptr>\n\tstd::vector<mint> convolution(std::vector<mint>\
    \ a, std::vector<mint> b) {\n\t\tint n = int(a.size()), m = int(b.size());\n\t\
    \tif (!n || !m) return {};\n\t\tif (std::min(n, m) <= 60) {\n\t\t\tif (n < m)\
    \ {\n\t\t\t\tstd::swap(n, m);\n\t\t\t\tstd::swap(a, b);\n\t\t\t}\n\t\t\tstd::vector<mint>\
    \ ans(n + m - 1);\n\t\t\tfor (int i = 0; i < n; i++) {\n\t\t\t\tfor (int j = 0;\
    \ j < m; j++) {\n\t\t\t\t\tans[i + j] += a[i] * b[j];\n\t\t\t\t}\n\t\t\t}\n\t\t\
    \treturn ans;\n\t\t}\n\t\tint z = 1 << internal::ceil_pow2(n + m - 1);\n\t\ta.resize(z);\n\
    \t\tinternal::butterfly(a);\n\t\tb.resize(z);\n\t\tinternal::butterfly(b);\n\t\
    \tfor (int i = 0; i < z; i++) {\n\t\t\ta[i] *= b[i];\n\t\t}\n\t\tinternal::butterfly_inv(a);\n\
    \t\ta.resize(n + m - 1);\n\t\tmint iz = mint(z).inv();\n\t\tfor (int i = 0; i\
    \ < n + m - 1; i++)\n\t\t\ta[i] *= iz;\n\t\treturn a;\n\t}\n\n\ttemplate <unsigned\
    \ int mod = 998244353, class T, std::enable_if_t<internal::is_integral<T>::value>*\
    \ = nullptr>\n\tstd::vector<T> convolution(const std::vector<T>& a, const std::vector<T>&\
    \ b) {\n\t\tint n = int(a.size()), m = int(b.size());\n\t\tif (!n || !m) return\
    \ {};\n\n\t\tusing mint = static_modint<mod>;\n\t\tstd::vector<mint> a2(n), b2(m);\n\
    \t\tfor (int i = 0; i < n; i++) {\n\t\t\ta2[i] = mint(a[i]);\n\t\t}\n\t\tfor (int\
    \ i = 0; i < m; i++) {\n\t\t\tb2[i] = mint(b[i]);\n\t\t}\n\t\tauto c2 = convolution(move(a2),\
    \ move(b2));\n\t\tstd::vector<T> c(n + m - 1);\n\t\tfor (int i = 0; i < n + m\
    \ - 1; i++) {\n\t\t\tc[i] = c2[i].val();\n\t\t}\n\t\treturn c;\n\t}\n\n\tstd::vector<long\
    \ long> convolution_ll(const std::vector<long long>& a, const std::vector<long\
    \ long>& b) {\n\t\tint n = int(a.size()), m = int(b.size());\n\t\tif (!n || !m)\
    \ return {};\n\n\t\tstatic constexpr unsigned long long MOD1 = 754974721;  //\
    \ 2^24\n\t\tstatic constexpr unsigned long long MOD2 = 167772161;  // 2^25\n\t\
    \tstatic constexpr unsigned long long MOD3 = 469762049;  // 2^26\n\t\tstatic constexpr\
    \ unsigned long long M2M3 = MOD2 * MOD3;\n\t\tstatic constexpr unsigned long long\
    \ M1M3 = MOD1 * MOD3;\n\t\tstatic constexpr unsigned long long M1M2 = MOD1 * MOD2;\n\
    \t\tstatic constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;\n\n\t\tstatic\
    \ constexpr unsigned long long i1 = internal::inv_gcd(MOD2 * MOD3, MOD1).second;\n\
    \t\tstatic constexpr unsigned long long i2 = internal::inv_gcd(MOD1 * MOD3, MOD2).second;\n\
    \t\tstatic constexpr unsigned long long i3 = internal::inv_gcd(MOD1 * MOD2, MOD3).second;\n\
    \n\t\tauto c1 = convolution<MOD1>(a, b);\n\t\tauto c2 = convolution<MOD2>(a, b);\n\
    \t\tauto c3 = convolution<MOD3>(a, b);\n\n\t\tstd::vector<long long> c(n + m -\
    \ 1);\n\t\tfor (int i = 0; i < n + m - 1; i++) {\n\t\t\tunsigned long long x =\
    \ 0;\n\t\t\tx += (c1[i] * i1) % MOD1 * M2M3;\n\t\t\tx += (c2[i] * i2) % MOD2 *\
    \ M1M3;\n\t\t\tx += (c3[i] * i3) % MOD3 * M1M2;\n\t\t\t// B = 2^63, -B <= x, r(real\
    \ value) < B\n\t\t\t// (x, x - M, x - 2M, or x - 3M) = r (mod 2B)\n\t\t\t// r\
    \ = c1[i] (mod MOD1)\n\t\t\t// focus on MOD1\n\t\t\t// r = x, x - M', x - 2M',\
    \ x - 3M' (M' = M % 2^64) (mod 2B)\n\t\t\t// r = x,\n\t\t\t//     x - M' + (0\
    \ or 2B),\n\t\t\t//     x - 2M' + (0, 2B or 4B),\n\t\t\t//     x - 3M' + (0, 2B,\
    \ 4B or 6B) (without mod!)\n\t\t\t// (r - x) = 0, (0)\n\t\t\t//           - M'\
    \ + (0 or 2B), (1)\n\t\t\t//           -2M' + (0 or 2B or 4B), (2)\n\t\t\t// \
    \          -3M' + (0 or 2B or 4B or 6B) (3) (mod MOD1)\n\t\t\t// we checked that\n\
    \t\t\t//   ((1) mod MOD1) mod 5 = 2\n\t\t\t//   ((2) mod MOD1) mod 5 = 3\n\t\t\
    \t//   ((3) mod MOD1) mod 5 = 4\n\t\t\tlong long diff = c1[i] - internal::safe_mod((long\
    \ long)(x), (long long)(MOD1));\n\t\t\tif (diff < 0) diff += MOD1;\n\t\t\tstatic\
    \ constexpr unsigned long long offset[5] = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\n\
    \t\t\tx -= offset[diff % 5];\n\t\t\tc[i] = x;\n\t\t}\n\n\t\treturn c;\n\t}\n\n\
    }  // namespace atcoder\n\n#endif  // ATCODER_CONVOLUTION_HPP\n"
  dependsOn:
  - atcoder/internal_bit.hpp
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  isVerificationFile: false
  path: atcoder/convolution.hpp
  requiredBy: []
  timestamp: '2020-10-30 19:21:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: atcoder/convolution.hpp
layout: document
redirect_from:
- /library/atcoder/convolution.hpp
- /library/atcoder/convolution.hpp.html
title: atcoder/convolution.hpp
---
