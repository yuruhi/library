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
  bundledCode: "#line 2 \"DataStructure/PersistentStack.cpp\"\n#include <memory>\n\
    #include <vector>\n#include <cassert>\n\ntemplate <class T> class PersistentStack\
    \ {\npublic:\n\tusing value_type = T;\n\tusing const_reference = const value_type&;\n\
    \nprivate:\n\tclass node_type;\n\tusing node_ptr = std::shared_ptr<const node_type>;\n\
    \tstruct node_type {\n\t\tnode_ptr next;\n\t\tvalue_type value;\n\t\tnode_type(node_ptr\
    \ _next, const value_type& _value) : next(_next), value(_value) {}\n\t};\n\n\t\
    node_ptr root;\n\tstd::size_t size_m;\n\tPersistentStack(node_ptr _root, std::size_t\
    \ _size_m) : root(_root), size_m(_size_m) {}\n\npublic:\n\tPersistentStack() :\
    \ size_m(0) {}\n\tbool empty() const {\n\t\treturn !root;\n\t}\n\tstd::size_t\
    \ size() const {\n\t\treturn size_m;\n\t}\n\tconst_reference top() const {\n\t\
    \treturn root->value;\n\t}\n\tPersistentStack push(const_reference value) const\
    \ {\n\t\treturn PersistentStack(std::make_shared<node_type>(root, value), size_m\
    \ + 1);\n\t}\n\tPersistentStack pop() const {\n\t\tassert(!empty());\n\t\treturn\
    \ PersistentStack(root->next, size_m - 1);\n\t}\n\tstd::vector<value_type> to_a()\
    \ const {\n\t\tstd::vector<value_type> result;\n\t\tfor (node_ptr node = root;\
    \ node; node = node->next) {\n\t\t\tresult.push_back(node->value);\n\t\t}\n\t\t\
    return result;\n\t}\n};\n"
  code: "#pragma once\n#include <memory>\n#include <vector>\n#include <cassert>\n\n\
    template <class T> class PersistentStack {\npublic:\n\tusing value_type = T;\n\
    \tusing const_reference = const value_type&;\n\nprivate:\n\tclass node_type;\n\
    \tusing node_ptr = std::shared_ptr<const node_type>;\n\tstruct node_type {\n\t\
    \tnode_ptr next;\n\t\tvalue_type value;\n\t\tnode_type(node_ptr _next, const value_type&\
    \ _value) : next(_next), value(_value) {}\n\t};\n\n\tnode_ptr root;\n\tstd::size_t\
    \ size_m;\n\tPersistentStack(node_ptr _root, std::size_t _size_m) : root(_root),\
    \ size_m(_size_m) {}\n\npublic:\n\tPersistentStack() : size_m(0) {}\n\tbool empty()\
    \ const {\n\t\treturn !root;\n\t}\n\tstd::size_t size() const {\n\t\treturn size_m;\n\
    \t}\n\tconst_reference top() const {\n\t\treturn root->value;\n\t}\n\tPersistentStack\
    \ push(const_reference value) const {\n\t\treturn PersistentStack(std::make_shared<node_type>(root,\
    \ value), size_m + 1);\n\t}\n\tPersistentStack pop() const {\n\t\tassert(!empty());\n\
    \t\treturn PersistentStack(root->next, size_m - 1);\n\t}\n\tstd::vector<value_type>\
    \ to_a() const {\n\t\tstd::vector<value_type> result;\n\t\tfor (node_ptr node\
    \ = root; node; node = node->next) {\n\t\t\tresult.push_back(node->value);\n\t\
    \t}\n\t\treturn result;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/PersistentStack.cpp
  requiredBy: []
  timestamp: '2021-04-06 14:24:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/PersistentStack.cpp
layout: document
redirect_from:
- /library/DataStructure/PersistentStack.cpp
- /library/DataStructure/PersistentStack.cpp.html
title: DataStructure/PersistentStack.cpp
---
