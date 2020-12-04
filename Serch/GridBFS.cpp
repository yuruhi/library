#pragma once
#include "./../Utility/Point.cpp"
#include <vector>
#include <string>
#include <queue>
#include <optional>
#include <limits>
#include <cassert>
using namespace std;

vector<vector<int>> GridBFS(const vector<string>& grid, Point start, char wall) {
	constexpr int INF = numeric_limits<int>::max();
	int h = grid.size(), w = grid.front().size();
	Point::set_range(h, w);
	vector<vector<int>> result(h, vector<int>(w, INF));
	if (grid[start.y][start.x] == wall) {
		return result;
	}
	result[start.y][start.x] = 0;
	queue<Point> q;
	q.push(start);
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		for (auto adj : now.adj4_in_range()) {
			if (grid[adj.y][adj.x] != wall && result[adj.y][adj.x] == INF) {
				q.push(adj);
				result[adj.y][adj.x] = result[now.y][now.x] + 1;
			}
		}
	}
	return result;
}
vector<vector<int>> GridBFS(const vector<string>& grid, char start, char wall) {
	Point::set_range(grid.size(), grid.front().size());
	auto s = Point::find_one(grid, start);
	assert(s);
	return GridBFS(grid, *s, wall);
}
int GridBFS(const vector<string>& grid, Point start, Point goal, char wall) {
	return GridBFS(grid, start, wall)[goal.y][goal.x];
}
int GridBFS(const vector<string>& grid, char start, char goal, char wall) {
	assert(start != goal);
	Point::set_range(grid.size(), grid.front().size());
	auto s = Point::find_one(grid, start), g = Point::find_one(grid, goal);
	assert(s && g);
	return GridBFS(grid, *s, *g, wall);
}