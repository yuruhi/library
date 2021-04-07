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
  bundledCode: "#line 2 \"Utility/RunLengthArray.cpp\"\n#include <vector>\n#include\
    \ <initializer_list>\n#include <utility>\n#include <cassert>\n\ntemplate <class\
    \ value_type, class size_type = std::size_t> class RunLengthArray {\n\tstd::vector<value_type>\
    \ value;\n\tstd::vector<std::pair<size_type, size_type>> index;  // [first, second)\n\
    \n\tstd::size_t find(size_type i) {\n\t\tint left = 0, right = value.size();\n\
    \t\twhile (right - left > 1) {\n\t\t\tint mid = left + (right - left) / 2;\n\t\
    \t\t(index[mid].first <= i ? left : right) = mid;\n\t\t}\n\t\treturn left;\n\t\
    }\n\npublic:\n\tRunLengthArray() {}\n\tRunLengthArray(const value_type& val, size_type\
    \ size) : value({val}), index({{0, size}}) {}\n\tRunLengthArray(const std::initializer_list<std::pair<size_type,\
    \ value_type>>& v) {\n\t\tindex.reserve(v.size());\n\t\tvalue.reserve(v.size());\n\
    \t\tsize_type now = 0;\n\t\tfor (const auto& p : v) {\n\t\t\tindex.emplace_back(now,\
    \ now + p.first);\n\t\t\tvalue.push_back(p.second);\n\t\t\tnow += p.first;\n\t\
    \t}\n\t}\n\tsize_type size() const {\n\t\treturn empty() ? 0 : index.back().second;\n\
    \t}\n\tbool empty() const {\n\t\treturn value.empty() || index.empty();\n\t}\n\
    \texplicit operator bool() const {\n\t\treturn !empty();\n\t}\n\n\tconst value_type&\
    \ operator[](const size_type i) const {\n\t\tassert(i < size());\n\t\treturn value[find(i)];\n\
    \t}\n\tconst value_type& front() const {\n\t\tassert(!empty());\n\t\treturn value.front();\n\
    \t}\n\tconst value_type& back() const {\n\t\tassert(!empty());\n\t\treturn value.back();\n\
    \t}\n\n\tauto at(const std::size_t i) const {\n\t\treturn std::pair(value[i],\
    \ index[i].second - index[i].first);\n\t}\n\tstd::size_t value_size() const {\n\
    \t\treturn value.size();\n\t}\n\n\tvoid clear() {\n\t\tvalue.clear();\n\t\tindex.clear();\n\
    \t}\n\tRunLengthArray& push_back(const value_type& val, const size_type new_size\
    \ = 1) {\n\t\tif (empty() || value.back() != val) {\n\t\t\tvalue.push_back(val);\n\
    \t\t\tindex.emplace_back(size(), size() + new_size);\n\t\t} else {\n\t\t\tindex.back().second\
    \ += new_size;\n\t\t}\n\t\treturn *this;\n\t}\n\tRunLengthArray& pop_back(const\
    \ size_type pop_size = 1) {\n\t\tassert(pop_size <= size());\n\t\tsize_type until\
    \ = size() - pop_size;\n\t\twhile (!empty()) {\n\t\t\tif (index.back().first ==\
    \ until) {\n\t\t\t\tvalue.pop_back();\n\t\t\t\tindex.pop_back();\n\t\t\t\tbreak;\n\
    \t\t\t} else if (index.back().first <= until && until < index.back().second) {\n\
    \t\t\t\tindex.back().second = until;\n\t\t\t\tbreak;\n\t\t\t} else {\n\t\t\t\t\
    value.pop_back();\n\t\t\t\tindex.pop_back();\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\
    \t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <initializer_list>\n#include <utility>\n\
    #include <cassert>\n\ntemplate <class value_type, class size_type = std::size_t>\
    \ class RunLengthArray {\n\tstd::vector<value_type> value;\n\tstd::vector<std::pair<size_type,\
    \ size_type>> index;  // [first, second)\n\n\tstd::size_t find(size_type i) {\n\
    \t\tint left = 0, right = value.size();\n\t\twhile (right - left > 1) {\n\t\t\t\
    int mid = left + (right - left) / 2;\n\t\t\t(index[mid].first <= i ? left : right)\
    \ = mid;\n\t\t}\n\t\treturn left;\n\t}\n\npublic:\n\tRunLengthArray() {}\n\tRunLengthArray(const\
    \ value_type& val, size_type size) : value({val}), index({{0, size}}) {}\n\tRunLengthArray(const\
    \ std::initializer_list<std::pair<size_type, value_type>>& v) {\n\t\tindex.reserve(v.size());\n\
    \t\tvalue.reserve(v.size());\n\t\tsize_type now = 0;\n\t\tfor (const auto& p :\
    \ v) {\n\t\t\tindex.emplace_back(now, now + p.first);\n\t\t\tvalue.push_back(p.second);\n\
    \t\t\tnow += p.first;\n\t\t}\n\t}\n\tsize_type size() const {\n\t\treturn empty()\
    \ ? 0 : index.back().second;\n\t}\n\tbool empty() const {\n\t\treturn value.empty()\
    \ || index.empty();\n\t}\n\texplicit operator bool() const {\n\t\treturn !empty();\n\
    \t}\n\n\tconst value_type& operator[](const size_type i) const {\n\t\tassert(i\
    \ < size());\n\t\treturn value[find(i)];\n\t}\n\tconst value_type& front() const\
    \ {\n\t\tassert(!empty());\n\t\treturn value.front();\n\t}\n\tconst value_type&\
    \ back() const {\n\t\tassert(!empty());\n\t\treturn value.back();\n\t}\n\n\tauto\
    \ at(const std::size_t i) const {\n\t\treturn std::pair(value[i], index[i].second\
    \ - index[i].first);\n\t}\n\tstd::size_t value_size() const {\n\t\treturn value.size();\n\
    \t}\n\n\tvoid clear() {\n\t\tvalue.clear();\n\t\tindex.clear();\n\t}\n\tRunLengthArray&\
    \ push_back(const value_type& val, const size_type new_size = 1) {\n\t\tif (empty()\
    \ || value.back() != val) {\n\t\t\tvalue.push_back(val);\n\t\t\tindex.emplace_back(size(),\
    \ size() + new_size);\n\t\t} else {\n\t\t\tindex.back().second += new_size;\n\t\
    \t}\n\t\treturn *this;\n\t}\n\tRunLengthArray& pop_back(const size_type pop_size\
    \ = 1) {\n\t\tassert(pop_size <= size());\n\t\tsize_type until = size() - pop_size;\n\
    \t\twhile (!empty()) {\n\t\t\tif (index.back().first == until) {\n\t\t\t\tvalue.pop_back();\n\
    \t\t\t\tindex.pop_back();\n\t\t\t\tbreak;\n\t\t\t} else if (index.back().first\
    \ <= until && until < index.back().second) {\n\t\t\t\tindex.back().second = until;\n\
    \t\t\t\tbreak;\n\t\t\t} else {\n\t\t\t\tvalue.pop_back();\n\t\t\t\tindex.pop_back();\n\
    \t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/RunLengthArray.cpp
  requiredBy: []
  timestamp: '2021-04-06 14:24:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/RunLengthArray.cpp
layout: document
redirect_from:
- /library/Utility/RunLengthArray.cpp
- /library/Utility/RunLengthArray.cpp.html
title: Utility/RunLengthArray.cpp
---
