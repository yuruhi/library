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
  bundledCode: "#line 2 \"DataStructure/Imos2D.cpp\"\n#include <vector>\n#include\
    \ <utility>\n#include <cassert>\n\ntemplate <class T> class Imos2D {\npublic:\n\
    \tusing value_type = T;\n\tusing data_type = std::vector<std::vector<value_type>>;\n\
    \nprivate:\n\tstd::size_t h, w;\n\tdata_type table;\n\tbool builded = false;\n\
    \npublic:\n\tImos2D(std::size_t _h, std::size_t _w)\n\t    : h(_h), w(_w), table(_h\
    \ + 1, std::vector<T>(_w + 1)) {}\n\tstd::size_t height() const {\n\t\treturn\
    \ h;\n\t}\n\tstd::size_t weight() const {\n\t\treturn w;\n\t}\n\t// [x1, x2) *\
    \ [y1, y2)\n\tvoid add(std::size_t y1, std::size_t y2, std::size_t x1, std::size_t\
    \ x2,\n\t         const T& value = 1) {\n\t\tassert(0 <= x1 && x1 < x2 && x2 <=\
    \ w);\n\t\tassert(0 <= y1 && y1 < y2 && y2 <= h);\n\t\tassert(!builded);\n\t\t\
    table[y1][x1] += value;\n\t\ttable[y1][x2] -= value;\n\t\ttable[y2][x1] -= value;\n\
    \t\ttable[y2][x2] += value;\n\t}\n\tvoid add(const std::pair<std::size_t, std::size_t>&\
    \ y,\n\t         const std::pair<std::size_t, std::size_t>& x, const T& value\
    \ = 1) {\n\t\tassert(!builded);\n\t\tadd(y.first, y.second, x.first, x.second,\
    \ value);\n\t}\n\tvoid build() {\n\t\tbuilded = true;\n\t\tfor (std::size_t y\
    \ = 0; y <= h; ++y) {\n\t\t\tfor (std::size_t x = 1; x <= w; ++x) {\n\t\t\t\t\
    table[y][x] += table[y][x - 1];\n\t\t\t}\n\t\t}\n\t\tfor (std::size_t y = 1; y\
    \ <= h; ++y) {\n\t\t\tfor (std::size_t x = 0; x <= w; ++x) {\n\t\t\t\ttable[y][x]\
    \ += table[y - 1][x];\n\t\t\t}\n\t\t}\n\t}\n\tconst value_type& operator()(std::size_t\
    \ y, std::size_t x) const {\n\t\tassert(builded);\n\t\treturn table[y][x];\n\t\
    }\n\tconst data_type& operator*() const {\n\t\tassert(builded);\n\t\treturn table;\n\
    \t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <cassert>\n\
    \ntemplate <class T> class Imos2D {\npublic:\n\tusing value_type = T;\n\tusing\
    \ data_type = std::vector<std::vector<value_type>>;\n\nprivate:\n\tstd::size_t\
    \ h, w;\n\tdata_type table;\n\tbool builded = false;\n\npublic:\n\tImos2D(std::size_t\
    \ _h, std::size_t _w)\n\t    : h(_h), w(_w), table(_h + 1, std::vector<T>(_w +\
    \ 1)) {}\n\tstd::size_t height() const {\n\t\treturn h;\n\t}\n\tstd::size_t weight()\
    \ const {\n\t\treturn w;\n\t}\n\t// [x1, x2) * [y1, y2)\n\tvoid add(std::size_t\
    \ y1, std::size_t y2, std::size_t x1, std::size_t x2,\n\t         const T& value\
    \ = 1) {\n\t\tassert(0 <= x1 && x1 < x2 && x2 <= w);\n\t\tassert(0 <= y1 && y1\
    \ < y2 && y2 <= h);\n\t\tassert(!builded);\n\t\ttable[y1][x1] += value;\n\t\t\
    table[y1][x2] -= value;\n\t\ttable[y2][x1] -= value;\n\t\ttable[y2][x2] += value;\n\
    \t}\n\tvoid add(const std::pair<std::size_t, std::size_t>& y,\n\t         const\
    \ std::pair<std::size_t, std::size_t>& x, const T& value = 1) {\n\t\tassert(!builded);\n\
    \t\tadd(y.first, y.second, x.first, x.second, value);\n\t}\n\tvoid build() {\n\
    \t\tbuilded = true;\n\t\tfor (std::size_t y = 0; y <= h; ++y) {\n\t\t\tfor (std::size_t\
    \ x = 1; x <= w; ++x) {\n\t\t\t\ttable[y][x] += table[y][x - 1];\n\t\t\t}\n\t\t\
    }\n\t\tfor (std::size_t y = 1; y <= h; ++y) {\n\t\t\tfor (std::size_t x = 0; x\
    \ <= w; ++x) {\n\t\t\t\ttable[y][x] += table[y - 1][x];\n\t\t\t}\n\t\t}\n\t}\n\
    \tconst value_type& operator()(std::size_t y, std::size_t x) const {\n\t\tassert(builded);\n\
    \t\treturn table[y][x];\n\t}\n\tconst data_type& operator*() const {\n\t\tassert(builded);\n\
    \t\treturn table;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Imos2D.cpp
  requiredBy: []
  timestamp: '2021-04-06 14:24:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Imos2D.cpp
layout: document
redirect_from:
- /library/DataStructure/Imos2D.cpp
- /library/DataStructure/Imos2D.cpp.html
title: DataStructure/Imos2D.cpp
---
