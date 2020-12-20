#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <iostream>
#include "./../DataStructure/BinaryIndexedTree.cpp"
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	BinaryIndexedTree<ll> bit(n);
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		bit.add(i, x);
	}

	while (q--) {
		int com;
		cin >> com;
		if (com == 0) {
			int p;
			ll x;
			cin >> p >> x;
			bit.add(p, x);
		} else {
			int l, r;
			cin >> l >> r;
			cout << bit(l, r) << endl;
		}
	}
}