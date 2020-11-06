#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "./../template/Input.cpp"
#include <iostream>
using namespace std;

int main() {
	int t = in;
	auto [a, b] = in.multiple<long long, long long>(t);
	for (int i = 0; i < t; ++i) {
		cout << a[i] + b[i] << '\n';
	}
}
