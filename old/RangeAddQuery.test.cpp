#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_E"
#include "./../old/RangeAddQuery.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	RangeAddQuery<int> seg(n);
	while (q--) {
		int com;
		cin >> com;
		if (com == 0) {
			int l, r, x;
			cin >> l >> r >> x;
			seg.add(l - 1, r, x);
		} else {
			int i;
			cin >> i;
			cout << seg[i - 1] << '\n';
		}
	}
}