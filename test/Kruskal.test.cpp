#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A"
#include "./../Graph/Kruskal.cpp"
#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	Edges edges(m);
	for (int i = 0; i < m; ++i) {
		int s, t;
		Weight d;
		cin >> s >> t >> d;
		edges[i] = Edge2(s, t, d);
	}

	cout << Kruskal(n, edges) << '\n';
}