---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DP/Knapsack01.cpp
    title: DP/Knapsack01.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_C
  bundledCode: "#line 1 \"test/Knapsack01.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_C\"\
    \n#line 2 \"DP/Knapsack01.cpp\"\n#include <vector>\n#include <algorithm>\nusing\
    \ namespace std;\n\ntemplate <class T>\nvector<T> Knapsack01(int n, int wight_limit,\
    \ const vector<T>& value,\n                     const vector<int>& weight) {\n\
    \tvector<T> dp(wight_limit + 1, 0);\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor\
    \ (int j = 0; j <= wight_limit - weight[i]; ++j) {\n\t\t\tdp[j + weight[i]] =\
    \ max(dp[j + weight[i]], dp[j] + value[i]);\n\t\t}\n\t}\n\treturn dp;\n}\n#line\
    \ 3 \"test/Knapsack01.test.cpp\"\n#include <iostream>\n#line 5 \"test/Knapsack01.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint N, W;\n\tcin >> N >> W;\n\tvector<int> v(N), w(N);\n\tfor (int i = 0; i\
    \ < N; ++i) {\n\t\tcin >> v[i] >> w[i];\n\t}\n\tcout << Knapsack01(N, W, v, w)[W]\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_C\"\
    \n#include \"./../DP/Knapsack01.cpp\"\n#include <iostream>\n#include <vector>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint N, W;\n\tcin >> N >> W;\n\tvector<int> v(N), w(N);\n\tfor (int i = 0; i\
    \ < N; ++i) {\n\t\tcin >> v[i] >> w[i];\n\t}\n\tcout << Knapsack01(N, W, v, w)[W]\
    \ << '\\n';\n}"
  dependsOn:
  - DP/Knapsack01.cpp
  isVerificationFile: true
  path: test/Knapsack01.test.cpp
  requiredBy: []
  timestamp: '2020-11-20 21:19:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Knapsack01.test.cpp
layout: document
redirect_from:
- /verify/test/Knapsack01.test.cpp
- /verify/test/Knapsack01.test.cpp.html
title: test/Knapsack01.test.cpp
---
