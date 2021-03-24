---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Bsearch.test.cpp
    title: test/Bsearch.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/Bsearch.cpp\"\n#include <optional>\n#include <type_traits>\n\
    #include <cassert>\n\ntemplate <class T, class F, std::enable_if_t<std::is_integral_v<T>,\
    \ std::nullptr_t> = nullptr>\nstd::optional<T> Bsearch(T left, T right, F f) {\n\
    \tif (left > right || !f(right)) {\n\t\treturn std::nullopt;\n\t} else if (f(left))\
    \ {\n\t\treturn left;\n\t}\n\twhile (right - left > 1) {\n\t\tT middle = (left\
    \ + right) / 2;\n\t\t(f(middle) ? right : left) = middle;\n\t}\n\tassert(!f(left));\n\
    \tassert(f(right));\n\treturn right;\n}\n"
  code: "#pragma once\n#include <optional>\n#include <type_traits>\n#include <cassert>\n\
    \ntemplate <class T, class F, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t>\
    \ = nullptr>\nstd::optional<T> Bsearch(T left, T right, F f) {\n\tif (left > right\
    \ || !f(right)) {\n\t\treturn std::nullopt;\n\t} else if (f(left)) {\n\t\treturn\
    \ left;\n\t}\n\twhile (right - left > 1) {\n\t\tT middle = (left + right) / 2;\n\
    \t\t(f(middle) ? right : left) = middle;\n\t}\n\tassert(!f(left));\n\tassert(f(right));\n\
    \treturn right;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Bsearch.cpp
  requiredBy: []
  timestamp: '2021-03-24 15:18:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Bsearch.test.cpp
documentation_of: Utility/Bsearch.cpp
layout: document
redirect_from:
- /library/Utility/Bsearch.cpp
- /library/Utility/Bsearch.cpp.html
title: Utility/Bsearch.cpp
---
