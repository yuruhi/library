#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include "./../Graph/BipartiteMatching.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int l, r, m;
	cin >> l >> r >> m;

	BipartiteMatching graph(l, r);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		graph.add_edge(a, b);
	}

	cout << graph.solve() << '\n';
	for (auto [a, b] : graph.edges()) {
		cout << a << ' ' << b << '\n';
	}
}