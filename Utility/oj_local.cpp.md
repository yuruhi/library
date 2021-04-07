---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  - icon: ':warning:'
    path: template_no_Ruby.cpp
    title: template_no_Ruby.cpp
  _extendedVerifiedWith:
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
  bundledCode: "#line 2 \"Utility/oj_local.cpp\"\ntemplate <class T> constexpr T oj_local(const\
    \ T& oj, const T& local) {\n#ifndef LOCAL\n\treturn oj;\n#else\n\treturn local;\n\
    #endif\n}\n"
  code: "#pragma once\ntemplate <class T> constexpr T oj_local(const T& oj, const\
    \ T& local) {\n#ifndef LOCAL\n\treturn oj;\n#else\n\treturn local;\n#endif\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/oj_local.cpp
  requiredBy:
  - template.cpp
  - template_no_Ruby.cpp
  timestamp: '2021-03-22 13:25:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/template.test.cpp
  - test/template_no_Ruby.test.cpp
documentation_of: Utility/oj_local.cpp
layout: document
redirect_from:
- /library/Utility/oj_local.cpp
- /library/Utility/oj_local.cpp.html
title: Utility/oj_local.cpp
---
