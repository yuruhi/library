---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/Random.cpp\"\n#include <random>\n#include <algorithm>\n\
    using namespace std;\n\nclass Random {\n\tusing T = unsigned int;\n\tmt19937 mt;\n\
    \trandom_device rd;\n\npublic:\n\tRandom() {\n\t\tseed();\n\t}\n\tvoid seed()\
    \ {\n\t\tmt.seed(rd());\n\t}\n\tvoid seed(T s) {\n\t\tmt.seed(s);\n\t}\n\tT operator()()\
    \ {\n\t\treturn mt();\n\t}\n\tT operator()(T r) {  // [0, r)\n\t\tuniform_int_distribution<>\
    \ u(0, 0 < r ? r - 1 : 0);\n\t\treturn u(mt);\n\t}\n\tT operator()(T l, T r) {\
    \  // [l, r)\n\t\tuniform_int_distribution<> u(l, max(l, r) - 1);\n\t\treturn\
    \ u(mt);\n\t}\n\tT dice() {\n\t\treturn operator()(1, 7);\n\t}\n\tbool rand_bool()\
    \ {\n\t\treturn operator()(2);\n\t}\n\tbool rand_bool(double p) {\n\t\tbernoulli_distribution\
    \ u(p);\n\t\treturn u(mt);\n\t}\n\ttemplate <class T> void shuffle(T& v) {\n\t\
    \tstd::shuffle(v.begin(), v.end(), mt);\n\t}\n} rnd;\n"
  code: "#pragma once\n#include <random>\n#include <algorithm>\nusing namespace std;\n\
    \nclass Random {\n\tusing T = unsigned int;\n\tmt19937 mt;\n\trandom_device rd;\n\
    \npublic:\n\tRandom() {\n\t\tseed();\n\t}\n\tvoid seed() {\n\t\tmt.seed(rd());\n\
    \t}\n\tvoid seed(T s) {\n\t\tmt.seed(s);\n\t}\n\tT operator()() {\n\t\treturn\
    \ mt();\n\t}\n\tT operator()(T r) {  // [0, r)\n\t\tuniform_int_distribution<>\
    \ u(0, 0 < r ? r - 1 : 0);\n\t\treturn u(mt);\n\t}\n\tT operator()(T l, T r) {\
    \  // [l, r)\n\t\tuniform_int_distribution<> u(l, max(l, r) - 1);\n\t\treturn\
    \ u(mt);\n\t}\n\tT dice() {\n\t\treturn operator()(1, 7);\n\t}\n\tbool rand_bool()\
    \ {\n\t\treturn operator()(2);\n\t}\n\tbool rand_bool(double p) {\n\t\tbernoulli_distribution\
    \ u(p);\n\t\treturn u(mt);\n\t}\n\ttemplate <class T> void shuffle(T& v) {\n\t\
    \tstd::shuffle(v.begin(), v.end(), mt);\n\t}\n} rnd;\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Random.cpp
  requiredBy: []
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/Random.cpp
layout: document
redirect_from:
- /library/Utility/Random.cpp
- /library/Utility/Random.cpp.html
title: Utility/Random.cpp
---
