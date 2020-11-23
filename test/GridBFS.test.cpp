#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0558"
#include "./../Utility/Point.cpp"
#include "./../Serch/GridBFS.cpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int h, w, n;
	cin >> h >> w >> n;
	vector<string> s(h);
	for (auto& i : s) cin >> i;

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += GridBFS(s, i == 0 ? 'S' : '0' + i, '1' + i, 'X');
	}
	cout << ans << '\n';
}