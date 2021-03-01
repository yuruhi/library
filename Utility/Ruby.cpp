#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <numeric>
#include <cassert>
using namespace std;

template <class F> struct Callable {
	F func;
	Callable(const F& f) : func(f) {}
};
template <class T, class F> auto operator|(const T& v, const Callable<F>& c) {
	return c.func(v);
}

struct Sort_impl {
	template <class F> auto operator()(F&& f) {
		return Callable([&](auto v) {
			sort(begin(v), end(v), f);
			return v;
		});
	}
	template <class T> friend auto operator|(T v, [[maybe_unused]] const Sort_impl& c) {
		sort(begin(v), end(v));
		return v;
	}
} Sort;
struct SortBy_impl {
	template <class F> auto operator()(F&& f) {
		return Callable([&](auto v) {
			sort(begin(v), end(v), [&](const auto& i, const auto& j) { return f(i) < f(j); });
			return v;
		});
	}
} SortBy;
struct RSort_impl {
	template <class F> auto operator()(F&& f) {
		return Callable([&](auto v) {
			sort(rbegin(v), rend(v), f);
			return v;
		});
	}
	template <class T> friend auto operator|(T v, [[maybe_unused]] const RSort_impl& c) {
		sort(rbegin(v), rend(v));
		return v;
	}
} RSort;
struct RSortBy_impl {
	template <class F> auto operator()(F&& f) {
		return Callable([&](auto v) {
			sort(begin(v), end(v), [&](const auto& i, const auto& j) { return f(i) > f(j); });
			return v;
		});
	}
} RSortBy;
struct Reverse_impl {
	template <class T> friend auto operator|(T v, const Reverse_impl& c) {
		reverse(begin(v), end(v));
		return v;
	}
} Reverse;
struct Unique_impl {
	template <class T> friend auto operator|(T v, const Unique_impl& c) {
		v.erase(unique(begin(v), end(v), end(v)));
		return v;
	}
} Unique;
struct Uniq_impl {
	template <class T> friend auto operator|(T v, const Uniq_impl& c) {
		sort(begin(v), end(v));
		v.erase(unique(begin(v), end(v)), end(v));
		return v;
	}
} Uniq;
struct Rotate_impl {
	auto operator()(int&& left) {
		return Callable([&](auto v) {
			int s = static_cast<int>(size(v));
			assert(-s <= left && left <= s);
			if (0 <= left) {
				rotate(begin(v), begin(v) + left, end(v));
			} else {
				rotate(begin(v), end(v) + left, end(v));
			}
			return v;
		});
	}
} Rotate;
struct Max_impl {
	template <class F> auto operator()(F&& f) {
		return Callable([&](auto v) { return *max_element(begin(v), end(v), f); });
	}
	template <class T> friend auto operator|(T v, const Max_impl& c) {
		return *max_element(begin(v), end(v));
	}
} Max;
struct Min_impl {
	template <class F> auto operator()(F&& f) {
		return Callable([&](auto v) { return *min_element(begin(v), end(v), f); });
	}
	template <class T> friend auto operator|(T v, const Min_impl& c) {
		return *min_element(begin(v), end(v));
	}
} Min;
struct MaxPos_impl {
	template <class T> friend auto operator|(T v, const MaxPos_impl& c) {
		return max_element(begin(v), end(v)) - begin(v);
	}
} MaxPos;
struct MinPos_impl {
	template <class T> friend auto operator|(T v, const MinPos_impl& c) {
		return min_element(begin(v), end(v)) - begin(v);
	}
} MinPos;
struct MaxBy_impl {
	template <class F> auto operator()(F&& f) {
		return Callable([&](auto v) {
			auto max_it = begin(v);
			auto max_val = f(*max_it);
			for (auto it = next(begin(v)); it != end(v); ++it) {
				if (auto val = f(*it); max_val < val) {
					max_it = it;
					max_val = val;
				}
			}
			return *max_it;
		});
	}
} MaxBy;
struct MinBy_impl {
	template <class F> auto operator()(F&& f) {
		return Callable([&](auto v) {
			auto min_it = begin(v);
			auto min_val = f(*min_it);
			for (auto it = next(begin(v)); it != end(v); ++it) {
				if (auto val = f(*it); min_val > val) {
					min_it = it;
					min_val = val;
				}
			}
			return *min_it;
		});
	}
} MinBy;
struct MaxOf_impl {
	template <class F> auto operator()(F&& f) {
		return Callable([&](auto v) {
			auto max_val = f(*begin(v));
			for (auto it = next(begin(v)); it != end(v); ++it) {
				if (auto val = f(*it); max_val < val) {
					max_val = val;
				}
			}
			return max_val;
		});
	}
} MaxOf;
struct MinOf_impl {
	template <class F> auto operator()(F&& f) {
		return Callable([&](auto v) {
			auto min_val = f(*begin(v));
			for (auto it = next(begin(v)); it != end(v); ++it) {
				if (auto val = f(*it); min_val > val) {
					min_val = val;
				}
			}
			return min_val;
		});
	}
} MinOf;
struct Count_impl {
	template <class V> auto operator()(const V& val) {
		return Callable([&](auto v) { return count(begin(v), end(v), val); });
	}
} Count;
struct CountIf_impl {
	template <class F> auto operator()(const F& f) {
		return Callable([&](auto v) { return count_if(begin(v), end(v), f); });
	}
} CountIf;
struct Index_impl {
	template <class V> auto operator()(const V& val) {
		return Callable([&](auto v) -> optional<int> {
			auto result = find(begin(v), end(v), val);
			return result != end(v) ? optional(result - begin(v)) : nullopt;
		});
	}
	template <class V> auto operator()(const V& val, size_t i) {
		return Callable([&](auto v) -> optional<int> {
			auto result = find(next(begin(v), i), end(v), val);
			return result != end(v) ? optional(result - begin(v)) : nullopt;
		});
	}
} Index;
struct IndexIf_impl {
	template <class F> auto operator()(const F& f) {
		return Callable([&](auto v) -> optional<int> {
			auto result = find_if(begin(v), end(v), f);
			return result != end(v) ? optional(result - begin(v)) : nullopt;
		});
	}
} IndexIf;
struct FindIf_impl {
	template <class F> auto operator()(const F& f) {
		return Callable([&](auto v) -> optional<typename decltype(v)::value_type> {
			auto result = find_if(begin(v), end(v), f);
			return result != end(v) ? optional(*result) : nullopt;
		});
	}
} FindIf;
struct Sum_impl {
	template <class F> auto operator()(F&& f) {
		return Callable([&](auto v) {
			return accumulate(next(begin(v)), end(v), f(*begin(v)),
			                  [&](const auto& a, const auto& b) { return a + f(b); });
		});
	}
	template <class T> friend auto operator|(T v, [[maybe_unused]] const Sum_impl& c) {
		return accumulate(begin(v), end(v), typename T::value_type{});
	}
} Sum;
struct Includes {
	template <class V> auto operator()(const V& val) {
		return Callable([&](auto v) { return find(begin(v), end(v), val) != end(v); });
	}
} Includes;
struct IncludesIf_impl {
	template <class F> auto operator()(const F& f) {
		return Callable([&](auto v) { return find_if(begin(v), end(v), f) != end(v); });
	}
} IncludesIf;
struct RemoveIf_impl {
	template <class F> auto operator()(const F& f) {
		return Callable([&](auto v) {
			v.erase(remove_if(begin(v), end(v), f), end(v));
			return v;
		});
	}
} RemoveIf;
struct Each_impl {
	template <class F> auto operator()(F&& f) {
		return Callable([&](auto v) {
			for (const auto& i : v) {
				f(i);
			}
		});
	}
} Each;
struct EachConsPair_impl {
	template <class T, class value_type = typename T::value_type>
	friend auto operator|(const T& v, EachConsPair_impl& c) {
		vector<pair<value_type, value_type>> result;
		if (size(v) >= 2) {
			result.reserve(size(v) - 1);
			for (size_t i = 0; i < size(v) - 1; ++i) {
				result.emplace_back(v[i], v[i + 1]);
			}
		}
		return result;
	}
} EachConsPair;
struct Select_impl {
	template <class F> auto operator()(F&& f) {
		return Callable([&](auto v) {
			using value_type = typename decltype(v)::value_type;
			vector<value_type> result;
			for (const auto& i : v) {
				if (f(i)) result.push_back(i);
			}
			return result;
		});
	}
} Select;
struct Map_impl {
	template <class F> auto operator()(F&& f) {
		return Callable([&](auto v) {
			using result_type = invoke_result_t<F, typename decltype(v)::value_type>;
			vector<result_type> result;
			result.reserve(size(v));
			for (const auto& i : v) {
				result.push_back(f(i));
			}
			return result;
		});
	}
} Map;
struct Indexed_impl {
	template <class T> friend auto operator|(const T& v, Indexed_impl& c) {
		using value_type = typename T::value_type;
		vector<pair<value_type, int>> result;
		result.reserve(size(v));
		int index = 0;
		for (const auto& i : v) {
			result.emplace_back(i, index++);
		}
		return result;
	}
} Indexed;
struct AllOf_impl {
	template <class F> auto operator()(F&& f) {
		return Callable([&](auto v) {
			for (const auto& i : v) {
				if (!f(i)) return false;
			}
			return true;
		});
	}
} AllOf;
struct AnyOf_impl {
	template <class F> auto operator()(F&& f) {
		return Callable([&](auto v) {
			for (const auto& i : v) {
				if (f(i)) return true;
			}
			return false;
		});
	}
} AnyOf;
struct NoneOf_impl {
	template <class F> auto operator()(F&& f) {
		return Callable([&](auto v) {
			for (const auto& i : v) {
				if (f(i)) return false;
			}
			return true;
		});
	}
} NoneOf;

