#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_5_A"
#define ERROR "1e-8"
#include "./../Geometry/Polygon.hpp"
#include "./../Geometry/Geometric.cpp"
#include <iostream>
#include <cassert>
using namespace std;

int main() {
	int n;
	cin >> n;
	Geometric::Polygon p(n);
	for (auto& i : p)
		cin >> i;
	auto [dist, p1, p2] = p.closest_pair();
	assert(Geometric::sgn(dist - (p1 - p2).length()) == 0);
	printf("%.12Lf\n", dist);
}