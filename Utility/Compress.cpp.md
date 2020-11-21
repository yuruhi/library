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
    \ {\npublic:\n\tusing value_type = T;\n\nprivate:\n\tvector<value_type> v;\n\t\
    bool flag = false;\n\npublic:\n\tCompress() {}\n\ttemplate <class U> Compress(const\
    \ U& a) {\n\t\tadd(a);\n\t}\n\tCompress& add(const value_type& a) {\n\t\tflag\
    \ = false;\n\t\tv.push_back(a);\n\t\treturn *this;\n\t}\n\ttemplate <class U>\
    \ Compress& add(const vector<U>& a) {\n\t\tflag = false;\n\t\tfor (const auto&\
    \ i : a) add(i);\n\t\treturn *this;\n\t}\n\ttemplate <class U> Compress& add(const\
    \ initializer_list<U>& a) {\n\t\tflag = false;\n\t\tfor (const auto& v : a) add(v);\n\
    \t\treturn *this;\n\t}\n\ttemplate <class U> Compress& operator<<(const U& a)\
    \ {\n\t\tadd(a);\n\t\treturn *this;\n\t}\n\tvoid build() {\n\t\tsort(v.begin(),\
    \ v.end());\n\t\tv.erase(unique(v.begin(), v.end()), v.end());\n\t\tflag = true;\n\
    \t}\n\tint operator()(const value_type& x) const {\n\t\tassert(flag);\n\t\treturn\
    \ lower_bound(v.begin(), v.end(), x) - v.begin();\n\t}\n\tvector<int> operator()(const\
    \ vector<value_type>& x) const {\n\t\tassert(flag);\n\t\tvector<int> res;\n\t\t\
    res.reserve(x.size());\n\t\tfor (const value_type& i : x)\n\t\t\tres.push_back(lower_bound(v.begin(),\
    \ v.end(), i) - v.begin());\n\t\treturn res;\n\t}\n\tint size() const {\n\t\t\
    assert(flag);\n\t\treturn v.size();\n\t}\n\tconst vector<value_type>& operator*()\
    \ const {\n\t\tassert(flag);\n\t\treturn v;\n\t}\n\tconst value_type& operator[](int\
    \ i) const {\n\t\tassert(flag);\n\t\treturn v[i];\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    using namespace std;\n\ntemplate <class T> class Compress {\npublic:\n\tusing\
    \ value_type = T;\n\nprivate:\n\tvector<value_type> v;\n\tbool flag = false;\n\
    \npublic:\n\tCompress() {}\n\ttemplate <class U> Compress(const U& a) {\n\t\t\
    add(a);\n\t}\n\tCompress& add(const value_type& a) {\n\t\tflag = false;\n\t\t\
    v.push_back(a);\n\t\treturn *this;\n\t}\n\ttemplate <class U> Compress& add(const\
    \ vector<U>& a) {\n\t\tflag = false;\n\t\tfor (const auto& i : a) add(i);\n\t\t\
    return *this;\n\t}\n\ttemplate <class U> Compress& add(const initializer_list<U>&\
    \ a) {\n\t\tflag = false;\n\t\tfor (const auto& v : a) add(v);\n\t\treturn *this;\n\
    \t}\n\ttemplate <class U> Compress& operator<<(const U& a) {\n\t\tadd(a);\n\t\t\
    return *this;\n\t}\n\tvoid build() {\n\t\tsort(v.begin(), v.end());\n\t\tv.erase(unique(v.begin(),\
    \ v.end()), v.end());\n\t\tflag = true;\n\t}\n\tint operator()(const value_type&\
    \ x) const {\n\t\tassert(flag);\n\t\treturn lower_bound(v.begin(), v.end(), x)\
    \ - v.begin();\n\t}\n\tvector<int> operator()(const vector<value_type>& x) const\
    \ {\n\t\tassert(flag);\n\t\tvector<int> res;\n\t\tres.reserve(x.size());\n\t\t\
    for (const value_type& i : x)\n\t\t\tres.push_back(lower_bound(v.begin(), v.end(),\
    \ i) - v.begin());\n\t\treturn res;\n\t}\n\tint size() const {\n\t\tassert(flag);\n\
    \t\treturn v.size();\n\t}\n\tconst vector<value_type>& operator*() const {\n\t\
    \tassert(flag);\n\t\treturn v;\n\t}\n\tconst value_type& operator[](int i) const\
    \ {\n\t\tassert(flag);\n\t\treturn v[i];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Compress.cpp
  requiredBy: []
  timestamp: '2020-11-21 14:30:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/Compress.cpp
layout: document
redirect_from:
- /library/Utility/Compress.cpp
- /library/Utility/Compress.cpp.html
title: Utility/Compress.cpp
---
