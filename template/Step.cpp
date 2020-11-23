#pragma once
#include <vector>
using namespace std;

template <class T> struct Step {
	class It {
		T a, b, c;

	public:
		constexpr It() : a(T()), b(T()), c(T()) {}
		constexpr It(T _b, T _c, T _s) : a(_b), b(_c), c(_s) {}
		constexpr It& operator++() {
			--b;
			a += c;
			return *this;
		}
		constexpr It operator++(int) {
			It tmp = *this;
			--b;
			a += c;
			return tmp;
		}
		constexpr const T& operator*() const {
			return a;
		}
		constexpr const T* operator->() const {
			return &a;
		}
		constexpr bool operator==(const It& i) const {
			return b == i.b;
		}
		constexpr bool operator!=(const It& i) const {
			return !(b == i.b);
		}
		constexpr T start() const {
			return a;
		}
		constexpr T size() const {
			return b;
		}
		constexpr T step() const {
			return c;
		}
	};
	constexpr Step(T b, T c, T s) : be(b, c, s) {}
	constexpr It begin() const {
		return be;
	}
	constexpr It end() const {
		return en;
	}
	constexpr T start() const {
		return be.start();
	}
	constexpr T size() const {
		return be.size();
	}
	constexpr T step() const {
		return be.step();
	}
	constexpr T sum() const {
		return start() * size() + step() * (size() * (size() - 1) / 2);
	}
	operator vector<T>() const {
		return to_a();
	}
	auto to_a() const {
		vector<T> result;
		result.reserve(size());
		for (auto i : *this) {
			result.push_back(i);
		}
		return result;
	}
	using value_type = T;
	using iterator = It;

private:
	It be, en;
};
template <class T> constexpr auto step(T a) {
	return Step<T>(0, a, 1);
}
template <class T> constexpr auto step(T a, T b) {
	return Step<T>(a, b - a, 1);
}
template <class T> constexpr auto step(T a, T b, T c) {
	return Step<T>(a, a < b ? (b - a - 1) / c + 1 : 0, c);
}
