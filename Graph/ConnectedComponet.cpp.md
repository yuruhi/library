---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/ConnectedComponet.cpp\"\n// description : \u9023\u7D50\
    \u6210\u5206 return : { \u9023\u7D50\u6210\u5206\u6570, {\u756A\u53F7} }\ntuple<int,\
    \ vector<int>, vector<vector<int>>> ConnectedComponet(const vector<vector<int>>&\
    \ g) {\n\tint V = g.size(), N = 0;\n\tvector<int> id(V, -1);\n\tvector<vector<int>>\
    \ ind(V);\n\tfunction<void(int, int)> dfs = [&](int ID, int v) {\n\t\tid[v] =\
    \ ID;\n\t\tind[ID].push_back(v);\n\t\tfor (auto e : g[v])\n\t\t\tif (id[e] ==\
    \ -1) dfs(ID, e);\n\t};\n\tfor (int i = 0; i < V; ++i)\n\t\tif (id[i] == -1) dfs(N++,\
    \ i);\n\tind.resize(N);\n\treturn make_tuple(N, id, ind);\n}\n"
  code: "// description : \u9023\u7D50\u6210\u5206 return : { \u9023\u7D50\u6210\u5206\
    \u6570, {\u756A\u53F7} }\ntuple<int, vector<int>, vector<vector<int>>> ConnectedComponet(const\
    \ vector<vector<int>>& g) {\n\tint V = g.size(), N = 0;\n\tvector<int> id(V, -1);\n\
    \tvector<vector<int>> ind(V);\n\tfunction<void(int, int)> dfs = [&](int ID, int\
    \ v) {\n\t\tid[v] = ID;\n\t\tind[ID].push_back(v);\n\t\tfor (auto e : g[v])\n\t\
    \t\tif (id[e] == -1) dfs(ID, e);\n\t};\n\tfor (int i = 0; i < V; ++i)\n\t\tif\
    \ (id[i] == -1) dfs(N++, i);\n\tind.resize(N);\n\treturn make_tuple(N, id, ind);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Graph/ConnectedComponet.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/ConnectedComponet.cpp
layout: document
redirect_from:
- /library/Graph/ConnectedComponet.cpp
- /library/Graph/ConnectedComponet.cpp.html
title: Graph/ConnectedComponet.cpp
---
