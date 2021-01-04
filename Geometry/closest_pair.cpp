#pragma once
#include <vector>
#include "./Vec2.hpp"
#include "./Geometric.cpp"
using namespace std;

namespace Geometric {
	tuple<LD, Vec2, Vec2> closest_pair(vector<Vec2> points) {
		sort(points.begin(), points.end(), Vec2::compare_xy);

		auto dfs = [&](auto self, int left, int right) -> tuple<LD, Vec2, Vec2> {
			int n = right - left;
			if (n <= 1) {
				return {1e64, points[left], points[left]};
			} else {
				int mid = (left + right) / 2;
				LD x = points[mid].x;
				auto result = min(
				    self(self, left, mid), self(self, mid, right),
				    [](const auto& t1, const auto& t2) { return get<0>(t1) < get<0>(t2); });
				inplace_merge(points.begin() + left, points.begin() + mid,
				              points.begin() + right, Vec2::compare_y);

				vector<Vec2> around;
				for (int i = left; i < right; ++i) {
					if (get<0>(result) <= abs(points[i].x - x)) {
						continue;
					}
					for (int size = around.size(), j = size - 1; j >= 0; --j) {
						if (get<0>(result) <= points[i].y - around[j].y) {
							break;
						}
						if (LD length = (points[i] - around[j]).length();
						    get<0>(result) > length) {
							result = {length, points[i], around[j]};
						}
					}
					around.push_back(points[i]);
				}
				return result;
			}
		};

		return dfs(dfs, 0, points.size());
	}
}  // namespace Geometric
