#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A"
#include "./../Geometry/Vec2.hpp"
#include "./../Geometry/Geometric.cpp"
#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		Geometric::Vec2 p0, p1, p2, p3;
		cin >> p0 >> p1 >> p2 >> p3;
		Geometric::Vec2 v1 = p1 - p0, v2 = p2 - p3;
		if (Geometric::sgn(v1.cross(v2)) == 0) {
			cout << 2 << '\n';
		} else if (Geometric::sgn(v1.dot(v2)) == 0) {
			cout << 1 << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
}