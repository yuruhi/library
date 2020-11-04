#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_11_D"
#include "./../Utility/BitRangeBasedFor.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (long long bit : bit_comb(k, n)) {
		cout << bit << ':';
		for (int i = 0; i < n; ++i) {
			if (bit & (1 << i)) cout << ' ' << i;
		}
		cout << '\n';
	}
}