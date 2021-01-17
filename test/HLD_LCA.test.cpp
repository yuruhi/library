#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C"
#include "./../Graph/HeavyLightDecomposition.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	HLD hld(n);
	for (int v = 0; v < n; ++v) {
		int k;
		for (cin >> k; k--;) {
			int u;
			cin >> u;
			hld.add_edge(v, u);
		}
	}
	hld.build(0);

	int q;
	for (cin >> q; q--;) {
		int u, v;
		cin >> u >> v;
		cout << hld.lca(u, v) << '\n';
	}
}