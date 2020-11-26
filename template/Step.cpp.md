---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/template.cpp
    title: template/template.cpp
  - icon: ':warning:'
    path: template/template_no_Ruby.cpp
    title: template/template_no_Ruby.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/Step.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\ntemplate <class T> struct Step {\n\tusing value_type = T;\n\n\tclass\
    \ iterator {\n\t\tvalue_type a, b, c;\n\n\tpublic:\n\t\tconstexpr iterator() :\
    \ a(value_type()), b(value_type()), c(value_type()) {}\n\t\tconstexpr iterator(value_type\
    \ _b, value_type _c, value_type _s)\n\t\t    : a(_b), b(_c), c(_s) {}\n\t\tconstexpr\
    \ iterator& operator++() {\n\t\t\t--b;\n\t\t\ta += c;\n\t\t\treturn *this;\n\t\
    \t}\n\t\tconstexpr iterator operator++(int) {\n\t\t\titerator tmp = *this;\n\t\
    \t\t--b;\n\t\t\ta += c;\n\t\t\treturn tmp;\n\t\t}\n\t\tconstexpr const value_type&\
    \ operator*() const {\n\t\t\treturn a;\n\t\t}\n\t\tconstexpr const value_type*\
    \ operator->() const {\n\t\t\treturn &a;\n\t\t}\n\t\tconstexpr bool operator==(const\
    \ iterator& i) const {\n\t\t\treturn b == i.b;\n\t\t}\n\t\tconstexpr bool operator!=(const\
    \ iterator& i) const {\n\t\t\treturn !(b == i.b);\n\t\t}\n\t\tconstexpr value_type\
    \ start() const {\n\t\t\treturn a;\n\t\t}\n\t\tconstexpr value_type size() const\
    \ {\n\t\t\treturn b;\n\t\t}\n\t\tconstexpr value_type step() const {\n\t\t\treturn\
    \ c;\n\t\t}\n\t};\n\tconstexpr Step(value_type b, value_type c, value_type s)\
    \ : be(b, c, s) {}\n\tconstexpr iterator begin() const {\n\t\treturn be;\n\t}\n\
    \tconstexpr iterator end() const {\n\t\treturn en;\n\t}\n\tconstexpr value_type\
    \ start() const {\n\t\treturn be.start();\n\t}\n\tconstexpr value_type size()\
    \ const {\n\t\treturn be.size();\n\t}\n\tconstexpr value_type step() const {\n\
    \t\treturn be.step();\n\t}\n\tconstexpr value_type sum() const {\n\t\treturn start()\
    \ * size() + step() * (size() * (size() - 1) / 2);\n\t}\n\toperator vector<value_type>()\
    \ const {\n\t\treturn to_a();\n\t}\n\tauto to_a() const {\n\t\tvector<value_type>\
    \ result;\n\t\tresult.reserve(size());\n\t\tfor (auto i : *this) {\n\t\t\tresult.push_back(i);\n\
    \t\t}\n\t\treturn result;\n\t}\n\nprivate:\n\titerator be, en;\n};\ntemplate <class\
    \ T> constexpr auto step(T a) {\n\treturn Step<T>(0, a, 1);\n}\ntemplate <class\
    \ T> constexpr auto step(T a, T b) {\n\treturn Step<T>(a, b - a, 1);\n}\ntemplate\
    \ <class T> constexpr auto step(T a, T b, T c) {\n\treturn Step<T>(a, a < b ?\
    \ (b - a - 1) / c + 1 : 0, c);\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\ntemplate <class\
    \ T> struct Step {\n\tusing value_type = T;\n\n\tclass iterator {\n\t\tvalue_type\
    \ a, b, c;\n\n\tpublic:\n\t\tconstexpr iterator() : a(value_type()), b(value_type()),\
    \ c(value_type()) {}\n\t\tconstexpr iterator(value_type _b, value_type _c, value_type\
    \ _s)\n\t\t    : a(_b), b(_c), c(_s) {}\n\t\tconstexpr iterator& operator++()\
    \ {\n\t\t\t--b;\n\t\t\ta += c;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr iterator\
    \ operator++(int) {\n\t\t\titerator tmp = *this;\n\t\t\t--b;\n\t\t\ta += c;\n\t\
    \t\treturn tmp;\n\t\t}\n\t\tconstexpr const value_type& operator*() const {\n\t\
    \t\treturn a;\n\t\t}\n\t\tconstexpr const value_type* operator->() const {\n\t\
    \t\treturn &a;\n\t\t}\n\t\tconstexpr bool operator==(const iterator& i) const\
    \ {\n\t\t\treturn b == i.b;\n\t\t}\n\t\tconstexpr bool operator!=(const iterator&\
    \ i) const {\n\t\t\treturn !(b == i.b);\n\t\t}\n\t\tconstexpr value_type start()\
    \ const {\n\t\t\treturn a;\n\t\t}\n\t\tconstexpr value_type size() const {\n\t\
    \t\treturn b;\n\t\t}\n\t\tconstexpr value_type step() const {\n\t\t\treturn c;\n\
    \t\t}\n\t};\n\tconstexpr Step(value_type b, value_type c, value_type s) : be(b,\
    \ c, s) {}\n\tconstexpr iterator begin() const {\n\t\treturn be;\n\t}\n\tconstexpr\
    \ iterator end() const {\n\t\treturn en;\n\t}\n\tconstexpr value_type start()\
    \ const {\n\t\treturn be.start();\n\t}\n\tconstexpr value_type size() const {\n\
    \t\treturn be.size();\n\t}\n\tconstexpr value_type step() const {\n\t\treturn\
    \ be.step();\n\t}\n\tconstexpr value_type sum() const {\n\t\treturn start() *\
    \ size() + step() * (size() * (size() - 1) / 2);\n\t}\n\toperator vector<value_type>()\
    \ const {\n\t\treturn to_a();\n\t}\n\tauto to_a() const {\n\t\tvector<value_type>\
    \ result;\n\t\tresult.reserve(size());\n\t\tfor (auto i : *this) {\n\t\t\tresult.push_back(i);\n\
    \t\t}\n\t\treturn result;\n\t}\n\nprivate:\n\titerator be, en;\n};\ntemplate <class\
    \ T> constexpr auto step(T a) {\n\treturn Step<T>(0, a, 1);\n}\ntemplate <class\
    \ T> constexpr auto step(T a, T b) {\n\treturn Step<T>(a, b - a, 1);\n}\ntemplate\
    \ <class T> constexpr auto step(T a, T b, T c) {\n\treturn Step<T>(a, a < b ?\
    \ (b - a - 1) / c + 1 : 0, c);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: template/Step.cpp
  requiredBy:
  - template/template.cpp
  - template/template_no_Ruby.cpp
  timestamp: '2020-11-24 22:24:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/Step.cpp
layout: document
redirect_from:
- /library/template/Step.cpp
- /library/template/Step.cpp.html
title: template/Step.cpp
---
