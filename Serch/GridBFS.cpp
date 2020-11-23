#pragma once
#include "./../Utility/Point.cpp"
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<vector<int>> GridBFS(const vector<string>& grid, Point start, char wall = '#') {
	int h = grid.size(), w = grid.front().size();
	Point::set_range(h, w);
	vector<vector<int>> result(h, vector<int>(w, INT_MAX));
	if (grid[start.y][start.x] == wall) {
		return result;
	}
	result[start.y][start.x] = 0;
	queue<Point> q;
	q.push(start);
	while (!q.empty()) {
		auto f = q.front();
		q.pop();
		for (auto p : f.adj4_in_range()) {
			if (grid[p.y][p.x] != wall && result[p.y][p.x] == INT_MAX) {
				q.push(p);
				result[p.y][p.x] = result[f.y][f.x] + 1;
			}
		}
	}
	return result;
}
vector<vector<int>> GridBFS(const vector<string>& grid, char start, char wall = '#') {
	int h = grid.size(), w = grid.front().size();
	Point s;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			if (grid[i][j] == start) {
				s = Point(j, i);
			}
		}
	return GridBFS(grid, s, wall);
}
