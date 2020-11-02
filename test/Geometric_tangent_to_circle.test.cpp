#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_F"
#define ERROR "1e-6"
#include "./../Geometry/Circle.hpp"
#include "./../Geometry/Vec2.hpp"
#include "./../Geometry/Geometric.cpp"
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int main() {
	Geometric::Vec2 p;
	Geometric::Circle c;
	cin >> p >> c;
	auto ans = Geometric::tangent_to_circle(c, p);
	assert(ans.size() == 2);
	sort(ans.begin(), ans.end(), Geometric::Vec2::compare_xy);
	printf("%.12Lf %.12Lf\n%.12Lf %.12Lf\n", ans[0].x, ans[0].y, ans[1].x, ans[1].y);
}