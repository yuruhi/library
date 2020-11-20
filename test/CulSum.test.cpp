#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "./../Utility/CulSum.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	vector<long long> a(n);
	for (auto& i : a) cin >> i;

	CulSum<long long> sum(a);
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << sum(l, r) << '\n';
	}
}