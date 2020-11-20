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
    \ RLE(const T& a) {\n\tint n = a.size();\n\tvector<int> res1;\n\tvector<U> res2;\n\
    \tfor (int i = 0; i < n;) {\n\t\tint cnt = 0;\n\t\tauto e = a[i];\n\t\tfor (;\
    \ i < n && a[i] == e; ++i) ++cnt;\n\t\tres1.push_back(cnt);\n\t\tres2.push_back(e);\n\
    \t}\n\treturn make_pair(res1, res2);\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\nusing namespace std;\n\
    \ntemplate <class T, class U = typename T::value_type> auto RLE(const T& a) {\n\
    \tint n = a.size();\n\tvector<int> res1;\n\tvector<U> res2;\n\tfor (int i = 0;\
    \ i < n;) {\n\t\tint cnt = 0;\n\t\tauto e = a[i];\n\t\tfor (; i < n && a[i] ==\
    \ e; ++i) ++cnt;\n\t\tres1.push_back(cnt);\n\t\tres2.push_back(e);\n\t}\n\treturn\
    \ make_pair(res1, res2);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/RLE.cpp
  requiredBy: []
  timestamp: '2020-11-20 21:19:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/RLE.cpp
layout: document
redirect_from:
- /library/Utility/RLE.cpp
- /library/Utility/RLE.cpp.html
title: Utility/RLE.cpp
---
