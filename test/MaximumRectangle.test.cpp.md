---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DP/MaximumRectangle.cpp
    title: DP/MaximumRectangle.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_C
  bundledCode: "#line 1 \"test/MaximumRectangle.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_C\"\
    \n#line 2 \"DP/MaximumRectangle.cpp\"\n#include <vector>\n#include <stack>\n#include\
    \ <algorithm>\n\ntemplate <class T> T MaximumRectangle(const std::vector<T>& a)\
    \ {\n\tint n = a.size();\n\tT result = 0;\n\tstd::stack<int> st;\n\tstd::vector<int>\
    \ L(n), R(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\twhile (!st.empty() && a[st.top()]\
    \ >= a[i]) st.pop();\n\t\tL[i] = st.empty() ? 0 : st.top() + 1;\n\t\tst.push(i);\n\
    \t}\n\twhile (!st.empty()) st.pop();\n\tfor (int i = n - 1; i >= 0; --i) {\n\t\
    \twhile (!st.empty() && a[st.top()] >= a[i]) st.pop();\n\t\tR[i] = st.empty()\
    \ ? n : st.top();\n\t\tst.push(i);\n\t}\n\tfor (int i = 0; i < n; ++i) {\n\t\t\
    result = std::max(result, a[i] * (R[i] - L[i]));\n\t}\n\treturn result;\n}\n#line\
    \ 3 \"test/MaximumRectangle.test.cpp\"\n#include <iostream>\n#line 5 \"test/MaximumRectangle.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tusing ll = long long;\n\n\tint n;\n\tcin >> n;\n\tvector<ll> a(n);\n\tfor (ll&\
    \ i : a) {\n\t\tcin >> i;\n\t}\n\tcout << MaximumRectangle(a) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_C\"\n#include\
    \ \"./../DP/MaximumRectangle.cpp\"\n#include <iostream>\n#include <vector>\nusing\
    \ namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tusing ll = long long;\n\n\tint n;\n\tcin >> n;\n\tvector<ll> a(n);\n\tfor (ll&\
    \ i : a) {\n\t\tcin >> i;\n\t}\n\tcout << MaximumRectangle(a) << '\\n';\n}"
  dependsOn:
  - DP/MaximumRectangle.cpp
  isVerificationFile: true
  path: test/MaximumRectangle.test.cpp
  requiredBy: []
  timestamp: '2021-03-21 09:59:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/MaximumRectangle.test.cpp
layout: document
redirect_from:
- /verify/test/MaximumRectangle.test.cpp
- /verify/test/MaximumRectangle.test.cpp.html
title: test/MaximumRectangle.test.cpp
---
