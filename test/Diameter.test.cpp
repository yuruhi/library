#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "./../Graph/Diameter.cpp"
#include "./../Graph/DiameterPath.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	Graph g(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		Weight c;
		cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}

	auto [dist, u, v] = Diameter(g);
	auto [_dist, path] = DiameterPath(g);
	cout << dist << ' ' << path.size() << '\n';
	for (size_t i = 0; i < path.size(); i++) {
		cout << path[i] << (i != path.size() - 1 ? ' ' : '\n');
	}
}