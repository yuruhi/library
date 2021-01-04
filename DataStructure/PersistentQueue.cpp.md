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
    }\n\tPersistentArray set(size_t i, const_reference val) const {\n\t\treturn PersistentArray(set(i,\
    \ val, root));\n\t}\n\tvoid destructive_set(size_t i, const_reference val) {\n\
    \t\tdestructive_set(i, val, root);\n\t}\n};\n#line 3 \"DataStructure/PersistentQueue.cpp\"\
    \n#include <cassert>\n\ntemplate <class T> class PersistentQueue {\npublic:\n\t\
    using value_type = T;\n\tusing data_type = PersistentArray<value_type, 2>;\n\n\
    private:\n\tdata_type data;\n\tsize_t begin, end;  // [begin, end)\n\tPersistentQueue(const\
    \ data_type& _data, size_t _begin, size_t _end)\n\t    : data(_data), begin(_begin),\
    \ end(_end) {}\n\npublic:\n\tPersistentQueue() : data(), begin(0), end(0) {}\n\
    \tbool empty() const {\n\t\treturn begin == end;\n\t}\n\tsize_t size() const {\n\
    \t\treturn end - begin;\n\t}\n\tvalue_type front() const {\n\t\tassert(!empty());\n\
    \t\treturn data[begin];\n\t}\n\tvalue_type back() const {\n\t\tassert(!empty());\n\
    \t\treturn data[end - 1];\n\t}\n\tvalue_type operator[](size_t i) const {\n\t\t\
    assert(i < size());\n\t\treturn data[begin + i];\n\t}\n\tvalue_type at(size_t\
    \ i) const {\n\t\treturn operator[](i);\n\t}\n\tPersistentQueue push(const T&\
    \ val) const {\n\t\treturn PersistentQueue(data.set(end, val), begin, end + 1);\n\
    \t}\n\tPersistentQueue pop() const {\n\t\tassert(!empty());\n\t\treturn PersistentQueue(data.set(begin,\
    \ value_type()), begin + 1, end);\n\t}\n};\n"
  code: "#pragma once\n#include \"./PersistentArray.cpp\"\n#include <cassert>\n\n\
    template <class T> class PersistentQueue {\npublic:\n\tusing value_type = T;\n\
    \tusing data_type = PersistentArray<value_type, 2>;\n\nprivate:\n\tdata_type data;\n\
    \tsize_t begin, end;  // [begin, end)\n\tPersistentQueue(const data_type& _data,\
    \ size_t _begin, size_t _end)\n\t    : data(_data), begin(_begin), end(_end) {}\n\
    \npublic:\n\tPersistentQueue() : data(), begin(0), end(0) {}\n\tbool empty() const\
    \ {\n\t\treturn begin == end;\n\t}\n\tsize_t size() const {\n\t\treturn end -\
    \ begin;\n\t}\n\tvalue_type front() const {\n\t\tassert(!empty());\n\t\treturn\
    \ data[begin];\n\t}\n\tvalue_type back() const {\n\t\tassert(!empty());\n\t\t\
    return data[end - 1];\n\t}\n\tvalue_type operator[](size_t i) const {\n\t\tassert(i\
    \ < size());\n\t\treturn data[begin + i];\n\t}\n\tvalue_type at(size_t i) const\
    \ {\n\t\treturn operator[](i);\n\t}\n\tPersistentQueue push(const T& val) const\
    \ {\n\t\treturn PersistentQueue(data.set(end, val), begin, end + 1);\n\t}\n\t\
    PersistentQueue pop() const {\n\t\tassert(!empty());\n\t\treturn PersistentQueue(data.set(begin,\
    \ value_type()), begin + 1, end);\n\t}\n};\n"
  dependsOn:
  - DataStructure/PersistentArray.cpp
  isVerificationFile: false
  path: DataStructure/PersistentQueue.cpp
  requiredBy: []
  timestamp: '2020-11-21 14:30:57+09:00'
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