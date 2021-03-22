#pragma once
#include <vector>
#include <utility>
#include <iostream>
#include <limits>

using Weight = long long;
constexpr Weight INF = std::numeric_limits<Weight>::max();
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
	friend std::ostream& operator<<(std::ostream& os, const Edge& e) {
		return os << "->" << e.to << '(' << e.cost << ')';
	}
};
using UnWeightedGraph = std::vector<std::vector<int>>;
using Graph = std::vector<std::vector<Edge>>;
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
	friend std::ostream& operator<<(std::ostream& os, const Edge2& e) {
		return os << e.from << "->" << e.to << '(' << e.cost << ')';
	}
};
using UnWeightedEdges = std::vector<std::pair<int, int>>;
using Edges = std::vector<Edge2>;
using Matrix = std::vector<std::vector<Weight>>;

auto add_edge(UnWeightedGraph& graph, int v, int u) {
	graph[v].push_back(u);
	graph[u].push_back(v);
}
auto add_edge(Graph& graph, int v, int u, Weight cost) {
	graph[v].emplace_back(u, cost);
	graph[u].emplace_back(v, cost);
}
auto to_graph(const UnWeightedGraph& graph, Weight cost = 1) {
	Graph result(graph.size());
	for (std::size_t i = 0; i < graph.size(); ++i) {
		for (int v : graph[i]) {
			result[i].emplace_back(v, cost);
		}
	}
	return result;
}
auto to_unweighted_graph(const Graph& graph) {
	UnWeightedGraph result(graph.size());
	for (std::size_t i = 0; i < graph.size(); ++i) {
		for (auto [v, cost] : graph[i]) {
			result[i].push_back(v);
		}
	}
	return result;
}
auto to_edges(const UnWeightedGraph& graph, bool unique = false) {
	std::vector<std::pair<int, int>> edges;
	for (std::size_t i = 0; i < graph.size(); ++i) {
		for (int v : graph[i]) {
			if (!unique || static_cast<int>(i) < v) edges.emplace_back(i, v);
		}
	}
	return edges;
}
auto to_edges(const Graph& graph) {
	Edges edges;
	for (std::size_t i = 0; i < graph.size(); ++i) {
		for (auto [v, cost] : graph[i]) {
			edges.emplace_back(i, v, cost);
		}
	}
	return edges;
}
