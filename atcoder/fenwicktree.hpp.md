---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/Fenwick_tree
  bundledCode: "#line 1 \"atcoder/fenwicktree.hpp\"\n\n\n\n#line 1 \"atcoder/internal_type_traits.hpp\"\
    \n\n\n\n#include <cassert>\n#include <numeric>\n#include <type_traits>\n\nnamespace\
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
    \n\t}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 6 \"atcoder/fenwicktree.hpp\"\
    \n#include <vector>\n\nnamespace atcoder {\n\n\t// Reference: https://en.wikipedia.org/wiki/Fenwick_tree\n\
    \ttemplate <class T> struct fenwick_tree {\n\t\tusing U = internal::to_unsigned_t<T>;\n\
    \n\tpublic:\n\t\tfenwick_tree() : _n(0) {}\n\t\tfenwick_tree(int n) : _n(n), data(n)\
    \ {}\n\n\t\tvoid add(int p, T x) {\n\t\t\tassert(0 <= p && p < _n);\n\t\t\tp++;\n\
    \t\t\twhile (p <= _n) {\n\t\t\t\tdata[p - 1] += U(x);\n\t\t\t\tp += p & -p;\n\t\
    \t\t}\n\t\t}\n\n\t\tT sum(int l, int r) {\n\t\t\tassert(0 <= l && l <= r && r\
    \ <= _n);\n\t\t\treturn sum(r) - sum(l);\n\t\t}\n\n\tprivate:\n\t\tint _n;\n\t\
    \tstd::vector<U> data;\n\n\t\tU sum(int r) {\n\t\t\tU s = 0;\n\t\t\twhile (r >\
    \ 0) {\n\t\t\t\ts += data[r - 1];\n\t\t\t\tr -= r & -r;\n\t\t\t}\n\t\t\treturn\
    \ s;\n\t\t}\n\t};\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_FENWICKTREE_HPP\n#define ATCODER_FENWICKTREE_HPP 1\n\n#include\
    \ \"./internal_type_traits.hpp\"\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ atcoder {\n\n\t// Reference: https://en.wikipedia.org/wiki/Fenwick_tree\n\t\
    template <class T> struct fenwick_tree {\n\t\tusing U = internal::to_unsigned_t<T>;\n\
    \n\tpublic:\n\t\tfenwick_tree() : _n(0) {}\n\t\tfenwick_tree(int n) : _n(n), data(n)\
    \ {}\n\n\t\tvoid add(int p, T x) {\n\t\t\tassert(0 <= p && p < _n);\n\t\t\tp++;\n\
    \t\t\twhile (p <= _n) {\n\t\t\t\tdata[p - 1] += U(x);\n\t\t\t\tp += p & -p;\n\t\
    \t\t}\n\t\t}\n\n\t\tT sum(int l, int r) {\n\t\t\tassert(0 <= l && l <= r && r\
    \ <= _n);\n\t\t\treturn sum(r) - sum(l);\n\t\t}\n\n\tprivate:\n\t\tint _n;\n\t\
    \tstd::vector<U> data;\n\n\t\tU sum(int r) {\n\t\t\tU s = 0;\n\t\t\twhile (r >\
    \ 0) {\n\t\t\t\ts += data[r - 1];\n\t\t\t\tr -= r & -r;\n\t\t\t}\n\t\t\treturn\
    \ s;\n\t\t}\n\t};\n\n}  // namespace atcoder\n\n#endif  // ATCODER_FENWICKTREE_HPP\n"
  dependsOn:
  - atcoder/internal_type_traits.hpp
  isVerificationFile: false
  path: atcoder/fenwicktree.hpp
  requiredBy: []
  timestamp: '2020-10-30 19:21:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: atcoder/fenwicktree.hpp
layout: document
redirect_from:
- /library/atcoder/fenwicktree.hpp
- /library/atcoder/fenwicktree.hpp.html
title: atcoder/fenwicktree.hpp
---
