#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_5_D"
#include "./../Math/Inversion.cpp"
#include <iostream>
#include <algorithm>
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

	auto b = a;
	sort(b.begin(), b.end());
	for (int& i : a) {
		i = lower_bound(b.begin(), b.end(), i) - b.begin() + 1;
	}
	cout << Inversion(a, n) << '\n';
}