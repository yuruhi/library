#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A"
#include "./../DataStructure/SegmentTree.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	RangeMinQuery<int> seg(vector(n, 0x7FFFFFFF));
	while (q--) {
		int com, x, y;
		cin >> com >> x >> y;
		if (com == 0) {
			seg.set(x, y);
		} else if (com == 1) {
			cout << seg(x, y + 1) << '\n';
		}
	}
}