#pragma once
#include <random>
#include <algorithm>
#include <type_traits>
#include <cassert>
using namespace std;

class Random {
	mt19937 engine;
	random_device rd;

public:
	Random() {
		seed();
	}
	void seed() {
		engine.seed(rd());
	}
	void seed(uint_fast32_t s) {
		engine.seed(s);
	}
	template <class T,
	          enable_if_t<is_integral_v<T> && !is_same_v<bool, T>, nullptr_t> = nullptr>
	T get(T l, T r) {
		assert(l <= r);
		return uniform_int_distribution<T>(l, r)(engine);
	}
	template <class T, enable_if_t<is_floating_point_v<T>, nullptr_t> = nullptr>
	T get(T l, T r) {
		assert(l <= r);
		return uniform_real_distribution<T>(l, r)(engine);
	}
	template <class T, enable_if_t<is_same_v<bool, T>, nullptr_t> = nullptr>
	T get(double probability = 0.5) {
		bernoulli_distribution u(probability);
		return u(engine);
	}
	template <class T, enable_if_t<is_same_v<string, T>, nullptr_t> = nullptr>
	T get(size_t n, string_view chars = "abcdefghjiklmnopqrstuvwxyz") {
		string result;
		result.reserve(n);
		sample(chars.begin(), chars.end(), back_inserter(result), n, engine);
		return result;
	}
	int dice() {
		return get<int>(1, 7);
	}
	template <class T> void shuffle(T& v) {
		std::shuffle(begin(v), end(v), engine);
	}
} rnd;
