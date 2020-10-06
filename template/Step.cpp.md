---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/Step.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\ntemplate <class T> struct Step {\n\tclass It {\n\t\tT a, b, c;\n\n\t\
    public:\n\t\tconstexpr It() : a(T()), b(T()), c(T()) {}\n\t\tconstexpr It(T _b,\
    \ T _c, T _s) : a(_b), b(_c), c(_s) {}\n\t\tconstexpr It& operator++() {\n\t\t\
    \t--b;\n\t\t\ta += c;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr It operator++(int)\
    \ {\n\t\t\tIt tmp = *this;\n\t\t\t--b;\n\t\t\ta += c;\n\t\t\treturn tmp;\n\t\t\
    }\n\t\tconstexpr const T& operator*() const {\n\t\t\treturn a;\n\t\t}\n\t\tconstexpr\
    \ const T* operator->() const {\n\t\t\treturn &a;\n\t\t}\n\t\tconstexpr bool operator==(const\
    \ It& i) const {\n\t\t\treturn b == i.b;\n\t\t}\n\t\tconstexpr bool operator!=(const\
    \ It& i) const {\n\t\t\treturn !(b == i.b);\n\t\t}\n\t\tconstexpr T start() const\
    \ {\n\t\t\treturn a;\n\t\t}\n\t\tconstexpr T size() const {\n\t\t\treturn b;\n\
    \t\t}\n\t\tconstexpr T step() const {\n\t\t\treturn c;\n\t\t}\n\t};\n\tconstexpr\
    \ Step(T b, T c, T s) : be(b, c, s) {}\n\tconstexpr It begin() const {\n\t\treturn\
    \ be;\n\t}\n\tconstexpr It end() const {\n\t\treturn en;\n\t}\n\tconstexpr T start()\
    \ const {\n\t\treturn be.start();\n\t}\n\tconstexpr T size() const {\n\t\treturn\
    \ be.size();\n\t}\n\tconstexpr T step() const {\n\t\treturn be.step();\n\t}\n\t\
    constexpr T sum() const {\n\t\treturn start() * size() + step() * (size() * (size()\
    \ - 1) / 2);\n\t}\n\toperator vector<T>() const {\n\t\treturn to_a();\n\t}\n\t\
    auto to_a() const {\n\t\tvector<T> res;\n\t\tres.reserve(size());\n\t\tfor (auto\
    \ i : *this) {\n\t\t\tres.push_back(i);\n\t\t}\n\t\treturn res;\n\t}\n\tusing\
    \ value_type = T;\n\tusing iterator = It;\n\nprivate:\n\tIt be, en;\n};\ntemplate\
    \ <class T> inline constexpr auto step(T a) {\n\treturn Step<T>(0, a, 1);\n}\n\
    template <class T> inline constexpr auto step(T a, T b) {\n\treturn Step<T>(a,\
    \ b - a, 1);\n}\ntemplate <class T> inline constexpr auto step(T a, T b, T c)\
    \ {\n\treturn Step<T>(a, a < b ? (b - a - 1) / c + 1 : 0, c);\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\ntemplate <class\
    \ T> struct Step {\n\tclass It {\n\t\tT a, b, c;\n\n\tpublic:\n\t\tconstexpr It()\
    \ : a(T()), b(T()), c(T()) {}\n\t\tconstexpr It(T _b, T _c, T _s) : a(_b), b(_c),\
    \ c(_s) {}\n\t\tconstexpr It& operator++() {\n\t\t\t--b;\n\t\t\ta += c;\n\t\t\t\
    return *this;\n\t\t}\n\t\tconstexpr It operator++(int) {\n\t\t\tIt tmp = *this;\n\
    \t\t\t--b;\n\t\t\ta += c;\n\t\t\treturn tmp;\n\t\t}\n\t\tconstexpr const T& operator*()\
    \ const {\n\t\t\treturn a;\n\t\t}\n\t\tconstexpr const T* operator->() const {\n\
    \t\t\treturn &a;\n\t\t}\n\t\tconstexpr bool operator==(const It& i) const {\n\t\
    \t\treturn b == i.b;\n\t\t}\n\t\tconstexpr bool operator!=(const It& i) const\
    \ {\n\t\t\treturn !(b == i.b);\n\t\t}\n\t\tconstexpr T start() const {\n\t\t\t\
    return a;\n\t\t}\n\t\tconstexpr T size() const {\n\t\t\treturn b;\n\t\t}\n\t\t\
    constexpr T step() const {\n\t\t\treturn c;\n\t\t}\n\t};\n\tconstexpr Step(T b,\
    \ T c, T s) : be(b, c, s) {}\n\tconstexpr It begin() const {\n\t\treturn be;\n\
    \t}\n\tconstexpr It end() const {\n\t\treturn en;\n\t}\n\tconstexpr T start()\
    \ const {\n\t\treturn be.start();\n\t}\n\tconstexpr T size() const {\n\t\treturn\
    \ be.size();\n\t}\n\tconstexpr T step() const {\n\t\treturn be.step();\n\t}\n\t\
    constexpr T sum() const {\n\t\treturn start() * size() + step() * (size() * (size()\
    \ - 1) / 2);\n\t}\n\toperator vector<T>() const {\n\t\treturn to_a();\n\t}\n\t\
    auto to_a() const {\n\t\tvector<T> res;\n\t\tres.reserve(size());\n\t\tfor (auto\
    \ i : *this) {\n\t\t\tres.push_back(i);\n\t\t}\n\t\treturn res;\n\t}\n\tusing\
    \ value_type = T;\n\tusing iterator = It;\n\nprivate:\n\tIt be, en;\n};\ntemplate\
    \ <class T> inline constexpr auto step(T a) {\n\treturn Step<T>(0, a, 1);\n}\n\
    template <class T> inline constexpr auto step(T a, T b) {\n\treturn Step<T>(a,\
    \ b - a, 1);\n}\ntemplate <class T> inline constexpr auto step(T a, T b, T c)\
    \ {\n\treturn Step<T>(a, a < b ? (b - a - 1) / c + 1 : 0, c);\n}"
  dependsOn: []
  isVerificationFile: false
  path: template/Step.cpp
  requiredBy:
  - template/template.cpp
  timestamp: '2020-10-06 16:32:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/Step.cpp
layout: document
redirect_from:
- /library/template/Step.cpp
- /library/template/Step.cpp.html
title: template/Step.cpp
---
