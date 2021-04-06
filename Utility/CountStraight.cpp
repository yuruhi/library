#pragma once
#include <vector>
#include <tuple>

template <class F> auto CountLR(int n, F f) {
	std::vector<int> left(n);
	for (int i = 0; i < n; ++i) {
		if (f(i)) left[i] = 1 + (i ? left[i - 1] : 0);
	}
	std::vector<int> right(n);
	for (int i = n - 1; i >= 0; --i) {
		if (f(i)) right[i] = 1 + (i != n - 1 ? right[i + 1] : 0);
	}
	return std::tuple(left, right);
}

template <class F> auto CountLR(int h, int w, F f) {
	std::vector<std::vector<int>> left(h, std::vector<int>(w));
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (f(i, j)) left[i][j] = 1 + (j ? left[i][j - 1] : 0);
		}
	}
	std::vector<std::vector<int>> right(h, std::vector<int>(w));
	for (int i = 0; i < h; ++i) {
		for (int j = w - 1; j >= 0; --j) {
			if (f(i, j)) right[i][j] = 1 + (j != w - 1 ? right[i][j + 1] : 0);
		}
	}
	return std::tuple(left, right);
}

template <class F> auto CountUD(int h, int w, F f) {
	std::vector<std::vector<int>> up(h, std::vector<int>(w));
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (f(i, j)) up[i][j] = 1 + (i ? up[i - 1][j] : 0);
		}
	}
	std::vector<std::vector<int>> down(h, std::vector<int>(w));
	for (int i = h - 1; i >= 0; --i) {
		for (int j = 0; j < w; ++j) {
			if (f(i, j)) down[i][j] = 1 + (i != h - 1 ? down[i + 1][j] : 0);
		}
	}
	return std::tuple(up, down);
}

template <class F> auto CountTLBR(int h, int w, F f) {
	std::vector<std::vector<int>> tl(h, std::vector<int>(w));
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (f(i, j)) tl[i][j] = 1 + (i && j ? tl[i - 1][j - 1] : 0);
		}
	}
	std::vector<std::vector<int>> br(h, std::vector<int>(w));
	for (int i = h - 1; i >= 0; --i) {
		for (int j = w - 1; j >= 0; --j) {
			if (f(i, j)) br[i][j] = 1 + (i != h - 1 && j != w - 1 ? br[i + 1][j + 1] : 0);
		}
	}
	return std::tuple(tl, br);
}
