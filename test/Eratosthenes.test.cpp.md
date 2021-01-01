---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Eratosthenes.cpp
    title: Math/Eratosthenes.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C
  bundledCode: "#line 1 \"test/Eratosthenes.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C\"\
    \n#line 2 \"Math/Eratosthenes.cpp\"\n#include <vector>\nusing namespace std;\n\
    \nvector<bool> Eratosthenes(size_t n) {\n\tvector<bool> result(n + 1, true);\n\
    \tresult[0] = result[1] = false;\n\tfor (size_t i = 2; i * i <= n; ++i) {\n\t\t\
    if (result[i]) {\n\t\t\tfor (size_t j = i * i; j <= n; j += i) result[j] = false;\n\
    \t\t}\n\t}\n\treturn result;\n}\n#line 3 \"test/Eratosthenes.test.cpp\"\n#include\
    \ <iostream>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tauto table = Eratosthenes(100000000);\n\tint n;\n\tcin >> n;\n\tint ans =\
    \ 0;\n\twhile (n--) {\n\t\tint x;\n\t\tcin >> x;\n\t\tans += table[x];\n\t}\n\t\
    cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C\"\n\
    #include \"./../Math/Eratosthenes.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tauto table = Eratosthenes(100000000);\n\tint n;\n\tcin >> n;\n\tint ans =\
    \ 0;\n\twhile (n--) {\n\t\tint x;\n\t\tcin >> x;\n\t\tans += table[x];\n\t}\n\t\
    cout << ans << '\\n';\n}"
  dependsOn:
  - Math/Eratosthenes.cpp
  isVerificationFile: true
  path: test/Eratosthenes.test.cpp
  requiredBy: []
  timestamp: '2021-01-01 17:28:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Eratosthenes.test.cpp
layout: document
redirect_from:
- /verify/test/Eratosthenes.test.cpp
- /verify/test/Eratosthenes.test.cpp.html
title: test/Eratosthenes.test.cpp
---
