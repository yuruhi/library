---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/RunLengthArray.cpp\"\n#include <vector>\n#include\
    \ <initializer_list>\n#include <utility>\n#include <cassert>\nusing namespace\
    \ std;\n\ntemplate <class value_type, class size_type = size_t> class RunLengthArray\
    \ {\n\tusing T = value_type;\n\tusing S = size_type;\n\n\tvector<T> value;\n\t\
    vector<pair<S, S>> index;  // [first, second)\n\n\tsize_t find(S i) {\n\t\tint\
    \ left = 0, right = value.size();\n\t\twhile (right - left > 1) {\n\t\t\tint mid\
    \ = left + (right - left) / 2;\n\t\t\t(index[mid].first <= i ? left : right) =\
    \ mid;\n\t\t}\n\t\treturn left;\n\t}\n\npublic:\n\tRunLengthArray() {}\n\tRunLengthArray(const\
    \ T& val, S size) : value({val}), index({{0, size}}) {}\n\tRunLengthArray(const\
    \ initializer_list<pair<S, T>>& v) {\n\t\tindex.reserve(v.size());\n\t\tvalue.reserve(v.size());\n\
    \t\tS now = 0;\n\t\tfor (const auto& p : v) {\n\t\t\tindex.emplace_back(now, now\
    \ + p.first);\n\t\t\tvalue.push_back(p.second);\n\t\t\tnow += p.first;\n\t\t}\n\
    \t}\n\tS size() const {\n\t\treturn empty() ? 0 : index.back().second;\n\t}\n\t\
    bool empty() const {\n\t\treturn value.empty() || index.empty();\n\t}\n\texplicit\
    \ operator bool() const {\n\t\treturn !empty();\n\t}\n\n\tconst T& operator[](const\
    \ S i) const {\n\t\tassert(i < size());\n\t\treturn value[find(i)];\n\t}\n\tconst\
    \ T& front() const {\n\t\tassert(!empty());\n\t\treturn value.front();\n\t}\n\t\
    const T& back() const {\n\t\tassert(!empty());\n\t\treturn value.back();\n\t}\n\
    \n\tpair<T, S> at(const size_t i) const {\n\t\treturn make_pair(value[i], index[i].second\
    \ - index[i].first);\n\t}\n\tsize_t value_size() const {\n\t\treturn value.size();\n\
    \t}\n\n\tvoid clear() {\n\t\tvalue.clear();\n\t\tindex.clear();\n\t}\n\tRunLengthArray&\
    \ push_back(const T& val, const S new_size = 1) {\n\t\tif (empty() || value.back()\
    \ != val) {\n\t\t\tvalue.push_back(val);\n\t\t\tindex.emplace_back(size(), size()\
    \ + new_size);\n\t\t} else {\n\t\t\tindex.back().second += new_size;\n\t\t}\n\t\
    \treturn *this;\n\t}\n\tRunLengthArray& pop_back(const S pop_size = 1) {\n\t\t\
    assert(pop_size <= size());\n\t\tS until = size() - pop_size;\n\t\twhile (!empty())\
    \ {\n\t\t\tif (index.back().first == until) {\n\t\t\t\tvalue.pop_back();\n\t\t\
    \t\tindex.pop_back();\n\t\t\t\tbreak;\n\t\t\t} else if (index.back().first <=\
    \ until && until < index.back().second) {\n\t\t\t\tindex.back().second = until;\n\
    \t\t\t\tbreak;\n\t\t\t} else {\n\t\t\t\tvalue.pop_back();\n\t\t\t\tindex.pop_back();\n\
    \t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <initializer_list>\n#include <utility>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class value_type, class\
    \ size_type = size_t> class RunLengthArray {\n\tusing T = value_type;\n\tusing\
    \ S = size_type;\n\n\tvector<T> value;\n\tvector<pair<S, S>> index;  // [first,\
    \ second)\n\n\tsize_t find(S i) {\n\t\tint left = 0, right = value.size();\n\t\
    \twhile (right - left > 1) {\n\t\t\tint mid = left + (right - left) / 2;\n\t\t\
    \t(index[mid].first <= i ? left : right) = mid;\n\t\t}\n\t\treturn left;\n\t}\n\
    \npublic:\n\tRunLengthArray() {}\n\tRunLengthArray(const T& val, S size) : value({val}),\
    \ index({{0, size}}) {}\n\tRunLengthArray(const initializer_list<pair<S, T>>&\
    \ v) {\n\t\tindex.reserve(v.size());\n\t\tvalue.reserve(v.size());\n\t\tS now\
    \ = 0;\n\t\tfor (const auto& p : v) {\n\t\t\tindex.emplace_back(now, now + p.first);\n\
    \t\t\tvalue.push_back(p.second);\n\t\t\tnow += p.first;\n\t\t}\n\t}\n\tS size()\
    \ const {\n\t\treturn empty() ? 0 : index.back().second;\n\t}\n\tbool empty()\
    \ const {\n\t\treturn value.empty() || index.empty();\n\t}\n\texplicit operator\
    \ bool() const {\n\t\treturn !empty();\n\t}\n\n\tconst T& operator[](const S i)\
    \ const {\n\t\tassert(i < size());\n\t\treturn value[find(i)];\n\t}\n\tconst T&\
    \ front() const {\n\t\tassert(!empty());\n\t\treturn value.front();\n\t}\n\tconst\
    \ T& back() const {\n\t\tassert(!empty());\n\t\treturn value.back();\n\t}\n\n\t\
    pair<T, S> at(const size_t i) const {\n\t\treturn make_pair(value[i], index[i].second\
    \ - index[i].first);\n\t}\n\tsize_t value_size() const {\n\t\treturn value.size();\n\
    \t}\n\n\tvoid clear() {\n\t\tvalue.clear();\n\t\tindex.clear();\n\t}\n\tRunLengthArray&\
    \ push_back(const T& val, const S new_size = 1) {\n\t\tif (empty() || value.back()\
    \ != val) {\n\t\t\tvalue.push_back(val);\n\t\t\tindex.emplace_back(size(), size()\
    \ + new_size);\n\t\t} else {\n\t\t\tindex.back().second += new_size;\n\t\t}\n\t\
    \treturn *this;\n\t}\n\tRunLengthArray& pop_back(const S pop_size = 1) {\n\t\t\
    assert(pop_size <= size());\n\t\tS until = size() - pop_size;\n\t\twhile (!empty())\
    \ {\n\t\t\tif (index.back().first == until) {\n\t\t\t\tvalue.pop_back();\n\t\t\
    \t\tindex.pop_back();\n\t\t\t\tbreak;\n\t\t\t} else if (index.back().first <=\
    \ until && until < index.back().second) {\n\t\t\t\tindex.back().second = until;\n\
    \t\t\t\tbreak;\n\t\t\t} else {\n\t\t\t\tvalue.pop_back();\n\t\t\t\tindex.pop_back();\n\
    \t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/RunLengthArray.cpp
  requiredBy: []
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/RunLengthArray.cpp
layout: document
redirect_from:
- /library/Utility/RunLengthArray.cpp
- /library/Utility/RunLengthArray.cpp.html
title: Utility/RunLengthArray.cpp
---
