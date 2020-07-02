// shortcut : isConnected
// description : 連結判定
bool isConnected(const Graph &graph, int s, int t) {
	int V = graph.size();
	queue<int> que;
	que.push(s);
	vector<bool> vis(V);
	vis[s] = true;
	while (!que.empty()) {
		int fro = que.front();
		que.pop();
		if (fro == t) return true;
		for (auto e : graph[fro])
			if (!vis[e.to]) {
				que.push(e.to);
				vis[e.to] = true;
			}
	}
	return false;
}