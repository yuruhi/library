#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2013"
#include "./../DataStructure/Imos.cpp"
#include <iostream>
#include <algorithm>
using namespace std;

int input_time() {
	int h, m, s;
	char c;
	cin >> h >> c >> m >> c >> s;
	return h * 3600 + m * 60 + s;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		Imos<int> imos(24 * 60 * 60);
		for (int i = 0; i < n; ++i) {
			int s = input_time(), t = input_time();
			imos.add(s, t);
		}
		imos.build();
		auto a = imos.to_a();
		cout << *max_element(a.begin(), a.end()) << '\n';
	}
}