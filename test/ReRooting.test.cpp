#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/WUPC/3163"
#include "./../Graph/ReRooting.cpp"
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> a;

struct DP {
	ll sum, val;
	DP() : sum(0), val(0) {}
	DP operator+(const DP& d) const {
		return DP(*this) += d;
	}
	DP& operator+=(const DP& d) {
		sum += d.sum;
		val += d.val;
		return *this;
	}
	DP add_root([[maybe_unused]] int v) const {
		DP res = *this;
		res.val += sum;
		res.sum += a[v];
		return res;
	}
};

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	a.assign(n, 0);
	for (ll& i : a) cin >> i;

	ReRooting<DP> dp(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		dp.add_edge(u - 1, v - 1);
	}
	for (auto i : dp.solve()) {
		cout << i.val << endl;
	}
}
