---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/MaximumRectangle.test.cpp
    title: test/MaximumRectangle.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DP/MaximumRectangle.cpp\"\n#include <vector>\n#include <stack>\n\
    #include <algorithm>\nusing namespace std;\n\ntemplate <class T> T MaximumRectangle(const\
    \ vector<T>& a) {\n\tint n = a.size();\n\tT result = 0;\n\tstack<int> st;\n\t\
    vector<int> L(n), R(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\twhile (!st.empty()\
    \ && a[st.top()] >= a[i]) st.pop();\n\t\tL[i] = st.empty() ? 0 : st.top() + 1;\n\
    \t\tst.push(i);\n\t}\n\twhile (!st.empty()) st.pop();\n\tfor (int i = n - 1; i\
    \ >= 0; --i) {\n\t\twhile (!st.empty() && a[st.top()] >= a[i]) st.pop();\n\t\t\
    R[i] = st.empty() ? n : st.top();\n\t\tst.push(i);\n\t}\n\tfor (int i = 0; i <\
    \ n; ++i) {\n\t\tresult = max(result, a[i] * (R[i] - L[i]));\n\t}\n\treturn result;\n\
    }\n"
  code: "#pragma once\n#include <vector>\n#include <stack>\n#include <algorithm>\n\
    using namespace std;\n\ntemplate <class T> T MaximumRectangle(const vector<T>&\
    \ a) {\n\tint n = a.size();\n\tT result = 0;\n\tstack<int> st;\n\tvector<int>\
    \ L(n), R(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\twhile (!st.empty() && a[st.top()]\
    \ >= a[i]) st.pop();\n\t\tL[i] = st.empty() ? 0 : st.top() + 1;\n\t\tst.push(i);\n\
    \t}\n\twhile (!st.empty()) st.pop();\n\tfor (int i = n - 1; i >= 0; --i) {\n\t\
    \twhile (!st.empty() && a[st.top()] >= a[i]) st.pop();\n\t\tR[i] = st.empty()\
    \ ? n : st.top();\n\t\tst.push(i);\n\t}\n\tfor (int i = 0; i < n; ++i) {\n\t\t\
    result = max(result, a[i] * (R[i] - L[i]));\n\t}\n\treturn result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/MaximumRectangle.cpp
  requiredBy: []
  timestamp: '2020-11-20 21:19:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/MaximumRectangle.test.cpp
documentation_of: DP/MaximumRectangle.cpp
layout: document
redirect_from:
- /library/DP/MaximumRectangle.cpp
- /library/DP/MaximumRectangle.cpp.html
title: DP/MaximumRectangle.cpp
---
