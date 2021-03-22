---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/Bsearch.cpp\"\n#include <optional>\n#include <type_traits>\n\
    #include <cassert>\n\ntemplate <class T, class F, std::enable_if_t<std::is_integral_v<T>,\
    \ std::nullptr_t> = nullptr>\nstd::optional<T> Bsearch(T left, T right, F f) {\n\
    \tif (left >= right || !f(right)) {\n\t\treturn std::nullopt;\n\t}\n\twhile (right\
    \ - left > 1) {\n\t\tT middle = (left + right) / 2;\n\t\t(f(middle) ? right :\
    \ left) = middle;\n\t}\n\tassert(!f(left));\n\tassert(f(right));\n\treturn right;\n\
    }\n"
  code: "#pragma once\n#include <optional>\n#include <type_traits>\n#include <cassert>\n\
    \ntemplate <class T, class F, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t>\
    \ = nullptr>\nstd::optional<T> Bsearch(T left, T right, F f) {\n\tif (left >=\
    \ right || !f(right)) {\n\t\treturn std::nullopt;\n\t}\n\twhile (right - left\
    \ > 1) {\n\t\tT middle = (left + right) / 2;\n\t\t(f(middle) ? right : left) =\
    \ middle;\n\t}\n\tassert(!f(left));\n\tassert(f(right));\n\treturn right;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Bsearch.cpp
  requiredBy: []
  timestamp: '2021-03-22 13:25:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/Bsearch.cpp
layout: document
redirect_from:
- /library/Utility/Bsearch.cpp
- /library/Utility/Bsearch.cpp.html
title: Utility/Bsearch.cpp
---
