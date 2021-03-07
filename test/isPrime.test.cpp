#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C"
#include "./../math/isPrime.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = 0;
	while (n--) {
		int x;
		cin >> x;
		ans += isPrime(x);
	}
	cout << ans << '\n';
}