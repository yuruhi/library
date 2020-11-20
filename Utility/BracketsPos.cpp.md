---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/BracketsPos.cpp\"\n#include <vector>\n#include <string>\n\
    #include <stack>\n#include <utility>\n#include <cassert>\nusing namespace std;\n\
    \nsize_t BracketsPos(const string& s, size_t pos, char c1 = '(', char c2 = ')')\
    \ {\n\tassert(s[pos] == c1);\n\tint p = 1;\n\tfor (size_t i = pos + 1; i < s.size();\
    \ ++i) {\n\t\tif (s[i] == c1) {\n\t\t\tp++;\n\t\t} else if (s[i] == c2) {\n\t\t\
    \tif (p == 1) {\n\t\t\t\treturn i;\n\t\t\t}\n\t\t\tp--;\n\t\t}\n\t}\n\treturn\
    \ string::npos;\n}\n\npair<size_t, size_t> BracketsPos2(const string& s, size_t\
    \ pos, char c1 = '(',\n                                  char c2 = ')') {\n\t\
    size_t l = s.find(c1, pos);\n\tif (l != string::npos) {\n\t\tsize_t r = BracketsPos(s,\
    \ l, c1, c2);\n\t\tif (r != string::npos) {\n\t\t\treturn {l, r};\n\t\t} else\
    \ {\n\t\t\treturn {string::npos, string::npos};\n\t\t}\n\t} else {\n\t\treturn\
    \ {string::npos, string::npos};\n\t}\n}\n\nvector<int> AllBracketsPos(const string&\
    \ s, char c1 = '(', char c2 = ')') {\n\tint n = s.size();\n\tvector<int> res(n,\
    \ -1);\n\tstack<int> st;\n\tfor (int i = 0; i < n; ++i) {\n\t\tif (s[i] == c1)\
    \ {\n\t\t\tst.push(i);\n\t\t} else if (s[i] == c2) {\n\t\t\tassert(st.size());\n\
    \t\t\tres[st.top()] = i;\n\t\t\tst.pop();\n\t\t}\n\t}\n\treturn res;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <string>\n#include <stack>\n#include\
    \ <utility>\n#include <cassert>\nusing namespace std;\n\nsize_t BracketsPos(const\
    \ string& s, size_t pos, char c1 = '(', char c2 = ')') {\n\tassert(s[pos] == c1);\n\
    \tint p = 1;\n\tfor (size_t i = pos + 1; i < s.size(); ++i) {\n\t\tif (s[i] ==\
    \ c1) {\n\t\t\tp++;\n\t\t} else if (s[i] == c2) {\n\t\t\tif (p == 1) {\n\t\t\t\
    \treturn i;\n\t\t\t}\n\t\t\tp--;\n\t\t}\n\t}\n\treturn string::npos;\n}\n\npair<size_t,\
    \ size_t> BracketsPos2(const string& s, size_t pos, char c1 = '(',\n         \
    \                         char c2 = ')') {\n\tsize_t l = s.find(c1, pos);\n\t\
    if (l != string::npos) {\n\t\tsize_t r = BracketsPos(s, l, c1, c2);\n\t\tif (r\
    \ != string::npos) {\n\t\t\treturn {l, r};\n\t\t} else {\n\t\t\treturn {string::npos,\
    \ string::npos};\n\t\t}\n\t} else {\n\t\treturn {string::npos, string::npos};\n\
    \t}\n}\n\nvector<int> AllBracketsPos(const string& s, char c1 = '(', char c2 =\
    \ ')') {\n\tint n = s.size();\n\tvector<int> res(n, -1);\n\tstack<int> st;\n\t\
    for (int i = 0; i < n; ++i) {\n\t\tif (s[i] == c1) {\n\t\t\tst.push(i);\n\t\t\
    } else if (s[i] == c2) {\n\t\t\tassert(st.size());\n\t\t\tres[st.top()] = i;\n\
    \t\t\tst.pop();\n\t\t}\n\t}\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/BracketsPos.cpp
  requiredBy: []
  timestamp: '2020-11-20 21:19:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/BracketsPos.cpp
layout: document
redirect_from:
- /library/Utility/BracketsPos.cpp
- /library/Utility/BracketsPos.cpp.html
title: Utility/BracketsPos.cpp
---
