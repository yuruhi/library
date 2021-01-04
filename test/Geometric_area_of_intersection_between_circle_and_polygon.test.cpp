#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_H"
#define ERROR "1e-6"
#include "./../Geometry/area_of_intersection.cpp"
#include <iostream>
using namespace std;

int main() {
	int n;
	Geometric::LD r;
	cin >> n >> r;
	Geometric::Circle c(Geometric::Vec2::zero(), r);
	Geometric::Polygon p(n);
	cin >> p;
	printf("%.12Lf\n", Geometric::area_of_intersection(c, p));
}