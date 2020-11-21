---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/Radix.cpp\"\n#include <vector>\n#include <string>\n\
    #include <map>\n#include <algorithm>\n#include <cassert>\nusing namespace std;\n\
    \nclass Radix {\npublic:\n\tusing value_type = long long;\n\nprivate:\n\tstatic\
    \ string Str;\n\tstatic map<char, int> Map;\n\npublic:\n\tstatic void Init(string\
    \ s = \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\") {\n\t\tStr = s;\n\t\tfor (int\
    \ i = 0; i < (int)Str.size(); i++) {\n\t\t\tMap[Str[i]] = i;\n\t\t}\n\t}\n\t//\
    \ value(R) -> res(10)\n\tstatic value_type to10(const string& value, int R) {\n\
    \t\tvalue_type res = 0, p = 1;\n\t\tfor (int i = (int)value.size() - 1; i >= 0;\
    \ --i) {\n\t\t\tassert(Map.count(value[i]));\n\t\t\tres += Map[value[i]] * p;\n\
    \t\t\tp *= R;\n\t\t}\n\t\treturn res;\n\t}\n\t// value(10) -> res(N)\n\tstatic\
    \ string toN(value_type value, int N) {\n\t\tstring res;\n\t\tvalue_type m = value;\n\
    \t\tdo {\n\t\t\tres += Str[m % N];\n\t\t\tm /= N;\n\t\t} while (m);\n\t\treverse(res.begin(),\
    \ res.end());\n\t\treturn res;\n\t}\n\t// value(R) -> res(N)\n\tstatic string\
    \ toN(const string& value, int R, int N) {\n\t\treturn toN(to10(value, R), N);\n\
    \t}\n};\nstring Radix::Str;\nmap<char, int> Radix::Map;\n"
  code: "#pragma once\n#include <vector>\n#include <string>\n#include <map>\n#include\
    \ <algorithm>\n#include <cassert>\nusing namespace std;\n\nclass Radix {\npublic:\n\
    \tusing value_type = long long;\n\nprivate:\n\tstatic string Str;\n\tstatic map<char,\
    \ int> Map;\n\npublic:\n\tstatic void Init(string s = \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\"\
    ) {\n\t\tStr = s;\n\t\tfor (int i = 0; i < (int)Str.size(); i++) {\n\t\t\tMap[Str[i]]\
    \ = i;\n\t\t}\n\t}\n\t// value(R) -> res(10)\n\tstatic value_type to10(const string&\
    \ value, int R) {\n\t\tvalue_type res = 0, p = 1;\n\t\tfor (int i = (int)value.size()\
    \ - 1; i >= 0; --i) {\n\t\t\tassert(Map.count(value[i]));\n\t\t\tres += Map[value[i]]\
    \ * p;\n\t\t\tp *= R;\n\t\t}\n\t\treturn res;\n\t}\n\t// value(10) -> res(N)\n\
    \tstatic string toN(value_type value, int N) {\n\t\tstring res;\n\t\tvalue_type\
    \ m = value;\n\t\tdo {\n\t\t\tres += Str[m % N];\n\t\t\tm /= N;\n\t\t} while (m);\n\
    \t\treverse(res.begin(), res.end());\n\t\treturn res;\n\t}\n\t// value(R) -> res(N)\n\
    \tstatic string toN(const string& value, int R, int N) {\n\t\treturn toN(to10(value,\
    \ R), N);\n\t}\n};\nstring Radix::Str;\nmap<char, int> Radix::Map;\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Radix.cpp
  requiredBy: []
  timestamp: '2020-11-21 14:30:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Radix.cpp
layout: document
redirect_from:
- /library/Math/Radix.cpp
- /library/Math/Radix.cpp.html
title: Math/Radix.cpp
---
