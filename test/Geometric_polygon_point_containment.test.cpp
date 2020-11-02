#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_C"
#include "./../Geometry/Polygon.hpp"
#include "./../Geometry/Geometric.cpp"
#include <iostream>
using namespace std;

int main() {
	int n, q;
	cin >> n;
	Geometric::Polygon p(n);
	cin >> p;
	cin >> q;
	while (q--) {
		Geometric::Vec2 v;
		cin >> v;
		if (p.tangent(v)) {
			puts("2");
		} else if (p.intersects(v)) {
			puts("1");
		} else {
			puts("0");
		}
	}
}