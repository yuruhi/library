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
  bundledCode: "#line 2 \"Utility/stringOperation.cpp\"\n#include <vector>\n#include\
    \ <string>\n\nvoid replace_all(std::string& s, const std::string& t, const std::string&\
    \ u) {\n\tstd::size_t pos = s.find(t);\n\twhile (pos != std::string::npos) {\n\
    \t\ts.replace(pos, t.size(), u);\n\t\tpos = s.find(t, pos + u.size());\n\t}\n\
    }\nstd::string replaced_all(std::string s, const std::string& t, const std::string&\
    \ u) {\n\treplace_all(s, t, u);\n\treturn s;\n}\nstd::vector<std::string> Split(std::string\
    \ s, const std::string& t) {\n\tstd::vector<std::string> result;\n\tfor (std::size_t\
    \ p = 0; (p = s.find(t)) != std::string::npos;) {\n\t\tresult.emplace_back(s.begin(),\
    \ s.begin() + p);\n\t\ts = s.substr(p + t.size());\n\t}\n\tresult.push_back(s);\n\
    \treturn result;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <string>\n\nvoid replace_all(std::string&\
    \ s, const std::string& t, const std::string& u) {\n\tstd::size_t pos = s.find(t);\n\
    \twhile (pos != std::string::npos) {\n\t\ts.replace(pos, t.size(), u);\n\t\tpos\
    \ = s.find(t, pos + u.size());\n\t}\n}\nstd::string replaced_all(std::string s,\
    \ const std::string& t, const std::string& u) {\n\treplace_all(s, t, u);\n\treturn\
    \ s;\n}\nstd::vector<std::string> Split(std::string s, const std::string& t) {\n\
    \tstd::vector<std::string> result;\n\tfor (std::size_t p = 0; (p = s.find(t))\
    \ != std::string::npos;) {\n\t\tresult.emplace_back(s.begin(), s.begin() + p);\n\
    \t\ts = s.substr(p + t.size());\n\t}\n\tresult.push_back(s);\n\treturn result;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/stringOperation.cpp
  requiredBy: []
  timestamp: '2021-04-06 14:24:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/stringOperation.cpp
layout: document
redirect_from:
- /library/Utility/stringOperation.cpp
- /library/Utility/stringOperation.cpp.html
title: Utility/stringOperation.cpp
---
