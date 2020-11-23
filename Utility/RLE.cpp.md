---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/RLE.cpp\"\n#include <vector>\n#include <utility>\n\
    using namespace std;\n\ntemplate <class T, class U = typename T::value_type> auto\
    \ RLE(const T& a) {\n\tsize_t n = a.size();\n\tvector<size_t> count;\n\tvector<U>\
    \ value;\n\tfor (size_t i = 0; i < n;) {\n\t\tsize_t cnt = 0;\n\t\tauto val =\
    \ a[i];\n\t\tfor (; i < n && a[i] == val; ++i) ++cnt;\n\t\tcount.push_back(cnt);\n\
    \t\tvalue.push_back(val);\n\t}\n\treturn make_pair(count, value);\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\nusing namespace std;\n\
    \ntemplate <class T, class U = typename T::value_type> auto RLE(const T& a) {\n\
    \tsize_t n = a.size();\n\tvector<size_t> count;\n\tvector<U> value;\n\tfor (size_t\
    \ i = 0; i < n;) {\n\t\tsize_t cnt = 0;\n\t\tauto val = a[i];\n\t\tfor (; i <\
    \ n && a[i] == val; ++i) ++cnt;\n\t\tcount.push_back(cnt);\n\t\tvalue.push_back(val);\n\
    \t}\n\treturn make_pair(count, value);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/RLE.cpp
  requiredBy: []
  timestamp: '2020-11-23 14:52:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/RLE.cpp
layout: document
redirect_from:
- /library/Utility/RLE.cpp
- /library/Utility/RLE.cpp.html
title: Utility/RLE.cpp
---
