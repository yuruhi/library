#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C"
#include "./../math/Sieve.cpp"
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	Sieve sieve(100000000);
	const auto& primes = sieve.primes();
	int n;
	cin >> n;
	int ans = 0;
	while (n--) {
		int x;
		cin >> x;
		ans += sieve.is_prime(x);
		assert(sieve.is_prime(x) == binary_search(primes.begin(), primes.end(), x));
	}
	cout << ans << '\n';
}