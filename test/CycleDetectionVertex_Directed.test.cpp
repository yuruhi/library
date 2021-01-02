#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"
#include "./../Graph/CycleDetection.cpp"
#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edges(m);
	map<pair<int, int>, int> index;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		edges[i] = {u, v};
		index[{u, v}] = i;
	}
	auto cycle = CycleDetectionVertex(n, edges);
	if (cycle) {
		cout << cycle->size() << '\n';
		for (size_t i = 0; i < cycle->size(); ++i) {
			cout << index[{cycle.value()[i], cycle.value()[(i + 1) % cycle->size()]}] << '\n';
		}
	} else {
		cout << -1 << '\n';
	}
}