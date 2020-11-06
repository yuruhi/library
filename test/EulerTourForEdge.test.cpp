#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_D"
#include "library/Graph/EulerTourForEdge.cpp"
#include "library/DataStructure/BinaryIndexedTree.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for (vector<int>& v : g) {
		int k;
		cin >> k;
		v.resize(k);
		for (int& j : v) {
			cin >> j;
		}
	}

	EulerTourForEdge euler(g);
	euler.build();

	BinaryIndexedTree<long long> bit(euler.size());
	int q;
	cin >> q;
	while (q--) {
		int com;
		cin >> com;
		if (com == 0) {
			int v;
			long long w;
			cin >> v >> w;
			bit.add(euler.l(v), +w);
			bit.add(euler.r(v), -w);
		} else if (com == 1) {
			int v;
			cin >> v;
			cout << bit(euler.l(v)) << endl;
		}
	}
}
