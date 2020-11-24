#pragma once
#include <vector>
using namespace std;

template <class T> struct Step {
	using value_type = T;

	class iterator {
		value_type a, b, c;

	public:
		constexpr iterator() : a(value_type()), b(value_type()), c(value_type()) {}
		constexpr iterator(value_type _b, value_type _c, value_type _s)
		    : a(_b), b(_c), c(_s) {}
		constexpr iterator& operator++() {
			--b;
			a += c;
			return *this;
		}
		constexpr iterator operator++(int) {
			iterator tmp = *this;
			--b;
			a += c;
			return tmp;
		}
		constexpr const value_type& operator*() const {
			return a;
		}
		constexpr const value_type* operator->() const {
			return &a;
		}
		constexpr bool operator==(const iterator& i) const {
			return b == i.b;
		}
		constexpr bool operator!=(const iterator& i) const {
			return !(b == i.b);
		}
		constexpr value_type start() const {
			return a;
		}
		constexpr value_type size() const {
			return b;
		}
		constexpr value_type step() const {
			return c;
		}
	};
	constexpr Step(value_type b, value_type c, value_type s) : be(b, c, s) {}
	constexpr iterator begin() const {
		return be;
	}
	constexpr iterator end() const {
		return en;
	}
	constexpr value_type start() const {
		return be.start();
	}
	constexpr value_type size() const {
		return be.size();
	}
	constexpr value_type step() const {
		return be.step();
	}
	constexpr value_type sum() const {
		return start() * size() + step() * (size() * (size() - 1) / 2);
	}
	operator vector<value_type>() const {
		return to_a();
	}
	auto to_a() const {
		vector<value_type> result;
		result.reserve(size());
		for (auto i : *this) {
			result.push_back(i);
		}
		return result;
	}

private:
	iterator be, en;
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
