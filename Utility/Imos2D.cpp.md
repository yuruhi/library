---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/Imos2D.cpp\"\n#include <vector>\n#include <utility>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> class Imos2D {\n\
    public:\n\tusing value_type = T;\n\tusing data_type = vector<vector<value_type>>;\n\
    \nprivate:\n\tsize_t h, w;\n\tdata_type table;\n\tbool builded = false;\n\npublic:\n\
    \tImos2D(size_t _h, size_t _w) : h(_h), w(_w), table(_h + 1, vector<T>(_w + 1))\
    \ {}\n\tsize_t height() const {\n\t\treturn h;\n\t}\n\tsize_t weight() const {\n\
    \t\treturn w;\n\t}\n\t// [x1, x2) * [y1, y2)\n\tvoid add(size_t y1, size_t y2,\
    \ size_t x1, size_t x2, const T& value = 1) {\n\t\tassert(0 <= x1 && x1 < x2 &&\
    \ x2 <= w);\n\t\tassert(0 <= y1 && y1 < y2 && y2 <= h);\n\t\tassert(!builded);\n\
    \t\ttable[y1][x1] += value;\n\t\ttable[y1][x2] -= value;\n\t\ttable[y2][x1] -=\
    \ value;\n\t\ttable[y2][x2] += value;\n\t}\n\tvoid add(const pair<size_t, size_t>&\
    \ y, const pair<size_t, size_t>& x,\n\t         const T& value = 1) {\n\t\tassert(!builded);\n\
    \t\tadd(y.first, y.second, x.first, x.second, value);\n\t}\n\tvoid build() {\n\
    \t\tbuilded = true;\n\t\tfor (size_t y = 0; y <= h; ++y) {\n\t\t\tfor (size_t\
    \ x = 1; x <= w; ++x) {\n\t\t\t\ttable[y][x] += table[y][x - 1];\n\t\t\t}\n\t\t\
    }\n\t\tfor (size_t y = 1; y <= h; ++y) {\n\t\t\tfor (size_t x = 0; x <= w; ++x)\
    \ {\n\t\t\t\ttable[y][x] += table[y - 1][x];\n\t\t\t}\n\t\t}\n\t}\n\tconst value_type&\
    \ operator()(size_t y, size_t x) const {\n\t\tassert(builded);\n\t\treturn table[y][x];\n\
    \t}\n\tconst data_type& operator*() const {\n\t\tassert(builded);\n\t\treturn\
    \ table;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <cassert>\n\
    using namespace std;\n\ntemplate <class T> class Imos2D {\npublic:\n\tusing value_type\
    \ = T;\n\tusing data_type = vector<vector<value_type>>;\n\nprivate:\n\tsize_t\
    \ h, w;\n\tdata_type table;\n\tbool builded = false;\n\npublic:\n\tImos2D(size_t\
    \ _h, size_t _w) : h(_h), w(_w), table(_h + 1, vector<T>(_w + 1)) {}\n\tsize_t\
    \ height() const {\n\t\treturn h;\n\t}\n\tsize_t weight() const {\n\t\treturn\
    \ w;\n\t}\n\t// [x1, x2) * [y1, y2)\n\tvoid add(size_t y1, size_t y2, size_t x1,\
    \ size_t x2, const T& value = 1) {\n\t\tassert(0 <= x1 && x1 < x2 && x2 <= w);\n\
    \t\tassert(0 <= y1 && y1 < y2 && y2 <= h);\n\t\tassert(!builded);\n\t\ttable[y1][x1]\
    \ += value;\n\t\ttable[y1][x2] -= value;\n\t\ttable[y2][x1] -= value;\n\t\ttable[y2][x2]\
    \ += value;\n\t}\n\tvoid add(const pair<size_t, size_t>& y, const pair<size_t,\
    \ size_t>& x,\n\t         const T& value = 1) {\n\t\tassert(!builded);\n\t\tadd(y.first,\
    \ y.second, x.first, x.second, value);\n\t}\n\tvoid build() {\n\t\tbuilded = true;\n\
    \t\tfor (size_t y = 0; y <= h; ++y) {\n\t\t\tfor (size_t x = 1; x <= w; ++x) {\n\
    \t\t\t\ttable[y][x] += table[y][x - 1];\n\t\t\t}\n\t\t}\n\t\tfor (size_t y = 1;\
    \ y <= h; ++y) {\n\t\t\tfor (size_t x = 0; x <= w; ++x) {\n\t\t\t\ttable[y][x]\
    \ += table[y - 1][x];\n\t\t\t}\n\t\t}\n\t}\n\tconst value_type& operator()(size_t\
    \ y, size_t x) const {\n\t\tassert(builded);\n\t\treturn table[y][x];\n\t}\n\t\
    const data_type& operator*() const {\n\t\tassert(builded);\n\t\treturn table;\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Imos2D.cpp
  requiredBy: []
  timestamp: '2020-11-21 14:30:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/Imos2D.cpp
layout: document
redirect_from:
- /library/Utility/Imos2D.cpp
- /library/Utility/Imos2D.cpp.html
title: Utility/Imos2D.cpp
---
