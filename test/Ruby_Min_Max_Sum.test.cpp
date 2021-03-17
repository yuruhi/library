#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_4_D"
#include "./../Utility/Ruby.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<long long> a(n);
	for (auto& i : a) cin >> i;
	cout << (a | Min) << ' ' << (a | Max) << ' ' << (a | Sum) << '\n';
}