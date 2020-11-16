#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D"
#include "./../DP/LIS.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) {
		cin >> i;
	}
	cout << LIS(a) << '\n';
}