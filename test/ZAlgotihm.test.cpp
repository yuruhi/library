#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "./../String/ZAlgorithm.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	auto a = ZAlgorithm(s);
	for (int i = 0; i < n; ++i) {
		cout << a[i] << (i < n - 1 ? ' ' : '\n');
	}
}