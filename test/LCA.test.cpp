#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "./../Graph/LCA.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	Graph g(n);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		g[i].emplace_back(p, 1);
		g[p].emplace_back(i, 1);
	}

	LCA lca(g, 0);
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}
}