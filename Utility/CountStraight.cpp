#pragma once
#include <vector>
#include <tuple>
using namespace std;

template <class F> tuple<vector<int>, vector<int>> CountLR(int n, F f) {
	vector<int> left(n);
	for (int i = 0; i < n; ++i) {
		if (f(i)) left[i] = 1 + (i ? left[i - 1] : 0);
	}
	vector<int> right(n);
	for (int i = 0; i < n; ++i) {
		if (f(i)) right[i] = 1 + (i != n - 1 ? right[i + 1] : 0);
	}
	return make_tuple(left, right);
}

template <class F> tuple<vector<vector<int>>, vector<vector<int>>> CountLR(int h, int w, F f) {
	vector<vector<int>> left(h, vector<int>(w));
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			if (f(i, j)) left[i][j] = 1 + (j ? left[i][j - 1] : 0);
		}
	vector<vector<int>> right(h, vector<int>(w));
	for (int i = 0; i < h; ++i)
		for (int j = w - 1; j >= 0; --j) {
			if (f(i, j)) right[i][j] = 1 + (j != w - 1 ? right[i][j + 1] : 0);
		}
	return make_tuple(left, right);
}

template <class F> tuple<vector<vector<int>>, vector<vector<int>>> CountUD(int h, int w, F f) {
	vector<vector<int>> up(h, vector<int>(w));
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			if (f(i, j)) up[i][j] = 1 + (i ? up[i - 1][j] : 0);
		}
	vector<vector<int>> down(h, vector<int>(w));
	for (int i = h - 1; i >= 0; --i)
		for (int j = 0; j < w; ++j) {
			if (f(i, j)) down[i][j] = 1 + (i != h - 1 ? down[i + 1][j] : 0);
		}
	return make_tuple(up, down);
}

template <class F> tuple<vector<vector<int>>, vector<vector<int>>> CountTLBR(int h, int w, F f) {
	vector<vector<int>> tl(h, vector<int>(w));
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			if (f(i, j)) tl[i][j] = 1 + (i && j ? tl[i - 1][j - 1] : 0);
		}
	vector<vector<int>> br(h, vector<int>(w));
	for (int i = h - 1; i >= 0; --i)
		for (int j = w - 1; j >= 0; --j) {
			if (f(i, j)) br[i][j] = 1 + (i != h - 1 && j != w - 1 ? br[i + 1][j + 1] : 0);
		}
	return make_tuple(tl, br);
}
