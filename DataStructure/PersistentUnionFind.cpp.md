---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/PersistentArray.cpp
    title: DataStructure/PersistentArray.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/PersistentUnionFind.test.cpp
    title: test/PersistentUnionFind.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/PersistentUnionFind.cpp\"\n#include <utility>\n\
    #line 2 \"DataStructure/PersistentArray.cpp\"\n#include <array>\n#include <vector>\n\
    #include <memory>\nusing namespace std;\n\ntemplate <class T, size_t LOG> class\
    \ PersistentArray {\npublic:\n\tusing value_type = T;\n\tusing const_reference\
    \ = const value_type&;\n\nprivate:\n\tstruct node_type;\n\tusing node_ptr = shared_ptr<node_type>;\n\
    \tstatic constexpr size_t CHILD_SIZE = 1 << LOG;\n\tstruct node_type {\n\t\tvalue_type\
    \ value;\n\t\tarray<node_ptr, CHILD_SIZE> child;\n\t};\n\n\tnode_ptr root;\n\n\
    \tPersistentArray(node_ptr _root) : root(_root) {}\n\tvalue_type get(size_t i,\
    \ node_ptr p) const {\n\t\tif (!p) {\n\t\t\treturn value_type();\n\t\t} else if\
    \ (i == 0) {\n\t\t\treturn p->value;\n\t\t} else {\n\t\t\treturn get(i >> LOG,\
    \ p->child[i & (CHILD_SIZE - 1)]);\n\t\t}\n\t}\n\tnode_ptr set(size_t i, const_reference\
    \ val, node_ptr p) {\n\t\tnode_ptr result = p ? make_shared<node_type>(*p) : make_shared<node_type>();\n\
    \t\tif (i == 0) {\n\t\t\tresult->value = val;\n\t\t} else {\n\t\t\tsize_t index\
    \ = i & (CHILD_SIZE - 1);\n\t\t\tresult->child[index] = set(i >> LOG, val, result->child[index]);\n\
    \t\t}\n\t\treturn result;\n\t}\n\tvoid destructive_set(size_t i, const_reference\
    \ val, node_ptr& p) {\n\t\tif (!p) {\n\t\t\tp = make_shared<node_type>();\n\t\t\
    }\n\t\tif (i == 0) {\n\t\t\tp->value = val;\n\t\t} else {\n\t\t\tsize_t index\
    \ = i & (CHILD_SIZE - 1);\n\t\t\tdestructive_set(i >> LOG, val, p->child[index]);\n\
    \t\t}\n\t}\n\npublic:\n\tPersistentArray() : root() {}\n\tPersistentArray(const\
    \ vector<value_type>& v) : root() {\n\t\tfor (size_t i = 0; i < v.size(); ++i)\
    \ {\n\t\t\tdestructive_set(i, v[i]);\n\t\t}\n\t}\n\tvalue_type get(size_t i) const\
    \ {\n\t\treturn get(i, root);\n\t}\n\tvalue_type operator[](size_t i) const {\n\
    \t\treturn get(i);\n\t}\n\tvector<value_type> to_a(size_t n) const {\n\t\tvector<value_type>\
    \ result(n);\n\t\tfor (size_t i = 0; i < n; ++i) {\n\t\t\tresult[i] = get(i);\n\
    \t\t}\n\t\treturn result;\n\t}\n\tPersistentArray set(size_t i, const_reference\
    \ val) {\n\t\treturn PersistentArray(set(i, val, root));\n\t}\n\tvoid destructive_set(size_t\
    \ i, const_reference val) {\n\t\tdestructive_set(i, val, root);\n\t}\n};\n#line\
    \ 4 \"DataStructure/PersistentUnionFind.cpp\"\n\nclass PersistentUnionFind {\n\
    \tusing data_type = PersistentArray<int, 2>;\n\npublic:\n\tdata_type data;\n\t\
    PersistentUnionFind(const data_type& _data) : data(_data) {}\n\n\tPersistentUnionFind()\
    \ = default;\n\tPersistentUnionFind(int n) : data(vector(n, -1)) {}\n\tint root(int\
    \ k) const {\n\t\tint p = data[k];\n\t\treturn p >= 0 ? root(p) : k;\n\t}\n\t\
    bool same(int u, int v) const {\n\t\treturn root(u) == root(v);\n\t}\n\tint size(int\
    \ k) const {\n\t\treturn -data[root(k)];\n\t}\n\tpair<bool, PersistentUnionFind>\
    \ unite(int x, int y) {\n\t\tx = root(x);\n\t\ty = root(y);\n\t\tif (x == y) {\n\
    \t\t\treturn {false, *this};\n\t\t}\n\t\tif (data[x] > data[y]) {\n\t\t\tswap(x,\
    \ y);\n\t\t}\n\t\treturn {true, data.set(x, data[x] + data[y]).set(y, x)};\n\t\
    }\n};\n"
  code: "#pragma once\n#include <utility>\n#include \"./PersistentArray.cpp\"\n\n\
    class PersistentUnionFind {\n\tusing data_type = PersistentArray<int, 2>;\n\n\
    public:\n\tdata_type data;\n\tPersistentUnionFind(const data_type& _data) : data(_data)\
    \ {}\n\n\tPersistentUnionFind() = default;\n\tPersistentUnionFind(int n) : data(vector(n,\
    \ -1)) {}\n\tint root(int k) const {\n\t\tint p = data[k];\n\t\treturn p >= 0\
    \ ? root(p) : k;\n\t}\n\tbool same(int u, int v) const {\n\t\treturn root(u) ==\
    \ root(v);\n\t}\n\tint size(int k) const {\n\t\treturn -data[root(k)];\n\t}\n\t\
    pair<bool, PersistentUnionFind> unite(int x, int y) {\n\t\tx = root(x);\n\t\t\
    y = root(y);\n\t\tif (x == y) {\n\t\t\treturn {false, *this};\n\t\t}\n\t\tif (data[x]\
    \ > data[y]) {\n\t\t\tswap(x, y);\n\t\t}\n\t\treturn {true, data.set(x, data[x]\
    \ + data[y]).set(y, x)};\n\t}\n};\n"
  dependsOn:
  - DataStructure/PersistentArray.cpp
  isVerificationFile: false
  path: DataStructure/PersistentUnionFind.cpp
  requiredBy: []
  timestamp: '2020-11-16 17:59:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/PersistentUnionFind.test.cpp
documentation_of: DataStructure/PersistentUnionFind.cpp
layout: document
redirect_from:
- /library/DataStructure/PersistentUnionFind.cpp
- /library/DataStructure/PersistentUnionFind.cpp.html
title: DataStructure/PersistentUnionFind.cpp
---
