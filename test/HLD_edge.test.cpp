#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_E"
#include "./../Graph/HeavyLightDecomposition.cpp"
#include "./../DataStructure/LazySegmentTree.cpp"
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	HLD hld(n);
	for (int v = 0; v < n; ++v) {
		int k;
		cin >> k;
		while (k--) {
			int u;
			cin >> u;
			hld.add_edge(v, u);
		}
	}
	hld.build(0);

	RangeAddRangeSum<ll, ll> seg(vector<S_sum<ll>>(n, 0));
	int q;
	cin >> q;
	while (q--) {
		int com;
		cin >> com;
		if (com == 0) {
			int v;
			ll w;
			cin >> v >> w;
			hld.each_edge(0, v, [&](int a, int b) { seg.apply(a, b + 1, w); });
		} else if (com == 1) {
			int u;
			cin >> u;
			ll ans = 0;
			hld.each_edge(0, u, [&](int a, int b) { ans += seg(a, b + 1).value; });
			cout << ans << '\n';
		}
	}
}