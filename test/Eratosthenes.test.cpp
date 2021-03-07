#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C"
#include "./../math/Eratosthenes.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	auto table = Eratosthenes(100000000);
	int n;
	cin >> n;
	int ans = 0;
	while (n--) {
		int x;
		cin >> x;
		ans += table[x];
	}
	cout << ans << '\n';
}