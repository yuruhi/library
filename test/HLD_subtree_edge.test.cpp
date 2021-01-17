#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/Rupc/2667?year=2015"
#include "./../Graph/HeavyLightDecomposition.cpp"
#include "./../DataStructure/LazySegmentTree.cpp"
#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	HLD g(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		g.add_edge(a, b);
	}
	g.build(0);

	RangeAddRangeSum<ll, ll> seg(vector<S_sum<ll>>(n, 0));
	while (q--) {
		int com;
		cin >> com;
		if (com == 0) {
			int u, v;
			cin >> u >> v;
			ll ans = 0;
			g.each_edge(u, v, [&](int l, int r) { ans += seg.prod(l, r).value; });
			cout << ans << '\n';
		} else {
			int v;
			ll x;
			cin >> v >> x;
			g.each_subtree_edge(v, [&](int l, int r) { seg.apply(l, r, x); });
		}
	}
}