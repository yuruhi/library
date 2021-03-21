#pragma once
#include "./GraphTemplate.cpp"
#include "./Graph/CycleDetection.cpp"
#include <vector>
#include <utility>
#include <numeric>

class DirectedMinimumSpanningTree {
	int n;
	Edges edges;

public:
	DirectedMinimumSpanningTree(int _n) : n(_n) {}
	void add_edge(int from, int to, Weight cost) {
		if (from != to) {
			edges.emplace_back(from, to, cost);
		}
	}
	Weight solve(int root) {
		std::vector<std::vector<Edge>> in_edges(n);
		for (auto edge : edges) {
			if (root != edge.to) {
				in_edges[edge.to].emplace_back(edge.from, edge.cost);
			}
		}

		std::vector<std::pair<int, int>> min_edges;
		std::vector<Weight> min_costs;
		for (int i = 0; i < n; ++i) {
			if (in_edges[i].empty()) continue;
			std::pair<int, int> min_edge;
			Weight min_cost = INF;
			for (auto edge : in_edges[i]) {
				if (min_cost > edge.cost) {
					min_edge = std::pair(edge.to, i);
					min_cost = edge.cost;
				}
			}
			min_edges.push_back(min_edge);
			min_costs.push_back(min_cost);
		}

		if (auto cycle_opt = CycleDetectionEdge(n, min_edges); cycle_opt) {
			const auto& cycle = cycle_opt.value();

			std::vector<Weight> minus(n);
			std::vector<bool> on_cycle(n);
			Weight cycle_cost_sum = 0;
			for (int i : cycle) {
				minus[min_edges[i].second] = min_costs[i];
				on_cycle[min_edges[i].first] = true;
				cycle_cost_sum += min_costs[i];
			}

			int compressed_vertex = min_edges[cycle.front()].first;
			DirectedMinimumSpanningTree sub(n);
			for (std::size_t i = 0; i < edges.size(); ++i) {
				auto edge = edges[i];
				if (on_cycle[edge.to]) {
					if (on_cycle[edge.from]) continue;
					edge.cost -= minus[edge.to];
					edge.to = compressed_vertex;
				}
				if (on_cycle[edge.from]) {
					edge.from = compressed_vertex;
				}
				sub.add_edge(edge.from, edge.to, edge.cost);
			}
			return cycle_cost_sum + sub.solve(root);
		} else {
			return std::accumulate(min_costs.begin(), min_costs.end(), Weight(0));
		}
	}
};
