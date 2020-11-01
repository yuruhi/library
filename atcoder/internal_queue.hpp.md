---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: atcoder/maxflow.hpp
    title: atcoder/maxflow.hpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/internal_queue.hpp\"\n\n\n\n#include <vector>\n\n\
    namespace atcoder {\n\n\tnamespace internal {\n\n\t\ttemplate <class T> struct\
    \ simple_queue {\n\t\t\tstd::vector<T> payload;\n\t\t\tint pos = 0;\n\t\t\tvoid\
    \ reserve(int n) {\n\t\t\t\tpayload.reserve(n);\n\t\t\t}\n\t\t\tint size() const\
    \ {\n\t\t\t\treturn int(payload.size()) - pos;\n\t\t\t}\n\t\t\tbool empty() const\
    \ {\n\t\t\t\treturn pos == int(payload.size());\n\t\t\t}\n\t\t\tvoid push(const\
    \ T& t) {\n\t\t\t\tpayload.push_back(t);\n\t\t\t}\n\t\t\tT& front() {\n\t\t\t\t\
    return payload[pos];\n\t\t\t}\n\t\t\tvoid clear() {\n\t\t\t\tpayload.clear();\n\
    \t\t\t\tpos = 0;\n\t\t\t}\n\t\t\tvoid pop() {\n\t\t\t\tpos++;\n\t\t\t}\n\t\t};\n\
    \n\t}  // namespace internal\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_INTERNAL_QUEUE_HPP\n#define ATCODER_INTERNAL_QUEUE_HPP 1\n\
    \n#include <vector>\n\nnamespace atcoder {\n\n\tnamespace internal {\n\n\t\ttemplate\
    \ <class T> struct simple_queue {\n\t\t\tstd::vector<T> payload;\n\t\t\tint pos\
    \ = 0;\n\t\t\tvoid reserve(int n) {\n\t\t\t\tpayload.reserve(n);\n\t\t\t}\n\t\t\
    \tint size() const {\n\t\t\t\treturn int(payload.size()) - pos;\n\t\t\t}\n\t\t\
    \tbool empty() const {\n\t\t\t\treturn pos == int(payload.size());\n\t\t\t}\n\t\
    \t\tvoid push(const T& t) {\n\t\t\t\tpayload.push_back(t);\n\t\t\t}\n\t\t\tT&\
    \ front() {\n\t\t\t\treturn payload[pos];\n\t\t\t}\n\t\t\tvoid clear() {\n\t\t\
    \t\tpayload.clear();\n\t\t\t\tpos = 0;\n\t\t\t}\n\t\t\tvoid pop() {\n\t\t\t\t\
    pos++;\n\t\t\t}\n\t\t};\n\n\t}  // namespace internal\n\n}  // namespace atcoder\n\
    \n#endif  // ATCODER_INTERNAL_QUEUE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/internal_queue.hpp
  requiredBy:
  - atcoder/maxflow.hpp
  timestamp: '2020-10-30 19:21:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: atcoder/internal_queue.hpp
layout: document
redirect_from:
- /library/atcoder/internal_queue.hpp
- /library/atcoder/internal_queue.hpp.html
title: atcoder/internal_queue.hpp
---
