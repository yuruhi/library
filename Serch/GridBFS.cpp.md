---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Utility/Point.cpp
    title: Utility/Point.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/Point.cpp\"\n#include <vector>\n#include <utility>\n\
    #include <iostream>\nusing namespace std;\n\nstruct Point {\n\tstatic int H, W;\n\
    \tstatic const vector<Point> d;\n\tstatic void set_range(int _H, int _W) {\n\t\
    \tH = _H;\n\t\tW = _W;\n\t}\n\tstatic constexpr Point zero() {\n\t\treturn {0,\
    \ 0};\n\t}\n\tstatic constexpr Point one() {\n\t\treturn {1, 1};\n\t}\n\tint x,\
    \ y;\n\tconstexpr Point() : x(0), y(0) {}\n\tconstexpr Point(int _x, int _y) :\
    \ x(_x), y(_y) {}\n\tconstexpr Point(const pair<int, int>& xy) : x(xy.first),\
    \ y(xy.second) {}\n\tPoint(int n) : x(n % W), y(n / W) {}\n\tconstexpr Point operator+()\
    \ const {\n\t\treturn *this;\n\t}\n\tconstexpr Point operator-() const {\n\t\t\
    return {-x, -y};\n\t}\n\tconstexpr Point operator+(const Point& p) const {\n\t\
    \treturn Point(*this) += p;\n\t}\n\tconstexpr Point operator-(const Point& p)\
    \ const {\n\t\treturn Point(*this) -= p;\n\t}\n\tconstexpr Point operator*(const\
    \ Point& p) const {\n\t\treturn Point(*this) *= p;\n\t}\n\tconstexpr Point operator/(const\
    \ Point& p) const {\n\t\treturn Point(*this) /= p;\n\t}\n\tconstexpr Point operator%(const\
    \ Point& p) const {\n\t\treturn Point(*this) %= p;\n\t}\n\tconstexpr Point operator+(int\
    \ n) const {\n\t\treturn Point(*this) += n;\n\t}\n\tconstexpr Point operator-(int\
    \ n) const {\n\t\treturn Point(*this) -= n;\n\t}\n\tconstexpr Point operator*(int\
    \ n) const {\n\t\treturn Point(*this) *= n;\n\t}\n\tconstexpr Point operator/(int\
    \ n) const {\n\t\treturn Point(*this) /= n;\n\t}\n\tconstexpr Point operator%(int\
    \ n) const {\n\t\treturn Point(*this) %= n;\n\t}\n\tconstexpr Point& operator+=(const\
    \ Point& p) {\n\t\tx += p.x;\n\t\ty += p.y;\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ Point& operator-=(const Point& p) {\n\t\tx -= p.x;\n\t\ty -= p.y;\n\t\treturn\
    \ *this;\n\t}\n\tconstexpr Point& operator*=(const Point& p) {\n\t\tx *= p.x;\n\
    \t\ty *= p.y;\n\t\treturn *this;\n\t}\n\tconstexpr Point& operator/=(const Point&\
    \ p) {\n\t\tx /= p.x;\n\t\ty /= p.y;\n\t\treturn *this;\n\t}\n\tconstexpr Point&\
    \ operator%=(const Point& p) {\n\t\tx %= p.x;\n\t\ty %= p.y;\n\t\treturn *this;\n\
    \t}\n\tconstexpr Point& operator+=(int n) {\n\t\tx += n;\n\t\ty += n;\n\t\treturn\
    \ *this;\n\t}\n\tconstexpr Point& operator-=(int n) {\n\t\tx -= n;\n\t\ty -= n;\n\
    \t\treturn *this;\n\t}\n\tconstexpr Point& operator*=(int n) {\n\t\tx *= n;\n\t\
    \ty *= n;\n\t\treturn *this;\n\t}\n\tconstexpr Point& operator/=(int n) {\n\t\t\
    x /= n;\n\t\ty /= n;\n\t\treturn *this;\n\t}\n\tconstexpr Point& operator%=(int\
    \ n) {\n\t\tx %= n;\n\t\ty %= n;\n\t\treturn *this;\n\t}\n\tconstexpr bool operator==(const\
    \ Point& p) const {\n\t\treturn x == p.x && y == p.y;\n\t}\n\tconstexpr bool operator!=(const\
    \ Point& p) const {\n\t\treturn x != p.x || y != p.y;\n\t}\n\tbool operator<(const\
    \ Point& p) const {\n\t\treturn to_i() < p.to_i();\n\t}\n\tbool operator<=(const\
    \ Point& p) const {\n\t\treturn to_i() <= p.to_i();\n\t}\n\tbool operator>(const\
    \ Point& p) const {\n\t\treturn to_i() > p.to_i();\n\t}\n\tbool operator>=(const\
    \ Point& p) const {\n\t\treturn to_i() >= p.to_i();\n\t}\n\tconstexpr int operator[](int\
    \ i) const {\n\t\treturn i == 0 ? x : i == 1 ? y : 0;\n\t}\n\tconstexpr bool in_range(int\
    \ height, int width) const {\n\t\treturn 0 <= x && x < width && 0 <= y && y <\
    \ height;\n\t}\n\tbool in_range() const {\n\t\treturn in_range(H, W);\n\t}\n\t\
    int to_i() const {\n\t\treturn x + y * W;\n\t}\n\tconstexpr pair<int, int> to_pair()\
    \ const {\n\t\treturn {x, y};\n\t}\n\tint dist(const Point& p) const {\n\t\treturn\
    \ std::abs(x - p.x) + std::abs(y - p.y);\n\t}\n\tint dist_square(const Point&\
    \ p) const {\n\t\treturn (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);\n\t}\n\
    \tPoint abs(const Point& p) const {\n\t\treturn {std::abs(x - p.x), std::abs(y\
    \ - p.y)};\n\t}\n\tPoint abs() const {\n\t\treturn {std::abs(x), std::abs(y)};\n\
    \t}\n\tPoint& swap() {\n\t\tstd::swap(x, y);\n\t\treturn *this;\n\t}\n\n\ttemplate\
    \ <class It> vector<Point> enum_adjanect(It first, It last) const {\n\t\tvector<Point>\
    \ res;\n\t\tfor (; first != last; ++first) {\n\t\t\tres.push_back(operator+(*first));\n\
    \t\t}\n\t\treturn res;\n\t}\n\ttemplate <class It> vector<Point> enum_adj_in_range(It\
    \ first, It last) const {\n\t\tvector<Point> res;\n\t\tfor (; first != last; ++first)\
    \ {\n\t\t\tauto p = operator+(*first);\n\t\t\tif (p.in_range()) res.push_back(p);\n\
    \t\t}\n\t\treturn res;\n\t}\n\tvector<Point> adjacent4() const {\n\t\treturn enum_adjanect(d.begin(),\
    \ d.begin() + 4);\n\t}\n\tvector<Point> adjacent8() const {\n\t\treturn enum_adjanect(d.begin(),\
    \ d.end());\n\t}\n\tvector<Point> adj4_in_range() const {\n\t\treturn enum_adj_in_range(d.begin(),\
    \ d.begin() + 4);\n\t}\n\tvector<Point> adj8_in_range() const {\n\t\treturn enum_adj_in_range(d.begin(),\
    \ d.end());\n\t}\n\tconstexpr Point left() const {\n\t\treturn {x - 1, y};\n\t\
    }\n\tconstexpr Point right() const {\n\t\treturn {x + 1, y};\n\t}\n\tconstexpr\
    \ Point up() const {\n\t\treturn {x, y - 1};\n\t}\n\tconstexpr Point down() const\
    \ {\n\t\treturn {x, y + 1};\n\t}\n\tconstexpr Point moved(char c) const {\n\t\t\
    return Point(*this).move(c);\n\t}\n\tconstexpr Point& move(char c) {\n\t\tswitch\
    \ (c) {\n\t\t\tcase 'L':\n\t\t\tcase 'l':\n\t\t\tcase 'W':\n\t\t\tcase '>':\n\t\
    \t\t\tx--;\n\t\t\t\tbreak;\n\t\t\tcase 'R':\n\t\t\tcase 'r':\n\t\t\tcase 'E':\n\
    \t\t\tcase '<':\n\t\t\t\tx++;\n\t\t\t\tbreak;\n\t\t\tcase 'U':\n\t\t\tcase 'u':\n\
    \t\t\tcase 'N':\n\t\t\tcase '^':\n\t\t\t\ty--;\n\t\t\t\tbreak;\n\t\t\tcase 'D':\n\
    \t\t\tcase 'd':\n\t\t\tcase 'S':\n\t\t\tcase 'v':\n\t\t\t\ty++;\n\t\t\t\tbreak;\n\
    \t\t}\n\t\treturn *this;\n\t}\n\tconstexpr Point rotate90() const {\n\t\treturn\
    \ {y, -x};\n\t}\n\tconstexpr Point rotate180() const {\n\t\treturn {-x, -y};\n\
    \t}\n\tconstexpr Point rotate270() const {\n\t\treturn {-y, x};\n\t}\n\tchar to_direction_char(const\
    \ string chars = \"LRUD\") const {\n\t\tassert(4 <= chars.size() && chars.size()\
    \ <= 5);\n\t\tif (y == 0 && x < 0) {\n\t\t\treturn chars[0];\n\t\t} else if (y\
    \ == 0 && x > 0) {\n\t\t\treturn chars[1];\n\t\t} else if (x == 0 && y < 0) {\n\
    \t\t\treturn chars[2];\n\t\t} else if (x == 0 && y > 0) {\n\t\t\treturn chars[3];\n\
    \t\t} else if (chars.size() == 5) {\n\t\t\treturn chars[4];\n\t\t} else {\n\t\t\
    \tassert(false);\n\t\t}\n\t}\n\tfriend ostream& operator<<(ostream& os, const\
    \ Point& p) {\n\t\treturn os << '(' << p.x << \", \" << p.y << ')';\n\t}\n\tfriend\
    \ istream& operator>>(istream& is, Point& p) {\n\t\treturn is >> p.y >> p.x;\n\
    \t}\n};\nint Point::H, Point::W;\nconst vector<Point> Point::d{{0, 1}, {1, 0},\
    \   {0, -1}, {-1, 0},\n                             {1, 1}, {-1, -1}, {1, -1},\
    \ {-1, 1}};\n#line 4 \"Serch/GridBFS.cpp\"\n#include <string>\n#include <queue>\n\
    using namespace std;\n\nvector<vector<int>> GridBFS(const vector<string>& grid,\
    \ Point start, char wall = '#') {\n\tint h = grid.size(), w = grid.front().size();\n\
    \tPoint::set_range(h, w);\n\tvector<vector<int>> res(h, vector<int>(w, INT_MAX));\n\
    \tif (grid[start.y][start.x] == wall) {\n\t\treturn res;\n\t}\n\tres[start.y][start.x]\
    \ = 0;\n\tqueue<Point> q;\n\tq.push(start);\n\twhile (!q.empty()) {\n\t\tauto\
    \ f = q.front();\n\t\tq.pop();\n\t\tfor (auto p : f.adj4_in_range()) {\n\t\t\t\
    if (grid[p.y][p.x] != wall && res[p.y][p.x] == INT_MAX) {\n\t\t\t\tq.push(p);\n\
    \t\t\t\tres[p.y][p.x] = res[f.y][f.x] + 1;\n\t\t\t}\n\t\t}\n\t}\n\treturn res;\n\
    }\nvector<vector<int>> GridBFS(const vector<string>& grid, char start, char wall\
    \ = '#') {\n\tint h = grid.size(), w = grid.front().size();\n\tPoint s;\n\tfor\
    \ (int i = 0; i < h; ++i)\n\t\tfor (int j = 0; j < w; ++j) {\n\t\t\tif (grid[i][j]\
    \ == start) {\n\t\t\t\ts = Point(j, i);\n\t\t\t}\n\t\t}\n\treturn GridBFS(grid,\
    \ s, wall);\n}\n"
  code: "#pragma once\n#include \"./../Utility/Point.cpp\"\n#include <vector>\n#include\
    \ <string>\n#include <queue>\nusing namespace std;\n\nvector<vector<int>> GridBFS(const\
    \ vector<string>& grid, Point start, char wall = '#') {\n\tint h = grid.size(),\
    \ w = grid.front().size();\n\tPoint::set_range(h, w);\n\tvector<vector<int>> res(h,\
    \ vector<int>(w, INT_MAX));\n\tif (grid[start.y][start.x] == wall) {\n\t\treturn\
    \ res;\n\t}\n\tres[start.y][start.x] = 0;\n\tqueue<Point> q;\n\tq.push(start);\n\
    \twhile (!q.empty()) {\n\t\tauto f = q.front();\n\t\tq.pop();\n\t\tfor (auto p\
    \ : f.adj4_in_range()) {\n\t\t\tif (grid[p.y][p.x] != wall && res[p.y][p.x] ==\
    \ INT_MAX) {\n\t\t\t\tq.push(p);\n\t\t\t\tres[p.y][p.x] = res[f.y][f.x] + 1;\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn res;\n}\nvector<vector<int>> GridBFS(const vector<string>&\
    \ grid, char start, char wall = '#') {\n\tint h = grid.size(), w = grid.front().size();\n\
    \tPoint s;\n\tfor (int i = 0; i < h; ++i)\n\t\tfor (int j = 0; j < w; ++j) {\n\
    \t\t\tif (grid[i][j] == start) {\n\t\t\t\ts = Point(j, i);\n\t\t\t}\n\t\t}\n\t\
    return GridBFS(grid, s, wall);\n}\n"
  dependsOn:
  - Utility/Point.cpp
  isVerificationFile: false
  path: Serch/GridBFS.cpp
  requiredBy: []
  timestamp: '2020-11-21 14:30:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Serch/GridBFS.cpp
layout: document
redirect_from:
- /library/Serch/GridBFS.cpp
- /library/Serch/GridBFS.cpp.html
title: Serch/GridBFS.cpp
---
