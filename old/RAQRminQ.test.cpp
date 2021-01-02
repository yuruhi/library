#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_H"
#include "./../old/RAQRminQ.cpp"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	RAQRmQ<int> seg(vector<int>(n), numeric_limits<int>::max());
	while (q--) {
		int com;
		cin >> com;
		if (com == 0) {
			int l, r, x;
			cin >> l >> r >> x;
			seg.add(l, r + 1, x);
		} else {
			int l, r;
			cin >> l >> r;
			cout << seg(l, r + 1) << '\n';
		}
	}
}