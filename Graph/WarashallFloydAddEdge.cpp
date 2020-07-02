// shortcut : WarashallFloydAddEdge
// description : ワーシャルフロイド法 辺の追加 O(V^2)
void AddEdge(Matrix &dist, const Edge2 &e) {
	int V = dist.size();
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
			dist[i][j] = min(dist[i][j], min(dist[i][e.u] + dist[e.v][j], dist[i][e.v] + dist[e.u][j]) + e.cost);
}