---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Serch/GridBFS.cpp\"\n// description : \u30B0\u30EA\u30C3\
    \u30C9\u4E0A\u306EBFS\nvector<vector<int>> GridBFS(const vector<string>& grid,\
    \ Point s, char wall = '#') {\n\tint h = grid.size(), w = grid.front().size();\n\
    \tPoint::set_range(h, w);\n\tvector<vector<int>> res(h, vector<int>(w, INT_MAX));\n\
    \tif (grid[s.y][s.x] == wall) {\n\t\treturn res;\n\t}\n\tres[s.y][s.x] = 0;\n\t\
    queue<Point> q;\n\tq.push(s);\n\twhile (!q.empty()) {\n\t\tauto f = q.front();\n\
    \t\tq.pop();\n\t\tfor (auto p : f.adj4_in_range()) {\n\t\t\tif (grid[p.y][p.x]\
    \ != wall && res[p.y][p.x] == INT_MAX) {\n\t\t\t\tq.push(p);\n\t\t\t\tres[p.y][p.x]\
    \ = res[f.y][f.x] + 1;\n\t\t\t}\n\t\t}\n\t}\n\treturn res;\n}\nvector<vector<int>>\
    \ GridBFS(const vector<string>& grid, char start, char wall = '#') {\n\tint h\
    \ = grid.size(), w = grid.front().size();\n\tPoint s;\n\tfor (int i = 0; i < h;\
    \ ++i)\n\t\tfor (int j = 0; j < w; ++j) {\n\t\t\tif (grid[i][j] == start) {\n\t\
    \t\t\ts = Point(j, i);\n\t\t\t}\n\t\t}\n\treturn GridBFS(grid, s, wall);\n}\n"
  code: "// description : \u30B0\u30EA\u30C3\u30C9\u4E0A\u306EBFS\nvector<vector<int>>\
    \ GridBFS(const vector<string>& grid, Point s, char wall = '#') {\n\tint h = grid.size(),\
    \ w = grid.front().size();\n\tPoint::set_range(h, w);\n\tvector<vector<int>> res(h,\
    \ vector<int>(w, INT_MAX));\n\tif (grid[s.y][s.x] == wall) {\n\t\treturn res;\n\
    \t}\n\tres[s.y][s.x] = 0;\n\tqueue<Point> q;\n\tq.push(s);\n\twhile (!q.empty())\
    \ {\n\t\tauto f = q.front();\n\t\tq.pop();\n\t\tfor (auto p : f.adj4_in_range())\
    \ {\n\t\t\tif (grid[p.y][p.x] != wall && res[p.y][p.x] == INT_MAX) {\n\t\t\t\t\
    q.push(p);\n\t\t\t\tres[p.y][p.x] = res[f.y][f.x] + 1;\n\t\t\t}\n\t\t}\n\t}\n\t\
    return res;\n}\nvector<vector<int>> GridBFS(const vector<string>& grid, char start,\
    \ char wall = '#') {\n\tint h = grid.size(), w = grid.front().size();\n\tPoint\
    \ s;\n\tfor (int i = 0; i < h; ++i)\n\t\tfor (int j = 0; j < w; ++j) {\n\t\t\t\
    if (grid[i][j] == start) {\n\t\t\t\ts = Point(j, i);\n\t\t\t}\n\t\t}\n\treturn\
    \ GridBFS(grid, s, wall);\n}"
  dependsOn: []
  isVerificationFile: false
  path: Serch/GridBFS.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Serch/GridBFS.cpp
layout: document
redirect_from:
- /library/Serch/GridBFS.cpp
- /library/Serch/GridBFS.cpp.html
title: Serch/GridBFS.cpp
---
