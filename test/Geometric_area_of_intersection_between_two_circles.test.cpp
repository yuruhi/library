#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_I"
#define ERROR "1e-6"
#include "./../Geometry/area_of_intersection.cpp"
#include <iostream>
using namespace std;

int main() {
	Geometric::Circle c1, c2;
	cin >> c1 >> c2;
	printf("%.12Lf\n", Geometric::area_of_intersection(c1, c2));
}