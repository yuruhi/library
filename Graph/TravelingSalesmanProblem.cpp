#pragma once
#include "./GraphTemplate.cpp"
#include <algorithm>

Weight TravelingSelesman(const Matrix& graph, const Weight INF = 1000000000000000000ll) {
	int n = graph.size();
	std::vector dp(1 << n, std::vector(n, INF));
	dp.back()[0] = 0;
	for (int s = (1 << n) - 2; s >= 0; --s) {
		for (int v = 0; v < n; ++v) {
			for (int u = 0; u < n; ++u) {
				if (!(s & (1 << u))) {
					dp[s][v] = std::min(dp[s][v], dp[s | (1 << u)][u] + graph[v][u]);
				}
			}
		}
	}
	return dp[0][0];
}
