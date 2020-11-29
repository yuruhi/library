#pragma once
#include "./Dijkstra.cpp"
#include <vector>
using namespace std;

Weight ChinesePostman(const Graph& graph) {
	size_t n = graph.size();
	Weight sum = 0;
	vector<int> odds;
	for (size_t v = 0; v < n; ++v) {
		for (const auto& e : graph[v]) sum += e.cost;
		if (graph[v].size() % 2 == 1) odds.push_back(v);
	}
	sum /= 2;

	size_t m = odds.size(), M = 1 << m;
	Matrix dist(m, vector<Weight>(m));
	for (size_t i = 0; i < m; ++i) {
		auto dist_v = Dijkstra(graph, odds[i]);
		for (size_t j = 0; j < m; ++j) {
			dist[i][j] = dist_v[odds[j]];
		}
	}

	vector<Weight> dp(M, INF);
	dp[0] = 0;
	for (size_t s = 0; s < M; ++s) {
		for (size_t i = 0; i < m; ++i) {
			if (!(s & (1 << i))) {
				for (size_t j = i + 1; j < m; ++j) {
					if (!(s & (1 << j))) {
						size_t t = s | (1 << i) | (1 << j);
						dp[t] = min(dp[t], dp[s] + dist[i][j]);
					}
				}
			}
		}
	}
	return sum + dp[M - 1];
}
