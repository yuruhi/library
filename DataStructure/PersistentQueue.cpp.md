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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/PersistentArray.cpp\"\n#include <array>\n\
    #include <vector>\n#include <memory>\n\ntemplate <class T, std::size_t LOG> class\
    \ PersistentArray {\npublic:\n\tusing value_type = T;\n\tusing const_reference\
    \ = const value_type&;\n\tstatic constexpr std::size_t CHILD_SIZE = 1 << LOG;\n\
    \nprivate:\n\tstruct node_type;\n\tusing node_ptr = std::shared_ptr<node_type>;\n\
    \tstruct node_type {\n\t\tvalue_type value;\n\t\tstd::array<node_ptr, CHILD_SIZE>\
    \ child;\n\t};\n\n\tstatic value_type get(std::size_t i, node_ptr p) {\n\t\tif\
    \ (!p) {\n\t\t\treturn value_type();\n\t\t} else if (i == 0) {\n\t\t\treturn p->value;\n\
    \t\t} else {\n\t\t\treturn get(i >> LOG, p->child[i & (CHILD_SIZE - 1)]);\n\t\t\
    }\n\t}\n\tstatic node_ptr set(std::size_t i, const_reference val, node_ptr p)\
    \ {\n\t\tnode_ptr result = p ? std::make_shared<node_type>(*p) : std::make_shared<node_type>();\n\
    \t\tif (i == 0) {\n\t\t\tresult->value = val;\n\t\t} else {\n\t\t\tstd::size_t\
    \ index = i & (CHILD_SIZE - 1);\n\t\t\tresult->child[index] = set(i >> LOG, val,\
    \ result->child[index]);\n\t\t}\n\t\treturn result;\n\t}\n\tstatic void destructive_set(std::size_t\
    \ i, const_reference val, node_ptr& p) {\n\t\tif (!p) {\n\t\t\tp = std::make_shared<node_type>();\n\
    \t\t}\n\t\tif (i == 0) {\n\t\t\tp->value = val;\n\t\t} else {\n\t\t\tstd::size_t\
    \ index = i & (CHILD_SIZE - 1);\n\t\t\tdestructive_set(i >> LOG, val, p->child[index]);\n\
    \t\t}\n\t}\n\n\tnode_ptr root;\n\tPersistentArray(node_ptr _root) : root(_root)\
    \ {}\n\npublic:\n\tPersistentArray() : root() {}\n\tPersistentArray(const std::vector<value_type>&\
    \ v) : root() {\n\t\tfor (std::size_t i = 0; i < v.size(); ++i) {\n\t\t\tdestructive_set(i,\
    \ v[i]);\n\t\t}\n\t}\n\tvalue_type get(std::size_t i) const {\n\t\treturn get(i,\
    \ root);\n\t}\n\tvalue_type operator[](std::size_t i) const {\n\t\treturn get(i);\n\
    \t}\n\tstd::vector<value_type> to_a(std::size_t n) const {\n\t\tstd::vector<value_type>\
    \ result(n);\n\t\tfor (std::size_t i = 0; i < n; ++i) {\n\t\t\tresult[i] = get(i);\n\
    \t\t}\n\t\treturn result;\n\t}\n\tPersistentArray set(std::size_t i, const_reference\
    \ val) const {\n\t\treturn PersistentArray(set(i, val, root));\n\t}\n\tvoid destructive_set(std::size_t\
    \ i, const_reference val) {\n\t\tdestructive_set(i, val, root);\n\t}\n};\n#line\
    \ 3 \"DataStructure/PersistentQueue.cpp\"\n#include <cassert>\n\ntemplate <class\
    \ T> class PersistentQueue {\npublic:\n\tusing value_type = T;\n\tusing data_type\
    \ = PersistentArray<value_type, 2>;\n\nprivate:\n\tdata_type data;\n\tsize_t begin,\
    \ end;  // [begin, end)\n\tPersistentQueue(const data_type& _data, size_t _begin,\
    \ size_t _end)\n\t    : data(_data), begin(_begin), end(_end) {}\n\npublic:\n\t\
    PersistentQueue() : data(), begin(0), end(0) {}\n\tbool empty() const {\n\t\t\
    return begin == end;\n\t}\n\tsize_t size() const {\n\t\treturn end - begin;\n\t\
    }\n\tvalue_type front() const {\n\t\tassert(!empty());\n\t\treturn data[begin];\n\
    \t}\n\tvalue_type back() const {\n\t\tassert(!empty());\n\t\treturn data[end -\
    \ 1];\n\t}\n\tvalue_type operator[](size_t i) const {\n\t\tassert(i < size());\n\
    \t\treturn data[begin + i];\n\t}\n\tvalue_type at(size_t i) const {\n\t\treturn\
    \ operator[](i);\n\t}\n\tPersistentQueue push(const T& val) const {\n\t\treturn\
    \ PersistentQueue(data.set(end, val), begin, end + 1);\n\t}\n\tPersistentQueue\
    \ pop() const {\n\t\tassert(!empty());\n\t\treturn PersistentQueue(data.set(begin,\
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
  timestamp: '2021-04-06 14:24:56+09:00'
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