struct Tally_impl {
	auto operator()(size_t max_val) {
		return Callable([&](auto v) {
			vector<size_t> result(max_val);
			for (const auto& i : v) {
				result[static_cast<size_t>(i)]++;
			}
			return result;
		});
	}
	template <class T, class value_type = typename T::value_type>
	friend auto operator|(const T& v, Tally_impl& c) {
		map<value_type, size_t> result;
		for (const auto& i : v) {
			result[i]++;
		}
		return result;
	}
} Tally;

template <class T> auto operator*(const vector<T>& a, size_t n) {
	T result;
	for (size_t i = 0; i < n; ++i) {
		result.insert(result.end(), a.begin(), a.end());
	}
	return result;
}
auto operator*(string a, size_t n) {
	string result;
	for (size_t i = 0; i < n; ++i) {
		result += a;
	}
	return result;
}
template <class T, class U> auto& operator<<(vector<T>& a, const U& b) {
	a.insert(a.end(), all(b));
	return a;
}
template <class T> auto& operator<<(string& a, const T& b) {
	a.insert(a.end(), all(b));
	return a;
}
template <class T, class U> auto operator+(vector<T> a, const U& b) {
	a << b;
	return a;
}
template <class T> auto operator+(string a, const T& b) {
	a << b;
	return a;
}
