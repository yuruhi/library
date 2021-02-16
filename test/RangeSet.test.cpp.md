---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/RangeSet.cpp
    title: DataStructure/RangeSet.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2880
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2880
  bundledCode: "#line 1 \"test/RangeSet.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2880\"\
    \n#line 2 \"DataStructure/RangeSet.cpp\"\n#include <set>\n#include <utility>\n\
    #include <optional>\n#include <limits>\n#include <cassert>\nusing namespace std;\n\
    \ntemplate <class T> class RangeSet {\npublic:\n\tusing size_type = size_t;\n\t\
    using value_type = T;\n\tusing range_type = pair<value_type, value_type>;\n\n\
    private:\n\tconstexpr static value_type MIN = numeric_limits<value_type>::min();\n\
    \tconstexpr static value_type MAX = numeric_limits<value_type>::max();\n\tset<range_type>\
    \ ranges;\n\tsize_t size_m;\n\n\tauto prev_range_iterator(value_type x) const\
    \ {\n\t\treturn prev(ranges.lower_bound({x + 1, x + 1}));\n\t}\n\trange_type prev_range(value_type\
    \ x) const {\n\t\treturn *prev_range_iterator(x);\n\t}\n\npublic:\n\tRangeSet()\
    \ : size_m(0) {\n\t\tranges.emplace(MIN, MIN);\n\t\tranges.emplace(MAX, MAX);\n\
    \t};\n\tsize_t size() const {\n\t\treturn size_m;\n\t}\n\tsize_t count_ranges()\
    \ const {\n\t\treturn ranges.size() - 2;\n\t}\n\tbool empty() const {\n\t\treturn\
    \ size() == 0;\n\t}\n\tvoid clear() {\n\t\tranges.clear();\n\t\tranges.emplace(MIN,\
    \ MIN);\n\t\tranges.smplace(MAX, MAX);\n\t\tsize_m = 0;\n\t}\n\tconst set<range_type>&\
    \ data() const {\n\t\treturn ranges;\n\t}\n\tbool contains(value_type l, value_type\
    \ r) const {\n\t\tassert(l <= r);\n\t\tauto [L, R] = prev_range(l);\n\t\treturn\
    \ L <= l && r <= R;\n\t}\n\tbool contains(value_type x) const {\n\t\treturn contains(x,\
    \ x);\n\t}\n\tvalue_type insert(value_type l, value_type r) {\n\t\tassert(l <=\
    \ r);\n\t\tauto it = prev_range_iterator(l);\n\t\tvalue_type inserted_count =\
    \ 0;\n\t\tif (l < it->first || it->second < r) {\n\t\t\tif (it->first <= l &&\
    \ l <= it->second + 1) {\n\t\t\t\tl = it->first;\n\t\t\t\tinserted_count -= it->second\
    \ - it->first + 1;\n\t\t\t\tit = ranges.erase(it);\n\t\t\t} else {\n\t\t\t\tit\
    \ = next(it);\n\t\t\t}\n\t\t\twhile (r > it->second) {\n\t\t\t\tinserted_count\
    \ -= it->second - it->first + 1;\n\t\t\t\tit = ranges.erase(it);\n\t\t\t}\n\t\t\
    \tif (it->first - 1 <= r && r <= it->second) {\n\t\t\t\tr = it->second;\n\t\t\t\
    \tinserted_count -= it->second - it->first + 1;\n\t\t\t\tranges.erase(it);\n\t\
    \t\t}\n\t\t\tinserted_count += r - l + 1;\n\t\t\tranges.emplace(l, r);\n\t\t}\n\
    \t\tsize_m += inserted_count;\n\t\treturn inserted_count;\n\t}\n\tvalue_type insert(value_type\
    \ x) {\n\t\treturn insert(x, x);\n\t}\n\tvalue_type erase(value_type l, value_type\
    \ r) {\n\t\tassert(l <= r);\n\t\tauto it = prev_range_iterator(l);\n\t\tvalue_type\
    \ erased_count = 0;\n\t\tif (it->first <= l && r <= it->second) {\n\t\t\tif (it->first\
    \ < l) {\n\t\t\t\tranges.emplace(it->first, l - 1);\n\t\t\t}\n\t\t\tif (r < it->second)\
    \ {\n\t\t\t\tranges.emplace(r + 1, it->second);\n\t\t\t}\n\t\t\tranges.erase(it);\n\
    \t\t\terased_count = r - l + 1;\n\t\t} else {\n\t\t\tif (it->first <= l && l <=\
    \ it->second) {\n\t\t\t\terased_count += it->second - l + 1;\n\t\t\t\tif (it->first\
    \ < l) {\n\t\t\t\t\tranges.emplace(it->first, l - 1);\n\t\t\t\t}\n\t\t\t\tit =\
    \ ranges.erase(it);\n\t\t\t} else {\n\t\t\t\tit = next(it);\n\t\t\t}\n\t\t\twhile\
    \ (it->second <= r) {\n\t\t\t\terased_count += it->second - it->first + 1;\n\t\
    \t\t\tit = ranges.erase(it);\n\t\t\t}\n\t\t\tif (it->first <= r && r <= it->second)\
    \ {\n\t\t\t\terased_count += r - it->first + 1;\n\t\t\t\tif (r < it->second) {\n\
    \t\t\t\t\tranges.emplace(r + 1, it->second);\n\t\t\t\t}\n\t\t\t\tranges.erase(it);\n\
    \t\t\t}\n\t\t}\n\t\tsize_m -= erased_count;\n\t\treturn erased_count;\n\t}\n\t\
    value_type erase(value_type x) {\n\t\treturn erase(x, x);\n\t}\n\tvalue_type find_next(value_type\
    \ x) const {\n\t\tauto [l, r] = prev_range(x);\n\t\tif (l <= x && x <= r) {\n\t\
    \t\treturn x;\n\t\t} else {\n\t\t\treturn l;\n\t\t}\n\t}\n\tvalue_type mex(value_type\
    \ x) const {\n\t\tauto [l, r] = prev_range(x);\n\t\tif (l <= x && x <= r) {\n\t\
    \t\treturn r + 1;\n\t\t} else {\n\t\t\treturn x;\n\t\t}\n\t}\n\toptional<range_type>\
    \ find_range(value_type x) const {\n\t\trange_type r = prev_range(x);\n\t\tif\
    \ (r.first <= x && x <= r.second) {\n\t\t\treturn r;\n\t\t} else {\n\t\t\treturn\
    \ nullopt;\n\t\t}\n\t}\n};\n#line 3 \"test/RangeSet.test.cpp\"\n#include <iostream>\n\
    #include <vector>\n#include <map>\n#include <tuple>\n#include <algorithm>\nusing\
    \ namespace std;\n\nstruct Data {\n\tbool query;\n\tint a, b, i;\n\tData() = default;\n\
    \tData(bool _q, int _a, int _b, int _i) : query(_q), a(_a), b(_b), i(_i) {}\n\t\
    friend bool operator<(const Data& d1, const Data& d2) {\n\t\treturn !d1.query\
    \ < !d2.query;\n\t}\n};\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tint n, m, q;\n\tcin >> n >> m >> q;\n\tmap<int, vector<Data>> data_map;\n\t\
    for (int i = 0; i < m; ++i) {\n\t\tint d, a, b;\n\t\tcin >> d >> a >> b;\n\t\t\
    data_map[d].emplace_back(false, a, b, i);\n\t}\n\tfor (int i = 0; i < q; ++i)\
    \ {\n\t\tint e, s, t;\n\t\tcin >> e >> s >> t;\n\t\tdata_map[e].emplace_back(true,\
    \ s, t, i);\n\t}\n\n\tvector<bool> ans(q);\n\tRangeSet<int> range_set;\n\tfor\
    \ (auto [time, datas] : data_map) {\n\t\tsort(datas.begin(), datas.end());\n\t\
    \tfor (const Data& data : datas) {\n\t\t\tif (data.query) {\n\t\t\t\tif (data.a\
    \ < data.b) {\n\t\t\t\t\tans[data.i] = range_set.contains(data.a, data.b - 1);\n\
    \t\t\t\t} else {\n\t\t\t\t\tans[data.i] = true;\n\t\t\t\t}\n\t\t\t} else {\n\t\
    \t\t\trange_set.insert(data.a, data.b - 1);\n\t\t\t}\n\t\t}\n\t}\n\tfor (bool\
    \ f : ans) {\n\t\tcout << (f ? \"Yes\" : \"No\") << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2880\"\n#include\
    \ \"./../DataStructure/RangeSet.cpp\"\n#include <iostream>\n#include <vector>\n\
    #include <map>\n#include <tuple>\n#include <algorithm>\nusing namespace std;\n\
    \nstruct Data {\n\tbool query;\n\tint a, b, i;\n\tData() = default;\n\tData(bool\
    \ _q, int _a, int _b, int _i) : query(_q), a(_a), b(_b), i(_i) {}\n\tfriend bool\
    \ operator<(const Data& d1, const Data& d2) {\n\t\treturn !d1.query < !d2.query;\n\
    \t}\n};\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tint n, m, q;\n\tcin >> n >> m >> q;\n\tmap<int, vector<Data>> data_map;\n\t\
    for (int i = 0; i < m; ++i) {\n\t\tint d, a, b;\n\t\tcin >> d >> a >> b;\n\t\t\
    data_map[d].emplace_back(false, a, b, i);\n\t}\n\tfor (int i = 0; i < q; ++i)\
    \ {\n\t\tint e, s, t;\n\t\tcin >> e >> s >> t;\n\t\tdata_map[e].emplace_back(true,\
    \ s, t, i);\n\t}\n\n\tvector<bool> ans(q);\n\tRangeSet<int> range_set;\n\tfor\
    \ (auto [time, datas] : data_map) {\n\t\tsort(datas.begin(), datas.end());\n\t\
    \tfor (const Data& data : datas) {\n\t\t\tif (data.query) {\n\t\t\t\tif (data.a\
    \ < data.b) {\n\t\t\t\t\tans[data.i] = range_set.contains(data.a, data.b - 1);\n\
    \t\t\t\t} else {\n\t\t\t\t\tans[data.i] = true;\n\t\t\t\t}\n\t\t\t} else {\n\t\
    \t\t\trange_set.insert(data.a, data.b - 1);\n\t\t\t}\n\t\t}\n\t}\n\tfor (bool\
    \ f : ans) {\n\t\tcout << (f ? \"Yes\" : \"No\") << '\\n';\n\t}\n}"
  dependsOn:
  - DataStructure/RangeSet.cpp
  isVerificationFile: true
  path: test/RangeSet.test.cpp
  requiredBy: []
  timestamp: '2021-02-15 18:37:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/RangeSet.test.cpp
layout: document
redirect_from:
- /verify/test/RangeSet.test.cpp
- /verify/test/RangeSet.test.cpp.html
title: test/RangeSet.test.cpp
---
