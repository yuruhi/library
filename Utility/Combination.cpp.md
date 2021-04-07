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
  bundledCode: "#line 2 \"Utility/Combination.cpp\"\n#include <vector>\n\ntemplate\
    \ <class T, class F>\nvoid each_repeated_permutation(const T& array, std::size_t\
    \ count, F f) {\n\tusing value_type = typename T::value_type;\n\tstd::vector<value_type>\
    \ permutation(count);\n\tauto dfs = [&](auto self, std::size_t size) -> void {\n\
    \t\tif (size == count) {\n\t\t\tf(permutation);\n\t\t} else {\n\t\t\tfor (const\
    \ auto& i : array) {\n\t\t\t\tpermutation[size] = i;\n\t\t\t\tself(self, size\
    \ + 1);\n\t\t\t}\n\t\t}\n\t};\n\tdfs(dfs, 0);\n}\n\ntemplate <class T> auto repeated_permutations(const\
    \ T& array, std::size_t count) {\n\tusing value_type = typename T::value_type;\n\
    \tstd::vector<std::vector<value_type>> result;\n\tstd::size_t size = 1;\n\tfor\
    \ (std::size_t i = 0; i < count; ++i) {\n\t\tsize *= array.size();\n\t}\n\tresult.reserve(size);\n\
    \teach_repeated_permutation(array, count, [&](const auto& perm) { result.push_back(perm);\
    \ });\n\treturn result;\n}\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <class T, class F>\nvoid each_repeated_permutation(const\
    \ T& array, std::size_t count, F f) {\n\tusing value_type = typename T::value_type;\n\
    \tstd::vector<value_type> permutation(count);\n\tauto dfs = [&](auto self, std::size_t\
    \ size) -> void {\n\t\tif (size == count) {\n\t\t\tf(permutation);\n\t\t} else\
    \ {\n\t\t\tfor (const auto& i : array) {\n\t\t\t\tpermutation[size] = i;\n\t\t\
    \t\tself(self, size + 1);\n\t\t\t}\n\t\t}\n\t};\n\tdfs(dfs, 0);\n}\n\ntemplate\
    \ <class T> auto repeated_permutations(const T& array, std::size_t count) {\n\t\
    using value_type = typename T::value_type;\n\tstd::vector<std::vector<value_type>>\
    \ result;\n\tstd::size_t size = 1;\n\tfor (std::size_t i = 0; i < count; ++i)\
    \ {\n\t\tsize *= array.size();\n\t}\n\tresult.reserve(size);\n\teach_repeated_permutation(array,\
    \ count, [&](const auto& perm) { result.push_back(perm); });\n\treturn result;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Combination.cpp
  requiredBy: []
  timestamp: '2021-04-06 14:24:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/Combination.cpp
layout: document
redirect_from:
- /library/Utility/Combination.cpp
- /library/Utility/Combination.cpp.html
title: Utility/Combination.cpp
---
