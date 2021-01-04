#pragma once
#include "./Geometric.hpp"
#include "./Vec2.hpp"
#include <iostream>
#include <utility>
#include <tuple>
#include <optional>
#include <cmath>
using namespace std;

namespace Geometric {

	namespace internal {
		struct LineBase {
		protected:
			constexpr LineBase() = default;
			constexpr LineBase(const Vec2& _begin, const Vec2& _end) : begin(_begin), end(_end) {}
			constexpr LineBase(LD begin_x, LD begin_y, LD end_x, LD end_y)
			    : begin(begin_x, begin_y), end(end_x, end_y) {}

		public:
			Vec2 begin, end;
			constexpr LineBase operator+(const Vec2& v) {
				return LineBase(*this) += v;
			}
			constexpr LineBase operator-(const Vec2& v) {
				return LineBase(*this) -= v;
			}
			constexpr LineBase& operator+=(const Vec2& v) {
				begin += v;
				end += v;
				return *this;
			}
			constexpr LineBase& operator-=(const Vec2& v) {
				begin -= v;
				end -= v;
				return *this;
			}
			constexpr Vec2 vec() const {
				return end - begin;
			}
			constexpr Vec2 counter_vec() const {
				return begin - end;
			}
			// 平行判定
			constexpr bool is_parallel(const LineBase& l) const {
				return sgn(vec().cross(l.vec())) == 0;
			}
			// 直交判定
			constexpr bool is_orthogonal(const LineBase& l) const {
				return sgn(vec().dot(l.vec())) == 0;
			}
			friend ostream& operator<<(ostream& os, const LineBase& l) {
				return os << '(' << l.begin << ", " << l.end << ')';
			}
			friend istream& operator>>(istream& is, LineBase& l) {
				return is >> l.begin >> l.end;
			}
		};
	}  // namespace internal

	struct Line : internal::LineBase {
		constexpr Line() = default;
		constexpr Line(const Vec2& _begin, const Vec2& _end) : LineBase(_begin, _end) {}
		constexpr Line(LD begin_x, LD begin_y, LD end_x, LD end_y) : LineBase(begin_x, begin_y, end_x, end_y) {}
		constexpr Line(const LineBase& l) : LineBase(l) {}
		template <class Shape2DType> LD distance(const Shape2DType& shape) const {
			return Geometric::distance(*this, shape);
		}
		// ax + by + c = 0 の式に変形する
		tuple<LD, LD, LD> abc() const {
			if (sgn(begin.x - end.x) == 0) {
				return {1, 0, -begin.x};
			} else {
				LD slope = (end.y - begin.y) / (end.x - begin.x);
				return {slope, -1, begin.y - begin.x * slope};
			}
		}
	};

	struct Segment : internal::LineBase {
		constexpr Segment() = default;
		constexpr Segment(const Vec2& _begin, const Vec2& _end) : LineBase(_begin, _end) {}
		constexpr Segment(LD begin_x, LD begin_y, LD end_x, LD end_y) : LineBase(begin_x, begin_y, end_x, end_y) {}
		constexpr Segment(const LineBase& l) : LineBase(l) {}
		template <class Shape2DType> LD distance(const Shape2DType& shape) const {
			return Geometric::distance(*this, shape);
		}
	};

}  // namespace Geometric
