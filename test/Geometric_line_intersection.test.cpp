#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C"
#define ERROR "1e-8"
#include "./../Geometry/Line.hpp"
#include "./../Geometry/Geometric.cpp"
#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		Geometric::Segment l1, l2;
		cin >> l1 >> l2;
		auto point = *l1.cross_point(l2);
		printf("%.12Lf %.12Lf\n", point.x, point.y);
	}
}