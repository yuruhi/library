---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/PersistentArray.cpp
    title: DataStructure/PersistentArray.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/PersistentQueue.test.cpp
    title: test/PersistentQueue.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/PersistentArray.cpp\"\n#include <array>\n\
    #include <vector>\n#include <memory>\nusing namespace std;\n\ntemplate <class\
    \ T, int LOG> class PersistentArray {\npublic:\n\tusing value_type = T;\n\tusing\
    \ const_reference = const value_type&;\n\nprivate:\n\tstruct node_type;\n\tusing\
    \ node_ptr = shared_ptr<node_type>;\n\tstruct node_type {\n\t\tvalue_type value;\n\
    \t\tarray<node_ptr, 1 << LOG> child;\n\t};\n\n\tnode_ptr root;\n\n\tPersistentArray(node_ptr\
    \ _root) : root(_root) {}\n\tvalue_type get(int i, node_ptr p) const {\n\t\tif\
    \ (!p) {\n\t\t\treturn value_type();\n\t\t} else if (i == 0) {\n\t\t\treturn p->value;\n\
    \t\t} else {\n\t\t\treturn get(i >> LOG, p->child[i & ((1 << LOG) - 1)]);\n\t\t\
    }\n\t}\n\tnode_ptr set(int i, const_reference val, node_ptr p) {\n\t\tnode_ptr\
    \ result = p ? make_shared<node_type>(*p) : make_shared<node_type>();\n\t\tif\
    \ (i == 0) {\n\t\t\tresult->value = val;\n\t\t} else {\n\t\t\tint index = i &\
    \ ((1 << LOG) - 1);\n\t\t\tresult->child[index] = set(i >> LOG, val, result->child[index]);\n\
    \t\t}\n\t\treturn result;\n\t}\n\tvoid destructive_set(int i, const_reference\
    \ val, node_ptr& p) {\n\t\tif (!p) {\n\t\t\tp = make_shared<node_type>();\n\t\t\
    }\n\t\tif (i == 0) {\n\t\t\tp->value = val;\n\t\t} else {\n\t\t\tint index = i\
    \ & ((1 << LOG) - 1);\n\t\t\tdestructive_set(i >> LOG, val, p->child[index]);\n\
    \t\t}\n\t}\n\npublic:\n\tPersistentArray() : root() {}\n\tPersistentArray(const\
    \ vector<value_type>& v) : root() {\n\t\tfor (size_t i = 0; i < v.size(); ++i)\
    \ {\n\t\t\tdestructive_set(i, v[i]);\n\t\t}\n\t}\n\tvalue_type get(int i) const\
    \ {\n\t\treturn get(i, root);\n\t}\n\tvalue_type operator[](int i) const {\n\t\
    \treturn get(i);\n\t}\n\tvector<value_type> to_a(int n) const {\n\t\tvector<value_type>\
    \ result(n);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tresult[i] = get(i);\n\t\
    \t}\n\t\treturn result;\n\t}\n\tPersistentArray set(int i, const_reference val)\
    \ {\n\t\treturn PersistentArray(set(i, val, root));\n\t}\n\tvoid destructive_set(int\
    \ i, const_reference val) {\n\t\tdestructive_set(i, val, root);\n\t}\n};\n#line\
    \ 3 \"DataStructure/PersistentQueue.cpp\"\n#include <cassert>\n\ntemplate <class\
    \ T> class PersistentQueue {\npublic:\n\tusing value_type = T;\n\nprivate:\n\t\
    using data_type = PersistentArray<value_type, 3>;\n\tdata_type data;\n\tint begin,\
    \ end;  // [begin, end)\n\tPersistentQueue(const data_type& _data, int _begin,\
    \ int _end) : data(_data), begin(_begin), end(_end) {}\n\npublic:\n\tPersistentQueue()\
    \ : data(), begin(0), end(0) {}\n\tbool empty() const {\n\t\treturn begin == end;\n\
    \t}\n\tvalue_type front() const {\n\t\tassert(!empty());\n\t\treturn data[begin];\n\
    \t}\n\tvalue_type back() const {\n\t\tassert(!empty());\n\t\treturn data[end -\
    \ 1];\n\t}\n\tPersistentQueue push(const T& val) {\n\t\treturn PersistentQueue(data.set(end,\
    \ val), begin, end + 1);\n\t}\n\tPersistentQueue pop() {\n\t\tassert(!empty());\n\
    \t\treturn PersistentQueue(data.set(begin, value_type()), begin + 1, end);\n\t\
    }\n};\n"
  code: "#pragma once\n#include \"./PersistentArray.cpp\"\n#include <cassert>\n\n\
    template <class T> class PersistentQueue {\npublic:\n\tusing value_type = T;\n\
    \nprivate:\n\tusing data_type = PersistentArray<value_type, 3>;\n\tdata_type data;\n\
    \tint begin, end;  // [begin, end)\n\tPersistentQueue(const data_type& _data,\
    \ int _begin, int _end) : data(_data), begin(_begin), end(_end) {}\n\npublic:\n\
    \tPersistentQueue() : data(), begin(0), end(0) {}\n\tbool empty() const {\n\t\t\
    return begin == end;\n\t}\n\tvalue_type front() const {\n\t\tassert(!empty());\n\
    \t\treturn data[begin];\n\t}\n\tvalue_type back() const {\n\t\tassert(!empty());\n\
    \t\treturn data[end - 1];\n\t}\n\tPersistentQueue push(const T& val) {\n\t\treturn\
    \ PersistentQueue(data.set(end, val), begin, end + 1);\n\t}\n\tPersistentQueue\
    \ pop() {\n\t\tassert(!empty());\n\t\treturn PersistentQueue(data.set(begin, value_type()),\
    \ begin + 1, end);\n\t}\n};\n"
  dependsOn:
  - DataStructure/PersistentArray.cpp
  isVerificationFile: false
  path: DataStructure/PersistentQueue.cpp
  requiredBy: []
  timestamp: '2020-11-15 19:07:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/PersistentQueue.test.cpp
documentation_of: DataStructure/PersistentQueue.cpp
layout: document
redirect_from:
- /library/DataStructure/PersistentQueue.cpp
- /library/DataStructure/PersistentQueue.cpp.html
title: DataStructure/PersistentQueue.cpp
---
