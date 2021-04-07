---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/ZAlgorithm.cpp
    title: string/ZAlgorithm.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/ZAlgotihm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n#line 2 \"string/ZAlgorithm.cpp\"\n#include <vector>\n\ntemplate <class T> std::vector<int>\
    \ ZAlgorithm(const T& s) {\n\tif (s.size() == 0) {\n\t\treturn {};\n\t}\n\tint\
    \ n = s.size(), i = 1, j = 0;\n\tstd::vector<int> result(n);\n\tresult[0] = n;\n\
    \twhile (i < n) {\n\t\twhile (i + j < n && s[j] == s[i + j]) j++;\n\t\tresult[i]\
    \ = j;\n\t\tif (j == 0) {\n\t\t\ti++;\n\t\t\tcontinue;\n\t\t}\n\t\tint k = 1;\n\
    \t\twhile (i + k < n && k + result[k] < j) {\n\t\t\tresult[i + k] = result[k];\n\
    \t\t\tk++;\n\t\t}\n\t\ti += k;\n\t\tj -= k;\n\t}\n\treturn result;\n}\n#line 3\
    \ \"test/ZAlgotihm.test.cpp\"\n#include <iostream>\nusing namespace std;\n\nint\
    \ main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\tstring\
    \ s;\n\tcin >> s;\n\tint n = s.size();\n\tauto a = ZAlgorithm(s);\n\tfor (int\
    \ i = 0; i < n; ++i) {\n\t\tcout << a[i] << (i < n - 1 ? ' ' : '\\n');\n\t}\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"./../string/ZAlgorithm.cpp\"\n#include <iostream>\nusing namespace std;\n\n\
    int main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\tstring\
    \ s;\n\tcin >> s;\n\tint n = s.size();\n\tauto a = ZAlgorithm(s);\n\tfor (int\
    \ i = 0; i < n; ++i) {\n\t\tcout << a[i] << (i < n - 1 ? ' ' : '\\n');\n\t}\n}"
  dependsOn:
  - string/ZAlgorithm.cpp
  isVerificationFile: true
  path: test/ZAlgotihm.test.cpp
  requiredBy: []
  timestamp: '2021-04-06 14:09:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ZAlgotihm.test.cpp
layout: document
redirect_from:
- /verify/test/ZAlgotihm.test.cpp
- /verify/test/ZAlgotihm.test.cpp.html
title: test/ZAlgotihm.test.cpp
---
