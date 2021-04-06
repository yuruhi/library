#pragma once
#include "./../Utility/Point.cpp"
#include <vector>
#include <string>
#include <queue>
#include <optional>
#include <limits>
#include <cassert>

auto GridBFS(const std::vector<std::string>& grid, Point start, char wall_char) {
	constexpr int INF = std::numeric_limits<int>::max();
	int h = grid.size(), w = grid.front().size();
	Point::set_range(h, w);

	std::vector result(h, std::vector(w, INF));
	if (grid[start.y][start.x] == wall_char) {
		return result;
	}
	result[start.y][start.x] = 0;
	std::queue<Point> q;
	q.push(start);
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		for (auto adj : now.adj4_in_range()) {
			if (grid[adj.y][adj.x] != wall_char && result[adj.y][adj.x] == INF) {
				q.push(adj);
				result[adj.y][adj.x] = result[now.y][now.x] + 1;
			}
		}
	}
	return result;
}
auto GridBFS(const std::vector<std::string>& grid, char start_char, char wall_char) {
	Point::set_range(grid.size(), grid.front().size());
	auto start = Point::find_one(grid, start_char);
	assert(start);
	return GridBFS(grid, *start, wall_char);
}
int GridBFS(const std::vector<std::string>& grid, Point start, Point goal, char wall_char) {
	return GridBFS(grid, start, wall_char)[goal.y][goal.x];
}
int GridBFS(const std::vector<std::string>& grid, char start_char, char goal_char,
            char wall_char) {
	assert(start_char != goal_char);
	Point::set_range(grid.size(), grid.front().size());
	auto start = Point::find_one(grid, start_char), goal = Point::find_one(grid, goal_char);
	assert(start && goal);
	return GridBFS(grid, *start, *goal, wall_char);
}
