#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_B"
#include "./../Geometry/Polygon.hpp"
#include "./../Geometry/Geometric.cpp"
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	Geometric::Polygon p(n);
	for (auto& i : p) cin >> i;
	auto [dist, i, j] = p.diameter();
	printf("%.12Lf\n", dist);
}