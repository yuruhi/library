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
  bundledCode: "#line 2 \"math/Radix.cpp\"\n#include <vector>\n#include <string>\n\
    #include <map>\n#include <algorithm>\n#include <cassert>\n\nclass Radix {\npublic:\n\
    \tusing value_type = long long;\n\nprivate:\n\tstatic inline std::string chars;\n\
    \tstatic inline std::map<char, int> char_to_int;\n\npublic:\n\tstatic void Init(std::string\
    \ s = \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\") {\n\t\tchars = s;\n\t\tfor (std::size_t\
    \ i = 0; i < chars.size(); i++) {\n\t\t\tchar_to_int[chars[i]] = i;\n\t\t}\n\t\
    }\n\t// value(R) -> result(10)\n\tstatic value_type to10(const std::string& value,\
    \ int R) {\n\t\tvalue_type result = 0, p = 1;\n\t\tfor (int i = value.size() -\
    \ 1; i >= 0; --i) {\n\t\t\tassert(char_to_int.count(value[i]));\n\t\t\tresult\
    \ += char_to_int[value[i]] * p;\n\t\t\tp *= R;\n\t\t}\n\t\treturn result;\n\t\
    }\n\t// value(10) -> result(N)\n\tstatic std::string toN(value_type value, int\
    \ N) {\n\t\tstd::string result;\n\t\tvalue_type m = value;\n\t\tdo {\n\t\t\tresult\
    \ += chars[m % N];\n\t\t\tm /= N;\n\t\t} while (m);\n\t\tstd::reverse(result.begin(),\
    \ result.end());\n\t\treturn result;\n\t}\n\t// value(R) -> result(N)\n\tstatic\
    \ std::string toN(const std::string& value, int R, int N) {\n\t\treturn toN(to10(value,\
    \ R), N);\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <string>\n#include <map>\n#include\
    \ <algorithm>\n#include <cassert>\n\nclass Radix {\npublic:\n\tusing value_type\
    \ = long long;\n\nprivate:\n\tstatic inline std::string chars;\n\tstatic inline\
    \ std::map<char, int> char_to_int;\n\npublic:\n\tstatic void Init(std::string\
    \ s = \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\") {\n\t\tchars = s;\n\t\tfor (std::size_t\
    \ i = 0; i < chars.size(); i++) {\n\t\t\tchar_to_int[chars[i]] = i;\n\t\t}\n\t\
    }\n\t// value(R) -> result(10)\n\tstatic value_type to10(const std::string& value,\
    \ int R) {\n\t\tvalue_type result = 0, p = 1;\n\t\tfor (int i = value.size() -\
    \ 1; i >= 0; --i) {\n\t\t\tassert(char_to_int.count(value[i]));\n\t\t\tresult\
    \ += char_to_int[value[i]] * p;\n\t\t\tp *= R;\n\t\t}\n\t\treturn result;\n\t\
    }\n\t// value(10) -> result(N)\n\tstatic std::string toN(value_type value, int\
    \ N) {\n\t\tstd::string result;\n\t\tvalue_type m = value;\n\t\tdo {\n\t\t\tresult\
    \ += chars[m % N];\n\t\t\tm /= N;\n\t\t} while (m);\n\t\tstd::reverse(result.begin(),\
    \ result.end());\n\t\treturn result;\n\t}\n\t// value(R) -> result(N)\n\tstatic\
    \ std::string toN(const std::string& value, int R, int N) {\n\t\treturn toN(to10(value,\
    \ R), N);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/Radix.cpp
  requiredBy: []
  timestamp: '2021-03-21 09:59:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Radix.cpp
layout: document
redirect_from:
- /library/math/Radix.cpp
- /library/math/Radix.cpp.html
title: math/Radix.cpp
---
