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
    PROBLEM: https://yukicoder.me/problems/no/674
    links:
    - https://yukicoder.me/problems/no/674
  bundledCode: "#line 1 \"test/RangeSet2.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/674\"\
    \n#line 2 \"DataStructure/RangeSet.cpp\"\n#include <set>\n#include <utility>\n\
    #include <optional>\n#include <limits>\n#include <cassert>\n\ntemplate <class\
    \ T> class RangeSet {\npublic:\n\tusing size_type = std::size_t;\n\tusing value_type\
    \ = T;\n\tusing range_type = std::pair<value_type, value_type>;\n\nprivate:\n\t\
    constexpr static value_type MIN = std::numeric_limits<value_type>::min();\n\t\
    constexpr static value_type MAX = std::numeric_limits<value_type>::max();\n\t\
    std::set<range_type> ranges;\n\tvalue_type size_m;\n\n\tauto prev_range_iterator(value_type\
    \ x) const {\n\t\treturn prev(ranges.lower_bound({x + 1, x + 1}));\n\t}\n\trange_type\
    \ prev_range(value_type x) const {\n\t\treturn *prev_range_iterator(x);\n\t}\n\
    \npublic:\n\tRangeSet() : size_m(0) {\n\t\tranges.emplace(MIN, MIN);\n\t\tranges.emplace(MAX,\
    \ MAX);\n\t};\n\tvalue_type size() const {\n\t\treturn size_m;\n\t}\n\tsize_type\
    \ count_ranges() const {\n\t\treturn ranges.size() - 2;\n\t}\n\tbool empty() const\
    \ {\n\t\treturn size() == 0;\n\t}\n\tvoid clear() {\n\t\tranges.clear();\n\t\t\
    ranges.emplace(MIN, MIN);\n\t\tranges.smplace(MAX, MAX);\n\t\tsize_m = 0;\n\t\
    }\n\tconst std::set<range_type>& data() const {\n\t\treturn ranges;\n\t}\n\tbool\
    \ contains(value_type l, value_type r) const {\n\t\tassert(l <= r);\n\t\tauto\
    \ [L, R] = prev_range(l);\n\t\treturn L <= l && r <= R;\n\t}\n\tbool contains(value_type\
    \ x) const {\n\t\treturn contains(x, x);\n\t}\n\tvalue_type insert(value_type\
    \ l, value_type r) {\n\t\tassert(l <= r);\n\t\tauto it = prev_range_iterator(l);\n\
    \t\tvalue_type inserted_count = 0;\n\t\tif (l < it->first || it->second < r) {\n\
    \t\t\tif (it->first <= l && l <= it->second + 1) {\n\t\t\t\tl = it->first;\n\t\
    \t\t\tinserted_count -= it->second - it->first + 1;\n\t\t\t\tit = ranges.erase(it);\n\
    \t\t\t} else {\n\t\t\t\tit = next(it);\n\t\t\t}\n\t\t\twhile (r > it->second)\
    \ {\n\t\t\t\tinserted_count -= it->second - it->first + 1;\n\t\t\t\tit = ranges.erase(it);\n\
    \t\t\t}\n\t\t\tif (it->first - 1 <= r && r <= it->second) {\n\t\t\t\tr = it->second;\n\
    \t\t\t\tinserted_count -= it->second - it->first + 1;\n\t\t\t\tranges.erase(it);\n\
    \t\t\t}\n\t\t\tinserted_count += r - l + 1;\n\t\t\tranges.emplace(l, r);\n\t\t\
    }\n\t\tsize_m += inserted_count;\n\t\treturn inserted_count;\n\t}\n\tvalue_type\
    \ insert(value_type x) {\n\t\treturn insert(x, x);\n\t}\n\tvalue_type erase(value_type\
    \ l, value_type r) {\n\t\tassert(l <= r);\n\t\tauto it = prev_range_iterator(l);\n\
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
    \t\t} else {\n\t\t\treturn x;\n\t\t}\n\t}\n\tstd::optional<range_type> find_range(value_type\
    \ x) const {\n\t\trange_type r = prev_range(x);\n\t\tif (r.first <= x && x <=\
    \ r.second) {\n\t\t\treturn r;\n\t\t} else {\n\t\t\treturn std::nullopt;\n\t\t\
    }\n\t}\n};\n#line 3 \"test/RangeSet2.test.cpp\"\n#include <iostream>\n#include\
    \ <algorithm>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tusing ll = long long;\n\n\tll d;\n\tint q;\n\tcin >> d >> q;\n\tRangeSet<ll>\
    \ range_set;\n\tll ans = 0;\n\twhile (q--) {\n\t\tll a, b;\n\t\tcin >> a >> b;\n\
    \t\trange_set.insert(a, b);\n\t\tauto r = *range_set.find_range(a);\n\t\tans =\
    \ max(ans, r.second - r.first + 1);\n\t\tcout << ans << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/674\"\n#include \"./../DataStructure/RangeSet.cpp\"\
    \n#include <iostream>\n#include <algorithm>\nusing namespace std;\n\nint main()\
    \ {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\tusing ll = long\
    \ long;\n\n\tll d;\n\tint q;\n\tcin >> d >> q;\n\tRangeSet<ll> range_set;\n\t\
    ll ans = 0;\n\twhile (q--) {\n\t\tll a, b;\n\t\tcin >> a >> b;\n\t\trange_set.insert(a,\
    \ b);\n\t\tauto r = *range_set.find_range(a);\n\t\tans = max(ans, r.second - r.first\
    \ + 1);\n\t\tcout << ans << '\\n';\n\t}\n}"
  dependsOn:
  - DataStructure/RangeSet.cpp
  isVerificationFile: true
  path: test/RangeSet2.test.cpp
  requiredBy: []
  timestamp: '2021-03-02 07:38:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/RangeSet2.test.cpp
layout: document
redirect_from:
- /verify/test/RangeSet2.test.cpp
- /verify/test/RangeSet2.test.cpp.html
title: test/RangeSet2.test.cpp
---
