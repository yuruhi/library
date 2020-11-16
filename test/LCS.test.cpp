#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_10_C"
#include "./../DP/LCS.cpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		string s, t;
		cin >> s >> t;
		cout << LCS(s, t) << '\n';
	}
}