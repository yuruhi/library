#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_6_C"
#include "./../Utility/Bsearch.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	int q;
	for (cin >> q; q--;) {
		int x;
		cin >> x;
		cout << Bsearch(0, n - 1, [&](int i) { return a[i] >= x; }).value_or(n) << '\n';
	}
}