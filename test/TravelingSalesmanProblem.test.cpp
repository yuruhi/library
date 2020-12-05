#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_2_A"
#include "./../Graph/TravelingSalesmanProblem.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	constexpr Weight inf = 1e18;
	int n, m;
	cin >> n >> m;
	Matrix g(n, vector(n, inf));
	for (int i = 0; i < n; ++i) {
		g[i][i] = 0;
	}
	for (int i = 0; i < m; ++i) {
		int s, t;
		Weight d;
		cin >> s >> t >> d;
		g[s][t] = d;
	}

	Weight ans = TravelingSelesman(g, inf);
	cout << (ans < inf ? ans : -1) << '\n';
}