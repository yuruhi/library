#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"
#include "./../DataStructure/SegmentTree.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	RangeSumQuery<int> seg(vector(n, 0));
	while (q--) {
		int com, x, y;
		cin >> com >> x >> y;
		x--;
		if (com == 0) {
			seg.set(x, seg[x] + y);
		} else if (com == 1) {
			cout << seg(x, y) << '\n';
		}
	}
}