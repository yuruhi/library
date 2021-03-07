#define PROBLEM "https://yukicoder.me/problems/no/269"
#include "./../math/Partition.cpp"
#include "./../math/modint.cpp"
#include <iostream>
using namespace std;

int main() {
	int n, s, k;
	cin >> n >> s >> k;
	int sum = s - n * (n - 1) / 2 * k;
	if (sum < 0) {
		cout << 0 << '\n';
	} else {
		cout << Partition<mint>(n, sum)[n][sum] << '\n';
	}
}