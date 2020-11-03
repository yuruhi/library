#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_11_D"
#include "./../Utility/Dice.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<Dice> d(n);
	for (auto& i : d) {
		cin >> i;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (d[i].same(d[j])) {
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
}