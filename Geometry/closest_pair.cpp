#pragma once
#include "./Vec2.hpp"
#include "./Geometric.cpp"
#include <vector>
#include <tuple>
#include <algorithm>

namespace Geometric {
	std::tuple<LD, Vec2, Vec2> closest_pair(std::vector<Vec2> points) {
		std::sort(points.begin(), points.end(), Vec2::compare_xy);

		auto dfs = [&](auto self, int left, int right) -> std::tuple<LD, Vec2, Vec2> {
			int n = right - left;
			if (n <= 1) {
				return {1e64, points[left], points[left]};
			} else {
				int mid = (left + right) / 2;
				LD x = points[mid].x;
				auto result = std::min(self(self, left, mid), self(self, mid, right),
				                  [](const auto& t1, const auto& t2) {
					                  return std::get<0>(t1) < std::get<0>(t2);
				                  });
				std::inplace_merge(points.begin() + left, points.begin() + mid,
				              points.begin() + right, Vec2::compare_y);

				std::vector<Vec2> around;
				for (int i = left; i < right; ++i) {
					if (std::get<0>(result) <= std::abs(points[i].x - x)) {
						continue;
					}
					for (int size = around.size(), j = size - 1; j >= 0; --j) {
						if (std::get<0>(result) <= points[i].y - around[j].y) {
							break;
						}
						if (LD length = (points[i] - around[j]).length();
						    std::get<0>(result) > length) {
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
