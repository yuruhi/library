---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/HasCycle.cpp\"\n// description : \u9589\u8DEF\u691C\
    \u51FA\nbool HasCycle(const Graph& graph) {\n\tint V = graph.size();\n\tvector<int>\
    \ h(V);\n\tfor (auto g : graph) {\n\t\tfor (auto e : g)\n\t\t\th[e.to]++;\n\t\
    }\n\tstack<int> st;\n\tint cnt = 0;\n\tfor (int i = 0; i < V; i++)\n\t\tif (!h[i])\
    \ {\n\t\t\tst.push(i);\n\t\t\tcnt++;\n\t\t}\n\tvector<int> res;\n\twhile (!st.empty())\
    \ {\n\t\tint i = st.top();\n\t\tst.pop();\n\t\tres.push_back(i);\n\t\tfor (auto&\
    \ e : graph[i]) {\n\t\t\th[e.to]--;\n\t\t\tif (!h[e.to]) {\n\t\t\t\tst.push(e.to);\n\
    \t\t\t\tcnt++;\n\t\t\t}\n\t\t}\n\t}\n\treturn cnt != V;\n}\n"
  code: "// description : \u9589\u8DEF\u691C\u51FA\nbool HasCycle(const Graph& graph)\
    \ {\n\tint V = graph.size();\n\tvector<int> h(V);\n\tfor (auto g : graph) {\n\t\
    \tfor (auto e : g)\n\t\t\th[e.to]++;\n\t}\n\tstack<int> st;\n\tint cnt = 0;\n\t\
    for (int i = 0; i < V; i++)\n\t\tif (!h[i]) {\n\t\t\tst.push(i);\n\t\t\tcnt++;\n\
    \t\t}\n\tvector<int> res;\n\twhile (!st.empty()) {\n\t\tint i = st.top();\n\t\t\
    st.pop();\n\t\tres.push_back(i);\n\t\tfor (auto& e : graph[i]) {\n\t\t\th[e.to]--;\n\
    \t\t\tif (!h[e.to]) {\n\t\t\t\tst.push(e.to);\n\t\t\t\tcnt++;\n\t\t\t}\n\t\t}\n\
    \t}\n\treturn cnt != V;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/HasCycle.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/HasCycle.cpp
layout: document
redirect_from:
- /library/Graph/HasCycle.cpp
- /library/Graph/HasCycle.cpp.html
title: Graph/HasCycle.cpp
---
