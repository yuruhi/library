#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_E"
#define ERROR "1e-6"
#include "./../Geometry/Circle.hpp"
#include "./../Geometry/Geometric.cpp"
#include <iostream>
#include <cassert>
using namespace std;

int main() {
	Geometric::Circle c1, c2;
	cin >> c1 >> c2;
	auto ans = cross_points(c1, c2);
	assert(1 <= ans.size() && ans.size() <= 2);
	if (ans.size() == 1) {
		ans.push_back(ans[0]);
	} else {
		sort(ans.begin(), ans.end(), Geometric::Vec2::compare_xy);
	}
	printf("%.12Lf %.12Lf %.12Lf %.12Lf\n", ans[0].x, ans[0].y, ans[1].x, ans[1].y);
}