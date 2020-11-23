#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0560"
#include "./../Utility/CulSum2D.cpp"
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

	CulSum2D<int> cnt_J(s, [](char c) { return c == 'J'; });
	CulSum2D<int> cnt_O(s, [](char c) { return c == 'O'; });
	CulSum2D<int> cnt_I(s, [](char c) { return c == 'I'; });

	while (n--) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		y1--;
		x1--;
		cout << cnt_J(y1, y2, x1, x2) << ' ' << cnt_O(y1, y2, x1, x2) << ' '
		     << cnt_I(y1, y2, x1, x2) << '\n';
	}
}