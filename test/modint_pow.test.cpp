#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_B"
#include "./../Math/modint.cpp"
#include <iostream>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	cout << mint(m).pow(n) << '\n';
}