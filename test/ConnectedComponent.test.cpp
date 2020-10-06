#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_11_D"
#include "./../Graph/ConnectedComponent.cpp"
#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	auto [k, id, ind] = ConnectedComponent(g);
	int q;
	cin >> q;
	while (q--) {
		int s, t;
		cin >> s >> t;
		cout << (id[s] == id[t] ? "yes" : "no") << '\n';
	}
}