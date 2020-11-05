#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B"
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
	sort(bridges.begin(), bridges.end());
	for (auto [u, v] : bridges) {
		cout << u << ' ' << v << '\n';
	}
}