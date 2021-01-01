#pragma once
#include "./../atcoder/segtree.hpp"
#include <algorithm>
#include <limits>

namespace internal {
	template <class S> constexpr S op_max(S x, S y) {
		return std::max(x, y);
	}
	template <class S> constexpr S op_min(S x, S y) {
		return std::min(x, y);
	}
	template <class S> constexpr S op_sum(S x, S y) {
		return x + y;
	}
	template <class S> constexpr S e_min() {
		return std::numeric_limits<S>::min();
	}
	template <class S> constexpr S e_max() {
		return std::numeric_limits<S>::max();
	}
	template <class S> constexpr S e_zero() {
		return static_cast<S>(0);
	}
}  // namespace internal

template <class S>
using RangeMaxQuery = atcoder::segtree<S, internal::op_max<S>, internal::e_min<S>>;
template <class S>
using RangeMinQuery = atcoder::segtree<S, internal::op_min<S>, internal::e_max<S>>;
template <class S>
using RangeSumQuery = atcoder::segtree<S, internal::op_sum<S>, internal::e_zero<S>>;
