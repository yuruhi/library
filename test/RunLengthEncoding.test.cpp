#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/JOI/Final/0506"
#include "./../Utility/RunLengthEncoding.cpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		string s;
		cin >> s;
		for (int i = 0; i < n; ++i) {
			string t;
			for (auto [count, value] : RunLengthEncoding(s)) {
				t += to_string(count);
				t += value;
			}
			s = t;
		}
		cout << s << endl;
	}
}