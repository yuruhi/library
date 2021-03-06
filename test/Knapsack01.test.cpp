#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_B"
#include "./../DP/Knapsack01.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int N, W;
	cin >> N >> W;
	vector<int> v(N), w(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i] >> w[i];
	}
	cout << Knapsack01(N, W, v, w)[W] << '\n';
}