#define PROBLEM "https://yukicoder.me/problems/no/399"
#include "./../Graph/HeavyLightDecomposition.cpp"
#include "./../DataStructure/RAQRSQ.cpp"
#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	HLD hld(n);
	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		v--;
		u--;
		hld.add_edge(v, u);
	}
	hld.build(0);

	ll ans = 0;
	RAQRSQ<ll> seg(vector(n, 1ll), 0);
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		hld.each_vertex(a, b, [&](int p, int q) {
			ans += seg(p, q + 1);
			seg.add(p, q + 1, 1);
		});
	}
	cout << ans << '\n';
}