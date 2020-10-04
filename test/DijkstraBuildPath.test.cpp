#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "./../Graph/DijkstraBuildPath.cpp"
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, s, t;
	cin >> n >> m >> s >> t;

	Graph g(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		Weight c;
		cin >> a >> b >> c;
		g[a].emplace_back(b, c);
	}

	auto [dist, prev] = DijkstraBuildPrev(g, s);
	auto path = BuildPath(prev, t);

	if (dist[t] < INF) {
		cout << dist[t] << ' ' << path.size() - 1 << endl;
		for (size_t i = 0; i < path.size() - 1; i++) {
			cout << path[i] << ' ' << path[i + 1] << endl;
		}
	} else {
		cout << -1 << endl;
	}
}