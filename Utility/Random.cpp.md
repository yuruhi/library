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
  bundledCode: "#line 2 \"Utility/Random.cpp\"\n#include <random>\n#include <algorithm>\n\
    #include <type_traits>\n#include <cassert>\nusing namespace std;\n\nclass Random\
    \ {\n\tmt19937 engine;\n\trandom_device rd;\n\npublic:\n\tRandom() {\n\t\tseed();\n\
    \t}\n\tvoid seed() {\n\t\tengine.seed(rd());\n\t}\n\tvoid seed(uint_fast32_t s)\
    \ {\n\t\tengine.seed(s);\n\t}\n\ttemplate <class T,\n\t          enable_if_t<is_integral_v<T>\
    \ && !is_same_v<bool, T>, nullptr_t> = nullptr>\n\tT get(T l, T r) {\n\t\tassert(l\
    \ <= r);\n\t\treturn uniform_int_distribution<T>(l, r)(engine);\n\t}\n\ttemplate\
    \ <class T, enable_if_t<is_floating_point_v<T>, nullptr_t> = nullptr>\n\tT get(T\
    \ l, T r) {\n\t\tassert(l <= r);\n\t\treturn uniform_real_distribution<T>(l, r)(engine);\n\
    \t}\n\ttemplate <class T, enable_if_t<is_same_v<bool, T>, nullptr_t> = nullptr>\n\
    \tT get(double probability = 0.5) {\n\t\tbernoulli_distribution u(probability);\n\
    \t\treturn u(engine);\n\t}\n\ttemplate <class T, enable_if_t<is_same_v<string,\
    \ T>, nullptr_t> = nullptr>\n\tT get(size_t n, string_view chars = \"abcdefghjiklmnopqrstuvwxyz\"\
    ) {\n\t\tstring result;\n\t\tresult.reserve(n);\n\t\tsample(chars.begin(), chars.end(),\
    \ back_inserter(result), n, engine);\n\t\treturn result;\n\t}\n\tint dice() {\n\
    \t\treturn get<int>(1, 7);\n\t}\n\ttemplate <class T> void shuffle(T& v) {\n\t\
    \tstd::shuffle(begin(v), end(v), engine);\n\t}\n} rnd;\n"
  code: "#pragma once\n#include <random>\n#include <algorithm>\n#include <type_traits>\n\
    #include <cassert>\nusing namespace std;\n\nclass Random {\n\tmt19937 engine;\n\
    \trandom_device rd;\n\npublic:\n\tRandom() {\n\t\tseed();\n\t}\n\tvoid seed()\
    \ {\n\t\tengine.seed(rd());\n\t}\n\tvoid seed(uint_fast32_t s) {\n\t\tengine.seed(s);\n\
    \t}\n\ttemplate <class T,\n\t          enable_if_t<is_integral_v<T> && !is_same_v<bool,\
    \ T>, nullptr_t> = nullptr>\n\tT get(T l, T r) {\n\t\tassert(l <= r);\n\t\treturn\
    \ uniform_int_distribution<T>(l, r)(engine);\n\t}\n\ttemplate <class T, enable_if_t<is_floating_point_v<T>,\
    \ nullptr_t> = nullptr>\n\tT get(T l, T r) {\n\t\tassert(l <= r);\n\t\treturn\
    \ uniform_real_distribution<T>(l, r)(engine);\n\t}\n\ttemplate <class T, enable_if_t<is_same_v<bool,\
    \ T>, nullptr_t> = nullptr>\n\tT get(double probability = 0.5) {\n\t\tbernoulli_distribution\
    \ u(probability);\n\t\treturn u(engine);\n\t}\n\ttemplate <class T, enable_if_t<is_same_v<string,\
    \ T>, nullptr_t> = nullptr>\n\tT get(size_t n, string_view chars = \"abcdefghjiklmnopqrstuvwxyz\"\
    ) {\n\t\tstring result;\n\t\tresult.reserve(n);\n\t\tsample(chars.begin(), chars.end(),\
    \ back_inserter(result), n, engine);\n\t\treturn result;\n\t}\n\tint dice() {\n\
    \t\treturn get<int>(1, 7);\n\t}\n\ttemplate <class T> void shuffle(T& v) {\n\t\
    \tstd::shuffle(begin(v), end(v), engine);\n\t}\n} rnd;\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Random.cpp
  requiredBy: []
  timestamp: '2020-11-26 14:21:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/Random.cpp
layout: document
redirect_from:
- /library/Utility/Random.cpp
- /library/Utility/Random.cpp.html
title: Utility/Random.cpp
---
