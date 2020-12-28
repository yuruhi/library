#pragma once
#include <vector>
#include <string_view>
#include <utility>
#include <optional>
#include <memory>
#include <iostream>
#include <cassert>
using namespace std;

struct Point {
	static int H, W;
	static const vector<Point> direction;
	using direction_iterator = vector<Point>::const_iterator;
	static void set_range(int _H, int _W) {
		H = _H;
		W = _W;
	}
	static constexpr Point zero() {
		return {0, 0};
	}
	static constexpr Point one() {
		return {1, 1};
	}
	static constexpr Point L() {
		return {-1, 0};
	}
	static constexpr Point R() {
		return {1, 0};
	}
	static constexpr Point U() {
		return {0, -1};
	}
	static constexpr Point D() {
		return {0, 1};
	}
	static constexpr Point LU() {
		return {-1, -1};
	}
	static constexpr Point LD() {
		return {-1, 1};
	}
	static constexpr Point RU() {
		return {1, -1};
	}
	static constexpr Point RD() {
		return {1, 1};
	}

	int x, y;
	constexpr Point() : x(0), y(0) {}
	constexpr Point(int _x, int _y) : x(_x), y(_y) {}
	constexpr Point(const pair<int, int>& xy) : x(xy.first), y(xy.second) {}
	Point(int n) : x(n % W), y(n / W) {}
	constexpr Point operator+() const {
		return *this;
	}
	constexpr Point operator-() const {
		return {-x, -y};
	}
	constexpr Point operator+(const Point& p) const {
		return Point(*this) += p;
	}
	constexpr Point operator-(const Point& p) const {
		return Point(*this) -= p;
	}
	constexpr Point operator*(const Point& p) const {
		return Point(*this) *= p;
	}
	constexpr Point operator/(const Point& p) const {
		return Point(*this) /= p;
	}
	constexpr Point operator%(const Point& p) const {
		return Point(*this) %= p;
	}
	constexpr Point operator+(int n) const {
		return Point(*this) += n;
	}
	constexpr Point operator-(int n) const {
		return Point(*this) -= n;
	}
	constexpr Point operator*(int n) const {
		return Point(*this) *= n;
	}
	constexpr Point operator/(int n) const {
		return Point(*this) /= n;
	}
	constexpr Point operator%(int n) const {
		return Point(*this) %= n;
	}
	constexpr Point& operator+=(const Point& p) {
		x += p.x;
		y += p.y;
		return *this;
	}
	constexpr Point& operator-=(const Point& p) {
		x -= p.x;
		y -= p.y;
		return *this;
	}
	constexpr Point& operator*=(const Point& p) {
		x *= p.x;
		y *= p.y;
		return *this;
	}
	constexpr Point& operator/=(const Point& p) {
		x /= p.x;
		y /= p.y;
		return *this;
	}
	constexpr Point& operator%=(const Point& p) {
		x %= p.x;
		y %= p.y;
		return *this;
	}
	constexpr Point& operator+=(int n) {
		x += n;
		y += n;
		return *this;
	}
	constexpr Point& operator-=(int n) {
		x -= n;
		y -= n;
		return *this;
	}
	constexpr Point& operator*=(int n) {
		x *= n;
		y *= n;
		return *this;
	}
	constexpr Point& operator/=(int n) {
		x /= n;
		y /= n;
		return *this;
	}
	constexpr Point& operator%=(int n) {
		x %= n;
		y %= n;
		return *this;
	}
	constexpr bool operator==(const Point& p) const {
		return x == p.x && y == p.y;
	}
	constexpr bool operator!=(const Point& p) const {
		return x != p.x || y != p.y;
	}
	bool operator<(const Point& p) const {
		return to_i() < p.to_i();
	}
	bool operator<=(const Point& p) const {
		return to_i() <= p.to_i();
	}
	bool operator>(const Point& p) const {
		return to_i() > p.to_i();
	}
	bool operator>=(const Point& p) const {
		return to_i() >= p.to_i();
	}
	constexpr int operator[](int i) const {
		return i == 0 ? x : i == 1 ? y : 0;
	}
	constexpr bool in_range(int height, int width) const {
		return 0 <= x && x < width && 0 <= y && y < height;
	}
	bool in_range() const {
		return in_range(H, W);
	}
	int to_i() const {
		return x + y * W;
	}
	constexpr pair<int, int> to_pair() const {
		return {x, y};
	}
	constexpr int manhattan(const Point& p) const {
		return abs(x - p.x) + abs(y - p.y);
	}
	constexpr int chebyshev(const Point& p) const {
		return max(abs(x - p.x), abs(y - p.y));
	}
	constexpr int distance_square(const Point& p) const {
		return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
	}
	template <class Real> constexpr Real distance(const Point& p) const {
		return sqrt(static_cast<Real>(distance_square(p)));
	}
	constexpr Point absolute(const Point& p) const {
		return absolute(*this - p);
	}
	constexpr Point absolute() const {
		return {abs(x), abs(y)};
	}
	Point& swap() {
		std::swap(x, y);
		return *this;
	}

