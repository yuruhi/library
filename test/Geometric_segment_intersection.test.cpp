#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B"
#include "./../Geometry/Line.hpp"
#include "./../Geometry/Geometric.cpp"
#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		Geometric::Segment l1, l2;
		cin >> l1 >> l2;
		auto [flag, point] = l1.intersection(l2);
		cout << flag << '\n';
	}
}