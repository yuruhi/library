#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"
#include "./../DataStructure/PersistentUnionFind.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	vector<PersistentUnionFind> g(q + 1);
	g[0] = PersistentUnionFind(n);
	for (int i = 1; i <= q; ++i) {
		int com, k, u, v;
		cin >> com >> k >> u >> v;
		k++;
		if (com == 0) {
			g[i] = g[k].unite(u, v).second;
		} else {
			cout << g[k].same(u, v) << '\n';
		}
	}
}