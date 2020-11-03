#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_G"
#define ERROR "1e-6"
#include "./../Geometry/Circle.hpp"
#include "./../Geometry/Geometric.cpp"
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	Geometric::Circle c1, c2;
	cin >> c1 >> c2;
	auto lines = Geometric::common_tangent(c1, c2);
	vector<Geometric::Vec2> ans;
	for (const auto& line : lines) {
		ans.push_back(line.begin);
	}
	sort(ans.begin(), ans.end(), Geometric::Vec2::compare_xy);
	for (const auto& v : ans) {
		printf("%.12Lf %.12Lf\n", v.x, v.y);
	}
}