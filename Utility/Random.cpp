#pragma once
#include <random>
#include <algorithm>
#include <type_traits>
#include <cassert>

class Random {
	std::mt19937 engine;
	std::random_device rd;

public:
	Random() {
		seed();
	}
	void seed() {
		engine.seed(rd());
	}
	void seed(std::uint_fast32_t s) {
		engine.seed(s);
	}
	template <class T,
	          std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<bool, T>,
	                           std::nullptr_t> = nullptr>
	T get(T l, T r) {
		assert(l <= r);
		return std::uniform_int_distribution<T>(l, r)(engine);
	}
	template <class T, std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
	T get(T l, T r) {
		assert(l <= r);
		return uniform_real_distribution<T>(l, r)(engine);
	}
	template <class T, std::enable_if_t<std::is_same_v<bool, T>, std::nullptr_t> = nullptr>
	T get(double probability = 0.5) {
		bernoulli_distribution u(probability);
		return u(engine);
	}
	template <class T,
	          std::enable_if_t<std::is_same_v<std::string, T>, std::nullptr_t> = nullptr>
	T get(size_t n, string_view chars = "abcdefghjiklmnopqrstuvwxyz") {
		string result;
		result.reserve(n);
		std::sample(chars.begin(), chars.end(), std::back_inserter(result), n, engine);
		return result;
	}
	int dice() {
		return get<int>(1, 7);
	}
	template <class T> void shuffle(T& v) {
		std::shuffle(std::begin(v), std::end(v), engine);
	}
} rnd;
