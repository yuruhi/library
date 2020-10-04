#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B"
#include "./../Graph/BellmanFord.cpp"
#include <iostream>
using namespace std;

int main() {
	int n, m, s;
	cin >> n >> m >> s;
	Graph g(n);
	for (int i = 0; i < m; ++i) {
		int s, t;
		Weight d;
		cin >> s >> t >> d;
		g[s].emplace_back(t, d);
	}

	auto [flag, dist] = BellmanFord(g, s);
	if (!flag) {
		for (int i = 0; i < n; ++i) {
			if (dist[i] < INF) {
				cout << dist[i] << '\n';
			} else {
				cout << "INF\n";
			}
		}
	} else {
		cout << "NEGATIVE CYCLE\n";
	}
}