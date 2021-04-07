---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Utility/constants.cpp
    title: Utility/constants.cpp
  - icon: ':warning:'
    path: math/Combination.cpp
    title: math/Combination.cpp
  - icon: ':heavy_check_mark:'
    path: math/modint.cpp
    title: math/modint.cpp
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  - icon: ':warning:'
    path: template_no_Ruby.cpp
    title: template_no_Ruby.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Partition.test.cpp
    title: test/Partition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint_pow.test.cpp
    title: test/modint_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/template.test.cpp
    title: test/template.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/template_no_Ruby.test.cpp
    title: test/template_no_Ruby.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/get_MOD.cpp\"\nconstexpr long long get_MOD() {\n\
    #ifdef SET_MOD\n\treturn SET_MOD;\n#else\n\treturn 1000000007;\n#endif\n}\n"
  code: "#pragma once\nconstexpr long long get_MOD() {\n#ifdef SET_MOD\n\treturn SET_MOD;\n\
    #else\n\treturn 1000000007;\n#endif\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/get_MOD.cpp
  requiredBy:
  - Utility/constants.cpp
  - math/modint.cpp
  - math/Combination.cpp
  - template.cpp
  - template_no_Ruby.cpp
  timestamp: '2021-03-18 10:33:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/template.test.cpp
  - test/template_no_Ruby.test.cpp
  - test/modint_pow.test.cpp
  - test/Partition.test.cpp
documentation_of: Utility/get_MOD.cpp
layout: document
redirect_from:
- /library/Utility/get_MOD.cpp
- /library/Utility/get_MOD.cpp.html
title: Utility/get_MOD.cpp
---
