---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/Compress.cpp\"\n#include <vector>\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> class Compress\
    \ {\n\tvector<T> v;\n\tbool flag = false;\n\npublic:\n\tCompress() {}\n\ttemplate\
    \ <class U> Compress(const U& a) {\n\t\tadd(a);\n\t}\n\tCompress& add(const T&\
    \ a) {\n\t\tflag = false;\n\t\tv.push_back(a);\n\t\treturn *this;\n\t}\n\ttemplate\
    \ <class U> Compress& add(const vector<U>& a) {\n\t\tflag = false;\n\t\tfor (const\
    \ auto& i : a) add(i);\n\t\treturn *this;\n\t}\n\ttemplate <class U> Compress&\
    \ add(const initializer_list<U>& a) {\n\t\tflag = false;\n\t\tfor (const auto&\
    \ v : a) add(v);\n\t\treturn *this;\n\t}\n\ttemplate <class U> Compress& operator<<(const\
    \ U& a) {\n\t\tadd(a);\n\t\treturn *this;\n\t}\n\tvoid build() {\n\t\tsort(v.begin(),\
    \ v.end());\n\t\tv.erase(unique(v.begin(), v.end()), v.end());\n\t\tflag = true;\n\
    \t}\n\tint operator()(const T& x) const {\n\t\tassert(flag);\n\t\treturn lower_bound(v.begin(),\
    \ v.end(), x) - v.begin();\n\t}\n\tvector<int> operator()(const vector<T>& x)\
    \ const {\n\t\tassert(flag);\n\t\tvector<int> res;\n\t\tres.reserve(x.size());\n\
    \t\tfor (const T& i : x)\n\t\t\tres.push_back(lower_bound(v.begin(), v.end(),\
    \ i) - v.begin());\n\t\treturn res;\n\t}\n\tint size() const {\n\t\tassert(flag);\n\
    \t\treturn v.size();\n\t}\n\tconst vector<T>& operator*() const {\n\t\tassert(flag);\n\
    \t\treturn v;\n\t}\n\tconst T& operator[](int i) const {\n\t\tassert(flag);\n\t\
    \treturn v[i];\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    using namespace std;\n\ntemplate <class T> class Compress {\n\tvector<T> v;\n\t\
    bool flag = false;\n\npublic:\n\tCompress() {}\n\ttemplate <class U> Compress(const\
    \ U& a) {\n\t\tadd(a);\n\t}\n\tCompress& add(const T& a) {\n\t\tflag = false;\n\
    \t\tv.push_back(a);\n\t\treturn *this;\n\t}\n\ttemplate <class U> Compress& add(const\
    \ vector<U>& a) {\n\t\tflag = false;\n\t\tfor (const auto& i : a) add(i);\n\t\t\
    return *this;\n\t}\n\ttemplate <class U> Compress& add(const initializer_list<U>&\
    \ a) {\n\t\tflag = false;\n\t\tfor (const auto& v : a) add(v);\n\t\treturn *this;\n\
    \t}\n\ttemplate <class U> Compress& operator<<(const U& a) {\n\t\tadd(a);\n\t\t\
    return *this;\n\t}\n\tvoid build() {\n\t\tsort(v.begin(), v.end());\n\t\tv.erase(unique(v.begin(),\
    \ v.end()), v.end());\n\t\tflag = true;\n\t}\n\tint operator()(const T& x) const\
    \ {\n\t\tassert(flag);\n\t\treturn lower_bound(v.begin(), v.end(), x) - v.begin();\n\
    \t}\n\tvector<int> operator()(const vector<T>& x) const {\n\t\tassert(flag);\n\
    \t\tvector<int> res;\n\t\tres.reserve(x.size());\n\t\tfor (const T& i : x)\n\t\
    \t\tres.push_back(lower_bound(v.begin(), v.end(), i) - v.begin());\n\t\treturn\
    \ res;\n\t}\n\tint size() const {\n\t\tassert(flag);\n\t\treturn v.size();\n\t\
    }\n\tconst vector<T>& operator*() const {\n\t\tassert(flag);\n\t\treturn v;\n\t\
    }\n\tconst T& operator[](int i) const {\n\t\tassert(flag);\n\t\treturn v[i];\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Compress.cpp
  requiredBy: []
  timestamp: '2020-11-20 21:19:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/Compress.cpp
layout: document
redirect_from:
- /library/Utility/Compress.cpp
- /library/Utility/Compress.cpp.html
title: Utility/Compress.cpp
---
