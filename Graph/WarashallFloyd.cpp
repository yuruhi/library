#pragma once
#include "./GraphTemplate.cpp"
#include <algorithm>

bool WarashallFloyd(Matrix& dist, Weight INF_ = INF) {
	int V = dist.size();
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
			for (int k = 0; k < V; ++k) {
				if (dist[j][i] == INF_ || dist[i][k] == INF_) continue;
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
	for (int i = 0; i < V; ++i)
		if (dist[i][i] < 0) return true;
	return false;
}