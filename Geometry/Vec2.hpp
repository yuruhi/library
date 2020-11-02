#pragma once
#include "./Geometric.hpp"
#include <iostream>
#include <cmath>

namespace Geometric {

	struct Vec2 {
		LD x, y;
		static bool compare_x(const Vec2& v1, const Vec2& v2) {
			return v1.x < v2.x;
		}
		static bool compare_y(const Vec2& v1, const Vec2& v2) {
			return v1.y < v2.y;
		}
		static bool compare_xy(const Vec2& v1, const Vec2& v2) {
			return make_pair(v1.x, v1.y) < make_pair(v2.x, v2.y);
		}
		static bool compare_yx(const Vec2& v1, const Vec2& v2) {
			return make_pair(v1.y, v1.x) < make_pair(v2.y, v2.x);
		}
		constexpr Vec2() : x(0), y(0) {}
		constexpr Vec2(LD _x, LD _y) : x(_x), y(_y) {}
		Vec2(LD rad) : x(cos(rad)), y(sin(rad)) {}
		constexpr bool operator==(const Vec2& v) const {
			return Equal(x, v.x) && Equal(y, v.y);
		}
		constexpr bool operator!=(const Vec2& v) const {
			return !(*this == v);
		}
		constexpr bool operator<(const Vec2& v) const {
			return x < v.x - EPS && y < v.y - EPS;
		}
		constexpr bool operator<=(const Vec2& v) const {
			return x < v.x + EPS && y < v.y + EPS;
		}
		constexpr Vec2 operator+() const {
			return *this;
		}
		constexpr Vec2 operator-() const {
			return {-x, -y};
		}
		constexpr Vec2 operator+(const Vec2& v) const {
			return Vec2(*this) += v;
		}
		constexpr Vec2 operator-(const Vec2& v) const {
			return Vec2(*this) -= v;
		}
		constexpr Vec2 operator*(const Vec2& v) const {
			return Vec2(*this) *= v;
		}
		constexpr Vec2 operator/(const Vec2& v) const {
			return Vec2(*this) /= v;
		}
		constexpr Vec2 operator+(LD n) const {
			return Vec2(*this) += Vec2(n, n);
		}
		constexpr Vec2 operator-(LD n) const {
			return Vec2(*this) -= Vec2(n, n);
		}
		constexpr Vec2 operator*(LD n) const {
			return Vec2(*this) *= Vec2(n, n);
		}
		constexpr Vec2 operator/(LD n) const {
			return Vec2(*this) /= Vec2(n, n);
		}
		constexpr Vec2& operator+=(const Vec2& v) {
			x += v.x;
			y += v.y;
			return *this;
		}
		constexpr Vec2& operator-=(const Vec2& v) {
			x -= v.x;
			y -= v.y;
			return *this;
		}
		constexpr Vec2& operator*=(const Vec2& v) {
			x *= v.x;
			y *= v.y;
			return *this;
		}
		constexpr Vec2& operator/=(const Vec2& v) {
			x /= v.x;
			y /= v.y;
			return *this;
		}
		constexpr Vec2& operator+=(LD n) {
			x += n;
			x += n;
			return *this;
		}
		constexpr Vec2& operator-=(LD n) {
			x -= n;
			x -= n;
			return *this;
		}
		constexpr Vec2& operator*=(LD n) {
			x *= n;
			x *= n;
			return *this;
		}
		constexpr Vec2& operator/=(LD n) {
			x /= n;
			x /= n;
			return *this;
		}
		constexpr LD operator[](size_t i) const {
			return i == 0 ? x : i == 1 ? y : 0;
		}
		LD manhattan(const Vec2& v) const {
			return std::abs(x - v.x) + std::abs(y - v.y);
		}
		template <class Shape2DType> LD distance(const Shape2DType& shape) const {
			return Geometric::distance(*this, shape);
		}
		template <class Shape2DType> bool intersects(const Shape2DType& shape) const {
			return Geometric::intersect(*this, shape);
		}
		constexpr LD length_square() const {
			return dot(*this);
		}
		LD length() const {
			return sqrt(length_square());
		}
		// 内積
		constexpr LD dot(const Vec2& v) const {
			return x * v.x + y * v.y;
		}
		// 外積
		constexpr LD cross(const Vec2& v) const {
			return x * v.y - y * v.x;
		}
		// 正規化（長さを1にした）ベクトル
		Vec2 normalized() const {
			return *this / length();
		}
		// 原点中心に rad 回転した座標
		Vec2 rotation(LD rad) const {
			LD c = cos(rad), s = sin(rad);
			return {x * c - y * s, x * s + y * c};
		}
		// 原点中心の円上に乗っているとしたときの偏角
		LD angle() const {
			return atan2(y, x);
		}
		// 正射影
		Vec2 projection(const Line& l) const;
		// 鏡映変換
		Vec2 reflection(const Line& l) const;
		constexpr Vec2 rotate90() const {
			return {y, -x};
		}
		constexpr Vec2 rotate180() const {
			return {-x, -y};
		}
		constexpr Vec2 rotate270() const {
			return {-y, x};
		}
		friend ostream& operator<<(ostream& os, const Vec2& v) {
			return os << '(' << v.x << ", " << v.y << ')';
		}
		friend istream& operator>>(istream& is, Vec2& v) {
			return is >> v.x >> v.y;
		}
	};

}  // namespace Geometric
