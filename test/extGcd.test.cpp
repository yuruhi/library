#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E"
#include "./../math/extGcd.cpp"
#include <iostream>
using namespace std;

int main() {
	long long x, y;
	cin >> x >> y;
	long long a, b;
	extGcd(x, y, a, b);
	cout << a << ' ' << b << '\n';
}