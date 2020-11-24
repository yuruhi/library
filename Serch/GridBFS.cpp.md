---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/Point.cpp
    title: Utility/Point.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/GridBFS.test.cpp
    title: test/GridBFS.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/Point.cpp\"\n#include <vector>\n#include <utility>\n\
    #include <optional>\n#include <iostream>\n#include <cassert>\nusing namespace\
    \ std;\n\nstruct Point {\n\tstatic int H, W;\n\tstatic const vector<Point> d;\n\
    \tstatic void set_range(int _H, int _W) {\n\t\tH = _H;\n\t\tW = _W;\n\t}\n\tstatic\
    \ constexpr Point zero() {\n\t\treturn {0, 0};\n\t}\n\tstatic constexpr Point\
    \ one() {\n\t\treturn {1, 1};\n\t}\n\tstatic constexpr Point L() {\n\t\treturn\
    \ {-1, 0};\n\t}\n\tstatic constexpr Point R() {\n\t\treturn {1, 0};\n\t}\n\tstatic\
    \ constexpr Point U() {\n\t\treturn {0, -1};\n\t}\n\tstatic constexpr Point D()\
    \ {\n\t\treturn {0, 1};\n\t}\n\tstatic constexpr Point LU() {\n\t\treturn {-1,\
    \ -1};\n\t}\n\tstatic constexpr Point LD() {\n\t\treturn {-1, 1};\n\t}\n\tstatic\
    \ constexpr Point RU() {\n\t\treturn {1, -1};\n\t}\n\tstatic constexpr Point RD()\
    \ {\n\t\treturn {1, 1};\n\t}\n\n\tint x, y;\n\tconstexpr Point() : x(0), y(0)\
    \ {}\n\tconstexpr Point(int _x, int _y) : x(_x), y(_y) {}\n\tconstexpr Point(const\
    \ pair<int, int>& xy) : x(xy.first), y(xy.second) {}\n\tPoint(int n) : x(n % W),\
    \ y(n / W) {}\n\tconstexpr Point operator+() const {\n\t\treturn *this;\n\t}\n\
    \tconstexpr Point operator-() const {\n\t\treturn {-x, -y};\n\t}\n\tconstexpr\
    \ Point operator+(const Point& p) const {\n\t\treturn Point(*this) += p;\n\t}\n\
    \tconstexpr Point operator-(const Point& p) const {\n\t\treturn Point(*this) -=\
    \ p;\n\t}\n\tconstexpr Point operator*(const Point& p) const {\n\t\treturn Point(*this)\
    \ *= p;\n\t}\n\tconstexpr Point operator/(const Point& p) const {\n\t\treturn\
    \ Point(*this) /= p;\n\t}\n\tconstexpr Point operator%(const Point& p) const {\n\
    \t\treturn Point(*this) %= p;\n\t}\n\tconstexpr Point operator+(int n) const {\n\
    \t\treturn Point(*this) += n;\n\t}\n\tconstexpr Point operator-(int n) const {\n\
    \t\treturn Point(*this) -= n;\n\t}\n\tconstexpr Point operator*(int n) const {\n\
    \t\treturn Point(*this) *= n;\n\t}\n\tconstexpr Point operator/(int n) const {\n\
    \t\treturn Point(*this) /= n;\n\t}\n\tconstexpr Point operator%(int n) const {\n\
    \t\treturn Point(*this) %= n;\n\t}\n\tconstexpr Point& operator+=(const Point&\
    \ p) {\n\t\tx += p.x;\n\t\ty += p.y;\n\t\treturn *this;\n\t}\n\tconstexpr Point&\
    \ operator-=(const Point& p) {\n\t\tx -= p.x;\n\t\ty -= p.y;\n\t\treturn *this;\n\
    \t}\n\tconstexpr Point& operator*=(const Point& p) {\n\t\tx *= p.x;\n\t\ty *=\
    \ p.y;\n\t\treturn *this;\n\t}\n\tconstexpr Point& operator/=(const Point& p)\
    \ {\n\t\tx /= p.x;\n\t\ty /= p.y;\n\t\treturn *this;\n\t}\n\tconstexpr Point&\
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
    \ <class InputIterator>\n\tvector<Point> enumrate_adjanect(InputIterator first,\
    \ InputIterator last) const {\n\t\tvector<Point> result;\n\t\tfor (; first !=\
    \ last; ++first) {\n\t\t\tresult.push_back(operator+(*first));\n\t\t}\n\t\treturn\
    \ result;\n\t}\n\ttemplate <class InputIterator>\n\tvector<Point> enumrate_adj_in_range(InputIterator\
    \ first, InputIterator last) const {\n\t\tvector<Point> result;\n\t\tfor (; first\
    \ != last; ++first) {\n\t\t\tauto p = operator+(*first);\n\t\t\tif (p.in_range())\
    \ result.push_back(p);\n\t\t}\n\t\treturn result;\n\t}\n\tvector<Point> adjacent4()\
    \ const {\n\t\treturn enumrate_adjanect(d.begin(), d.begin() + 4);\n\t}\n\tvector<Point>\
    \ adjacent8() const {\n\t\treturn enumrate_adjanect(d.begin(), d.end());\n\t}\n\
    \tvector<Point> adj4_in_range() const {\n\t\treturn enumrate_adj_in_range(d.begin(),\
    \ d.begin() + 4);\n\t}\n\tvector<Point> adj8_in_range() const {\n\t\treturn enumrate_adj_in_range(d.begin(),\
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
    \ string& lrud = \"LRUD\") const {\n\t\tassert(4 <= lrud.size() && lrud.size()\
    \ <= 5);\n\t\tif (y == 0 && x < 0) {\n\t\t\treturn lrud[0];\n\t\t} else if (y\
    \ == 0 && x > 0) {\n\t\t\treturn lrud[1];\n\t\t} else if (x == 0 && y < 0) {\n\
    \t\t\treturn lrud[2];\n\t\t} else if (x == 0 && y > 0) {\n\t\t\treturn lrud[3];\n\
    \t\t} else if (lrud.size() == 5) {\n\t\t\treturn lrud[4];\n\t\t} else {\n\t\t\t\
    assert(false);\n\t\t}\n\t}\n\n\tstatic Point to_direction(char c, const string&\
    \ lrud = \"LRUD\") {\n\t\tassert(lrud.size() == 4);\n\t\tif (c == lrud[0]) {\n\
    \t\t\treturn L();\n\t\t} else if (c == lrud[1]) {\n\t\t\treturn R();\n\t\t} else\
    \ if (c == lrud[2]) {\n\t\t\treturn U();\n\t\t} else if (c == lrud[3]) {\n\t\t\
    \treturn D();\n\t\t} else {\n\t\t\treturn zero();\n\t\t}\n\t}\n\n\ttemplate <class\
    \ T, class value_type = typename T::value_type::value_type>\n\tstatic optional<Point>\
    \ find(const T& grid, const value_type& val) {\n\t\tassert(static_cast<int>(grid.size())\
    \ == H);\n\t\tfor (int i = 0; i < H; ++i) {\n\t\t\tassert(static_cast<int>(grid[i].size())\
    \ == W);\n\t\t\tfor (int j = 0; j < W; ++j) {\n\t\t\t\tif (grid[i][j] == val)\
    \ {\n\t\t\t\t\treturn Point(j, i);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn nullopt;\n\
    \t}\n\ttemplate <class T, class Predicate>\n\tstatic optional<Point> find_if(const\
    \ T& grid, Predicate pred) {\n\t\tassert(static_cast<int>(grid.size()) == H);\n\
    \t\tfor (int i = 0; i < H; ++i) {\n\t\t\tassert(static_cast<int>(grid[i].size())\
    \ == W);\n\t\t\tfor (int j = 0; j < W; ++j) {\n\t\t\t\tif (pred(grid[i][j])) {\n\
    \t\t\t\t\treturn Point(j, i);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn nullopt;\n\
    \t}\n\ttemplate <class T, class value_type = typename T::value_type::value_type>\n\
    \tstatic optional<Point> find_one(const T& grid, const value_type& val) {\n\t\t\
    assert(static_cast<int>(grid.size()) == H);\n\t\toptional<Point> result;\n\t\t\
    for (int i = 0; i < H; ++i) {\n\t\t\tassert(static_cast<int>(grid[i].size()) ==\
    \ W);\n\t\t\tfor (int j = 0; j < W; ++j) {\n\t\t\t\tif (grid[i][j] == val) {\n\
    \t\t\t\t\tassert(!result);\n\t\t\t\t\tresult = Point(j, i);\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t\treturn result;\n\t}\n\n\tfriend ostream& operator<<(ostream& os,\
    \ const Point& p) {\n\t\treturn os << '(' << p.x << \", \" << p.y << ')';\n\t\
    }\n\tfriend istream& operator>>(istream& is, Point& p) {\n\t\treturn is >> p.y\
    \ >> p.x;\n\t}\n};\nint Point::H, Point::W;\nconst vector<Point> Point::d{Point::R(),\
    \  Point::D(),  Point::U(),  Point::L(),\n                             Point::RD(),\
    \ Point::LU(), Point::RU(), Point::LD()};\n#line 4 \"Serch/GridBFS.cpp\"\n#include\
    \ <string>\n#include <queue>\n#line 7 \"Serch/GridBFS.cpp\"\n#include <limits>\n\
    #line 9 \"Serch/GridBFS.cpp\"\nusing namespace std;\n\nvector<vector<int>> GridBFS(const\
    \ vector<string>& grid, Point start, char wall) {\n\tconstexpr int INF = numeric_limits<int>::max();\n\
    \tint h = grid.size(), w = grid.front().size();\n\tPoint::set_range(h, w);\n\t\
    vector<vector<int>> result(h, vector<int>(w, INF));\n\tif (grid[start.y][start.x]\
    \ == wall) {\n\t\treturn result;\n\t}\n\tresult[start.y][start.x] = 0;\n\tqueue<Point>\
    \ q;\n\tq.push(start);\n\twhile (!q.empty()) {\n\t\tauto now = q.front();\n\t\t\
    q.pop();\n\t\tfor (auto adj : now.adj4_in_range()) {\n\t\t\tif (grid[adj.y][adj.x]\
    \ != wall && result[adj.y][adj.x] == INF) {\n\t\t\t\tq.push(adj);\n\t\t\t\tresult[adj.y][adj.x]\
    \ = result[now.y][now.x] + 1;\n\t\t\t}\n\t\t}\n\t}\n\treturn result;\n}\nvector<vector<int>>\
    \ GridBFS(const vector<string>& grid, char start, char wall) {\n\tPoint::set_range(grid.size(),\
    \ grid.front().size());\n\tauto s = Point::find_one(grid, start);\n\tassert(s);\n\
    \treturn GridBFS(grid, *s, wall);\n}\nint GridBFS(const vector<string>& grid,\
    \ char start, char goal, char wall) {\n\tassert(start != goal);\n\tPoint::set_range(grid.size(),\
    \ grid.front().size());\n\tauto s = Point::find_one(grid, start), g = Point::find_one(grid,\
    \ goal);\n\tassert(s && g);\n\treturn GridBFS(grid, *s, wall)[g->y][g->x];\n}\n"
  code: "#pragma once\n#include \"./../Utility/Point.cpp\"\n#include <vector>\n#include\
    \ <string>\n#include <queue>\n#include <optional>\n#include <limits>\n#include\
    \ <cassert>\nusing namespace std;\n\nvector<vector<int>> GridBFS(const vector<string>&\
    \ grid, Point start, char wall) {\n\tconstexpr int INF = numeric_limits<int>::max();\n\
    \tint h = grid.size(), w = grid.front().size();\n\tPoint::set_range(h, w);\n\t\
    vector<vector<int>> result(h, vector<int>(w, INF));\n\tif (grid[start.y][start.x]\
    \ == wall) {\n\t\treturn result;\n\t}\n\tresult[start.y][start.x] = 0;\n\tqueue<Point>\
    \ q;\n\tq.push(start);\n\twhile (!q.empty()) {\n\t\tauto now = q.front();\n\t\t\
    q.pop();\n\t\tfor (auto adj : now.adj4_in_range()) {\n\t\t\tif (grid[adj.y][adj.x]\
    \ != wall && result[adj.y][adj.x] == INF) {\n\t\t\t\tq.push(adj);\n\t\t\t\tresult[adj.y][adj.x]\
    \ = result[now.y][now.x] + 1;\n\t\t\t}\n\t\t}\n\t}\n\treturn result;\n}\nvector<vector<int>>\
    \ GridBFS(const vector<string>& grid, char start, char wall) {\n\tPoint::set_range(grid.size(),\
    \ grid.front().size());\n\tauto s = Point::find_one(grid, start);\n\tassert(s);\n\
    \treturn GridBFS(grid, *s, wall);\n}\nint GridBFS(const vector<string>& grid,\
    \ char start, char goal, char wall) {\n\tassert(start != goal);\n\tPoint::set_range(grid.size(),\
    \ grid.front().size());\n\tauto s = Point::find_one(grid, start), g = Point::find_one(grid,\
    \ goal);\n\tassert(s && g);\n\treturn GridBFS(grid, *s, wall)[g->y][g->x];\n}\n"
  dependsOn:
  - Utility/Point.cpp
  isVerificationFile: false
  path: Serch/GridBFS.cpp
  requiredBy: []
  timestamp: '2020-11-24 20:32:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/GridBFS.test.cpp
documentation_of: Serch/GridBFS.cpp
layout: document
redirect_from:
- /library/Serch/GridBFS.cpp
- /library/Serch/GridBFS.cpp.html
title: Serch/GridBFS.cpp
---
