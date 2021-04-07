---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/BracketsPos.cpp\"\n#include <vector>\n#include <string>\n\
    #include <stack>\n#include <utility>\n#include <cassert>\n\nstd::size_t BracketsPos(const\
    \ std::string& s, std::size_t pos, char left = '(',\n                        char\
    \ right = ')') {\n\tassert(s[pos] == left);\n\tint p = 1;\n\tfor (std::size_t\
    \ i = pos + 1; i < s.size(); ++i) {\n\t\tif (s[i] == left) {\n\t\t\tp++;\n\t\t\
    } else if (s[i] == right) {\n\t\t\tif (p == 1) {\n\t\t\t\treturn i;\n\t\t\t}\n\
    \t\t\tp--;\n\t\t}\n\t}\n\treturn std::string::npos;\n}\n\nstd::pair<std::size_t,\
    \ std::size_t> BracketsPosPair(const std::string& s, std::size_t pos,\n      \
    \                                              char left = '(', char right = ')')\
    \ {\n\tstd::size_t l = s.find(left, pos);\n\tif (l != std::string::npos) {\n\t\
    \tstd::size_t r = BracketsPos(s, l, left, right);\n\t\tif (r != std::string::npos)\
    \ {\n\t\t\treturn {l, r};\n\t\t} else {\n\t\t\treturn {std::string::npos, std::string::npos};\n\
    \t\t}\n\t} else {\n\t\treturn {std::string::npos, std::string::npos};\n\t}\n}\n\
    \nstd::vector<int> AllBracketsPos(const std::string& s, char left = '(', char\
    \ right = ')') {\n\tint n = s.size();\n\tstd::vector<int> result(n, -1);\n\tstd::stack<int>\
    \ st;\n\tfor (int i = 0; i < n; ++i) {\n\t\tif (s[i] == left) {\n\t\t\tst.push(i);\n\
    \t\t} else if (s[i] == right) {\n\t\t\tassert(st.size());\n\t\t\tresult[st.top()]\
    \ = i;\n\t\t\tst.pop();\n\t\t}\n\t}\n\treturn result;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <string>\n#include <stack>\n#include\
    \ <utility>\n#include <cassert>\n\nstd::size_t BracketsPos(const std::string&\
    \ s, std::size_t pos, char left = '(',\n                        char right = ')')\
    \ {\n\tassert(s[pos] == left);\n\tint p = 1;\n\tfor (std::size_t i = pos + 1;\
    \ i < s.size(); ++i) {\n\t\tif (s[i] == left) {\n\t\t\tp++;\n\t\t} else if (s[i]\
    \ == right) {\n\t\t\tif (p == 1) {\n\t\t\t\treturn i;\n\t\t\t}\n\t\t\tp--;\n\t\
    \t}\n\t}\n\treturn std::string::npos;\n}\n\nstd::pair<std::size_t, std::size_t>\
    \ BracketsPosPair(const std::string& s, std::size_t pos,\n                   \
    \                                 char left = '(', char right = ')') {\n\tstd::size_t\
    \ l = s.find(left, pos);\n\tif (l != std::string::npos) {\n\t\tstd::size_t r =\
    \ BracketsPos(s, l, left, right);\n\t\tif (r != std::string::npos) {\n\t\t\treturn\
    \ {l, r};\n\t\t} else {\n\t\t\treturn {std::string::npos, std::string::npos};\n\
    \t\t}\n\t} else {\n\t\treturn {std::string::npos, std::string::npos};\n\t}\n}\n\
    \nstd::vector<int> AllBracketsPos(const std::string& s, char left = '(', char\
    \ right = ')') {\n\tint n = s.size();\n\tstd::vector<int> result(n, -1);\n\tstd::stack<int>\
    \ st;\n\tfor (int i = 0; i < n; ++i) {\n\t\tif (s[i] == left) {\n\t\t\tst.push(i);\n\
    \t\t} else if (s[i] == right) {\n\t\t\tassert(st.size());\n\t\t\tresult[st.top()]\
    \ = i;\n\t\t\tst.pop();\n\t\t}\n\t}\n\treturn result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/BracketsPos.cpp
  requiredBy: []
  timestamp: '2021-04-06 14:30:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/BracketsPos.cpp
layout: document
redirect_from:
- /library/Utility/BracketsPos.cpp
- /library/Utility/BracketsPos.cpp.html
title: Utility/BracketsPos.cpp
---
