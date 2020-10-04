#pragma once
#include <vector>
#include <limits>
using namespace std;

using FLOW = long long;
constexpr FLOW INF_FLOW = numeric_limits<FLOW>::max();
struct EdgeF {
	int to, rev;
	FLOW cap;
	EdgeF() : to(-1), rev(-1), cap(-1) {}
	EdgeF(int t, int r, FLOW c) : to(t), rev(r), cap(c) {}
};
using GraphF = vector<vector<EdgeF>>;