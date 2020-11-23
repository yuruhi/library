#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D"
#include "./../Math/Divisors.cpp"
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int ans = 0;
	for (int d : Divisors(c)) {
		ans += a <= d && d <= b;
	}
	cout << ans << '\n';
}