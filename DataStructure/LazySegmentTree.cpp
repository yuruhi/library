#pragma once
#include "./../atcoder/lazysegtree.hpp"
#include <algorithm>
#include <limits>

namespace internal {
	template <class T> struct S_sum {
		T value, size;
		S_sum(T v, T s = 1) : value(v), size(s) {}
	};

	template <class S> constexpr S constant_min() {
		return std::numeric_limits<S>::min();
	}
	template <class S> constexpr S constant_max() {
		return std::numeric_limits<S>::max();
	}
	template <class S> constexpr S constant_zero() {
		return static_cast<S>(0);
	}
	template <class T> constexpr S_sum<T> constant_zero_sum() {
		return {0, 0};
	}

	template <class S> constexpr S op_max(S x, S y) {
		return std::max(x, y);
	}
	template <class S> constexpr S op_min(S x, S y) {
		return std::min(x, y);
	}
	template <class T> constexpr S_sum<T> op_sum(S_sum<T> x, S_sum<T> y) {
		return {x.value + y.value, x.size + y.size};
	}

	template <class S, class F> constexpr S mapping_add(F f, S x) {
		return f + x;
	}
	template <class T, class F> constexpr S_sum<T> mapping_add_sum(F f, S_sum<T> x) {
		return {x.value + f * x.size, x.size};
	}
	template <class S, class F> constexpr S mapping_update(F f, S x) {
		return f == constant_max<F>() ? x : f;
	}
	template <class T, class F> constexpr S_sum<T> mapping_update_sum(F f, S_sum<T> x) {
		if (f != constant_max<F>()) x.value = f * x.size;
		return x;
	}

	template <class F> constexpr F composition_add(F f, F g) {
		return f + g;
	}
	template <class F> constexpr F composition_update(F f, F g) {
		return f == constant_max<F>() ? g : f;
	}
}  // namespace internal

using internal::S_sum;

template <class S, class F>
using RangeAddRangeMax =
    atcoder::lazy_segtree<S, internal::op_max<S>, internal::constant_min<S>, F,
                          internal::mapping_add<S, F>, internal::composition_add<F>,
                          internal::constant_zero<F>>;
template <class S, class F>
using RangeAddRangeMin =
    atcoder::lazy_segtree<S, internal::op_min<S>, internal::constant_max<S>, F,
                          internal::mapping_add<S, F>, internal::composition_add<F>,
                          internal::constant_zero<F>>;
template <class T, class F>
using RangeAddRangeSum =
    atcoder::lazy_segtree<internal::S_sum<T>, internal::op_sum<T>,
                          internal::constant_zero_sum<T>, F, internal::mapping_add_sum<T, F>,
                          internal::composition_add<F>, internal::constant_zero<F>>;
template <class S, class F>
using RangeUpdateRangeMax =
    atcoder::lazy_segtree<S, internal::op_max<S>, internal::constant_min<S>, F,
                          internal::mapping_update<S, F>, internal::composition_update<F>,
                          internal::constant_max<F>>;
template <class S, class F>
using RangeUpdateRangeMin =
    atcoder::lazy_segtree<S, internal::op_min<S>, internal::constant_max<S>, F,
                          internal::mapping_update<S, F>, internal::composition_update<F>,
                          internal::constant_max<F>>;
template <class T, class F>
using RangeUpdateRangeSum =
    atcoder::lazy_segtree<internal::S_sum<T>, internal::op_sum<T>,
                          internal::constant_zero_sum<T>, F,
                          internal::mapping_update_sum<T, F>, internal::composition_update<F>,
                          internal::constant_max<F>>;
