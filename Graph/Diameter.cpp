#pragma once
#include "./GraphTemplate.cpp"
#include <utility>
#include <tuple>
using namespace std;

tuple<Weight, int, int> Diameter(const Graph& g) {
	auto dfs = [&](auto&& f, int v, int p, Weight depth) -> pair<Weight, int> {
		pair<Weight, int> res(depth, v);
		for (auto e : g[v])
			if (e.to != p) {
				auto res2 = f(f, e.to, v, depth + e.cost);
				if (res2.first > res.first) res = res2;
			}
		return res;
	};
	auto d1 = dfs(dfs, 0, -1, 0);
	auto d2 = dfs(dfs, d1.second, -1, 0);
	return {d2.first, d1.second, d2.second};
}