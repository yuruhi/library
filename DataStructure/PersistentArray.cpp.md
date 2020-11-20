---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: DataStructure/PersistentQueue.cpp
    title: DataStructure/PersistentQueue.cpp
  - icon: ':x:'
    path: DataStructure/PersistentUnionFind.cpp
    title: DataStructure/PersistentUnionFind.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/PersistentQueue.test.cpp
    title: test/PersistentQueue.test.cpp
  - icon: ':x:'
    path: test/PersistentUnionFind.test.cpp
    title: test/PersistentUnionFind.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/PersistentArray.cpp\"\n#include <array>\n\
    #include <vector>\n#include <memory>\nusing namespace std;\n\ntemplate <class\
    \ T, size_t LOG> class PersistentArray {\npublic:\n\tusing value_type = T;\n\t\
    using const_reference = const value_type&;\n\tstatic constexpr size_t CHILD_SIZE\
    \ = 1 << LOG;\n\nprivate:\n\tstruct node_type;\n\tusing node_ptr = shared_ptr<node_type>;\n\
    \tstruct node_type {\n\t\tvalue_type value;\n\t\tarray<node_ptr, CHILD_SIZE> child;\n\
    \t};\n\n\tstatic value_type get(size_t i, node_ptr p) {\n\t\tif (!p) {\n\t\t\t\
    return value_type();\n\t\t} else if (i == 0) {\n\t\t\treturn p->value;\n\t\t}\
    \ else {\n\t\t\treturn get(i >> LOG, p->child[i & (CHILD_SIZE - 1)]);\n\t\t}\n\
    \t}\n\tstatic node_ptr set(size_t i, const_reference val, node_ptr p) {\n\t\t\
    node_ptr result = p ? make_shared<node_type>(*p) : make_shared<node_type>();\n\
    \t\tif (i == 0) {\n\t\t\tresult->value = val;\n\t\t} else {\n\t\t\tsize_t index\
    \ = i & (CHILD_SIZE - 1);\n\t\t\tresult->child[index] = set(i >> LOG, val, result->child[index]);\n\
    \t\t}\n\t\treturn result;\n\t}\n\tstatic void destructive_set(size_t i, const_reference\
    \ val, node_ptr& p) {\n\t\tif (!p) {\n\t\t\tp = make_shared<node_type>();\n\t\t\
    }\n\t\tif (i == 0) {\n\t\t\tp->value = val;\n\t\t} else {\n\t\t\tsize_t index\
    \ = i & (CHILD_SIZE - 1);\n\t\t\tdestructive_set(i >> LOG, val, p->child[index]);\n\
    \t\t}\n\t}\n\n\tnode_ptr root;\n\tPersistentArray(node_ptr _root) : root(_root)\
    \ {}\n\npublic:\n\tPersistentArray() : root() {}\n\tPersistentArray(const vector<value_type>&\
    \ v) : root() {\n\t\tfor (size_t i = 0; i < v.size(); ++i) {\n\t\t\tdestructive_set(i,\
    \ v[i]);\n\t\t}\n\t}\n\tvalue_type get(size_t i) const {\n\t\treturn get(i, root);\n\
    \t}\n\tvalue_type operator[](size_t i) const {\n\t\treturn get(i);\n\t}\n\tvector<value_type>\
    \ to_a(size_t n) const {\n\t\tvector<value_type> result(n);\n\t\tfor (size_t i\
    \ = 0; i < n; ++i) {\n\t\t\tresult[i] = get(i);\n\t\t}\n\t\treturn result;\n\t\
    }\n\tPersistentArray set(size_t i, const_reference val) {\n\t\treturn PersistentArray(set(i,\
    \ val, root));\n\t}\n\tvoid destructive_set(size_t i, const_reference val) {\n\
    \t\tdestructive_set(i, val, root);\n\t}\n};\n"
  code: "#pragma once\n#include <array>\n#include <vector>\n#include <memory>\nusing\
    \ namespace std;\n\ntemplate <class T, size_t LOG> class PersistentArray {\npublic:\n\
    \tusing value_type = T;\n\tusing const_reference = const value_type&;\n\tstatic\
    \ constexpr size_t CHILD_SIZE = 1 << LOG;\n\nprivate:\n\tstruct node_type;\n\t\
    using node_ptr = shared_ptr<node_type>;\n\tstruct node_type {\n\t\tvalue_type\
    \ value;\n\t\tarray<node_ptr, CHILD_SIZE> child;\n\t};\n\n\tstatic value_type\
    \ get(size_t i, node_ptr p) {\n\t\tif (!p) {\n\t\t\treturn value_type();\n\t\t\
    } else if (i == 0) {\n\t\t\treturn p->value;\n\t\t} else {\n\t\t\treturn get(i\
    \ >> LOG, p->child[i & (CHILD_SIZE - 1)]);\n\t\t}\n\t}\n\tstatic node_ptr set(size_t\
    \ i, const_reference val, node_ptr p) {\n\t\tnode_ptr result = p ? make_shared<node_type>(*p)\
    \ : make_shared<node_type>();\n\t\tif (i == 0) {\n\t\t\tresult->value = val;\n\
    \t\t} else {\n\t\t\tsize_t index = i & (CHILD_SIZE - 1);\n\t\t\tresult->child[index]\
    \ = set(i >> LOG, val, result->child[index]);\n\t\t}\n\t\treturn result;\n\t}\n\
    \tstatic void destructive_set(size_t i, const_reference val, node_ptr& p) {\n\t\
    \tif (!p) {\n\t\t\tp = make_shared<node_type>();\n\t\t}\n\t\tif (i == 0) {\n\t\
    \t\tp->value = val;\n\t\t} else {\n\t\t\tsize_t index = i & (CHILD_SIZE - 1);\n\
    \t\t\tdestructive_set(i >> LOG, val, p->child[index]);\n\t\t}\n\t}\n\n\tnode_ptr\
    \ root;\n\tPersistentArray(node_ptr _root) : root(_root) {}\n\npublic:\n\tPersistentArray()\
    \ : root() {}\n\tPersistentArray(const vector<value_type>& v) : root() {\n\t\t\
    for (size_t i = 0; i < v.size(); ++i) {\n\t\t\tdestructive_set(i, v[i]);\n\t\t\
    }\n\t}\n\tvalue_type get(size_t i) const {\n\t\treturn get(i, root);\n\t}\n\t\
    value_type operator[](size_t i) const {\n\t\treturn get(i);\n\t}\n\tvector<value_type>\
    \ to_a(size_t n) const {\n\t\tvector<value_type> result(n);\n\t\tfor (size_t i\
    \ = 0; i < n; ++i) {\n\t\t\tresult[i] = get(i);\n\t\t}\n\t\treturn result;\n\t\
    }\n\tPersistentArray set(size_t i, const_reference val) {\n\t\treturn PersistentArray(set(i,\
    \ val, root));\n\t}\n\tvoid destructive_set(size_t i, const_reference val) {\n\
    \t\tdestructive_set(i, val, root);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/PersistentArray.cpp
  requiredBy:
  - DataStructure/PersistentQueue.cpp
  - DataStructure/PersistentUnionFind.cpp
  timestamp: '2020-11-17 20:26:59+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/PersistentUnionFind.test.cpp
  - test/PersistentQueue.test.cpp
documentation_of: DataStructure/PersistentArray.cpp
layout: document
redirect_from:
- /library/DataStructure/PersistentArray.cpp
- /library/DataStructure/PersistentArray.cpp.html
title: DataStructure/PersistentArray.cpp
---
