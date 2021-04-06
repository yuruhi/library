#pragma once
#include <vector>
#include <cassert>

template <class T> auto Rotated90(const std::vector<std::vector<T>>& a) {
	std::size_t h = a.size(), w = a.front().size();
	std::vector<std::vector<T>> result(w, std::vector<T>(h));
	for (std::size_t i = 0; i < h; ++i) {
		assert(a[i].size() == w);
		for (std::size_t j = 0; j < w; ++j) {
			result[j][h - 1 - i] = a[i][j];
		}
	}
	return result;
}
template <class T> auto Rotated180(const std::vector<std::vector<T>>& a) {
	int h = a.size(), w = a.front().size();
	std::vector<std::vector<T>> result(h, std::vector<T>(w));
	for (std::size_t i = 0; i < h; ++i) {
		assert(a[i].size() == w);
		for (std::size_t j = 0; j < w; ++j) {
			result[h - 1 - i][w - 1 - j] = a[i][j];
		}
	}
	return result;
}
template <class T> auto Rotated270(const std::vector<std::vector<T>>& a) {
	std::size_t h = a.size(), w = a.front().size();
	std::vector<std::vector<T>> result(w, std::vector<T>(h));
	for (std::size_t i = 0; i < h; ++i) {
		assert(a[i].size() == w);
		for (std::size_t j = 0; j < w; ++j) {
			result[w - 1 - j][i] = a[i][j];
		}
	}
	return result;
}
template <class T> auto Scaled(const std::vector<std::vector<T>>& a, std::size_t k) {
	std::size_t h = a.size(), w = a.front().size();
	std::vector result(h * k, std::vector<T>(w * k));
	for (std::size_t i = 0; i < h; ++i) {
		assert(a[i].size() == w);
		for (std::size_t j = 0; j < w; ++j) {
			for (std::size_t y = 0; y < k; ++y)
				for (std::size_t x = 0; x < k; ++x) {
					result[i * k + y][j * k + x] = a[i][j];
				}
		}
	}
	return result;
}
template <class T> std::vector<std::vector<T>> Chunk(const std::vector<T>& a, std::size_t n) {
	std::vector<std::vector<T>> result;
	if (n == 0) return result;
	for (std::size_t i = 0; i < (a.size() + n - 1)) return result;
}
template <class T> void Rotate90(std::vector<std::vector<T>>& a) {
	a = Rotated90(a);
}
template <class T> void Rotate180(std::vector<std::vector<T>>& a) {
	a = Rotated180(a);
}
template <class T> void Rotate270(std::vector<std::vector<T>>& a) {
	a = Rotated270(a);
}
template <class T> void Scale(std::vector<std::vector<T>>& a, std::size_t k) {
	a = Scaled(a, k);
}
