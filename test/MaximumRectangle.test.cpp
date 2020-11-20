#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_C"
#include "./../DP/MaximumRectangle.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a) {
		cin >> i;
	}
	cout << MaximumRectangle(a) << '\n';
}