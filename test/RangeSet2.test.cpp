#define PROBLEM "https://yukicoder.me/problems/no/674"
#include "./../DataStructure/RangeSet.cpp"
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	using ll = long long;

	ll d;
	int q;
	cin >> d >> q;
	RangeSet<ll> range_set;
	ll ans = 0;
	while (q--) {
		ll a, b;
		cin >> a >> b;
		range_set.insert(a, b);
		auto r = *range_set.find_range(a);
		ans = max(ans, r.second - r.first + 1);
		cout << ans << '\n';
	}
}