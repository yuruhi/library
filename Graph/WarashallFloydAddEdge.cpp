#pragma once
#include <algorithm>
using namespace std;

void WarashallFloydAddEdge(Matrix& dist, const Edge2& e) {
	int V = dist.size();
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
			dist[i][j] = min(dist[i][j], min(dist[i][e.u] + dist[e.v][j], dist[i][e.v] + dist[e.u][j]) + e.cost);
}