#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B"
#include "./../String/RollingHash.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();

	RH rh_s(s), rh_t(t);
	for (int i = 0; i <= n - m; ++i) {
		if (rh_s(i, i + m) == rh_t(m)) {
			cout << i << '\n';
		}
	}
}