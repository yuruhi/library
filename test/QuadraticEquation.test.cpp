#define PROBLEM "https://yukicoder.me/problems/no/1179"
#define ERROR "1e-4"
#include "./../Math/QuadraticEquation.cpp"
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	auto ans = *QuadraticEquation<long double>(a, b, c);
	sort(ans.begin(), ans.end());
	if (ans.empty()) {
		puts("imaginary");
	} else if (ans.size() == 1) {
		printf("%.6Lf\n", ans[0]);
	} else if (ans.size() == 2) {
		printf("%.6Lf %.6Lf\n", ans[0], ans[1]);
	} else {
		assert(false);
	}
}