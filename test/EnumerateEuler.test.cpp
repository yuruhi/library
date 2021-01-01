#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/RUPC/2286?year=2011"
#include "./../Math/Euler.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	const int MAX_A = 1000000;
	vector<int> euler = EnumerateEuler(MAX_A);
	vector<long long> ans(MAX_A + 1, 1);
	for (int i = 1; i <= MAX_A; ++i) {
		ans[i] = ans[i - 1] + euler[i];
	}

	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << ans[x] << '\n';
	}
}