---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DP/Knapsack01.cpp
    title: DP/Knapsack01.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_B
  bundledCode: "#line 1 \"test/Knapsack01.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_B\"\
    \n#line 2 \"DP/Knapsack01.cpp\"\n#include <vector>\n#include <algorithm>\n#include\
    \ <cassert>\nusing namespace std;\n\ntemplate <class T>\nvector<T> Knapsack01(int\
    \ n, int weight_limit, const vector<T>& value,\n                     const vector<int>&\
    \ weight) {\n\tassert(n == static_cast<int>(value.size()));\n\tassert(n == static_cast<int>(weight.size()));\n\
    \tvector<T> dp(weight_limit + 1, 0);\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor\
    \ (int j = weight_limit; j >= 0; --j) {\n\t\t\tif (j - weight[i] >= 0) dp[j] =\
    \ max(dp[j], dp[j - weight[i]] + value[i]);\n\t\t}\n\t}\n\treturn dp;\n}\n#line\
    \ 3 \"test/Knapsack01.test.cpp\"\n#include <iostream>\n#line 5 \"test/Knapsack01.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint N, W;\n\tcin >> N >> W;\n\tvector<int> v(N), w(N);\n\tfor (int i = 0; i\
    \ < N; ++i) {\n\t\tcin >> v[i] >> w[i];\n\t}\n\tcout << Knapsack01(N, W, v, w)[W]\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_B\"\
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
  timestamp: '2021-01-01 17:28:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Knapsack01.test.cpp
layout: document
redirect_from:
- /verify/test/Knapsack01.test.cpp
- /verify/test/Knapsack01.test.cpp.html
title: test/Knapsack01.test.cpp
---
