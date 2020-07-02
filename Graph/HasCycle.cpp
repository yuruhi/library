// shortcut : HasCycle
// description : 閉路検出
bool HasCycle(const Graph &graph) {
	int V = graph.size();
	vector<int> h(V);
	for (auto g : graph) {
		for (auto e : g) h[e.to]++;
	}
	stack<int> st;
	int cnt = 0;
	for (int i = 0; i < V; i++)
		if (!h[i]) {
			st.push(i);
			cnt++;
		}
	vector<int> ret;
	while (!st.empty()) {
		int i = st.top();
		st.pop();
		ret.push_back(i);
		for (auto &e : graph[i]) {
			h[e.to]--;
			if (!h[e.to]) {
				st.push(e.to);
				cnt++;
			}
		}
	}
	return cnt != V;
}