#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_B"
#define ERROR "1e-6"
#include "./../Geometry/Triangle.hpp"
#include "./../Geometry/Geometric.cpp"
#include <iostream>
using namespace std;

int main() {
	Geometric::Triangle t;
	cin >> t;
	Geometric::Circle ans = t.incircle();
	printf("%.12Lf %.12Lf %.12Lf\n", ans.center.x, ans.center.y, ans.r);
}