	class enumerate_adjacent_helper {
		shared_ptr<Point> p;
		direction_iterator first, last;

		class iterator {
			shared_ptr<Point> p;
			direction_iterator it;

		public:
			iterator(shared_ptr<Point> _p, direction_iterator _it) : p(_p), it(_it) {}
			Point operator*() const {
				return *p + *it;
			}
			iterator& operator++() {
				++it;
				return *this;
			}
			bool operator!=(iterator other) const {
				return it != other.it;
			}
		};

	public:
		enumerate_adjacent_helper(shared_ptr<Point> _p, direction_iterator _first,
		                          direction_iterator _last)
		    : p(_p), first(_first), last(_last) {}
		iterator begin() const {
			return iterator(p, first);
		}
		iterator end() const {
			return iterator(p, last);
		}
	};
	auto enumerate_adjacent(direction_iterator first, direction_iterator last) const {
		return enumerate_adjacent_helper(make_shared<Point>(*this), first, last);
	}
	auto adjacent4() const {
		return enumerate_adjacent(direction.begin(), direction.begin() + 4);
	}
	auto adjacent8() const {
		return enumerate_adjacent(direction.begin(), direction.begin() + 8);
	}

	class enumerate_adj_in_range_helper {
		shared_ptr<Point> p;
		direction_iterator first, last;

		class sentinel {};
		class iterator {
			shared_ptr<Point> p;
			direction_iterator first, last;

			void increment_until_in_range() {
				for (; first != last; ++first) {
					if ((*p + *first).in_range()) return;
				}
			}

		public:
			iterator(shared_ptr<Point> _p, direction_iterator _first,
			         direction_iterator _last)
			    : p(_p), first(_first), last(_last) {
				increment_until_in_range();
			}
			Point operator*() const {
				return *p + *first;
			}
			iterator& operator++() {
				++first;
				increment_until_in_range();
				return *this;
			}
			bool operator!=([[maybe_unused]] sentinel other) const {
				return first != last;
			}
		};

	public:
		enumerate_adj_in_range_helper(shared_ptr<Point> _p, direction_iterator _first,
		                              direction_iterator _last)
		    : p(_p), first(_first), last(_last) {}
		iterator begin() const {
			return iterator(p, first, last);
		}
		sentinel end() const {
			return sentinel();
		}
	};
	template <class InputIterator>
	auto enumerate_adj_in_range(InputIterator first, InputIterator last) const {
		return enumerate_adj_in_range_helper(make_shared<Point>(*this), first, last);
	}
	auto adj4_in_range() const {
		return enumerate_adj_in_range(direction.begin(), direction.begin() + 4);
	}
	auto adj8_in_range() const {
		return enumerate_adj_in_range(direction.begin(), direction.end());
	}

	constexpr Point left() const {
		return {x - 1, y};
	}
	constexpr Point right() const {
		return {x + 1, y};
	}
	constexpr Point up() const {
		return {x, y - 1};
	}
	constexpr Point down() const {
		return {x, y + 1};
	}
	Point succ() const {
		if (x != W - 1) {
			return {x + 1, y};
		} else {
			return {0, y + 1};
		}
	}
	Point pred() const {
		if (x != 0) {
			return {x - 1, y};
		} else {
			return {W - 1, y - 1};
		}
	}
	constexpr Point moved(char c) const {
		return Point(*this).move(c);
	}
	constexpr Point& move(char c) {
		switch (c) {
			case 'L':
			case 'l':
			case 'W':
			case '>':
				x--;
				break;
			case 'R':
			case 'r':
			case 'E':
			case '<':
				x++;
				break;
			case 'U':
			case 'u':
			case 'N':
			case '^':
				y--;
				break;
			case 'D':
			case 'd':
			case 'S':
			case 'v':
				y++;
				break;
		}
		return *this;
	}
	constexpr Point rotate90() const {
		return {y, -x};
	}
	constexpr Point rotate180() const {
		return {-x, -y};
	}
	constexpr Point rotate270() const {
		return {-y, x};
	}
	char to_direction_char(string_view lrud = "LRUD") const {
		assert(4 <= lrud.size() && lrud.size() <= 5);
		if (y == 0 && x < 0) {
			return lrud[0];
		} else if (y == 0 && x > 0) {
			return lrud[1];
		} else if (x == 0 && y < 0) {
			return lrud[2];
		} else if (x == 0 && y > 0) {
			return lrud[3];
		} else if (lrud.size() == 5) {
			return lrud[4];
		} else {
			assert(false);
		}
	}

