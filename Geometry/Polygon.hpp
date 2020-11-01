#pragma once
#include "./Geometric.hpp"
#include "./Vec2.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
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
				ans += abs((*this)[i].x * (*this)[i].y - (*this)[next].x * (*this)[i].y);
			}
			return ans / 2;
		}
		// 反時計回り
		bool is_convex() const {
			if (size() < 3) {
				return false;
			}
			for (size_t i = 0; i < size(); ++i) {
				size_t prev = i != 0 ? i - 1 : size() - 1;
				size_t next = i != size() - 1 ? i + 1 : 0;
				if (iSP((*this)[prev], (*this)[i], (*this)[next]) == -1) {
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