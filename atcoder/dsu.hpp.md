---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/dsu.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace atcoder {\n\n\t// Implement (union\
    \ by size) + (path compression)\n\t// Reference:\n\t// Zvi Galil and Giuseppe\
    \ F. Italiano,\n\t// Data structures and algorithms for disjoint set union problems\n\
    \tstruct dsu {\n\tpublic:\n\t\tdsu() : _n(0) {}\n\t\tdsu(int n) : _n(n), parent_or_size(n,\
    \ -1) {}\n\n\t\tint merge(int a, int b) {\n\t\t\tassert(0 <= a && a < _n);\n\t\
    \t\tassert(0 <= b && b < _n);\n\t\t\tint x = leader(a), y = leader(b);\n\t\t\t\
    if (x == y) return x;\n\t\t\tif (-parent_or_size[x] < -parent_or_size[y]) std::swap(x,\
    \ y);\n\t\t\tparent_or_size[x] += parent_or_size[y];\n\t\t\tparent_or_size[y]\
    \ = x;\n\t\t\treturn x;\n\t\t}\n\n\t\tbool same(int a, int b) {\n\t\t\tassert(0\
    \ <= a && a < _n);\n\t\t\tassert(0 <= b && b < _n);\n\t\t\treturn leader(a) ==\
    \ leader(b);\n\t\t}\n\n\t\tint leader(int a) {\n\t\t\tassert(0 <= a && a < _n);\n\
    \t\t\tif (parent_or_size[a] < 0) return a;\n\t\t\treturn parent_or_size[a] = leader(parent_or_size[a]);\n\
    \t\t}\n\n\t\tint size(int a) {\n\t\t\tassert(0 <= a && a < _n);\n\t\t\treturn\
    \ -parent_or_size[leader(a)];\n\t\t}\n\n\t\tstd::vector<std::vector<int>> groups()\
    \ {\n\t\t\tstd::vector<int> leader_buf(_n), group_size(_n);\n\t\t\tfor (int i\
    \ = 0; i < _n; i++) {\n\t\t\t\tleader_buf[i] = leader(i);\n\t\t\t\tgroup_size[leader_buf[i]]++;\n\
    \t\t\t}\n\t\t\tstd::vector<std::vector<int>> result(_n);\n\t\t\tfor (int i = 0;\
    \ i < _n; i++) {\n\t\t\t\tresult[i].reserve(group_size[i]);\n\t\t\t}\n\t\t\tfor\
    \ (int i = 0; i < _n; i++) {\n\t\t\t\tresult[leader_buf[i]].push_back(i);\n\t\t\
    \t}\n\t\t\tresult.erase(std::remove_if(result.begin(), result.end(),\n\t\t\t \
    \                           [&](const std::vector<int>& v) {\n\t\t\t\t       \
    \                     return v.empty();\n\t\t\t                            }),\n\
    \t\t\t             result.end());\n\t\t\treturn result;\n\t\t}\n\n\tprivate:\n\
    \t\tint _n;\n\t\t// root node: -1 * component size\n\t\t// otherwise: parent\n\
    \t\tstd::vector<int> parent_or_size;\n\t};\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_DSU_HPP\n#define ATCODER_DSU_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\nnamespace atcoder {\n\n\t// Implement\
    \ (union by size) + (path compression)\n\t// Reference:\n\t// Zvi Galil and Giuseppe\
    \ F. Italiano,\n\t// Data structures and algorithms for disjoint set union problems\n\
    \tstruct dsu {\n\tpublic:\n\t\tdsu() : _n(0) {}\n\t\tdsu(int n) : _n(n), parent_or_size(n,\
    \ -1) {}\n\n\t\tint merge(int a, int b) {\n\t\t\tassert(0 <= a && a < _n);\n\t\
    \t\tassert(0 <= b && b < _n);\n\t\t\tint x = leader(a), y = leader(b);\n\t\t\t\
    if (x == y) return x;\n\t\t\tif (-parent_or_size[x] < -parent_or_size[y]) std::swap(x,\
    \ y);\n\t\t\tparent_or_size[x] += parent_or_size[y];\n\t\t\tparent_or_size[y]\
    \ = x;\n\t\t\treturn x;\n\t\t}\n\n\t\tbool same(int a, int b) {\n\t\t\tassert(0\
    \ <= a && a < _n);\n\t\t\tassert(0 <= b && b < _n);\n\t\t\treturn leader(a) ==\
    \ leader(b);\n\t\t}\n\n\t\tint leader(int a) {\n\t\t\tassert(0 <= a && a < _n);\n\
    \t\t\tif (parent_or_size[a] < 0) return a;\n\t\t\treturn parent_or_size[a] = leader(parent_or_size[a]);\n\
    \t\t}\n\n\t\tint size(int a) {\n\t\t\tassert(0 <= a && a < _n);\n\t\t\treturn\
    \ -parent_or_size[leader(a)];\n\t\t}\n\n\t\tstd::vector<std::vector<int>> groups()\
    \ {\n\t\t\tstd::vector<int> leader_buf(_n), group_size(_n);\n\t\t\tfor (int i\
    \ = 0; i < _n; i++) {\n\t\t\t\tleader_buf[i] = leader(i);\n\t\t\t\tgroup_size[leader_buf[i]]++;\n\
    \t\t\t}\n\t\t\tstd::vector<std::vector<int>> result(_n);\n\t\t\tfor (int i = 0;\
    \ i < _n; i++) {\n\t\t\t\tresult[i].reserve(group_size[i]);\n\t\t\t}\n\t\t\tfor\
    \ (int i = 0; i < _n; i++) {\n\t\t\t\tresult[leader_buf[i]].push_back(i);\n\t\t\
    \t}\n\t\t\tresult.erase(std::remove_if(result.begin(), result.end(),\n\t\t\t \
    \                           [&](const std::vector<int>& v) {\n\t\t\t\t       \
    \                     return v.empty();\n\t\t\t                            }),\n\
    \t\t\t             result.end());\n\t\t\treturn result;\n\t\t}\n\n\tprivate:\n\
    \t\tint _n;\n\t\t// root node: -1 * component size\n\t\t// otherwise: parent\n\
    \t\tstd::vector<int> parent_or_size;\n\t};\n\n}  // namespace atcoder\n\n#endif\
    \  // ATCODER_DSU_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/dsu.hpp
  requiredBy: []
  timestamp: '2020-10-30 19:21:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: atcoder/dsu.hpp
layout: document
redirect_from:
- /library/atcoder/dsu.hpp
- /library/atcoder/dsu.hpp.html
title: atcoder/dsu.hpp
---
