#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D"
#define ERROR "1e-8"
#include "./../Geometry/Line.hpp"
#include "./../Geometry/Geometric.cpp"
#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		Geometric::Segment s1, s2;
		cin >> s1 >> s2;
		printf("%.12Lf\n", s1.distance(s2));
	}
}