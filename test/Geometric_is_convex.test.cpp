#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_B"
#include "./../Geometry/Polygon.hpp"
#include "./../Geometry/Geometric.cpp"
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<Geometric::Vec2> p(n);
	for (auto& i : p)
		cin >> i;
	cout << Geometric::Polygon(p).is_convex() << endl;
}