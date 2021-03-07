#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C"
#include "./../math/EnumeratePrimes.cpp"
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	auto primes = EnumeratePrimes(100000000);
	int n;
	cin >> n;
	int ans = 0;
	while (n--) {
		int x;
		cin >> x;
		ans += binary_search(primes.begin(), primes.end(), x);
	}
	cout << ans << '\n';
}