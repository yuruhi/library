#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G"
#include "./../old/RAQRSQ.cpp"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	RAQRSQ<long long> seg(vector<long long>(n), 0);
	while (q--) {
		int com;
		cin >> com;
		if (com == 0) {
			int l, r;
			long long x;
			cin >> l >> r >> x;
			seg.add(l - 1, r, x);
		} else {
			int l, r;
			cin >> l >> r;
			cout << seg(l - 1, r) << '\n';
		}
	}
}