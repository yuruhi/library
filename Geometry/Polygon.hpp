#pragma once
#include "./Geometric.hpp"
#include "./Vec2.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
using namespace std;

namespace Geometric {

	struct Polygon : vector<Vec2> {
	public:
		Polygon(int n) : vector<Vec2>(n) {}
		Polygon(const vector<Vec2>& _p) : vector<Vec2>(_p) {}
		LD area() const {
			LD ans = 0;
			for (size_t i = 0; i < size(); ++i) {
				size_t next = i < size() - 1 ? i : 0;
				ans += abs(at(i).x * at(i).y - at(next).x * at(i).y);
			}
			return ans / 2;
		}
		// 凸性判定（反時計回り）
		bool is_convex() const {
			if (size() < 3) {
				return false;
			}
			for (size_t i = 0; i < size(); ++i) {
				size_t prev = i != 0 ? i - 1 : size() - 1;
				size_t next = i != size() - 1 ? i + 1 : 0;
				if (iSP(at(prev), at(i), at(next)) == -1) {
					return false;
				}
			}
			return true;
		}
		// 凸包（反時計回り）
		Polygon convex_hull() const {
			vector<Vec2> ps = *this;
			sort(ps.begin(), ps.end(), [](const Vec2& v1, const Vec2& v2) {
				return make_pair(v1.x, v1.y) < make_pair(v2.x, v2.y);
			});
			int n = ps.size(), k = 0;
			Polygon res(2 * n);
			for (int i = 0; i < n; res[k++] = ps[i++]) {
				while (k >= 2 && iSP(res[k - 2], res[k - 1], ps[i]) <= 0) {
					--k;
				}
			}
			for (int i = n - 2, t = k + 1; i >= 0; res[k++] = ps[i--]) {
				while (k >= t && iSP(res[k - 2], res[k - 1], ps[i]) <= 0) {
					--k;
				}
			}
			res.resize(k - 1);
			return res;
		}
		// 凸包（一直線上の3点を含めない、反時計回り）
		Polygon convex_hull_no_collinear() const {
			vector<Vec2> ps = *this;
			sort(ps.begin(), ps.end(), [](const Vec2& v1, const Vec2& v2) {
				return make_pair(v1.x, v1.y) < make_pair(v2.x, v2.y);
			});
			int n = ps.size(), k = 0;
			Polygon res(2 * n);
			for (int i = 0; i < n; res[k++] = ps[i++]) {
				while (k >= 2 && iSP(res[k - 2], res[k - 1], ps[i]) != -1) {
					--k;
				}
			}
			for (int i = n - 2, t = k + 1; i >= 0; res[k++] = ps[i--]) {
				while (k >= t && iSP(res[k - 2], res[k - 1], ps[i]) != -1) {
					--k;
				}
			}
			res.resize(k - 1);
			return res;
		}
		// 直径
		tuple<LD, size_t, size_t> diameter() const {
			size_t i_start = 0, j_start = 0;
			for (size_t i = 1; i < size(); ++i) {
				if (at(i).y > at(i_start).y) i_start = i;
				if (at(i).y < at(j_start).y) j_start = i;
			}
			LD max_dist = (at(i_start) - at(j_start)).length();

			auto diff = [&](int i) {
				return at((i + 1) % size()) - at(i);
			};

			size_t i = i_start, i_max = i_start;
			size_t j = j_start, j_max = j_start;
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
		// 最近点対
		tuple<LD, Vec2, Vec2> closest_pair() const {
			vector<Vec2> points = *this;
			sort(points.begin(), points.end(), Vec2::compare_xy);

			auto dfs = [&](auto self, int left, int right) -> tuple<LD, Vec2, Vec2> {
				int n = right - left;
				if (n <= 1) {
					return {1e64, points[left], points[left]};
				} else {
					int mid = (left + right) / 2;
					LD x = points[mid].x;
					auto res = min(self(self, left, mid), self(self, mid, right));
					inplace_merge(points.begin() + left, points.begin() + mid, points.begin() + right, Vec2::compare_y);

					vector<Vec2> around;
					for (int i = left; i < right; ++i) {
						if (get<0>(res) <= abs(points[i].x - x)) {
							continue;
						}
						for (int size = around.size(), j = size - 1; j >= 0; --j) {
							if (get<0>(res) <= points[i].y - around[j].y) {
								break;
							}
							if (LD length = (points[i] - around[j]).length(); get<0>(res) > length) {
								res = {length, points[i], around[j]};
							}
						}
						around.push_back(points[i]);
					}
					return res;
				}
			};

			return dfs(dfs, 0, size());
		}
		template <class Shape2DType> bool intersects(const Shape2DType& shape) const {
			return Geometric::intersect(*this, shape);
		}
		template <class Shape2DType> bool tangent(const Shape2DType& shape) const {
			return Geometric::tangent(*this, shape);
		}
		friend ostream& operator<<(ostream& os, const Polygon& p) {
			os << "{ ";
			for (size_t i = 0; i < p.size(); ++i) {
				if (i != 0) os << ", ";
				os << p[i];
			}
			return os << " }";
		}
		friend istream& operator>>(istream& is, Polygon& p) {
			for (auto& v : p) {
				is >> v;
			}
			return is;
		}
	};

}  // namespace Geometric