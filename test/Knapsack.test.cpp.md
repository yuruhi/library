---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DP/Knapsack.cpp
    title: DP/Knapsack.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_B
  bundledCode: "#line 1 \"test/Knapsack.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_B\"\
    \n#line 2 \"DP/Knapsack.cpp\"\n#include <vector>\n#include <algorithm>\nusing\
    \ namespace std;\n\ntemplate <class T>\nvector<T> Knapsack(int n, T weight_limit,\
    \ const vector<T>& value, const vector<T>& weight) {\n\tvector<T> dp(weight_limit\
    \ + 1, 0);\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j = weight_limit; j\
    \ >= 0; --j) {\n\t\t\tif (j - weight[i] >= 0) dp[j] = max(dp[j], dp[j - weight[i]]\
    \ + value[i]);\n\t\t}\n\t}\n\treturn dp;\n}\n#line 3 \"test/Knapsack.test.cpp\"\
    \n#include <iostream>\n#line 5 \"test/Knapsack.test.cpp\"\nusing namespace std;\n\
    \nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\tint\
    \ N, W;\n\tcin >> N >> W;\n\tvector<int> v(N), w(N);\n\tfor (int i = 0; i < N;\
    \ ++i) {\n\t\tcin >> v[i] >> w[i];\n\t}\n\tcout << Knapsack(N, W, v, w)[W] <<\
    \ '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_B\"\
    \n#include \"./../DP/Knapsack.cpp\"\n#include <iostream>\n#include <vector>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint N, W;\n\tcin >> N >> W;\n\tvector<int> v(N), w(N);\n\tfor (int i = 0; i\
    \ < N; ++i) {\n\t\tcin >> v[i] >> w[i];\n\t}\n\tcout << Knapsack(N, W, v, w)[W]\
    \ << '\\n';\n}"
  dependsOn:
  - DP/Knapsack.cpp
  isVerificationFile: true
  path: test/Knapsack.test.cpp
  requiredBy: []
  timestamp: '2020-11-21 14:30:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Knapsack.test.cpp
layout: document
redirect_from:
- /verify/test/Knapsack.test.cpp
- /verify/test/Knapsack.test.cpp.html
title: test/Knapsack.test.cpp
---