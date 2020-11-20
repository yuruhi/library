---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':warning:'
    path: atcoder/lazysegtree.hpp
    title: atcoder/lazysegtree.hpp
  - icon: ':warning:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n#include\
    \ <intrin.h>\n#endif\n\nnamespace atcoder {\n\n\tnamespace internal {\n\n\t\t\
    // @param n `0 <= n`\n\t\t// @return minimum non-negative `x` s.t. `n <= 2**x`\n\
    \t\tint ceil_pow2(int n) {\n\t\t\tint x = 0;\n\t\t\twhile ((1U << x) < (unsigned\
    \ int)(n))\n\t\t\t\tx++;\n\t\t\treturn x;\n\t\t}\n\n\t\t// @param n `1 <= n`\n\
    \t\t// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\n\t\tint bsf(unsigned\
    \ int n) {\n#ifdef _MSC_VER\n\t\t\tunsigned long index;\n\t\t\t_BitScanForward(&index,\
    \ n);\n\t\t\treturn index;\n#else\n\t\t\treturn __builtin_ctz(n);\n#endif\n\t\t\
    }\n\n\t}  // namespace internal\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_INTERNAL_BITOP_HPP\n#define ATCODER_INTERNAL_BITOP_HPP 1\n\
    \n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\n\tnamespace\
    \ internal {\n\n\t\t// @param n `0 <= n`\n\t\t// @return minimum non-negative\
    \ `x` s.t. `n <= 2**x`\n\t\tint ceil_pow2(int n) {\n\t\t\tint x = 0;\n\t\t\twhile\
    \ ((1U << x) < (unsigned int)(n))\n\t\t\t\tx++;\n\t\t\treturn x;\n\t\t}\n\n\t\t\
    // @param n `1 <= n`\n\t\t// @return minimum non-negative `x` s.t. `(n & (1 <<\
    \ x)) != 0`\n\t\tint bsf(unsigned int n) {\n#ifdef _MSC_VER\n\t\t\tunsigned long\
    \ index;\n\t\t\t_BitScanForward(&index, n);\n\t\t\treturn index;\n#else\n\t\t\t\
    return __builtin_ctz(n);\n#endif\n\t\t}\n\n\t}  // namespace internal\n\n}  //\
    \ namespace atcoder\n\n#endif  // ATCODER_INTERNAL_BITOP_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/internal_bit.hpp
  requiredBy:
  - atcoder/convolution.hpp
  - atcoder/lazysegtree.hpp
  - atcoder/segtree.hpp
  timestamp: '2020-10-30 19:21:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: atcoder/internal_bit.hpp
layout: document
redirect_from:
- /library/atcoder/internal_bit.hpp
- /library/atcoder/internal_bit.hpp.html
title: atcoder/internal_bit.hpp
---
