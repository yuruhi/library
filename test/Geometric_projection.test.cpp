#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A"
#define ERROR "1e-8"
#include "./../Geometry/Vec2.hpp"
#include "./../Geometry/Geometric.cpp"
#include <iostream>
using namespace std;

int main() {
	Geometric::Line l;
	cin >> l;
	int q;
	cin >> q;
	while (q--) {
		Geometric::Vec2 p;
		cin >> p;
		Geometric::Vec2 ans = p.projection(l);
		printf("%.12Lf %.12Lf\n", ans.x, ans.y);
	}
}