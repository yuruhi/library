---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/RangeSet.test.cpp
    title: test/RangeSet.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/RangeSet.cpp\"\n#include <set>\n#include <utility>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> class RangeSet\
    \ {\npublic:\n\tusing size_type = size_t;\n\tusing value_type = T;\n\tusing range_type\
    \ = pair<value_type, value_type>;\n\nprivate:\n\tconstexpr static value_type MIN\
    \ = numeric_limits<value_type>::min();\n\tconstexpr static value_type MAX = numeric_limits<value_type>::max();\n\
    \tset<range_type> ranges;\n\tsize_t size_m;\n\n\tauto prev_range_iterator(value_type\
    \ x) const {\n\t\treturn prev(ranges.lower_bound({x + 1, x + 1}));\n\t}\n\trange_type\
    \ prev_range(value_type x) const {\n\t\treturn *prev_range_iterator(x);\n\t}\n\
    \npublic:\n\tRangeSet() : size_m(0) {\n\t\tranges.emplace(MIN, MIN);\n\t\tranges.emplace(MAX,\
    \ MAX);\n\t};\n\tsize_t size() const {\n\t\treturn size_m;\n\t}\n\tsize_t count_ranges()\
    \ const {\n\t\treturn ranges.size() - 2;\n\t}\n\tbool empty() const {\n\t\treturn\
    \ size() == 0;\n\t}\n\tvoid clear() {\n\t\tranges.clear();\n\t\tranges.emplace(MIN,\
    \ MIN);\n\t\tranges.smplace(MAX, MAX);\n\t\tsize_m = 0;\n\t}\n\tbool contains(value_type\
    \ l, value_type r) const {\n\t\tassert(l <= r);\n\t\tauto [L, R] = prev_range(l);\n\
    \t\treturn L <= l && r <= R;\n\t}\n\tbool contains(value_type x) const {\n\t\t\
    return contains(x, x);\n\t}\n\tvalue_type insert(value_type l, value_type r) {\n\
    \t\tassert(l <= r);\n\t\tauto it = prev_range_iterator(l);\n\t\tvalue_type erased_count\
    \ = 0;\n\t\tif (l < it->first || it->second < r) {\n\t\t\tif (it->first <= l &&\
    \ l <= it->second + 1) {\n\t\t\t\tl = it->first;\n\t\t\t\terased_count += it->second\
    \ - it->first + 1;\n\t\t\t\tit = ranges.erase(it);\n\t\t\t} else {\n\t\t\t\tit\
    \ = next(it);\n\t\t\t}\n\t\t\twhile (r > it->second) {\n\t\t\t\terased_count +=\
    \ it->second - it->first + 1;\n\t\t\t\tit = ranges.erase(it);\n\t\t\t}\n\t\t\t\
    if (it->first - 1 <= r && r <= it->second) {\n\t\t\t\terased_count += it->second\
    \ - it->first + 1;\n\t\t\t\tr = it->second;\n\t\t\t\tranges.erase(it);\n\t\t\t\
    }\n\t\t\tranges.emplace(l, r);\n\t\t}\n\t\tvalue_type inserted_count = r - l +\
    \ 1 - erased_count;\n\t\tsize_m += inserted_count;\n\t\treturn inserted_count;\n\
    \t}\n\tvalue_type insert(value_type x) {\n\t\treturn insert(x, x);\n\t}\n\tvalue_type\
    \ erase(value_type l, value_type r) {\n\t\tassert(l <= r);\n\t\tauto it = prev_range_iterator(l);\n\
    \t\tvalue_type erased_count = 0;\n\t\tif (it->first <= l && r <= it->second) {\n\
    \t\t\tif (it->first < l) {\n\t\t\t\tranges.emplace(it->first, l - 1);\n\t\t\t\
    }\n\t\t\tif (r < it->second) {\n\t\t\t\tranges.emplace(r + 1, it->second);\n\t\
    \t\t}\n\t\t\tranges.erase(it);\n\t\t\terased_count = r - l + 1;\n\t\t} else {\n\
    \t\t\tif (it->first <= l && l <= it->second) {\n\t\t\t\terased_count += it->second\
    \ - l + 1;\n\t\t\t\tif (it->first < l) {\n\t\t\t\t\tranges.emplace(it->first,\
    \ l - 1);\n\t\t\t\t}\n\t\t\t\tit = ranges.erase(it);\n\t\t\t} else {\n\t\t\t\t\
    it = next(it);\n\t\t\t}\n\t\t\twhile (it->second <= r) {\n\t\t\t\terased_count\
    \ += it->second - it->first + 1;\n\t\t\t\tit = ranges.erase(it);\n\t\t\t}\n\t\t\
    \tif (it->first <= r && r <= it->second) {\n\t\t\t\terased_count += r - it->first\
    \ + 1;\n\t\t\t\tif (r < it->second) {\n\t\t\t\t\tranges.emplace(r + 1, it->second);\n\
    \t\t\t\t}\n\t\t\t\tranges.erase(it);\n\t\t\t}\n\t\t}\n\t\tsize_m -= erased_count;\n\
    \t\treturn erased_count;\n\t}\n\tvalue_type erase(value_type x) {\n\t\treturn\
    \ erase(x, x);\n\t}\n\tvalue_type find_next(value_type x) const {\n\t\tauto [l,\
    \ r] = prev_range(x);\n\t\tif (l <= x && x <= r) {\n\t\t\treturn x;\n\t\t} else\
    \ {\n\t\t\treturn l;\n\t\t}\n\t}\n\tvalue_type mex(value_type x) const {\n\t\t\
    auto [l, r] = prev_range(x);\n\t\tif (l <= x && x <= r) {\n\t\t\treturn r + 1;\n\
    \t\t} else {\n\t\t\treturn x;\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n#include <set>\n#include <utility>\n#include <cassert>\nusing\
    \ namespace std;\n\ntemplate <class T> class RangeSet {\npublic:\n\tusing size_type\
    \ = size_t;\n\tusing value_type = T;\n\tusing range_type = pair<value_type, value_type>;\n\
    \nprivate:\n\tconstexpr static value_type MIN = numeric_limits<value_type>::min();\n\
    \tconstexpr static value_type MAX = numeric_limits<value_type>::max();\n\tset<range_type>\
    \ ranges;\n\tsize_t size_m;\n\n\tauto prev_range_iterator(value_type x) const\
    \ {\n\t\treturn prev(ranges.lower_bound({x + 1, x + 1}));\n\t}\n\trange_type prev_range(value_type\
    \ x) const {\n\t\treturn *prev_range_iterator(x);\n\t}\n\npublic:\n\tRangeSet()\
    \ : size_m(0) {\n\t\tranges.emplace(MIN, MIN);\n\t\tranges.emplace(MAX, MAX);\n\
    \t};\n\tsize_t size() const {\n\t\treturn size_m;\n\t}\n\tsize_t count_ranges()\
    \ const {\n\t\treturn ranges.size() - 2;\n\t}\n\tbool empty() const {\n\t\treturn\
    \ size() == 0;\n\t}\n\tvoid clear() {\n\t\tranges.clear();\n\t\tranges.emplace(MIN,\
    \ MIN);\n\t\tranges.smplace(MAX, MAX);\n\t\tsize_m = 0;\n\t}\n\tbool contains(value_type\
    \ l, value_type r) const {\n\t\tassert(l <= r);\n\t\tauto [L, R] = prev_range(l);\n\
    \t\treturn L <= l && r <= R;\n\t}\n\tbool contains(value_type x) const {\n\t\t\
    return contains(x, x);\n\t}\n\tvalue_type insert(value_type l, value_type r) {\n\
    \t\tassert(l <= r);\n\t\tauto it = prev_range_iterator(l);\n\t\tvalue_type erased_count\
    \ = 0;\n\t\tif (l < it->first || it->second < r) {\n\t\t\tif (it->first <= l &&\
    \ l <= it->second + 1) {\n\t\t\t\tl = it->first;\n\t\t\t\terased_count += it->second\
    \ - it->first + 1;\n\t\t\t\tit = ranges.erase(it);\n\t\t\t} else {\n\t\t\t\tit\
    \ = next(it);\n\t\t\t}\n\t\t\twhile (r > it->second) {\n\t\t\t\terased_count +=\
    \ it->second - it->first + 1;\n\t\t\t\tit = ranges.erase(it);\n\t\t\t}\n\t\t\t\
    if (it->first - 1 <= r && r <= it->second) {\n\t\t\t\terased_count += it->second\
    \ - it->first + 1;\n\t\t\t\tr = it->second;\n\t\t\t\tranges.erase(it);\n\t\t\t\
    }\n\t\t\tranges.emplace(l, r);\n\t\t}\n\t\tvalue_type inserted_count = r - l +\
    \ 1 - erased_count;\n\t\tsize_m += inserted_count;\n\t\treturn inserted_count;\n\
    \t}\n\tvalue_type insert(value_type x) {\n\t\treturn insert(x, x);\n\t}\n\tvalue_type\
    \ erase(value_type l, value_type r) {\n\t\tassert(l <= r);\n\t\tauto it = prev_range_iterator(l);\n\
    \t\tvalue_type erased_count = 0;\n\t\tif (it->first <= l && r <= it->second) {\n\
    \t\t\tif (it->first < l) {\n\t\t\t\tranges.emplace(it->first, l - 1);\n\t\t\t\
    }\n\t\t\tif (r < it->second) {\n\t\t\t\tranges.emplace(r + 1, it->second);\n\t\
    \t\t}\n\t\t\tranges.erase(it);\n\t\t\terased_count = r - l + 1;\n\t\t} else {\n\
    \t\t\tif (it->first <= l && l <= it->second) {\n\t\t\t\terased_count += it->second\
    \ - l + 1;\n\t\t\t\tif (it->first < l) {\n\t\t\t\t\tranges.emplace(it->first,\
    \ l - 1);\n\t\t\t\t}\n\t\t\t\tit = ranges.erase(it);\n\t\t\t} else {\n\t\t\t\t\
    it = next(it);\n\t\t\t}\n\t\t\twhile (it->second <= r) {\n\t\t\t\terased_count\
    \ += it->second - it->first + 1;\n\t\t\t\tit = ranges.erase(it);\n\t\t\t}\n\t\t\
    \tif (it->first <= r && r <= it->second) {\n\t\t\t\terased_count += r - it->first\
    \ + 1;\n\t\t\t\tif (r < it->second) {\n\t\t\t\t\tranges.emplace(r + 1, it->second);\n\
    \t\t\t\t}\n\t\t\t\tranges.erase(it);\n\t\t\t}\n\t\t}\n\t\tsize_m -= erased_count;\n\
    \t\treturn erased_count;\n\t}\n\tvalue_type erase(value_type x) {\n\t\treturn\
    \ erase(x, x);\n\t}\n\tvalue_type find_next(value_type x) const {\n\t\tauto [l,\
    \ r] = prev_range(x);\n\t\tif (l <= x && x <= r) {\n\t\t\treturn x;\n\t\t} else\
    \ {\n\t\t\treturn l;\n\t\t}\n\t}\n\tvalue_type mex(value_type x) const {\n\t\t\
    auto [l, r] = prev_range(x);\n\t\tif (l <= x && x <= r) {\n\t\t\treturn r + 1;\n\
    \t\t} else {\n\t\t\treturn x;\n\t\t}\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/RangeSet.cpp
  requiredBy: []
  timestamp: '2020-11-16 19:15:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/RangeSet.test.cpp
documentation_of: DataStructure/RangeSet.cpp
layout: document
redirect_from:
- /library/DataStructure/RangeSet.cpp
- /library/DataStructure/RangeSet.cpp.html
title: DataStructure/RangeSet.cpp
---
