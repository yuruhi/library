#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A"
#include "./../Graph/LowLink.cpp"
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	LowLink g(n);
	while (m--) {
		int u, v;
		cin >> u >> v;
		g.add_edge(u, v);
	}

	auto [aps, bridges] = g.build();
	sort(aps.begin(), aps.end());
	for (int v : aps) {
		cout << v << '\n';
	}
}