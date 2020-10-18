#pragma once
#include <limits>
#include <vector>
#include <iostream>
using namespace std;

using Weight = long long;
constexpr Weight INF = numeric_limits<Weight>::max();
struct Edge {
	int to;
	Weight cost;
	Edge() : to(-1), cost(-1) {}
	Edge(int _to, Weight _cost = 1) : to(_to), cost(_cost) {}
	friend bool operator<(const Edge& e1, const Edge& e2) {
		return e1.cost < e2.cost;
	}
	friend bool operator>(const Edge& e1, const Edge& e2) {
		return e1.cost > e2.cost;
	}
	friend ostream& operator<<(ostream& os, const Edge& e) {
		return os << "->" << e.to << '(' << e.cost << ')';
	}
};
using Graph = vector<vector<Edge>>;
struct Edge2 {
	int from, to;
	Weight cost;
	Edge2() : from(-1), to(-1), cost(0) {}
	Edge2(int _from, int _to, Weight _cost) : from(_from), to(_to), cost(_cost) {}
	friend bool operator<(const Edge2& e1, const Edge2& e2) {
		return e1.cost < e2.cost;
	}
	friend bool operator>(const Edge2& e1, const Edge2& e2) {
		return e1.cost > e2.cost;
	}
	friend ostream& operator<<(ostream& os, const Edge2& e) {
		return os << e.from << "->" << e.to << '(' << e.cost << ')';
	}
};
using Edges = vector<Edge2>;
using Matrix = vector<vector<Weight>>;
