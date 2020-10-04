---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DP/MaximumRectangle.cpp\"\n// description : \u30D2\u30B9\
    \u30C8\u30B0\u30E9\u30E0\u4E2D\u306E\u6700\u5927\u9577\u65B9\u5F62\ntemplate <class\
    \ T> T MaximumRectangle(vector<T> h) {\n\tint n = h.size();\n\tT ans = 0;\n\t\
    stack<int> s;\n\tvector<int> L(n), R(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\t\
    while (!s.empty() && h[s.top()] >= h[i])\n\t\t\ts.pop();\n\t\tL[i] = s.empty()\
    \ ? 0 : s.top() + 1;\n\t\ts.push(i);\n\t}\n\twhile (!s.empty())\n\t\ts.pop();\n\
    \tfor (int i = n - 1; i >= 0; --i) {\n\t\twhile (!s.empty() && h[s.top()] >= h[i])\n\
    \t\t\ts.pop();\n\t\tR[i] = s.empty() ? n : s.top();\n\t\ts.push(i);\n\t}\n\tfor\
    \ (int i = 0; i < n; ++i) {\n\t\tans = max(ans, h[i] * (R[i] - L[i]));\n\t}\n\t\
    return ans;\n}\n"
  code: "// description : \u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u4E2D\u306E\u6700\u5927\
    \u9577\u65B9\u5F62\ntemplate <class T> T MaximumRectangle(vector<T> h) {\n\tint\
    \ n = h.size();\n\tT ans = 0;\n\tstack<int> s;\n\tvector<int> L(n), R(n);\n\t\
    for (int i = 0; i < n; ++i) {\n\t\twhile (!s.empty() && h[s.top()] >= h[i])\n\t\
    \t\ts.pop();\n\t\tL[i] = s.empty() ? 0 : s.top() + 1;\n\t\ts.push(i);\n\t}\n\t\
    while (!s.empty())\n\t\ts.pop();\n\tfor (int i = n - 1; i >= 0; --i) {\n\t\twhile\
    \ (!s.empty() && h[s.top()] >= h[i])\n\t\t\ts.pop();\n\t\tR[i] = s.empty() ? n\
    \ : s.top();\n\t\ts.push(i);\n\t}\n\tfor (int i = 0; i < n; ++i) {\n\t\tans =\
    \ max(ans, h[i] * (R[i] - L[i]));\n\t}\n\treturn ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: DP/MaximumRectangle.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/MaximumRectangle.cpp
layout: document
redirect_from:
- /library/DP/MaximumRectangle.cpp
- /library/DP/MaximumRectangle.cpp.html
title: DP/MaximumRectangle.cpp
---
