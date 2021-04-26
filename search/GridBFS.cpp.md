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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/Point.cpp\"\n#include <vector>\n#include <string>\n\
    #include <string_view>\n#include <utility>\n#include <optional>\n#include <memory>\n\
    #include <iostream>\n#include <cmath>\n#include <cassert>\n\nstruct Point {\n\t\
    using direction_iterator = std::vector<Point>::const_iterator;\n\nprivate:\n\t\
    static inline int W, H;\n\npublic:\n\tstatic void set_range(int height, int width)\
    \ {\n\t\tH = height;\n\t\tW = width;\n\t}\n\tstatic int height() {\n\t\treturn\
    \ H;\n\t}\n\tstatic int width() {\n\t\treturn W;\n\t}\n\n\tstatic constexpr Point\
    \ zero() {\n\t\treturn {0, 0};\n\t}\n\tstatic constexpr Point L() {\n\t\treturn\
    \ {0, -1};\n\t}\n\tstatic constexpr Point R() {\n\t\treturn {0, 1};\n\t}\n\tstatic\
    \ constexpr Point U() {\n\t\treturn {-1, 0};\n\t}\n\tstatic constexpr Point D()\
    \ {\n\t\treturn {1, 0};\n\t}\n\tstatic constexpr Point LU() {\n\t\treturn {-1,\
    \ -1};\n\t}\n\tstatic constexpr Point LD() {\n\t\treturn {1, -1};\n\t}\n\tstatic\
    \ constexpr Point RU() {\n\t\treturn {-1, 1};\n\t}\n\tstatic constexpr Point RD()\
    \ {\n\t\treturn {1, 1};\n\t}\n\tstatic const std::vector<Point> direction;\n\n\
    \tint y, x;\n\tconstexpr Point() : y(0), x(0) {}\n\tconstexpr Point(int _y, int\
    \ _x) : y(_y), x(_x) {}\n\tconstexpr Point(const std::pair<int, int>& yx) : y(yx.first),\
    \ x(yx.second) {}\n\tPoint(int n) : y(n / W), x(n % W) {}\n\tconstexpr Point operator+()\
    \ const {\n\t\treturn *this;\n\t}\n\tconstexpr Point operator-() const {\n\t\t\
    return {-y, -x};\n\t}\n\tconstexpr Point operator+(const Point& p) const {\n\t\
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
    \ Point& p) {\n\t\ty += p.y;\n\t\tx += p.x;\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ Point& operator-=(const Point& p) {\n\t\ty -= p.y;\n\t\tx -= p.x;\n\t\treturn\
    \ *this;\n\t}\n\tconstexpr Point& operator*=(const Point& p) {\n\t\ty *= p.y;\n\
    \t\tx *= p.x;\n\t\treturn *this;\n\t}\n\tconstexpr Point& operator/=(const Point&\
    \ p) {\n\t\ty /= p.y;\n\t\tx /= p.x;\n\t\treturn *this;\n\t}\n\tconstexpr Point&\
    \ operator%=(const Point& p) {\n\t\ty %= p.y;\n\t\tx %= p.x;\n\t\treturn *this;\n\
    \t}\n\tconstexpr Point& operator+=(int n) {\n\t\ty += n;\n\t\tx += n;\n\t\treturn\
    \ *this;\n\t}\n\tconstexpr Point& operator-=(int n) {\n\t\ty -= n;\n\t\tx -= n;\n\
    \t\treturn *this;\n\t}\n\tconstexpr Point& operator*=(int n) {\n\t\ty *= n;\n\t\
    \tx *= n;\n\t\treturn *this;\n\t}\n\tconstexpr Point& operator/=(int n) {\n\t\t\
    y /= n;\n\t\tx /= n;\n\t\treturn *this;\n\t}\n\tconstexpr Point& operator%=(int\
    \ n) {\n\t\ty %= n;\n\t\tx %= n;\n\t\treturn *this;\n\t}\n\tconstexpr bool operator==(const\
    \ Point& p) const {\n\t\treturn y == p.y && x == p.x;\n\t}\n\tconstexpr bool operator!=(const\
    \ Point& p) const {\n\t\treturn y != p.y || x != p.x;\n\t}\n\tbool operator<(const\
    \ Point& p) const {\n\t\treturn to_i() < p.to_i();\n\t}\n\tbool operator<=(const\
    \ Point& p) const {\n\t\treturn to_i() <= p.to_i();\n\t}\n\tbool operator>(const\
    \ Point& p) const {\n\t\treturn to_i() > p.to_i();\n\t}\n\tbool operator>=(const\
    \ Point& p) const {\n\t\treturn to_i() >= p.to_i();\n\t}\n\tconstexpr bool in_range(int\
    \ height, int width) const {\n\t\treturn 0 <= y && y < height && 0 <= x && x <\
    \ width;\n\t}\n\tbool in_range() const {\n\t\treturn in_range(H, W);\n\t}\n\t\
    int to_i() const {\n\t\treturn y * W + x;\n\t}\n\tconstexpr Point yx() const {\n\
    \t\treturn {y, x};\n\t}\n\tconstexpr std::pair<int, int> pair() const {\n\t\t\
    return {y, x};\n\t}\n\tconstexpr std::pair<int, int> anti_pair() const {\n\t\t\
    return {x, y};\n\t}\n\tconstexpr int manhattan(const Point& p) const {\n\t\treturn\
    \ std::abs(x - p.x) + std::abs(y - p.y);\n\t}\n\tconstexpr int chebyshev(const\
    \ Point& p) const {\n\t\treturn std::max(std::abs(y - p.y), std::abs(x - p.x));\n\
    \t}\n\tconstexpr int distance_square(const Point& p) const {\n\t\treturn (y -\
    \ p.y) * (y - p.y) + (x - p.x) * (x - p.x);\n\t}\n\ttemplate <class Real> constexpr\
    \ Real distance(const Point& p) const {\n\t\treturn std::sqrt(static_cast<Real>(distance_square(p)));\n\
    \t}\n\tconstexpr Point absolute(const Point& p) const {\n\t\treturn absolute(*this\
    \ - p);\n\t}\n\tconstexpr Point absolute() const {\n\t\treturn {std::abs(y), std::abs(x)};\n\
    \t}\n\n\tclass enumerate_adjacent_helper {\n\t\tstd::shared_ptr<Point> p;\n\t\t\
    direction_iterator first, last;\n\n\t\tclass iterator {\n\t\t\tstd::shared_ptr<Point>\
    \ p;\n\t\t\tdirection_iterator it;\n\n\t\tpublic:\n\t\t\titerator(std::shared_ptr<Point>\
    \ _p, direction_iterator _it) : p(_p), it(_it) {}\n\t\t\tPoint operator*() const\
    \ {\n\t\t\t\treturn *p + *it;\n\t\t\t}\n\t\t\titerator& operator++() {\n\t\t\t\
    \t++it;\n\t\t\t\treturn *this;\n\t\t\t}\n\t\t\tbool operator!=(iterator other)\
    \ const {\n\t\t\t\treturn it != other.it;\n\t\t\t}\n\t\t};\n\n\tpublic:\n\t\t\
    enumerate_adjacent_helper(std::shared_ptr<Point> _p, direction_iterator _first,\n\
    \t\t                          direction_iterator _last)\n\t\t    : p(_p), first(_first),\
    \ last(_last) {}\n\t\titerator begin() const {\n\t\t\treturn iterator(p, first);\n\
    \t\t}\n\t\titerator end() const {\n\t\t\treturn iterator(p, last);\n\t\t}\n\t\
    };\n\tauto enumerate_adjacent(direction_iterator first, direction_iterator last)\
    \ const {\n\t\treturn enumerate_adjacent_helper(std::make_shared<Point>(*this),\
    \ first, last);\n\t}\n\tauto adj4() const {\n\t\treturn enumerate_adjacent(direction.begin()\
    \ + 1, direction.begin() + 5);\n\t}\n\tauto adj4_and_this() const {\n\t\treturn\
    \ enumerate_adjacent(direction.begin(), direction.begin() + 5);\n\t}\n\tauto adjacent8()\
    \ const {\n\t\treturn enumerate_adjacent(direction.begin() + 1, direction.begin()\
    \ + 9);\n\t}\n\tauto adj8_and_this() const {\n\t\treturn enumerate_adjacent(direction.begin(),\
    \ direction.begin() + 9);\n\t}\n\n\tclass enumerate_adj_in_range_helper {\n\t\t\
    std::shared_ptr<Point> p;\n\t\tdirection_iterator first, last;\n\n\t\tclass sentinel\
    \ {};\n\t\tclass iterator {\n\t\t\tstd::shared_ptr<Point> p;\n\t\t\tdirection_iterator\
    \ first, last;\n\n\t\t\tvoid increment_until_in_range() {\n\t\t\t\tfor (; first\
    \ != last; ++first) {\n\t\t\t\t\tif ((*p + *first).in_range()) return;\n\t\t\t\
    \t}\n\t\t\t}\n\n\t\tpublic:\n\t\t\titerator(std::shared_ptr<Point> _p, direction_iterator\
    \ _first,\n\t\t\t         direction_iterator _last)\n\t\t\t    : p(_p), first(_first),\
    \ last(_last) {\n\t\t\t\tincrement_until_in_range();\n\t\t\t}\n\t\t\tPoint operator*()\
    \ const {\n\t\t\t\treturn *p + *first;\n\t\t\t}\n\t\t\titerator& operator++()\
    \ {\n\t\t\t\t++first;\n\t\t\t\tincrement_until_in_range();\n\t\t\t\treturn *this;\n\
    \t\t\t}\n\t\t\tbool operator!=([[maybe_unused]] sentinel other) const {\n\t\t\t\
    \treturn first != last;\n\t\t\t}\n\t\t};\n\n\tpublic:\n\t\tenumerate_adj_in_range_helper(std::shared_ptr<Point>\
    \ _p, direction_iterator _first,\n\t\t                              direction_iterator\
    \ _last)\n\t\t    : p(_p), first(_first), last(_last) {}\n\t\titerator begin()\
    \ const {\n\t\t\treturn iterator(p, first, last);\n\t\t}\n\t\tsentinel end() const\
    \ {\n\t\t\treturn sentinel();\n\t\t}\n\t};\n\ttemplate <class InputIterator>\n\
    \tauto enumerate_adj_in_range(InputIterator first, InputIterator last) const {\n\
    \t\treturn enumerate_adj_in_range_helper(std::make_shared<Point>(*this), first,\
    \ last);\n\t}\n\tauto adj4_in_range() const {\n\t\treturn enumerate_adj_in_range(direction.begin()\
    \ + 1, direction.begin() + 5);\n\t}\n\tauto adj4_and_this_in_range() const {\n\
    \t\treturn enumerate_adj_in_range(direction.begin(), direction.begin() + 5);\n\
    \t}\n\tauto adj8_in_range() const {\n\t\treturn enumerate_adj_in_range(direction.begin()\
    \ + 1, direction.begin() + 9);\n\t}\n\tauto ajd8_and_this_in_range() const {\n\
    \t\treturn enumerate_adj_in_range(direction.begin(), direction.begin() + 9);\n\
    \t}\n\n\tconstexpr Point left() const {\n\t\treturn {y, x - 1};\n\t}\n\tconstexpr\
    \ Point right() const {\n\t\treturn {y, x + 1};\n\t}\n\tconstexpr Point up() const\
    \ {\n\t\treturn {y - 1, x};\n\t}\n\tconstexpr Point down() const {\n\t\treturn\
    \ {y + 1, x};\n\t}\n\tPoint succ() const {\n\t\tif (x != W - 1) {\n\t\t\treturn\
    \ {y, x + 1};\n\t\t} else {\n\t\t\treturn {y + 1, 0};\n\t\t}\n\t}\n\tPoint pred()\
    \ const {\n\t\tif (x != 0) {\n\t\t\treturn {y, x - 1};\n\t\t} else {\n\t\t\treturn\
    \ {y - 1, W - 1};\n\t\t}\n\t}\n\tconstexpr Point moved(char c) const {\n\t\treturn\
    \ Point(*this).move(c);\n\t}\n\tconstexpr Point& move(char c) {\n\t\tswitch (c)\
    \ {\n\t\t\tcase 'L':\n\t\t\tcase 'l':\n\t\t\tcase 'W':\n\t\t\tcase '>':\n\t\t\t\
    \tx--;\n\t\t\t\tbreak;\n\t\t\tcase 'R':\n\t\t\tcase 'r':\n\t\t\tcase 'E':\n\t\t\
    \tcase '<':\n\t\t\t\tx++;\n\t\t\t\tbreak;\n\t\t\tcase 'U':\n\t\t\tcase 'u':\n\t\
    \t\tcase 'N':\n\t\t\tcase '^':\n\t\t\t\ty--;\n\t\t\t\tbreak;\n\t\t\tcase 'D':\n\
    \t\t\tcase 'd':\n\t\t\tcase 'S':\n\t\t\tcase 'v':\n\t\t\t\ty++;\n\t\t\t\tbreak;\n\
    \t\t}\n\t\treturn *this;\n\t}\n\tconstexpr Point rotate90() const {\n\t\treturn\
    \ {-x, y};\n\t}\n\tconstexpr Point rotate180() const {\n\t\treturn {-y, -x};\n\
    \t}\n\tconstexpr Point rotate270() const {\n\t\treturn {x, -y};\n\t}\n\tchar to_direction_char(std::string_view\
    \ lrud = \"LRUD\") const {\n\t\tassert(4 <= lrud.size() && lrud.size() <= 5);\n\
    \t\tif (y == 0 && x < 0) {\n\t\t\treturn lrud[0];\n\t\t} else if (y == 0 && x\
    \ > 0) {\n\t\t\treturn lrud[1];\n\t\t} else if (x == 0 && y < 0) {\n\t\t\treturn\
    \ lrud[2];\n\t\t} else if (x == 0 && y > 0) {\n\t\t\treturn lrud[3];\n\t\t} else\
    \ if (lrud.size() == 5) {\n\t\t\treturn lrud[4];\n\t\t} else {\n\t\t\tassert(false);\n\
    \t\t}\n\t}\n\n\tstatic Point to_direction(char c, std::string_view lrud = \"LRUD\"\
    ) {\n\t\tassert(lrud.size() == 4);\n\t\tif (c == lrud[0]) {\n\t\t\treturn L();\n\
    \t\t} else if (c == lrud[1]) {\n\t\t\treturn R();\n\t\t} else if (c == lrud[2])\
    \ {\n\t\t\treturn U();\n\t\t} else if (c == lrud[3]) {\n\t\t\treturn D();\n\t\t\
    } else {\n\t\t\treturn zero();\n\t\t}\n\t}\n\tstatic Point to_direction(std::string\
    \ s, std::string_view lrud = \"LRUD\") {\n\t\tif (s.size() == 1) {\n\t\t\treturn\
    \ to_direction(s[0], lrud);\n\t\t} else if (s.size() == 2) {\n\t\t\tPoint p1 =\
    \ to_direction(s[0], lrud), p2 = to_direction(s[1], lrud);\n\t\t\tassert((p1.x\
    \ == 0) ^ (p2.x == 0));\n\t\t\tassert((p1.y == 0) ^ (p2.y == 0));\n\t\t\treturn\
    \ p1 + p2;\n\t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\n\ttemplate <class\
    \ T, class value_type = typename T::value_type::value_type>\n\tstatic std::optional<Point>\
    \ find(const T& grid, const value_type& val) {\n\t\tassert(static_cast<int>(grid.size())\
    \ == H);\n\t\tfor (int i = 0; i < H; ++i) {\n\t\t\tassert(static_cast<int>(grid[i].size())\
    \ == W);\n\t\t\tfor (int j = 0; j < W; ++j) {\n\t\t\t\tif (grid[i][j] == val)\
    \ {\n\t\t\t\t\treturn Point(i, j);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn std::nullopt;\n\
    \t}\n\ttemplate <class T, class Predicate>\n\tstatic std::optional<Point> find_if(const\
    \ T& grid, Predicate pred) {\n\t\tassert(static_cast<int>(grid.size()) == H);\n\
    \t\tfor (int i = 0; i < H; ++i) {\n\t\t\tassert(static_cast<int>(grid[i].size())\
    \ == W);\n\t\t\tfor (int j = 0; j < W; ++j) {\n\t\t\t\tif (pred(grid[i][j])) {\n\
    \t\t\t\t\treturn Point(i, j);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn std::nullopt;\n\
    \t}\n\ttemplate <class T, class value_type = typename T::value_type::value_type>\n\
    \tstatic std::optional<Point> find_one(const T& grid, const value_type& val) {\n\
    \t\tassert(static_cast<int>(grid.size()) == H);\n\t\tstd::optional<Point> result;\n\
    \t\tfor (int i = 0; i < H; ++i) {\n\t\t\tassert(static_cast<int>(grid[i].size())\
    \ == W);\n\t\t\tfor (int j = 0; j < W; ++j) {\n\t\t\t\tif (grid[i][j] == val)\
    \ {\n\t\t\t\t\tassert(!result);\n\t\t\t\t\tresult = Point(i, j);\n\t\t\t\t}\n\t\
    \t\t}\n\t\t}\n\t\treturn result;\n\t}\n\ttemplate <class T, class value_type =\
    \ typename T::value_type::value_type>\n\tstatic std::vector<Point> find_all(const\
    \ T& grid, const value_type& val) {\n\t\tassert(static_cast<int>(grid.size())\
    \ == H);\n\t\tstd::vector<Point> result;\n\t\tfor (int i = 0; i < H; ++i) {\n\t\
    \t\tassert(static_cast<int>(grid[i].size()) == W);\n\t\t\tfor (int j = 0; j <\
    \ W; ++j) {\n\t\t\t\tif (grid[i][j] == val) {\n\t\t\t\t\tresult.emplace_back(i,\
    \ j);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn result;\n\t}\n\n\tstatic auto enumerate_2D_points()\
    \ {\n\t\tclass enumerate_2D_points_helper {\n\t\tpublic:\n\t\t\tclass iterator\
    \ {\n\t\t\t\tPoint p;\n\n\t\t\tpublic:\n\t\t\t\titerator(const Point& _p) : p(_p)\
    \ {}\n\t\t\t\tPoint operator*() const {\n\t\t\t\t\treturn p;\n\t\t\t\t}\n\t\t\t\
    \titerator& operator++() {\n\t\t\t\t\tp = p.succ();\n\t\t\t\t\treturn *this;\n\
    \t\t\t\t}\n\t\t\t\titerator& operator--() {\n\t\t\t\t\tp = p.pred();\n\t\t\t\t\
    \treturn *this;\n\t\t\t\t}\n\t\t\t\tbool operator!=(iterator other) const {\n\t\
    \t\t\t\treturn p != other.p;\n\t\t\t\t}\n\t\t\t};\n\t\t\titerator begin() const\
    \ {\n\t\t\t\treturn iterator(Point(0, 0));\n\t\t\t}\n\t\t\titerator end() const\
    \ {\n\t\t\t\treturn iterator(Point(H, 0));\n\t\t\t}\n\t\t};\n\t\treturn enumerate_2D_points_helper();\n\
    \t}\n\n\ttemplate <class Scanner> void scan() {\n\t\tScanner::scan(y);\n\t\tScanner::scan(x);\n\
    \t}\n\ttemplate <class Printer> void print(const Printer& out) const {\n\t\tout.print('(');\n\
    \t\tout.print(y);\n\t\tout.print(\", \");\n\t\tout.print(x);\n\t\tout.print(')');\n\
    \t}\n\tfriend std::ostream& operator<<(std::ostream& os, const Point& p) {\n\t\
    \treturn os << '(' << p.y << \", \" << p.x << ')';\n\t}\n\tfriend std::istream&\
    \ operator>>(std::istream& is, Point& p) {\n\t\treturn is >> p.y >> p.x;\n\t}\n\
    };\nconst std::vector<Point> Point::direction{Point::zero(), Point::R(),  Point::D(),\n\
    \                                          Point::U(),    Point::L(),  Point::RD(),\n\
    \                                          Point::LU(),   Point::RU(), Point::LD()};\n\
    #line 5 \"search/GridBFS.cpp\"\n#include <queue>\n#line 7 \"search/GridBFS.cpp\"\
    \n#include <limits>\n#line 9 \"search/GridBFS.cpp\"\n\nauto GridBFS(const std::vector<std::string>&\
    \ grid, Point start, char wall_char) {\n\tconstexpr int INF = std::numeric_limits<int>::max();\n\
    \tint h = grid.size(), w = grid.front().size();\n\tPoint::set_range(h, w);\n\n\
    \tstd::vector result(h, std::vector(w, INF));\n\tif (grid[start.y][start.x] ==\
    \ wall_char) {\n\t\treturn result;\n\t}\n\tresult[start.y][start.x] = 0;\n\tstd::queue<Point>\
    \ q;\n\tq.push(start);\n\twhile (!q.empty()) {\n\t\tauto now = q.front();\n\t\t\
    q.pop();\n\t\tfor (auto adj : now.adj4_in_range()) {\n\t\t\tif (grid[adj.y][adj.x]\
    \ != wall_char && result[adj.y][adj.x] == INF) {\n\t\t\t\tq.push(adj);\n\t\t\t\
    \tresult[adj.y][adj.x] = result[now.y][now.x] + 1;\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ result;\n}\nauto GridBFS(const std::vector<std::string>& grid, char start_char,\
    \ char wall_char) {\n\tPoint::set_range(grid.size(), grid.front().size());\n\t\
    auto start = Point::find_one(grid, start_char);\n\tassert(start);\n\treturn GridBFS(grid,\
    \ *start, wall_char);\n}\nint GridBFS(const std::vector<std::string>& grid, Point\
    \ start, Point goal, char wall_char) {\n\treturn GridBFS(grid, start, wall_char)[goal.y][goal.x];\n\
    }\nint GridBFS(const std::vector<std::string>& grid, char start_char, char goal_char,\n\
    \            char wall_char) {\n\tassert(start_char != goal_char);\n\tPoint::set_range(grid.size(),\
    \ grid.front().size());\n\tauto start = Point::find_one(grid, start_char), goal\
    \ = Point::find_one(grid, goal_char);\n\tassert(start && goal);\n\treturn GridBFS(grid,\
    \ *start, *goal, wall_char);\n}\n"
  code: "#pragma once\n#include \"./../Utility/Point.cpp\"\n#include <vector>\n#include\
    \ <string>\n#include <queue>\n#include <optional>\n#include <limits>\n#include\
    \ <cassert>\n\nauto GridBFS(const std::vector<std::string>& grid, Point start,\
    \ char wall_char) {\n\tconstexpr int INF = std::numeric_limits<int>::max();\n\t\
    int h = grid.size(), w = grid.front().size();\n\tPoint::set_range(h, w);\n\n\t\
    std::vector result(h, std::vector(w, INF));\n\tif (grid[start.y][start.x] == wall_char)\
    \ {\n\t\treturn result;\n\t}\n\tresult[start.y][start.x] = 0;\n\tstd::queue<Point>\
    \ q;\n\tq.push(start);\n\twhile (!q.empty()) {\n\t\tauto now = q.front();\n\t\t\
    q.pop();\n\t\tfor (auto adj : now.adj4_in_range()) {\n\t\t\tif (grid[adj.y][adj.x]\
    \ != wall_char && result[adj.y][adj.x] == INF) {\n\t\t\t\tq.push(adj);\n\t\t\t\
    \tresult[adj.y][adj.x] = result[now.y][now.x] + 1;\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ result;\n}\nauto GridBFS(const std::vector<std::string>& grid, char start_char,\
    \ char wall_char) {\n\tPoint::set_range(grid.size(), grid.front().size());\n\t\
    auto start = Point::find_one(grid, start_char);\n\tassert(start);\n\treturn GridBFS(grid,\
    \ *start, wall_char);\n}\nint GridBFS(const std::vector<std::string>& grid, Point\
    \ start, Point goal, char wall_char) {\n\treturn GridBFS(grid, start, wall_char)[goal.y][goal.x];\n\
    }\nint GridBFS(const std::vector<std::string>& grid, char start_char, char goal_char,\n\
    \            char wall_char) {\n\tassert(start_char != goal_char);\n\tPoint::set_range(grid.size(),\
    \ grid.front().size());\n\tauto start = Point::find_one(grid, start_char), goal\
    \ = Point::find_one(grid, goal_char);\n\tassert(start && goal);\n\treturn GridBFS(grid,\
    \ *start, *goal, wall_char);\n}\n"
  dependsOn:
  - Utility/Point.cpp
  isVerificationFile: false
  path: search/GridBFS.cpp
  requiredBy: []
  timestamp: '2021-04-26 17:18:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/GridBFS.test.cpp
documentation_of: search/GridBFS.cpp
layout: document
redirect_from:
- /library/search/GridBFS.cpp
- /library/search/GridBFS.cpp.html
title: search/GridBFS.cpp
---
