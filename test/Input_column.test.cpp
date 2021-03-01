#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "./../Utility/Input.cpp"
#include <iostream>
using namespace std;

int main() {
	int t = in;
	auto [a, b] = in.column<long long, long long>(t);
	for (int i = 0; i < t; ++i) {
		cout << a[i] + b[i] << '\n';
	}
}
