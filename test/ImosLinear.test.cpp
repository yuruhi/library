#define PROBLEM "https://yukicoder.me/problems/no/1008"
#include "./../Utility/ImosLinear.cpp"
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	using ll = long long;

	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (ll& i : a) {
		cin >> i;
	}
	vector<pair<int, ll>> xw(m);
	for (auto& [x, w] : xw) {
		cin >> x >> w;
		x--;
	}

	auto check = [&](ll c) {
		ImosLinear<ll> imos(n);
		for (auto [x, w] : xw) {
			imos.add(x, x + 1, w, 0);
			int left = min<ll>(x, w / c);
			imos.add(x - left, x, w - c * left, c);
			int right = min<ll>(n - 1 - x, w / c);
			imos.add(x + 1, x + 1 + right, w - c, -c);
		}
		imos.build();
		for (int i = 0; i < n; ++i) {
			if (imos[i] >= a[i]) {
				return false;
			}
		}
		return true;
	};

	ll sum_w = 0, min_a = 10000000000;
	for (ll i : a) {
		min_a = min(min_a, i);
	}
	for (auto [x, w] : xw) {
		sum_w += w;
	}

	if (sum_w < min_a) {
		cout << 0 << '\n';
	} else if (!check(1000000099)) {
		cout << -1 << '\n';
	} else {
		ll ng = 0, ok = 1000000099;
		while (ok - ng > 1) {
			ll mid = (ok + ng) / 2;
			(check(mid) ? ok : ng) = mid;
		}
		cout << ok << '\n';
	}
}