#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_D"
#define ERROR "1e-6"
#include "./../Geometry/Line.hpp"
#include "./../Geometry/Circle.hpp"
#include "./../Geometry/Geometric.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int main() {
	Geometric::Circle c;
	cin >> c;
	int q;
	cin >> q;
	while (q--) {
		Geometric::Line l;
		cin >> l;
		auto ans = cross_points(c, l);
		assert(1 <= ans.size() && ans.size() <= 2);
		if (ans.size() == 1) {
			ans.push_back(ans[0]);
		} else {
			sort(ans.begin(), ans.end(), Geometric::Vec2::compare_xy);
		}
		printf("%.12Lf %.12Lf %.12Lf %.12Lf\n", ans[0].x, ans[0].y, ans[1].x, ans[1].y);
	}
}