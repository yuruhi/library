---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/PersistentArray.cpp
    title: DataStructure/PersistentArray.cpp
  - icon: ':x:'
    path: DataStructure/PersistentQueue.cpp
    title: DataStructure/PersistentQueue.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_queue
    links:
    - https://judge.yosupo.jp/problem/persistent_queue
  bundledCode: "#line 1 \"test/PersistentQueue.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\
    \n#line 2 \"DataStructure/PersistentArray.cpp\"\n#include <array>\n#include <vector>\n\
    #include <memory>\nusing namespace std;\n\ntemplate <class T, size_t LOG> class\
    \ PersistentArray {\npublic:\n\tusing value_type = T;\n\tusing const_reference\
    \ = const value_type&;\n\tstatic constexpr size_t CHILD_SIZE = 1 << LOG;\n\nprivate:\n\
    \tstruct node_type;\n\tusing node_ptr = shared_ptr<node_type>;\n\tstruct node_type\
    \ {\n\t\tvalue_type value;\n\t\tarray<node_ptr, CHILD_SIZE> child;\n\t};\n\n\t\
    static value_type get(size_t i, node_ptr p) {\n\t\tif (!p) {\n\t\t\treturn value_type();\n\
    \t\t} else if (i == 0) {\n\t\t\treturn p->value;\n\t\t} else {\n\t\t\treturn get(i\
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
    \t\tdestructive_set(i, val, root);\n\t}\n};\n#line 3 \"DataStructure/PersistentQueue.cpp\"\
    \n#include <cassert>\n\ntemplate <class T> class PersistentQueue {\npublic:\n\t\
    using value_type = T;\n\nprivate:\n\tusing data_type = PersistentArray<value_type,\
    \ 2>;\n\tdata_type data;\n\tint begin, end;  // [begin, end)\n\tPersistentQueue(const\
    \ data_type& _data, int _begin, int _end)\n\t    : data(_data), begin(_begin),\
    \ end(_end) {}\n\npublic:\n\tPersistentQueue() : data(), begin(0), end(0) {}\n\
    \tbool empty() const {\n\t\treturn begin == end;\n\t}\n\tvalue_type front() const\
    \ {\n\t\tassert(!empty());\n\t\treturn data[begin];\n\t}\n\tvalue_type back()\
    \ const {\n\t\tassert(!empty());\n\t\treturn data[end - 1];\n\t}\n\tPersistentQueue\
    \ push(const T& val) {\n\t\treturn PersistentQueue(data.set(end, val), begin,\
    \ end + 1);\n\t}\n\tPersistentQueue pop() {\n\t\tassert(!empty());\n\t\treturn\
    \ PersistentQueue(data.set(begin, value_type()), begin + 1, end);\n\t}\n};\n#line\
    \ 3 \"test/PersistentQueue.test.cpp\"\n#include <iostream>\n#line 5 \"test/PersistentQueue.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tint q;\n\tcin >> q;\n\tvector<PersistentQueue<int>> s(q + 1);\n\tfor (int\
    \ i = 1; i <= q; ++i) {\n\t\tint com, t;\n\t\tcin >> com >> t;\n\t\t++t;\n\t\t\
    if (com == 0) {\n\t\t\tint x;\n\t\t\tcin >> x;\n\t\t\ts[i] = s[t].push(x);\n\t\
    \t} else {\n\t\t\tcout << s[t].front() << endl;\n\t\t\ts[i] = s[t].pop();\n\t\t\
    }\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n#include\
    \ \"./../DataStructure/PersistentQueue.cpp\"\n#include <iostream>\n#include <vector>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tint q;\n\tcin >> q;\n\tvector<PersistentQueue<int>> s(q + 1);\n\tfor (int\
    \ i = 1; i <= q; ++i) {\n\t\tint com, t;\n\t\tcin >> com >> t;\n\t\t++t;\n\t\t\
    if (com == 0) {\n\t\t\tint x;\n\t\t\tcin >> x;\n\t\t\ts[i] = s[t].push(x);\n\t\
    \t} else {\n\t\t\tcout << s[t].front() << endl;\n\t\t\ts[i] = s[t].pop();\n\t\t\
    }\n\t}\n}"
  dependsOn:
  - DataStructure/PersistentQueue.cpp
  - DataStructure/PersistentArray.cpp
  isVerificationFile: true
  path: test/PersistentQueue.test.cpp
  requiredBy: []
  timestamp: '2020-11-20 21:19:41+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/PersistentQueue.test.cpp
layout: document
redirect_from:
- /verify/test/PersistentQueue.test.cpp
- /verify/test/PersistentQueue.test.cpp.html
title: test/PersistentQueue.test.cpp
---
