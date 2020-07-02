// shortcut : BellmanFord
// description : ベルマンフォード法 O(VE)
bool BellmanFord(const Graph &graph, vector<Weight> &dist, int s) {
	int V = graph.size();
	dist.assign(V, INF);
	dist[s] = 0;
	for (int i = 0; i < V; ++i)
		for (int v = 0; v < V; ++v)
			for (auto e : graph[v]) {
				if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
					dist[e.to] = dist[v] + e.cost;
					if (i == V - 1) return true;
				}
			}
	return false;
}