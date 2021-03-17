---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/template.test.cpp
    title: test/template.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/template_no_Ruby.test.cpp
    title: test/template_no_Ruby.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/Step.cpp\"\n#include <vector>\n#include <iterator>\n\
    #include <algorithm>\n#include <cassert>\n\ntemplate <class T> class step_iterator\
    \ {\npublic:\n\tusing value_type = T;\n\tusing difference_type = T;\n\tusing iterator_category\
    \ = std::random_access_iterator_tag;\n\tusing reference = T&;\n\tusing pointer\
    \ = T*;\n\nprivate:\n\tvalue_type start_m, size_m, step_m, index_m;\n\npublic:\n\
    \tconstexpr step_iterator()\n\t    : start_m(value_type()), size_m(value_type()),\
    \ step_m(value_type()), index_m(0) {}\n\tconstexpr step_iterator(value_type _start,\
    \ value_type _size, value_type _step)\n\t    : start_m(_start), size_m(_size),\
    \ step_m(_step), index_m(0) {}\n\tvalue_type operator*() const noexcept {\n\t\t\
    return value();\n\t}\n\tstep_iterator& operator++() noexcept {\n\t\t++index_m;\n\
    \t\treturn *this;\n\t}\n\tstep_iterator& operator++(int) noexcept {\n\t\tauto\
    \ tmp = *this;\n\t\t++*this;\n\t\treturn tmp;\n\t}\n\tstep_iterator& operator--()\
    \ noexcept {\n\t\t--index_m;\n\t\treturn *this;\n\t}\n\tstep_iterator& operator--(int)\
    \ noexcept {\n\t\tauto tmp = *this;\n\t\t--*this;\n\t\treturn tmp;\n\t}\n\tstep_iterator&\
    \ operator+=(difference_type n) {\n\t\tindex_m += n;\n\t\treturn *this;\n\t}\n\
    \tstep_iterator operator+(difference_type n) const {\n\t\treturn step_iterator(*this)\
    \ += n;\n\t}\n\tfriend step_iterator operator+(difference_type n, step_iterator\
    \ i) {\n\t\treturn i + n;\n\t}\n\tstep_iterator& operator-=(difference_type n)\
    \ {\n\t\tindex_m -= n;\n\t\treturn *this;\n\t}\n\tstep_iterator operator-(difference_type\
    \ n) const {\n\t\treturn step_iterator(*this) -= n;\n\t}\n\tfriend step_iterator\
    \ operator-(difference_type n, step_iterator i) {\n\t\treturn i - n;\n\t}\n\t\
    difference_type operator-(const step_iterator& other) const {\n\t\tassert(start_m\
    \ == other.start_m);\n\t\tassert(size_m == other.size_m);\n\t\tassert(step_m ==\
    \ other.step_m);\n\t\treturn index_m - other.index_m;\n\t}\n\tbool operator==(const\
    \ step_iterator& other) const noexcept {\n\t\treturn value() == other.value();\n\
    \t}\n\tbool operator!=(const step_iterator& other) const noexcept {\n\t\treturn\
    \ value() != other.value();\n\t}\n\tbool operator<(const step_iterator& other)\
    \ const noexcept {\n\t\treturn value() < other.value();\n\t}\n\tbool operator<=(const\
    \ step_iterator& other) const noexcept {\n\t\treturn value() <= other.value();\n\
    \t}\n\tbool operator>(const step_iterator& other) const noexcept {\n\t\treturn\
    \ value() > other.value();\n\t}\n\tbool operator>=(const step_iterator& other)\
    \ const noexcept {\n\t\treturn value() >= other.value();\n\t}\n\tconstexpr value_type\
    \ value() const noexcept {\n\t\treturn start_m + step_m * index_m;\n\t}\n};\n\n\
    template <class T> class Step {\npublic:\n\tusing value_type = T;\n\tusing iterator\
    \ = step_iterator<value_type>;\n\nprivate:\n\tvalue_type start_m, size_m, step_m;\n\
    \npublic:\n\tconstexpr Step(value_type _start, value_type _size, value_type _step)\n\
    \t    : start_m(_start), size_m(std::max<value_type>(0, _size)), step_m(_step)\
    \ {}\n\tconstexpr iterator begin() const {\n\t\treturn iterator(start_m, size_m,\
    \ step_m);\n\t}\n\tconstexpr iterator end() const {\n\t\treturn iterator(start_m,\
    \ size_m, step_m) + size_m;\n\t}\n\tconstexpr value_type start() const {\n\t\t\
    return start_m;\n\t}\n\tconstexpr value_type size() const {\n\t\treturn size_m;\n\
    \t}\n\tconstexpr value_type step() const {\n\t\treturn step_m;\n\t}\n\tconstexpr\
    \ value_type sum() const {\n\t\treturn start() * size() + step() * (size() * (size()\
    \ - 1) / 2);\n\t}\n\toperator std::vector<value_type>() const {\n\t\treturn to_a();\n\
    \t}\n\tauto to_a() const {\n\t\tstd::vector<value_type> result;\n\t\tresult.reserve(size());\n\
    \t\tfor (auto i : *this) {\n\t\t\tresult.push_back(i);\n\t\t}\n\t\treturn result;\n\
    \t}\n};\ntemplate <class T> constexpr auto upto(T from, T to, bool exclusive =\
    \ true) {\n\treturn Step<T>(from, to - from + exclusive, 1);\n}\ntemplate <class\
    \ T> constexpr auto downto(T from, T to, bool exclusive = true) {\n\treturn Step<T>(from,\
    \ from - to + exclusive, -1);\n}\ntemplate <class T> constexpr auto times(T n,\
    \ bool exclusive = false) {\n\treturn Step<T>(0, n + static_cast<T>(exclusive),\
    \ 1);\n}\n"
  code: "#pragma once\n#include <vector>\n#include <iterator>\n#include <algorithm>\n\
    #include <cassert>\n\ntemplate <class T> class step_iterator {\npublic:\n\tusing\
    \ value_type = T;\n\tusing difference_type = T;\n\tusing iterator_category = std::random_access_iterator_tag;\n\
    \tusing reference = T&;\n\tusing pointer = T*;\n\nprivate:\n\tvalue_type start_m,\
    \ size_m, step_m, index_m;\n\npublic:\n\tconstexpr step_iterator()\n\t    : start_m(value_type()),\
    \ size_m(value_type()), step_m(value_type()), index_m(0) {}\n\tconstexpr step_iterator(value_type\
    \ _start, value_type _size, value_type _step)\n\t    : start_m(_start), size_m(_size),\
    \ step_m(_step), index_m(0) {}\n\tvalue_type operator*() const noexcept {\n\t\t\
    return value();\n\t}\n\tstep_iterator& operator++() noexcept {\n\t\t++index_m;\n\
    \t\treturn *this;\n\t}\n\tstep_iterator& operator++(int) noexcept {\n\t\tauto\
    \ tmp = *this;\n\t\t++*this;\n\t\treturn tmp;\n\t}\n\tstep_iterator& operator--()\
    \ noexcept {\n\t\t--index_m;\n\t\treturn *this;\n\t}\n\tstep_iterator& operator--(int)\
    \ noexcept {\n\t\tauto tmp = *this;\n\t\t--*this;\n\t\treturn tmp;\n\t}\n\tstep_iterator&\
    \ operator+=(difference_type n) {\n\t\tindex_m += n;\n\t\treturn *this;\n\t}\n\
    \tstep_iterator operator+(difference_type n) const {\n\t\treturn step_iterator(*this)\
    \ += n;\n\t}\n\tfriend step_iterator operator+(difference_type n, step_iterator\
    \ i) {\n\t\treturn i + n;\n\t}\n\tstep_iterator& operator-=(difference_type n)\
    \ {\n\t\tindex_m -= n;\n\t\treturn *this;\n\t}\n\tstep_iterator operator-(difference_type\
    \ n) const {\n\t\treturn step_iterator(*this) -= n;\n\t}\n\tfriend step_iterator\
    \ operator-(difference_type n, step_iterator i) {\n\t\treturn i - n;\n\t}\n\t\
    difference_type operator-(const step_iterator& other) const {\n\t\tassert(start_m\
    \ == other.start_m);\n\t\tassert(size_m == other.size_m);\n\t\tassert(step_m ==\
    \ other.step_m);\n\t\treturn index_m - other.index_m;\n\t}\n\tbool operator==(const\
    \ step_iterator& other) const noexcept {\n\t\treturn value() == other.value();\n\
    \t}\n\tbool operator!=(const step_iterator& other) const noexcept {\n\t\treturn\
    \ value() != other.value();\n\t}\n\tbool operator<(const step_iterator& other)\
    \ const noexcept {\n\t\treturn value() < other.value();\n\t}\n\tbool operator<=(const\
    \ step_iterator& other) const noexcept {\n\t\treturn value() <= other.value();\n\
    \t}\n\tbool operator>(const step_iterator& other) const noexcept {\n\t\treturn\
    \ value() > other.value();\n\t}\n\tbool operator>=(const step_iterator& other)\
    \ const noexcept {\n\t\treturn value() >= other.value();\n\t}\n\tconstexpr value_type\
    \ value() const noexcept {\n\t\treturn start_m + step_m * index_m;\n\t}\n};\n\n\
    template <class T> class Step {\npublic:\n\tusing value_type = T;\n\tusing iterator\
    \ = step_iterator<value_type>;\n\nprivate:\n\tvalue_type start_m, size_m, step_m;\n\
    \npublic:\n\tconstexpr Step(value_type _start, value_type _size, value_type _step)\n\
    \t    : start_m(_start), size_m(std::max<value_type>(0, _size)), step_m(_step)\
    \ {}\n\tconstexpr iterator begin() const {\n\t\treturn iterator(start_m, size_m,\
    \ step_m);\n\t}\n\tconstexpr iterator end() const {\n\t\treturn iterator(start_m,\
    \ size_m, step_m) + size_m;\n\t}\n\tconstexpr value_type start() const {\n\t\t\
    return start_m;\n\t}\n\tconstexpr value_type size() const {\n\t\treturn size_m;\n\
    \t}\n\tconstexpr value_type step() const {\n\t\treturn step_m;\n\t}\n\tconstexpr\
    \ value_type sum() const {\n\t\treturn start() * size() + step() * (size() * (size()\
    \ - 1) / 2);\n\t}\n\toperator std::vector<value_type>() const {\n\t\treturn to_a();\n\
    \t}\n\tauto to_a() const {\n\t\tstd::vector<value_type> result;\n\t\tresult.reserve(size());\n\
    \t\tfor (auto i : *this) {\n\t\t\tresult.push_back(i);\n\t\t}\n\t\treturn result;\n\
    \t}\n};\ntemplate <class T> constexpr auto upto(T from, T to, bool exclusive =\
    \ true) {\n\treturn Step<T>(from, to - from + exclusive, 1);\n}\ntemplate <class\
    \ T> constexpr auto downto(T from, T to, bool exclusive = true) {\n\treturn Step<T>(from,\
    \ from - to + exclusive, -1);\n}\ntemplate <class T> constexpr auto times(T n,\
    \ bool exclusive = false) {\n\treturn Step<T>(0, n + static_cast<T>(exclusive),\
    \ 1);\n}"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Step.cpp
  requiredBy:
  - template.cpp
  timestamp: '2021-03-01 12:36:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/template.test.cpp
  - test/template_no_Ruby.test.cpp
documentation_of: Utility/Step.cpp
layout: document
redirect_from:
- /library/Utility/Step.cpp
- /library/Utility/Step.cpp.html
title: Utility/Step.cpp
---
