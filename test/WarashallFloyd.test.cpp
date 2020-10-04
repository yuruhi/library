#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C"
#include "./../Graph/WarashallFloyd.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	Matrix g(n, vector(n, INF));
	for (int i = 0; i < n; ++i) {
		g[i][i] = 0;
	}
	for (int i = 0; i < m; ++i) {
		int s, t;
		Weight d;
		cin >> s >> t >> d;
		g[s][t] = d;
	}

	bool flag = WarashallFloyd(g);
	if (!flag) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (g[i][j] < INF) {
					cout << g[i][j];
				} else {
					cout << "INF";
				}
				cout << (j < n - 1 ? ' ' : '\n');
			}
		}
	} else {
		cout << "NEGATIVE CYCLE\n";
	}
}