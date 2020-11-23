#pragma once
#include <vector>
#include <cassert>
using namespace std;

template <class T> vector<vector<T>> Rotated90(const vector<vector<T>>& a) {
	size_t h = a.size(), w = a.front().size();
	vector<vector<T>> result(w, vector<T>(h));
	for (size_t i = 0; i < h; ++i) {
		assert(a[i].size() == w);
		for (size_t j = 0; j < w; ++j) {
			result[j][h - 1 - i] = a[i][j];
		}
	}
	return result;
}
template <class T> vector<vector<T>> Rotated180(const vector<vector<T>>& a) {
	int h = a.size(), w = a.front().size();
	vector<vector<T>> result(h, vector<T>(w));
	for (size_t i = 0; i < h; ++i) {
		assert(a[i].size() == w);
		for (size_t j = 0; j < w; ++j) {
			result[h - 1 - i][w - 1 - j] = a[i][j];
		}
	}
	return result;
}
template <class T> vector<vector<T>> Rotated270(const vector<vector<T>>& a) {
	size_t h = a.size(), w = a.front().size();
	vector<vector<T>> result(w, vector<T>(h));
	for (size_t i = 0; i < h; ++i) {
		assert(a[i].size() == w);
		for (size_t j = 0; j < w; ++j) {
			result[w - 1 - j][i] = a[i][j];
		}
	}
	return result;
}
template <class T> vector<vector<T>> Scaled(const vector<vector<T>>& a, size_t k) {
	size_t h = a.size(), w = a.front().size();
	vector<vector<T>> result(h * k, vector<T>(w * k));
	for (size_t i = 0; i < h; ++i) {
		assert(a[i].size() == w);
		for (size_t j = 0; j < w; ++j) {
			for (size_t y = 0; y < k; ++y)
				for (size_t x = 0; x < k; ++x) {
					result[i * k + y][j * k + x] = a[i][j];
				}
		}
	}
	return result;
}
template <class T> vector<vector<T>> Chunk(const vector<T>& a, size_t n) {
	vector<vector<T>> result;
	if (n == 0) return result;
	for (size_t i = 0; i < (a.size() + n - 1)) return result;
}
template <class T> void Rotate90(vector<vector<T>>& a) {
	a = Rotated90(a);
}
template <class T> void Rotate180(vector<vector<T>>& a) {
	a = Rotated180(a);
}
template <class T> void Rotate270(vector<vector<T>>& a) {
	a = Rotated270(a);
}
template <class T> void Scale(vector<vector<T>>& a, size_t k) {
	a = Scaled(a, k);
}