	static Point to_direction(char c, string_view lrud = "LRUD") {
		assert(lrud.size() == 4);
		if (c == lrud[0]) {
			return L();
		} else if (c == lrud[1]) {
			return R();
		} else if (c == lrud[2]) {
			return U();
		} else if (c == lrud[3]) {
			return D();
		} else {
			return zero();
		}
	}
	static Point to_direction(string s, string_view lrud = "LRUD") {
		if (s.size() == 1) {
			return to_direction(s[0], lrud);
		} else if (s.size() == 2) {
			Point p1 = to_direction(s[0], lrud), p2 = to_direction(s[1], lrud);
			assert((p1.x == 0) ^ (p2.x == 0));
			assert((p1.y == 0) ^ (p2.y == 0));
			return p1 + p2;
		} else {
			assert(false);
		}
	}

	template <class T, class value_type = typename T::value_type::value_type>
	static optional<Point> find(const T& grid, const value_type& val) {
		assert(static_cast<int>(grid.size()) == H);
		for (int i = 0; i < H; ++i) {
			assert(static_cast<int>(grid[i].size()) == W);
			for (int j = 0; j < W; ++j) {
				if (grid[i][j] == val) {
					return Point(j, i);
				}
			}
		}
		return nullopt;
	}
	template <class T, class Predicate>
	static optional<Point> find_if(const T& grid, Predicate pred) {
		assert(static_cast<int>(grid.size()) == H);
		for (int i = 0; i < H; ++i) {
			assert(static_cast<int>(grid[i].size()) == W);
			for (int j = 0; j < W; ++j) {
				if (pred(grid[i][j])) {
					return Point(j, i);
				}
			}
		}
		return nullopt;
	}
	template <class T, class value_type = typename T::value_type::value_type>
	static optional<Point> find_one(const T& grid, const value_type& val) {
		assert(static_cast<int>(grid.size()) == H);
		optional<Point> result;
		for (int i = 0; i < H; ++i) {
			assert(static_cast<int>(grid[i].size()) == W);
			for (int j = 0; j < W; ++j) {
				if (grid[i][j] == val) {
					assert(!result);
					result = Point(j, i);
				}
			}
		}
		return result;
	}
	template <class T, class value_type = typename T::value_type::value_type>
	static vector<Point> find_all(const T& grid, const value_type& val) {
		assert(static_cast<int>(grid.size()) == H);
		vector<Point> result;
		for (int i = 0; i < H; ++i) {
			assert(static_cast<int>(grid[i].size()) == W);
			for (int j = 0; j < W; ++j) {
				if (grid[i][j] == val) {
					result.emplace_back(j, i);
				}
			}
		}
		return result;
	}

	static auto enumerate_2D_points() {
		class enumerate_2D_points_helper {
		public:
			class iterator {
				Point p;

			public:
				iterator(const Point& _p) : p(_p) {}
				Point operator*() const {
					return p;
				}
				iterator& operator++() {
					p = p.succ();
					return *this;
				}
				iterator& operator--() {
					p = p.pred();
					return *this;
				}
				bool operator!=(iterator other) const {
					return p != other.p;
				}
			};
			iterator begin() const {
				return iterator(Point(0, 0));
			}
			iterator end() const {
				return iterator(Point(0, H));
			}
		};
		return enumerate_2D_points_helper();
	}

	friend ostream& operator<<(ostream& os, const Point& p) {
		return os << '(' << p.x << ", " << p.y << ')';
	}
	friend istream& operator>>(istream& is, Point& p) {
		return is >> p.y >> p.x;
	}
};
int Point::H, Point::W;
const vector<Point> Point::direction{Point::R(),  Point::D(),  Point::U(),  Point::L(),
                                     Point::RD(), Point::LU(), Point::RU(), Point::LD()};
