---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/RunLengthEncoding.test.cpp
    title: test/RunLengthEncoding.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/RunLengthEncoding.cpp\"\n#include <vector>\n#include\
    \ <iterator>\n#include <utility>\nusing namespace std;\n\ntemplate <class InputIterator,\
    \ class value_type = typename InputIterator::value_type>\nauto RunLengthEncoding(InputIterator\
    \ first, InputIterator last) {\n\tvector<pair<size_t, value_type>> result;\n\t\
    for (; first != last; ++first) {\n\t\tif (result.empty() || result.back().second\
    \ != *first) {\n\t\t\tresult.emplace_back(1, *first);\n\t\t} else {\n\t\t\tresult.back().first++;\n\
    \t\t}\n\t}\n\treturn result;\n}\n\ntemplate <class Container, class value_type\
    \ = typename Container::value_type>\nauto RunLengthEncoding(const Container& a)\
    \ {\n\treturn RunLengthEncoding(a.begin(), a.end());\n}\n\ntemplate <class InputIterator,\
    \ class value_type = typename InputIterator::value_type>\nauto RunLengthEncoding_pair(InputIterator\
    \ first, InputIterator last) {\n\tvector<size_t> count;\n\tvector<value_type>\
    \ value;\n\tfor (; first != last; ++first) {\n\t\tif (value.empty() || value.back()\
    \ != *first) {\n\t\t\tcount.push_back(1);\n\t\t\tvalue.push_back(*first);\n\t\t\
    } else {\n\t\t\tcount.back()++;\n\t\t}\n\t}\n\treturn pair(count, value);\n}\n\
    \ntemplate <class Container, class value_type = typename Container::value_type>\n\
    auto RunLengthEncoding_pair(const Container& a) {\n\treturn RunLengthEncoding_pair(a.begin(),\
    \ a.end());\n}\n"
  code: "#pragma once\n#include <vector>\n#include <iterator>\n#include <utility>\n\
    using namespace std;\n\ntemplate <class InputIterator, class value_type = typename\
    \ InputIterator::value_type>\nauto RunLengthEncoding(InputIterator first, InputIterator\
    \ last) {\n\tvector<pair<size_t, value_type>> result;\n\tfor (; first != last;\
    \ ++first) {\n\t\tif (result.empty() || result.back().second != *first) {\n\t\t\
    \tresult.emplace_back(1, *first);\n\t\t} else {\n\t\t\tresult.back().first++;\n\
    \t\t}\n\t}\n\treturn result;\n}\n\ntemplate <class Container, class value_type\
    \ = typename Container::value_type>\nauto RunLengthEncoding(const Container& a)\
    \ {\n\treturn RunLengthEncoding(a.begin(), a.end());\n}\n\ntemplate <class InputIterator,\
    \ class value_type = typename InputIterator::value_type>\nauto RunLengthEncoding_pair(InputIterator\
    \ first, InputIterator last) {\n\tvector<size_t> count;\n\tvector<value_type>\
    \ value;\n\tfor (; first != last; ++first) {\n\t\tif (value.empty() || value.back()\
    \ != *first) {\n\t\t\tcount.push_back(1);\n\t\t\tvalue.push_back(*first);\n\t\t\
    } else {\n\t\t\tcount.back()++;\n\t\t}\n\t}\n\treturn pair(count, value);\n}\n\
    \ntemplate <class Container, class value_type = typename Container::value_type>\n\
    auto RunLengthEncoding_pair(const Container& a) {\n\treturn RunLengthEncoding_pair(a.begin(),\
    \ a.end());\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/RunLengthEncoding.cpp
  requiredBy: []
  timestamp: '2021-01-06 22:02:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/RunLengthEncoding.test.cpp
documentation_of: Utility/RunLengthEncoding.cpp
layout: document
redirect_from:
- /library/Utility/RunLengthEncoding.cpp
- /library/Utility/RunLengthEncoding.cpp.html
title: Utility/RunLengthEncoding.cpp
---
