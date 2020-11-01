#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A"
#include "./../Geometry/Line.hpp"
#include "./../Geometry/Geometric.cpp"
#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		Geometric::Line l1, l2;
		cin >> l1 >> l2;
		if (l1.is_parallel(l2)) {
			puts("2");
		} else if (l1.is_orthogonal(l2)) {
			puts("1");
		} else {
			puts("0");
		}
	}
}