#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_C"
#define ERROR "1e-6"
#include "./../Geometry/Polygon.hpp"
#include "./../Geometry/Geometric.cpp"
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	Geometric::Polygon p(n);
	cin >> p;
	int q;
	cin >> q;
	while (q--) {
		Geometric::Line v;
		cin >> v;
		printf("%.12Lf\n", p.cut(v).area());
	}
}