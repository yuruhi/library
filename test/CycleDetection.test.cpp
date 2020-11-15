#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"
#include "./../Graph/CycleDetection.cpp"
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edges(m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		edges[i] = {u, v};
	}
	auto [detected, cycle] = CycleDetectionEdge(n, edges);
	if (detected) {
		cout << cycle.size() << '\n';
		for (int e : cycle) {
			cout << e << '\n';
		}
	} else {
		cout << -1 << '\n';
	}
}