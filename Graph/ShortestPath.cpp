// description : 重さなしグラフの最短経路 O(V + E)
vector<int> ShortestPath(const vector<vector<int>>& G, const int s) {
	int V = G.size();
	vector<int> dist(V, INT_MAX);
	dist[s] = 0;
	queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int f = que.front();
		que.pop();
		for (auto e : G[f]) {
			if (dist[e] == INT_MAX) {
				que.push(e);
				dist[e] = dist[f] + 1;
			}
		}
	}
	return dist;
}