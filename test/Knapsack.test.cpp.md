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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_C
  bundledCode: "#line 1 \"test/Knapsack.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_C\"\
    \n#line 2 \"DP/Knapsack.cpp\"\n#include <vector>\n#include <algorithm>\n#include\
    \ <cassert>\nusing namespace std;\n\ntemplate <class T>\nvector<T> Knapsack(int\
    \ n, int wight_limit, const vector<T>& value,\n                   const vector<int>&\
    \ weight) {\n\tassert(n == static_cast<int>(value.size()));\n\tassert(n == static_cast<int>(weight.size()));\n\
    \tvector<T> dp(wight_limit + 1, 0);\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor\
    \ (int j = 0; j <= wight_limit - weight[i]; ++j) {\n\t\t\tdp[j + weight[i]] =\
    \ max(dp[j + weight[i]], dp[j] + value[i]);\n\t\t}\n\t}\n\treturn dp;\n}\n#line\
    \ 3 \"test/Knapsack.test.cpp\"\n#include <iostream>\n#line 5 \"test/Knapsack.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint N, W;\n\tcin >> N >> W;\n\tvector<int> v(N), w(N);\n\tfor (int i = 0; i\
    \ < N; ++i) {\n\t\tcin >> v[i] >> w[i];\n\t}\n\tcout << Knapsack(N, W, v, w)[W]\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_C\"\
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
  timestamp: '2020-12-20 17:43:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Knapsack.test.cpp
layout: document
redirect_from:
- /verify/test/Knapsack.test.cpp
- /verify/test/Knapsack.test.cpp.html
title: test/Knapsack.test.cpp
---
