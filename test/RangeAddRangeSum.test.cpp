#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G"
#include "./../DataStructure/LazySegmentTree.cpp"
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	RangeAddRangeSum<ll, ll> seg(vector<S_sum<ll>>(n, 0));
	while (q--) {
		int com, l, r;
		cin >> com >> l >> r;
		l--;
		if (com == 0) {
			ll x;
			cin >> x;
			seg.apply(l, r, x);
		} else if (com == 1) {
			cout << seg.prod(l, r).value << '\n';
		}
	}
}