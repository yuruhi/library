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
    #include <string>\n#include <string_view>\n#include <type_traits>\n#include <cassert>\n\
    \nclass Random {\n\tstd::mt19937 engine;\n\tstd::random_device rd;\n\npublic:\n\
    \tRandom() {\n\t\tseed();\n\t}\n\tvoid seed() {\n\t\tengine.seed(rd());\n\t}\n\
    \tvoid seed(std::uint_fast32_t s) {\n\t\tengine.seed(s);\n\t}\n\ttemplate <class\
    \ T,\n\t          std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<bool,\
    \ T>,\n\t                           std::nullptr_t> = nullptr>\n\tT get(T l, T\
    \ r) {\n\t\tassert(l <= r);\n\t\treturn std::uniform_int_distribution<T>(l, r)(engine);\n\
    \t}\n\ttemplate <class T, std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t>\
    \ = nullptr>\n\tT get(T l, T r) {\n\t\tassert(l <= r);\n\t\treturn std::uniform_real_distribution<T>(l,\
    \ r)(engine);\n\t}\n\ttemplate <class T, std::enable_if_t<std::is_same_v<bool,\
    \ T>, std::nullptr_t> = nullptr>\n\tT get(double probability = 0.5) {\n\t\tstd::bernoulli_distribution\
    \ u(probability);\n\t\treturn u(engine);\n\t}\n\ttemplate <class T,\n\t      \
    \    std::enable_if_t<std::is_same_v<std::string, T>, std::nullptr_t> = nullptr>\n\
    \tT get(size_t n, std::string_view chars = \"abcdefghjiklmnopqrstuvwxyz\") {\n\
    \t\tstd::string result;\n\t\tresult.reserve(n);\n\t\tstd::sample(chars.begin(),\
    \ chars.end(), std::back_inserter(result), n, engine);\n\t\treturn result;\n\t\
    }\n\tint dice() {\n\t\treturn get<int>(1, 7);\n\t}\n\ttemplate <class T> auto\
    \ sample(const T& v) {\n\t\treturn v[get<std::size_t>(0, std::size(v) - 1)];\n\
    \t}\n\ttemplate <class T> void shuffle(T& v) {\n\t\tstd::shuffle(std::begin(v),\
    \ std::end(v), engine);\n\t}\n} rnd;\n"
  code: "#pragma once\n#include <random>\n#include <algorithm>\n#include <string>\n\
    #include <string_view>\n#include <type_traits>\n#include <cassert>\n\nclass Random\
    \ {\n\tstd::mt19937 engine;\n\tstd::random_device rd;\n\npublic:\n\tRandom() {\n\
    \t\tseed();\n\t}\n\tvoid seed() {\n\t\tengine.seed(rd());\n\t}\n\tvoid seed(std::uint_fast32_t\
    \ s) {\n\t\tengine.seed(s);\n\t}\n\ttemplate <class T,\n\t          std::enable_if_t<std::is_integral_v<T>\
    \ && !std::is_same_v<bool, T>,\n\t                           std::nullptr_t> =\
    \ nullptr>\n\tT get(T l, T r) {\n\t\tassert(l <= r);\n\t\treturn std::uniform_int_distribution<T>(l,\
    \ r)(engine);\n\t}\n\ttemplate <class T, std::enable_if_t<std::is_floating_point_v<T>,\
    \ std::nullptr_t> = nullptr>\n\tT get(T l, T r) {\n\t\tassert(l <= r);\n\t\treturn\
    \ std::uniform_real_distribution<T>(l, r)(engine);\n\t}\n\ttemplate <class T,\
    \ std::enable_if_t<std::is_same_v<bool, T>, std::nullptr_t> = nullptr>\n\tT get(double\
    \ probability = 0.5) {\n\t\tstd::bernoulli_distribution u(probability);\n\t\t\
    return u(engine);\n\t}\n\ttemplate <class T,\n\t          std::enable_if_t<std::is_same_v<std::string,\
    \ T>, std::nullptr_t> = nullptr>\n\tT get(size_t n, std::string_view chars = \"\
    abcdefghjiklmnopqrstuvwxyz\") {\n\t\tstd::string result;\n\t\tresult.reserve(n);\n\
    \t\tstd::sample(chars.begin(), chars.end(), std::back_inserter(result), n, engine);\n\
    \t\treturn result;\n\t}\n\tint dice() {\n\t\treturn get<int>(1, 7);\n\t}\n\ttemplate\
    \ <class T> auto sample(const T& v) {\n\t\treturn v[get<std::size_t>(0, std::size(v)\
    \ - 1)];\n\t}\n\ttemplate <class T> void shuffle(T& v) {\n\t\tstd::shuffle(std::begin(v),\
    \ std::end(v), engine);\n\t}\n} rnd;\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Random.cpp
  requiredBy: []
  timestamp: '2021-03-10 22:57:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/Random.cpp
layout: document
redirect_from:
- /library/Utility/Random.cpp
- /library/Utility/Random.cpp.html
title: Utility/Random.cpp
---
