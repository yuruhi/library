#pragma once
#include <random>
#include <algorithm>
using namespace std;

class Random {
	using T = unsigned int;
	mt19937 mt;
	random_device rd;

public:
	Random() {
		seed();
	}
	void seed() {
		mt.seed(rd());
	}
	void seed(T s) {
		mt.seed(s);
	}
	T operator()() {
		return mt();
	}
	T operator()(T r) {  // [0, r)
		uniform_int_distribution<> u(0, 0 < r ? r - 1 : 0);
		return u(mt);
	}
	T operator()(T l, T r) {  // [l, r)
		uniform_int_distribution<> u(l, max(l, r) - 1);
		return u(mt);
	}
	T dice() {
		return operator()(1, 7);
	}
	bool rand_bool() {
		return operator()(2);
	}
	bool rand_bool(double p) {
		bernoulli_distribution u(p);
		return u(mt);
	}
	template <class T> void shuffle(T& v) {
		std::shuffle(v.begin(), v.end(), mt);
	}
} random;
