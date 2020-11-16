#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "./../Graph/StronglyConnectedComponents.cpp"
#include "./../Graph/TopologicalSort.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	StronglyConnectedComponents scc(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		scc.add_edge(a, b);
	}
	scc.build();
	cout << scc.count_strongly_components() << '\n';
	auto ans = scc.groups();
	for (int i : TopologicalSort(scc.make_DAG())) {
		cout << ans[i].size();
		for (size_t j = 0; j < ans[i].size(); ++j) {
			cout << ' ' << ans[i][j];
		}
		cout << '\n';
	}
}