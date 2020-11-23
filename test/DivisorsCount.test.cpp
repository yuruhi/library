#define IGNORE
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1562"
#include "./../Math/Divisors.cpp"
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1;; ++i) {
		if (DivisorsCount(i) == n) {
			cout << i << '\n';
			return 0;
		}
	}
}