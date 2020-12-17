---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':warning:'
    path: atcoder/fenwicktree.hpp
    title: atcoder/fenwicktree.hpp
  - icon: ':warning:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/internal_type_traits.hpp\"\n\n\n\n#include <cassert>\n\
    #include <numeric>\n#include <type_traits>\n\nnamespace atcoder {\n\n\tnamespace\
    \ internal {\n\n#ifndef _MSC_VER\n\t\ttemplate <class T>\n\t\tusing is_signed_int128\
    \ =\n\t\t    typename std::conditional<std::is_same<T, __int128_t>::value || std::is_same<T,\
    \ __int128>::value,\n\t\t                              std::true_type, std::false_type>::type;\n\
    \n\t\ttemplate <class T>\n\t\tusing is_unsigned_int128 =\n\t\t    typename std::conditional<std::is_same<T,\
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
    \n\t}  // namespace internal\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_INTERNAL_TYPE_TRAITS_HPP\n#define ATCODER_INTERNAL_TYPE_TRAITS_HPP\
    \ 1\n\n#include <cassert>\n#include <numeric>\n#include <type_traits>\n\nnamespace\
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
    \n\t}  // namespace internal\n\n}  // namespace atcoder\n\n#endif  // ATCODER_INTERNAL_TYPE_TRAITS_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/internal_type_traits.hpp
  requiredBy:
  - atcoder/modint.hpp
  - atcoder/fenwicktree.hpp
  - atcoder/convolution.hpp
  timestamp: '2020-10-30 19:21:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: atcoder/internal_type_traits.hpp
layout: document
redirect_from:
- /library/atcoder/internal_type_traits.hpp
- /library/atcoder/internal_type_traits.hpp.html
title: atcoder/internal_type_traits.hpp
---
