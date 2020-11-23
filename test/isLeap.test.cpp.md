---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Utility/isLeap.cpp
    title: Utility/isLeap.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/0093
  bundledCode: "#line 1 \"test/isLeap.test.cpp\"\n#define IGNORE\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/0093\"\n#line 2 \"Utility/isLeap.cpp\"\
    \n\nbool isLeap(int y) {\n\treturn !(y % 4) && (y % 100 || !(y % 400));\n}\n#line\
    \ 4 \"test/isLeap.test.cpp\"\n#include <iostream>\nusing namespace std;\n\nint\
    \ main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\n\tbool\
    \ first = true;\n\tfor (int a, b; cin >> a >> b && a && b;) {\n\t\tif (first)\
    \ {\n\t\t\tfirst = false;\n\t\t} else {\n\t\t\tcout << '\\n';\n\t\t}\n\t\tbool\
    \ NA = true;\n\t\tfor (int i = a; i <= b; ++i) {\n\t\t\tif (isLeap(i)) {\n\t\t\
    \t\tcout << i << '\\n';\n\t\t\t\tNA = false;\n\t\t\t}\n\t\t}\n\t\tif (NA) cout\
    \ << \"NA\\n\";\n\t}\n}\n"
  code: "#define IGNORE\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0093\"\
    \n#include \"./../Utility/isLeap.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\n\t\
    bool first = true;\n\tfor (int a, b; cin >> a >> b && a && b;) {\n\t\tif (first)\
    \ {\n\t\t\tfirst = false;\n\t\t} else {\n\t\t\tcout << '\\n';\n\t\t}\n\t\tbool\
    \ NA = true;\n\t\tfor (int i = a; i <= b; ++i) {\n\t\t\tif (isLeap(i)) {\n\t\t\
    \t\tcout << i << '\\n';\n\t\t\t\tNA = false;\n\t\t\t}\n\t\t}\n\t\tif (NA) cout\
    \ << \"NA\\n\";\n\t}\n}"
  dependsOn:
  - Utility/isLeap.cpp
  isVerificationFile: true
  path: test/isLeap.test.cpp
  requiredBy: []
  timestamp: '2020-11-23 17:15:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/isLeap.test.cpp
layout: document
redirect_from:
- /verify/test/isLeap.test.cpp
- /verify/test/isLeap.test.cpp.html
title: test/isLeap.test.cpp
---
