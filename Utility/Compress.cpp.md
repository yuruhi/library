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
  bundledCode: "#line 2 \"Utility/Compress.cpp\"\n#include <vector>\n#include <algorithm>\n\
    #include <cassert>\n\ntemplate <class T> class Compress {\npublic:\n\tusing value_type\
    \ = T;\n\nprivate:\n\tstd::vector<value_type> v;\n\tbool flag = false;\n\npublic:\n\
    \tCompress() {}\n\ttemplate <class U> Compress(const U& a) {\n\t\tadd(a);\n\t\
    }\n\tCompress& add(const value_type& a) {\n\t\tflag = false;\n\t\tv.push_back(a);\n\
    \t\treturn *this;\n\t}\n\ttemplate <class U> Compress& add(const std::vector<U>&\
    \ a) {\n\t\tflag = false;\n\t\tfor (const auto& i : a) add(i);\n\t\treturn *this;\n\
    \t}\n\ttemplate <class U> Compress& add(const std::initializer_list<U>& a) {\n\
    \t\tflag = false;\n\t\tfor (const auto& v : a) add(v);\n\t\treturn *this;\n\t\
    }\n\ttemplate <class U> Compress& operator<<(const U& a) {\n\t\tadd(a);\n\t\t\
    return *this;\n\t}\n\tvoid build() {\n\t\tstd::sort(v.begin(), v.end());\n\t\t\
    v.erase(unique(v.begin(), v.end()), v.end());\n\t\tflag = true;\n\t}\n\tint operator()(const\
    \ value_type& x) const {\n\t\tassert(flag);\n\t\treturn std::lower_bound(v.begin(),\
    \ v.end(), x) - v.begin();\n\t}\n\tstd::vector<int> operator()(const std::vector<value_type>&\
    \ x) const {\n\t\tassert(flag);\n\t\tstd::vector<int> result;\n\t\tresult.reserve(x.size());\n\
    \t\tfor (const value_type& i : x) {\n\t\t\tresult.push_back(std::lower_bound(v.begin(),\
    \ v.end(), i) - v.begin());\n\t\t}\n\t\treturn result;\n\t}\n\tint lower(const\
    \ value_type& x) const {\n\t\tassert(flag);\n\t\treturn std::lower_bound(v.begin(),\
    \ v.end(), x) - v.begin();\n\t}\n\tint upper(const value_type& x) const {\n\t\t\
    assert(flag);\n\t\treturn std::upper_bound(v.begin(), v.end(), x) - v.begin();\n\
    \t}\n\tint size() const {\n\t\tassert(flag);\n\t\treturn v.size();\n\t}\n\tconst\
    \ std::vector<value_type>& operator*() const {\n\t\tassert(flag);\n\t\treturn\
    \ v;\n\t}\n\tconst value_type& operator[](int i) const {\n\t\tassert(flag);\n\t\
    \treturn v[i];\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    \ntemplate <class T> class Compress {\npublic:\n\tusing value_type = T;\n\nprivate:\n\
    \tstd::vector<value_type> v;\n\tbool flag = false;\n\npublic:\n\tCompress() {}\n\
    \ttemplate <class U> Compress(const U& a) {\n\t\tadd(a);\n\t}\n\tCompress& add(const\
    \ value_type& a) {\n\t\tflag = false;\n\t\tv.push_back(a);\n\t\treturn *this;\n\
    \t}\n\ttemplate <class U> Compress& add(const std::vector<U>& a) {\n\t\tflag =\
    \ false;\n\t\tfor (const auto& i : a) add(i);\n\t\treturn *this;\n\t}\n\ttemplate\
    \ <class U> Compress& add(const std::initializer_list<U>& a) {\n\t\tflag = false;\n\
    \t\tfor (const auto& v : a) add(v);\n\t\treturn *this;\n\t}\n\ttemplate <class\
    \ U> Compress& operator<<(const U& a) {\n\t\tadd(a);\n\t\treturn *this;\n\t}\n\
    \tvoid build() {\n\t\tstd::sort(v.begin(), v.end());\n\t\tv.erase(unique(v.begin(),\
    \ v.end()), v.end());\n\t\tflag = true;\n\t}\n\tint operator()(const value_type&\
    \ x) const {\n\t\tassert(flag);\n\t\treturn std::lower_bound(v.begin(), v.end(),\
    \ x) - v.begin();\n\t}\n\tstd::vector<int> operator()(const std::vector<value_type>&\
    \ x) const {\n\t\tassert(flag);\n\t\tstd::vector<int> result;\n\t\tresult.reserve(x.size());\n\
    \t\tfor (const value_type& i : x) {\n\t\t\tresult.push_back(std::lower_bound(v.begin(),\
    \ v.end(), i) - v.begin());\n\t\t}\n\t\treturn result;\n\t}\n\tint lower(const\
    \ value_type& x) const {\n\t\tassert(flag);\n\t\treturn std::lower_bound(v.begin(),\
    \ v.end(), x) - v.begin();\n\t}\n\tint upper(const value_type& x) const {\n\t\t\
    assert(flag);\n\t\treturn std::upper_bound(v.begin(), v.end(), x) - v.begin();\n\
    \t}\n\tint size() const {\n\t\tassert(flag);\n\t\treturn v.size();\n\t}\n\tconst\
    \ std::vector<value_type>& operator*() const {\n\t\tassert(flag);\n\t\treturn\
    \ v;\n\t}\n\tconst value_type& operator[](int i) const {\n\t\tassert(flag);\n\t\
    \treturn v[i];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Compress.cpp
  requiredBy: []
  timestamp: '2021-04-06 14:24:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/Compress.cpp
layout: document
redirect_from:
- /library/Utility/Compress.cpp
- /library/Utility/Compress.cpp.html
title: Utility/Compress.cpp
---
