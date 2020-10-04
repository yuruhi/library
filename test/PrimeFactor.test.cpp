#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_A"
#include "./../Math/PrimeFactor.cpp"
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << n << ':';
	for (auto [p, e] : PrimeFactor(n)) {
		while (e--) {
			cout << ' ' << p;
		}
	}
	cout << '\n';
}