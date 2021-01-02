#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_B"
#include "./../Graph/DirectedMinimumSpanningTree.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, m, r;
	cin >> n >> m >> r;
	DirectedMinimumSpanningTree dmst(n);
	for (int i = 0; i < m; ++i) {
		int s, t;
		Weight cost;
		cin >> s >> t >> cost;
		dmst.add_edge(s, t, cost);
	}
	cout << dmst.solve(r) << '\n';
}