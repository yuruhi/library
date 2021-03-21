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
  bundledCode: "#line 2 \"math/EnumerateCombination.cpp\"\n#include <vector>\n\ntemplate\
    \ <class T> std::vector<std::vector<T>> EnumerateCombination(std::size_t n) {\n\
    \tstd::vector result(n + 1, std::vector<T>(n + 1));\n\tfor (std::size_t i = 0;\
    \ i <= n; ++i) result[i][0] = result[i][i] = 1;\n\tfor (std::size_t i = 1; i <=\
    \ n; ++i) {\n\t\tfor (std::size_t j = 1; j < i; ++j) {\n\t\t\tresult[i][j] = result[i\
    \ - 1][j - 1] + result[i - 1][j];\n\t\t}\n\t}\n\treturn result;\n}\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <class T> std::vector<std::vector<T>>\
    \ EnumerateCombination(std::size_t n) {\n\tstd::vector result(n + 1, std::vector<T>(n\
    \ + 1));\n\tfor (std::size_t i = 0; i <= n; ++i) result[i][0] = result[i][i] =\
    \ 1;\n\tfor (std::size_t i = 1; i <= n; ++i) {\n\t\tfor (std::size_t j = 1; j\
    \ < i; ++j) {\n\t\t\tresult[i][j] = result[i - 1][j - 1] + result[i - 1][j];\n\
    \t\t}\n\t}\n\treturn result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/EnumerateCombination.cpp
  requiredBy: []
  timestamp: '2021-03-21 09:59:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/EnumerateCombination.cpp
layout: document
redirect_from:
- /library/math/EnumerateCombination.cpp
- /library/math/EnumerateCombination.cpp.html
title: math/EnumerateCombination.cpp
---
