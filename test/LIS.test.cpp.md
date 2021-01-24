---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DP/LIS.cpp
    title: DP/LIS.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D
  bundledCode: "#line 1 \"test/LIS.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D\"\
    \n#line 2 \"DP/LIS.cpp\"\n#include <vector>\n#include <algorithm>\n#include <limits>\n\
    using namespace std;\n\ntemplate <class T> int LIS(const vector<T>& a) {\n\tconstexpr\
    \ T INF = numeric_limits<T>::max();\n\tvector<T> dp(a.size(), INF);\n\tfor (auto\
    \ num : a) {\n\t\t*lower_bound(dp.begin(), dp.end(), num) = num;\n\t}\n\treturn\
    \ lower_bound(dp.begin(), dp.end(), INF) - dp.begin();\n}\n#line 3 \"test/LIS.test.cpp\"\
    \n#include <iostream>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\tint n;\n\tcin >> n;\n\tvector<int> a(n);\n\
    \tfor (int& i : a) {\n\t\tcin >> i;\n\t}\n\tcout << LIS(a) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D\"\
    \n#include \"./../DP/LIS.cpp\"\n#include <iostream>\nusing namespace std;\n\n\
    int main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\tint\
    \ n;\n\tcin >> n;\n\tvector<int> a(n);\n\tfor (int& i : a) {\n\t\tcin >> i;\n\t\
    }\n\tcout << LIS(a) << '\\n';\n}"
  dependsOn:
  - DP/LIS.cpp
  isVerificationFile: true
  path: test/LIS.test.cpp
  requiredBy: []
  timestamp: '2020-12-15 11:08:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LIS.test.cpp
layout: document
redirect_from:
- /verify/test/LIS.test.cpp
- /verify/test/LIS.test.cpp.html
title: test/LIS.test.cpp
---
