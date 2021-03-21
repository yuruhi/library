#pragma once
#include "./Dijkstra.cpp"
#include <vector>
#include <algorithm>

Weight ChinesePostman(const Graph& graph) {
	std::size_t n = graph.size();
	Weight sum = 0;
	std::vector<int> odds;
	for (std::size_t v = 0; v < n; ++v) {
		for (const auto& e : graph[v]) sum += e.cost;
		if (graph[v].size() % 2 == 1) odds.push_back(v);
	}
	sum /= 2;

	std::size_t m = odds.size(), M = 1 << m;
	Matrix dist(m, std::vector<Weight>(m));
	for (std::size_t i = 0; i < m; ++i) {
		auto dist_v = Dijkstra(graph, odds[i]);
		for (std::size_t j = 0; j < m; ++j) {
			dist[i][j] = dist_v[odds[j]];
		}
	}

	std::vector<Weight> dp(M, INF);
	dp[0] = 0;
	for (std::size_t s = 0; s < M; ++s) {
		for (std::size_t i = 0; i < m; ++i) {
			if (!(s & (1 << i))) {
				for (std::size_t j = i + 1; j < m; ++j) {
					if (!(s & (1 << j))) {
						std::size_t t = s | (1 << i) | (1 << j);
						dp[t] = std::min(dp[t], dp[s] + dist[i][j]);
					}
				}
			}
		}
	}
	return sum + dp[M - 1];
}
