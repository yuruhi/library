#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_A"
#include "./../Geometry/Polygon.hpp"
#include "./../Geometry/Geometric.cpp"
#include <iostream>
#include <utility>
using namespace std;

int main() {
	int n;
	cin >> n;
	Geometric::Polygon p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	Geometric::Polygon ans = p.convex_hull();

	size_t min_index = 0;
	pair<Geometric::LD, Geometric::LD> min_val(10001, 10001);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (auto val = make_pair(ans[i].y, ans[i].x); min_val > val) {
			min_val = val;
			min_index = i;
		}
	}

	cout << ans.size() << '\n';
	for (size_t i = 0; i < ans.size(); ++i) {
		auto v = ans[(i + min_index) % ans.size()];
		cout << v.x << ' ' << v.y << '\n';
	}
}