#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_2_B"
#include "./../Graph/ChinesePostman.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; ++i) {
		int s, t;
		Weight d;
		cin >> s >> t >> d;
		g[s].emplace_back(t, d);
		g[t].emplace_back(s, d);
	}
	cout << ChinesePostman(g) << '\n';
}