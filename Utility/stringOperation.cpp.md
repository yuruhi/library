---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/stringOperation.cpp\"\n#include <vector>\n#include\
    \ <string>\nusing namespace std;\n\nvoid replace_all(string& s, const string&\
    \ t, const string& u) {\n\tsize_t pos = s.find(t);\n\twhile (pos != string::npos)\
    \ {\n\t\ts.replace(pos, t.size(), u);\n\t\tpos = s.find(t, pos + u.size());\n\t\
    }\n}\nstring replaced_all(string s, const string& t, const string& u) {\n\treplace_all(s,\
    \ t, u);\n\treturn s;\n}\nvector<string> Split(string s, const string& t) {\n\t\
    vector<string> res;\n\tfor (size_t p = 0; (p = s.find(t)) != string::npos;) {\n\
    \t\tres.emplace_back(s.begin(), s.begin() + p);\n\t\ts = s.substr(p + t.size());\n\
    \t}\n\tres.push_back(s);\n\treturn res;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <string>\nusing namespace std;\n\
    \nvoid replace_all(string& s, const string& t, const string& u) {\n\tsize_t pos\
    \ = s.find(t);\n\twhile (pos != string::npos) {\n\t\ts.replace(pos, t.size(),\
    \ u);\n\t\tpos = s.find(t, pos + u.size());\n\t}\n}\nstring replaced_all(string\
    \ s, const string& t, const string& u) {\n\treplace_all(s, t, u);\n\treturn s;\n\
    }\nvector<string> Split(string s, const string& t) {\n\tvector<string> res;\n\t\
    for (size_t p = 0; (p = s.find(t)) != string::npos;) {\n\t\tres.emplace_back(s.begin(),\
    \ s.begin() + p);\n\t\ts = s.substr(p + t.size());\n\t}\n\tres.push_back(s);\n\
    \treturn res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Utility/stringOperation.cpp
  requiredBy: []
  timestamp: '2020-10-06 16:32:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/stringOperation.cpp
layout: document
redirect_from:
- /library/Utility/stringOperation.cpp
- /library/Utility/stringOperation.cpp.html
title: Utility/stringOperation.cpp
---
