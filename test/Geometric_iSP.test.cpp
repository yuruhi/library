#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C"
#include "./../Geometry/Vec2.hpp"
#include "./../Geometry/Geometric.cpp"
#include <iostream>
using namespace std;

int main() {
	Geometric::Vec2 p0, p1;
	cin >> p0 >> p1;
	int q;
	cin >> q;
	while (q--) {
		Geometric::Vec2 p2;
		cin >> p2;
		if (int a = Geometric::iSP(p0, p1, p2); a == 1) {
			puts("COUNTER_CLOCKWISE");
		} else if (a == -1) {
			puts("CLOCKWISE");
		} else if (a == -2) {
			puts("ONLINE_BACK");
		} else if (a == 2) {
			puts("ONLINE_FRONT");
		} else if (a == 0) {
			puts("ON_SEGMENT");
		}
	}
}