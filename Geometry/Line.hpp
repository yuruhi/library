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
		Line() = default;
		Line(const Vec2& _begin, const Vec2& _end) : LineBase(_begin, _end) {}
		constexpr Line(LD begin_x, LD begin_y, LD end_x, LD end_y) : LineBase(begin_x, begin_y, end_x, end_y) {}
		Line(const LineBase& l) : LineBase(l) {}
		// 交点
		optional<Vec2> intersection(const Line& l) const {
			if (is_parallel(l)) {
				return nullopt;
			} else {
				// return begin + vec() * abs((l.end - begin).cross(l.vec()) / vec().cross(l.vec()));
				auto [a, b, c] = abc();
				auto [A, B, C] = l.abc();
				LD d = A * b - a * B;
				return Vec2((B * c - b * C) / d, (a * C - A * c) / d);
			}
		}
		template <class Shape2DType> LD distance(const Shape2DType& shape) const {
			return Geometric::distance(*this, shape);
		}
		template <class Shape2DType> bool intersects(const Shape2DType& shape) const {
			return Geometric::intersect(*this, shape);
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
		Segment() = default;
		Segment(const Vec2& _begin, const Vec2& _end) : LineBase(_begin, _end) {}
		constexpr Segment(LD begin_x, LD begin_y, LD end_x, LD end_y) : LineBase(begin_x, begin_y, end_x, end_y) {}
		Segment(const LineBase& l) : LineBase(l) {}
		// (共通部分を持つか, 交点)
		pair<bool, optional<Vec2>> intersection(const Segment& s) const {
			if (this->intersects(s)) {
				return {true, Line(*this).intersection(s)};
			} else {
				return {false, nullopt};
			}
		}
		template <class Shape2DType> LD distance(const Shape2DType& shape) const {
			return Geometric::distance(*this, shape);
		}
		template <class Shape2DType> bool intersects(const Shape2DType& shape) const {
			return Geometric::intersect(*this, shape);
		}
	};

}  // namespace Geometric
