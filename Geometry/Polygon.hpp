#pragma once
#include "./Geometric.hpp"
#include "./Vec2.hpp"
#include <iostream>
#include <vector>
using namespace std;

namespace Geometric {

	struct Polygon {
	private:
		vector<Vec2> p;

	public:
		Polygon(const vector<Vec2>& _p) : p(_p) {}
		size_t size() const {
			return p.size();
		}
		LD area() const {
			LD ans = 0;
			for (size_t i = 0; i < size(); ++i) {
				size_t next = i < size() - 1 ? i : 0;
				ans += abs(p[i].x * p[next].y - p[next].x * p[i].y);
			}
			return ans / 2;
		}
	};

}  // namespace Geometric