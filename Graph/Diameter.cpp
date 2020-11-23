#pragma once
#include "./GraphTemplate.cpp"
#include <utility>
#include <tuple>
using namespace std;

tuple<Weight, int, int> Diameter(const Graph& graph) {
	auto dfs = [&](auto&& f, int v, int p, Weight depth) -> pair<Weight, int> {
		pair<Weight, int> result(depth, v);
		for (auto e : graph[v]) {
			if (e.to != p) {
				auto tmp = f(f, e.to, v, depth + e.cost);
				if (tmp.first > result.first) result = tmp;
			}
		}
		return result;
	};
	auto d1 = dfs(dfs, 0, -1, 0);
	auto d2 = dfs(dfs, d1.second, -1, 0);
	return {d2.first, d1.second, d2.second};
}
