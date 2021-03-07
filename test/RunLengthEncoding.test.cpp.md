---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/RunLengthEncoding.cpp
    title: Utility/RunLengthEncoding.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/challenges/sources/JOI/Final/0506
    links:
    - https://onlinejudge.u-aizu.ac.jp/challenges/sources/JOI/Final/0506
  bundledCode: "#line 1 \"test/RunLengthEncoding.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/JOI/Final/0506\"\
    \n#line 2 \"Utility/RunLengthEncoding.cpp\"\n#include <vector>\n#include <iterator>\n\
    #include <utility>\n\ntemplate <class InputIterator, class value_type = typename\
    \ InputIterator::value_type>\nauto RunLengthEncoding(InputIterator first, InputIterator\
    \ last) {\n\tstd::vector<std::pair<std::size_t, value_type>> result;\n\tfor (;\
    \ first != last; ++first) {\n\t\tif (result.empty() || result.back().second !=\
    \ *first) {\n\t\t\tresult.emplace_back(1, *first);\n\t\t} else {\n\t\t\tresult.back().first++;\n\
    \t\t}\n\t}\n\treturn result;\n}\n\ntemplate <class Container> auto RunLengthEncoding(const\
    \ Container& a) {\n\treturn RunLengthEncoding(a.begin(), a.end());\n}\n\ntemplate\
    \ <class InputIterator, class value_type = typename InputIterator::value_type>\n\
    auto RunLengthEncoding_pair(InputIterator first, InputIterator last) {\n\tstd::vector<std::size_t>\
    \ count;\n\tstd::vector<value_type> value;\n\tfor (; first != last; ++first) {\n\
    \t\tif (value.empty() || value.back() != *first) {\n\t\t\tcount.push_back(1);\n\
    \t\t\tvalue.push_back(*first);\n\t\t} else {\n\t\t\tcount.back()++;\n\t\t}\n\t\
    }\n\treturn std::pair(count, value);\n}\n\ntemplate <class Container> auto RunLengthEncoding_pair(const\
    \ Container& a) {\n\treturn RunLengthEncoding_pair(a.begin(), a.end());\n}\n#line\
    \ 3 \"test/RunLengthEncoding.test.cpp\"\n#include <iostream>\n#include <string>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\twhile (true) {\n\t\tint n;\n\t\tcin >> n;\n\t\tif (n == 0) break;\n\t\tstring\
    \ s;\n\t\tcin >> s;\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tstring t;\n\t\t\t\
    for (auto [count, value] : RunLengthEncoding(s)) {\n\t\t\t\tt += to_string(count);\n\
    \t\t\t\tt += value;\n\t\t\t}\n\t\t\ts = t;\n\t\t}\n\t\tcout << s << endl;\n\t\
    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/JOI/Final/0506\"\
    \n#include \"./../Utility/RunLengthEncoding.cpp\"\n#include <iostream>\n#include\
    \ <string>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\twhile (true) {\n\t\tint n;\n\t\tcin >> n;\n\t\tif (n == 0) break;\n\t\tstring\
    \ s;\n\t\tcin >> s;\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tstring t;\n\t\t\t\
    for (auto [count, value] : RunLengthEncoding(s)) {\n\t\t\t\tt += to_string(count);\n\
    \t\t\t\tt += value;\n\t\t\t}\n\t\t\ts = t;\n\t\t}\n\t\tcout << s << endl;\n\t\
    }\n}"
  dependsOn:
  - Utility/RunLengthEncoding.cpp
  isVerificationFile: true
  path: test/RunLengthEncoding.test.cpp
  requiredBy: []
  timestamp: '2021-03-07 14:48:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/RunLengthEncoding.test.cpp
layout: document
redirect_from:
- /verify/test/RunLengthEncoding.test.cpp
- /verify/test/RunLengthEncoding.test.cpp.html
title: test/RunLengthEncoding.test.cpp
---
