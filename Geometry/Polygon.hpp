#pragma once
#include "./Geometric.hpp"
#include "./Vec2.hpp"
#include "./Line.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>

namespace Geometric {

	struct Polygon : std::vector<Vec2> {
	public:
		Polygon() = default;
		Polygon(std::size_t n) : std::vector<Vec2>(n) {}
		Polygon(const std::vector<Vec2>& _p) : std::vector<Vec2>(_p) {}
		LD area() const {
			LD ans = 0;
			for (std::size_t i = 0; i < size(); ++i) {
				std::size_t next = i != size() - 1 ? i + 1 : 0;
				ans += at(i).cross(at(next));
			}
			return std::abs(ans) / 2;
		}
		// 凸性判定（反時計回り）
		bool is_convex() const {
			if (size() < 3) {
				return false;
			}
			for (std::size_t i = 0; i < size(); ++i) {
				std::size_t prev = i != 0 ? i - 1 : size() - 1;
				std::size_t next = i != size() - 1 ? i + 1 : 0;
				if (iSP(at(prev), at(i), at(next)) == -1) {
					return false;
				}
			}
			return true;
		}
		// 凸包（反時計回り）
		Polygon convex_hull() const {
			std::vector<Vec2> ps = *this;
			std::sort(ps.begin(), ps.end(), Vec2::compare_xy);
			int n = ps.size(), k = 0;
			Polygon result(2 * n);
			for (int i = 0; i < n; result[k++] = ps[i++]) {
				while (k >= 2 && iSP(result[k - 2], result[k - 1], ps[i]) <= 0) {
					--k;
				}
			}
			for (int i = n - 2, t = k + 1; i >= 0; result[k++] = ps[i--]) {
				while (k >= t && iSP(result[k - 2], result[k - 1], ps[i]) <= 0) {
					--k;
				}
			}
			result.resize(k - 1);
			return result;
		}
		// 凸包（一直線上の3点を含めない、反時計回り）
		Polygon convex_hull_no_collinear() const {
			std::vector<Vec2> ps = *this;
			std::sort(ps.begin(), ps.end(), Vec2::compare_xy);
			int n = ps.size(), k = 0;
			Polygon result(2 * n);
			for (int i = 0; i < n; result[k++] = ps[i++]) {
				while (k >= 2 && iSP(result[k - 2], result[k - 1], ps[i]) != -1) {
					--k;
				}
			}
			for (int i = n - 2, t = k + 1; i >= 0; result[k++] = ps[i--]) {
				while (k >= t && iSP(result[k - 2], result[k - 1], ps[i]) != -1) {
					--k;
				}
			}
			result.resize(k - 1);
			return result;
		}
		// 直径
		std::tuple<LD, std::size_t, std::size_t> diameter() const {
			std::size_t i_start = 0, j_start = 0;
			for (std::size_t i = 1; i < size(); ++i) {
				if (at(i).y > at(i_start).y) i_start = i;
				if (at(i).y < at(j_start).y) j_start = i;
			}
			LD max_dist = (at(i_start) - at(j_start)).length();

			auto diff = [&](int i) {
				return at((i + 1) % size()) - at(i);
			};

			std::size_t i = i_start, i_max = i_start;
			std::size_t j = j_start, j_max = j_start;
			do {
				if (diff(i).cross(diff(j)) >= 0) {
					j = (j + 1) % size();
				} else {
					i = (i + 1) % size();
				}
				if (LD d = (at(i) - at(j)).length(); max_dist < d) {
					max_dist = d;
					i_max = i;
					j_max = j;
				}
			} while (i != i_start || j != j_start);
			return {max_dist, i_max, j_max};
		}
		// 切断
		Polygon cut(const Line& l) const {
			Polygon result;
			for (std::size_t i = 0; i < size(); ++i) {
				Vec2 a = at(i), b = at(i != size() - 1 ? i + 1 : 0);
				if (iSP(l.begin, l.end, a) != -1) {
					result.push_back(a);
				}
				if (iSP(l.begin, l.end, a) * iSP(l.begin, l.end, b) < 0) {
					result.push_back(*cross_point(Line(a, b), l));
				}
			}
			return result;
		}
		friend std::ostream& operator<<(std::ostream& os, const Polygon& p) {
			os << "{";
			for (std::size_t i = 0; i < p.size(); ++i) {
				if (i != 0) os << ", ";
				os << p[i];
			}
			return os << "}";
		}
		friend std::istream& operator>>(std::istream& is, Polygon& p) {
			for (auto& v : p) {
				is >> v;
			}
			return is;
		}
	};

}  // namespace Geometric
