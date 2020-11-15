---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/RangeSet.cpp\"\n#include <set>\n#include <utility>\n\
    #include <iostream>\nusing namespace std;\n\ntemplate <class T> class RangeSet\
    \ {\n\tconstexpr static T MIN = numeric_limits<T>::min();\n\tconstexpr static\
    \ T MAX = numeric_limits<T>::max();\n\tset<pair<T, T>> ranges;\n\n\tauto next_range_iterator(T\
    \ x) const {\n\t\treturn prev(ranges.lower_bound({x + 1, x + 1}));\n\t}\n\tpair<T,\
    \ T> next_range(T x) const {\n\t\treturn *next_range_iterator(x);\n\t}\n\npublic:\n\
    \tRangeSet() {\n\t\tranges.emplace(MIN, MIN);\n\t\tranges.emplace(MAX, MAX);\n\
    \t};\n\tsize_t size() const {\n\t\treturn ranges.size() - 2;\n\t}\n\tvoid clear()\
    \ {\n\t\tranges.clear();\n\t\tranges.emplace(MIN, MIN);\n\t\tranges.smplace(MAX,\
    \ MAX);\n\t}\n\tbool empty() const {\n\t\treturn size() == 0;\n\t}\n\tbool covered(T\
    \ l, T r) const {\n\t\tassert(l <= r);\n\t\tauto [L, R] = next_range(l);\n\t\t\
    return L <= l && r <= R;\n\t}\n\tbool coverd(T x) const {\n\t\treturn covered(x,\
    \ x);\n\t}\n\tT insert(T l, T r) {\n\t\tassert(l <= r);\n\t\tauto it = next_range_iterator(l);\n\
    \t\tif (it->first <= l && r <= it->second) {\n\t\t\treturn 0;\n\t\t}\n\n\t\tT\
    \ erased_count = 0;\n\t\tif (it->first <= l && l <= it->second + 1) {\n\t\t\t\
    l = it->first;\n\t\t\terased_count += it->second - it->first + 1;\n\t\t\tit =\
    \ ranges.erase(it);\n\t\t} else {\n\t\t\tit = next(it);\n\t\t}\n\t\twhile (r >\
    \ it->second) {\n\t\t\terased_count += it->second - it->first + 1;\n\t\t\tit =\
    \ ranges.erase(it);\n\t\t}\n\t\tif (it->first - 1 <= r && r <= it->second) {\n\
    \t\t\terased_count += it->second - it->first + 1;\n\t\t\tr = it->second;\n\t\t\
    \tranges.erase(it);\n\t\t}\n\t\tranges.emplace(l, r);\n\t\treturn r - l + 1 -\
    \ erased_count;\n\t}\n\tT insert(T x) {\n\t\treturn insert(x, x);\n\t}\n\tT erase(T\
    \ l, T r) {\n\t\tassert(l <= r);\n\t\tauto it = next_range_iterator(l);\n\t\t\
    if (it->first <= l && r <= it->second) {\n\t\t\tif (it->first < l) {\n\t\t\t\t\
    ranges.emplace(it->first, l - 1);\n\t\t\t}\n\t\t\tif (r < it->second) {\n\t\t\t\
    \tranges.emplace(r + 1, it->second);\n\t\t\t}\n\t\t\tranges.erase(it);\n\t\t\t\
    return r - l + 1;\n\t\t}\n\n\t\tT erased_count = 0;\n\t\tif (it->first <= l &&\
    \ l <= it->second) {\n\t\t\terased_count += it->second - l + 1;\n\t\t\tif (it->first\
    \ < l) {\n\t\t\t\tranges.emplace(it->first, l - 1);\n\t\t\t}\n\t\t\tit = ranges.erase(it);\n\
    \t\t} else {\n\t\t\tit = next(it);\n\t\t}\n\t\twhile (it->second <= r) {\n\t\t\
    \terased_count += it->second - it->first + 1;\n\t\t\tit = ranges.erase(it);\n\t\
    \t}\n\t\tif (it->first <= r && r <= it->second) {\n\t\t\terased_count += r - it->first\
    \ + 1;\n\t\t\tif (r < it->second) {\n\t\t\t\tranges.emplace(r + 1, it->second);\n\
    \t\t\t}\n\t\t\tranges.erase(it);\n\t\t}\n\t\treturn erased_count;\n\t}\n\tT erase(T\
    \ x) {\n\t\treturn erase(x, x);\n\t}\n\tT find_next(T x) const {\n\t\tauto [l,\
    \ r] = next_range(x);\n\t\tif (l <= x && x <= r) {\n\t\t\treturn x;\n\t\t} else\
    \ {\n\t\t\treturn l;\n\t\t}\n\t}\n\tT mex(T x) const {\n\t\tauto [l, r] = next_range(x);\n\
    \t\tif (l <= x && x <= r) {\n\t\t\treturn r + 1;\n\t\t} else {\n\t\t\treturn x;\n\
    \t\t}\n\t}\n};\n"
  code: "#pragma once\n#include <set>\n#include <utility>\n#include <iostream>\nusing\
    \ namespace std;\n\ntemplate <class T> class RangeSet {\n\tconstexpr static T\
    \ MIN = numeric_limits<T>::min();\n\tconstexpr static T MAX = numeric_limits<T>::max();\n\
    \tset<pair<T, T>> ranges;\n\n\tauto next_range_iterator(T x) const {\n\t\treturn\
    \ prev(ranges.lower_bound({x + 1, x + 1}));\n\t}\n\tpair<T, T> next_range(T x)\
    \ const {\n\t\treturn *next_range_iterator(x);\n\t}\n\npublic:\n\tRangeSet() {\n\
    \t\tranges.emplace(MIN, MIN);\n\t\tranges.emplace(MAX, MAX);\n\t};\n\tsize_t size()\
    \ const {\n\t\treturn ranges.size() - 2;\n\t}\n\tvoid clear() {\n\t\tranges.clear();\n\
    \t\tranges.emplace(MIN, MIN);\n\t\tranges.smplace(MAX, MAX);\n\t}\n\tbool empty()\
    \ const {\n\t\treturn size() == 0;\n\t}\n\tbool covered(T l, T r) const {\n\t\t\
    assert(l <= r);\n\t\tauto [L, R] = next_range(l);\n\t\treturn L <= l && r <= R;\n\
    \t}\n\tbool coverd(T x) const {\n\t\treturn covered(x, x);\n\t}\n\tT insert(T\
    \ l, T r) {\n\t\tassert(l <= r);\n\t\tauto it = next_range_iterator(l);\n\t\t\
    if (it->first <= l && r <= it->second) {\n\t\t\treturn 0;\n\t\t}\n\n\t\tT erased_count\
    \ = 0;\n\t\tif (it->first <= l && l <= it->second + 1) {\n\t\t\tl = it->first;\n\
    \t\t\terased_count += it->second - it->first + 1;\n\t\t\tit = ranges.erase(it);\n\
    \t\t} else {\n\t\t\tit = next(it);\n\t\t}\n\t\twhile (r > it->second) {\n\t\t\t\
    erased_count += it->second - it->first + 1;\n\t\t\tit = ranges.erase(it);\n\t\t\
    }\n\t\tif (it->first - 1 <= r && r <= it->second) {\n\t\t\terased_count += it->second\
    \ - it->first + 1;\n\t\t\tr = it->second;\n\t\t\tranges.erase(it);\n\t\t}\n\t\t\
    ranges.emplace(l, r);\n\t\treturn r - l + 1 - erased_count;\n\t}\n\tT insert(T\
    \ x) {\n\t\treturn insert(x, x);\n\t}\n\tT erase(T l, T r) {\n\t\tassert(l <=\
    \ r);\n\t\tauto it = next_range_iterator(l);\n\t\tif (it->first <= l && r <= it->second)\
    \ {\n\t\t\tif (it->first < l) {\n\t\t\t\tranges.emplace(it->first, l - 1);\n\t\
    \t\t}\n\t\t\tif (r < it->second) {\n\t\t\t\tranges.emplace(r + 1, it->second);\n\
    \t\t\t}\n\t\t\tranges.erase(it);\n\t\t\treturn r - l + 1;\n\t\t}\n\n\t\tT erased_count\
    \ = 0;\n\t\tif (it->first <= l && l <= it->second) {\n\t\t\terased_count += it->second\
    \ - l + 1;\n\t\t\tif (it->first < l) {\n\t\t\t\tranges.emplace(it->first, l -\
    \ 1);\n\t\t\t}\n\t\t\tit = ranges.erase(it);\n\t\t} else {\n\t\t\tit = next(it);\n\
    \t\t}\n\t\twhile (it->second <= r) {\n\t\t\terased_count += it->second - it->first\
    \ + 1;\n\t\t\tit = ranges.erase(it);\n\t\t}\n\t\tif (it->first <= r && r <= it->second)\
    \ {\n\t\t\terased_count += r - it->first + 1;\n\t\t\tif (r < it->second) {\n\t\
    \t\t\tranges.emplace(r + 1, it->second);\n\t\t\t}\n\t\t\tranges.erase(it);\n\t\
    \t}\n\t\treturn erased_count;\n\t}\n\tT erase(T x) {\n\t\treturn erase(x, x);\n\
    \t}\n\tT find_next(T x) const {\n\t\tauto [l, r] = next_range(x);\n\t\tif (l <=\
    \ x && x <= r) {\n\t\t\treturn x;\n\t\t} else {\n\t\t\treturn l;\n\t\t}\n\t}\n\
    \tT mex(T x) const {\n\t\tauto [l, r] = next_range(x);\n\t\tif (l <= x && x <=\
    \ r) {\n\t\t\treturn r + 1;\n\t\t} else {\n\t\t\treturn x;\n\t\t}\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/RangeSet.cpp
  requiredBy: []
  timestamp: '2020-11-09 21:25:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/RangeSet.cpp
layout: document
redirect_from:
- /library/DataStructure/RangeSet.cpp
- /library/DataStructure/RangeSet.cpp.html
title: DataStructure/RangeSet.cpp
---
