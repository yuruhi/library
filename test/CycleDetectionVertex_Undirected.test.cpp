#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2891"
#include "./../Graph/CycleDetection.cpp"
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int>> edges(n);
	for (int i = 0; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		edges[i] = {u, v};
	}
	auto [detected, cycle] = CycleDetectionVertex(n, edges, false);
	assert(detected);
	vector<bool> flag(n);
	for (int i : cycle) {
		flag[i] = true;
	}
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if (flag[a] && flag[b]) {
			cout << 2 << '\n';
		} else {
			cout << 1 << '\n';
		}
	}
}