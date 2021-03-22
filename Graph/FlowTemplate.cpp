#pragma once
#include <vector>
#include <limits>

using FLOW = long long;
constexpr FLOW INF_FLOW = std::numeric_limits<FLOW>::max();
struct EdgeF {
	int to, rev;
	FLOW cap;
	EdgeF() : to(-1), rev(-1), cap(-1) {}
	EdgeF(int t, int r, FLOW c) : to(t), rev(r), cap(c) {}
	friend std::ostream& operator<<(std::ostream& os, const EdgeF& e) {
		return os << "->" << e.to << "(" << e.cap << ")";
	}
};
using GraphF = std::vector<std::vector<EdgeF>>;
