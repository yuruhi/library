#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D"
#include "./../DataStructure/RangeUpdateQuery.cpp"
#include <iostream>
#include <limits>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	RangeUpdateQuery<int> seg(n, numeric_limits<int>::max());
	while (q--) {
		int com;
		cin >> com;
		if (com == 0) {
			int l, r, x;
			cin >> l >> r >> x;
			seg.update(l, r + 1, x);
		} else {
			int i;
			cin >> i;
			cout << seg[i] << '\n';
		}
	}
}