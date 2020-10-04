#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B"
#include "./../DataStructure/WeightedUnionFind.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	WeightedUnionFind<int> uf(n);
	while (q--) {
		int com;
		cin >> com;
		if (com == 0) {
			int x, y, z;
			cin >> x >> y >> z;
			uf.merge(x, y, z);
		} else {
			int x, y;
			cin >> x >> y;
			if (uf.same(x, y)) {
				cout << uf.diff(x, y) << '\n';
			} else {
				cout << "?\n";
			}
		}
	}
}