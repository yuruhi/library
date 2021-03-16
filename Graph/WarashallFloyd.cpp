#pragma once
#include "./GraphTemplate.cpp"
#include <algorithm>
#include <limits>

bool WarashallFloyd(Matrix& dist, Weight INF = std::numeric_limits<Weight>::max()) {
	std::size_t n = dist.size();
	for (std::size_t i = 0; i < n; ++i) {
		for (std::size_t j = 0; j < n; ++j) {
			for (std::size_t k = 0; k < n; ++k) {
				if (dist[j][i] == INF || dist[i][k] == INF) continue;
				dist[j][k] = std::min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}
	for (std::size_t i = 0; i < n; ++i) {
		if (dist[i][i] < 0) return true;
	}
	return false;
}

void WarashallFloydAddEdge(Matrix& dist, const Edge2& e) {
	std::size_t n = dist.size();
	for (std::size_t i = 0; i < n; ++i) {
		for (std::size_t j = 0; j < n; ++j) {
			dist[i][j] = std::min(
			    dist[i][j],
			    std::min(dist[i][e.from] + dist[e.to][j], dist[i][e.to] + dist[e.from][j]) +
			        e.cost);
		}
	}
}
