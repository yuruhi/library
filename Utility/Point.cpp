#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <utility>
#include <optional>
#include <memory>
#include <iostream>
#include <cmath>
#include <cassert>

struct Point {
	using direction_iterator = std::vector<Point>::const_iterator;

private:
	static inline int W, H;

public:
	static void set_range(int height, int width) {
		H = height;
		W = width;
	}
	static int height() {
		return H;
	}
	static int width() {
		return W;
	}

	static constexpr Point zero() {
		return {0, 0};
	}
	static constexpr Point L() {
		return {0, -1};
	}
	static constexpr Point R() {
		return {0, 1};
	}
	static constexpr Point U() {
		return {-1, 0};
	}
	static constexpr Point D() {
		return {1, 0};
	}
	static constexpr Point LU() {
		return {-1, -1};
	}
	static constexpr Point LD() {
		return {1, -1};
	}
	static constexpr Point RU() {
		return {-1, 1};
	}
	static constexpr Point RD() {
		return {1, 1};
	}
	static const std::vector<Point> direction;

	int y, x;
	constexpr Point() : y(0), x(0) {}
	constexpr Point(int _y, int _x) : y(_y), x(_x) {}
	constexpr Point(const std::pair<int, int>& yx) : y(yx.first), x(yx.second) {}
	Point(int n) : y(n / W), x(n % W) {}
	constexpr Point operator+() const {
		return *this;
	}
	constexpr Point operator-() const {
		return {-y, -x};
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
		y += p.y;
		x += p.x;
		return *this;
	}
	constexpr Point& operator-=(const Point& p) {
		y -= p.y;
		x -= p.x;
		return *this;
	}
	constexpr Point& operator*=(const Point& p) {
		y *= p.y;
		x *= p.x;
		return *this;
	}
	constexpr Point& operator/=(const Point& p) {
		y /= p.y;
		x /= p.x;
		return *this;
	}
	constexpr Point& operator%=(const Point& p) {
		y %= p.y;
		x %= p.x;
		return *this;
	}
	constexpr Point& operator+=(int n) {
		y += n;
		x += n;
		return *this;
	}
	constexpr Point& operator-=(int n) {
		y -= n;
		x -= n;
		return *this;
	}
	constexpr Point& operator*=(int n) {
		y *= n;
		x *= n;
		return *this;
	}
	constexpr Point& operator/=(int n) {
		y /= n;
		x /= n;
		return *this;
	}
	constexpr Point& operator%=(int n) {
		y %= n;
		x %= n;
		return *this;
	}
	constexpr bool operator==(const Point& p) const {
		return y == p.y && x == p.x;
	}
	constexpr bool operator!=(const Point& p) const {
		return y != p.y || x != p.x;
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
	constexpr bool in_range(int height, int width) const {
		return 0 <= y && y < height && 0 <= x && x < width;
	}
	bool in_range() const {
		return in_range(H, W);
	}
	int to_i() const {
		return y * W + x;
	}
	constexpr Point yx() const {
		return {y, x};
	}
	constexpr std::pair<int, int> pair() const {
		return {y, x};
	}
	constexpr std::pair<int, int> anti_pair() const {
		return {x, y};
	}
	constexpr int manhattan(const Point& p) const {
		return std::abs(x - p.x) + std::abs(y - p.y);
	}
	constexpr int chebyshev(const Point& p) const {
		return std::max(std::abs(y - p.y), std::abs(x - p.x));
	}
	constexpr int distance_square(const Point& p) const {
		return (y - p.y) * (y - p.y) + (x - p.x) * (x - p.x);
	}
	template <class Real> constexpr Real distance(const Point& p) const {
		return std::sqrt(static_cast<Real>(distance_square(p)));
	}
	constexpr Point absolute(const Point& p) const {
		return absolute(*this - p);
	}
	constexpr Point absolute() const {
		return {std::abs(y), std::abs(x)};
	}

	class enumerate_adjacent_helper {
		std::shared_ptr<Point> p;
		direction_iterator first, last;

		class iterator {
			std::shared_ptr<Point> p;
			direction_iterator it;

		public:
			iterator(std::shared_ptr<Point> _p, direction_iterator _it) : p(_p), it(_it) {}
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
		enumerate_adjacent_helper(std::shared_ptr<Point> _p, direction_iterator _first,
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
		return enumerate_adjacent_helper(std::make_shared<Point>(*this), first, last);
	}
	auto adj4() const {
		return enumerate_adjacent(direction.begin() + 1, direction.begin() + 5);
	}
	auto adj4_and_this() const {
		return enumerate_adjacent(direction.begin(), direction.begin() + 5);
	}
	auto adjacent8() const {
		return enumerate_adjacent(direction.begin() + 1, direction.begin() + 9);
	}
	auto adj8_and_this() const {
		return enumerate_adjacent(direction.begin(), direction.begin() + 9);
	}

	class enumerate_adj_in_range_helper {
		std::shared_ptr<Point> p;
		direction_iterator first, last;

		class sentinel {};
		class iterator {
			std::shared_ptr<Point> p;
			direction_iterator first, last;

			void increment_until_in_range() {
				for (; first != last; ++first) {
					if ((*p + *first).in_range()) return;
				}
			}

		public:
			iterator(std::shared_ptr<Point> _p, direction_iterator _first,
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
		enumerate_adj_in_range_helper(std::shared_ptr<Point> _p, direction_iterator _first,
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
		return enumerate_adj_in_range_helper(std::make_shared<Point>(*this), first, last);
	}
	auto adj4_in_range() const {
		return enumerate_adj_in_range(direction.begin() + 1, direction.begin() + 5);
	}
	auto adj4_and_this_in_range() const {
		return enumerate_adj_in_range(direction.begin(), direction.begin() + 5);
	}
	auto adj8_in_range() const {
		return enumerate_adj_in_range(direction.begin() + 1, direction.begin() + 9);
	}
	auto ajd8_and_this_in_range() const {
		return enumerate_adj_in_range(direction.begin(), direction.begin() + 9);
	}

	constexpr Point left() const {
		return {y, x - 1};
	}
	constexpr Point right() const {
		return {y, x + 1};
	}
	constexpr Point up() const {
		return {y - 1, x};
	}
	constexpr Point down() const {
		return {y + 1, x};
	}
	Point succ() const {
		if (x != W - 1) {
			return {y, x + 1};
		} else {
			return {y + 1, 0};
		}
	}
	Point pred() const {
		if (x != 0) {
			return {y, x - 1};
		} else {
			return {y - 1, W - 1};
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
		return {-x, y};
	}
	constexpr Point rotate180() const {
		return {-y, -x};
	}
	constexpr Point rotate270() const {
		return {x, -y};
	}
	char to_direction_char(std::string_view lrud = "LRUD") const {
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

	static Point to_direction(char c, std::string_view lrud = "LRUD") {
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
	static Point to_direction(std::string s, std::string_view lrud = "LRUD") {
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
	static std::optional<Point> find(const T& grid, const value_type& val) {
		assert(static_cast<int>(grid.size()) == H);
		for (int i = 0; i < H; ++i) {
			assert(static_cast<int>(grid[i].size()) == W);
			for (int j = 0; j < W; ++j) {
				if (grid[i][j] == val) {
					return Point(i, j);
				}
			}
		}
		return std::nullopt;
	}
	template <class T, class Predicate>
	static std::optional<Point> find_if(const T& grid, Predicate pred) {
		assert(static_cast<int>(grid.size()) == H);
		for (int i = 0; i < H; ++i) {
			assert(static_cast<int>(grid[i].size()) == W);
			for (int j = 0; j < W; ++j) {
				if (pred(grid[i][j])) {
					return Point(i, j);
				}
			}
		}
		return std::nullopt;
	}
	template <class T, class value_type = typename T::value_type::value_type>
	static std::optional<Point> find_one(const T& grid, const value_type& val) {
		assert(static_cast<int>(grid.size()) == H);
		std::optional<Point> result;
		for (int i = 0; i < H; ++i) {
			assert(static_cast<int>(grid[i].size()) == W);
			for (int j = 0; j < W; ++j) {
				if (grid[i][j] == val) {
					assert(!result);
					result = Point(i, j);
				}
			}
		}
		return result;
	}
	template <class T, class value_type = typename T::value_type::value_type>
	static std::vector<Point> find_all(const T& grid, const value_type& val) {
		assert(static_cast<int>(grid.size()) == H);
		std::vector<Point> result;
		for (int i = 0; i < H; ++i) {
			assert(static_cast<int>(grid[i].size()) == W);
			for (int j = 0; j < W; ++j) {
				if (grid[i][j] == val) {
					result.emplace_back(i, j);
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
				return iterator(Point(H, 0));
			}
		};
		return enumerate_2D_points_helper();
	}

	template <class Scanner> void scan() {
		Scanner::scan(y);
		Scanner::scan(x);
	}
	template <class Printer> void print(const Printer& out) const {
		out.print('(');
		out.print(y);
		out.print(", ");
		out.print(x);
		out.print(')');
	}
	friend std::ostream& operator<<(std::ostream& os, const Point& p) {
		return os << '(' << p.y << ", " << p.x << ')';
	}
	friend std::istream& operator>>(std::istream& is, Point& p) {
		return is >> p.y >> p.x;
	}
};
const std::vector<Point> Point::direction{Point::zero(), Point::R(),  Point::D(),
                                          Point::U(),    Point::L(),  Point::RD(),
                                          Point::LU(),   Point::RU(), Point::LD()};
