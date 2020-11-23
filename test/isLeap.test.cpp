#define IGNORE
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0093"
#include "./../Utility/isLeap.cpp"
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	bool first = true;
	for (int a, b; cin >> a >> b && a && b;) {
		if (first) {
			first = false;
		} else {
			cout << '\n';
		}
		bool NA = true;
		for (int i = a; i <= b; ++i) {
			if (isLeap(i)) {
				cout << i << '\n';
				NA = false;
			}
		}
		if (NA) cout << "NA\n";
	}
}