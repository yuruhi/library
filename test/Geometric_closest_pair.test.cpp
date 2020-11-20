#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_5_A"
#define ERROR "1e-8"
#include "./../Geometry/ClosestPair.cpp"
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<Geometric::Vec2> p(n);
	for (auto& i : p) cin >> i;
	auto [dist, p1, p2] = Geometric::closest_pair(p);
	assert(Geometric::sgn(dist - (p1 - p2).length()) == 0);
	printf("%.12Lf\n", dist);
}