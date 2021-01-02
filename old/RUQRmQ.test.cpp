#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F"
#include "./../old/RUQRminQ.cpp"
#include <iostream>
#include <limits>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	RUQRmQ<int> seg(vector(n, numeric_limits<int>::max()), numeric_limits<int>::max());
	while (q--) {
		int com;
		cin >> com;
		if (com == 0) {
			int l, r, x;
			cin >> l >> r >> x;
			seg.update(l, r + 1, x);
		} else {
			int l, r;
			cin >> l >> r;
			cout << seg(l, r + 1) << '\n';
		}
	}
}