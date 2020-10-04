#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A"
#include "./../Graph/FordFulkerson.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	FordFulkerson g(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		FLOW d;
		cin >> u >> v >> d;
		g.add_edge(u, v, d);
	}
	cout << g.solve(0, n - 1) << '\n';
}