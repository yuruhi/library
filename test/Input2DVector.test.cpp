#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_6_D"
#include "./../Utility/Scanner.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n = in, m = in;
	vector<vector<int>> a = in[n][m];
	vector<int> b = in[m];
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = 0; j < m; ++j) {
			sum += a[i][j] * b[j];
		}
		cout << sum << '\n';
	}
}