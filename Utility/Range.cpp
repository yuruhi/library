// shortcut : Range
// description : Range
struct Range {
	using T = long long;
	static constexpr Range nil() { return { numeric_limits<T>::min(),numeric_limits<T>::min() }; }
	T x, y; // [x, y]
	constexpr Range() :x(0), y(0) {}
	constexpr Range(T _x, T _y, bool exclude_end = false) : x(_x), y(_y - exclude_end) { assert(x <= y); }
	constexpr Range(const Range& _r, bool exclude_end = false) : x(_r.x), y(_r.y - exclude_end) { assert(x <= y); }
	constexpr operator bool()const { return *this != nil(); }
	constexpr pair<T, T> to_pair()const { return make_pair(x, y); }
	constexpr bool operator==(const Range& r)const { return x == r.x && y == r.y; }
	constexpr bool operator!=(const Range& r)const { return x != r.x || y != r.y; }
	constexpr bool operator<(const Range& r)const { return to_pair() < r.to_pair(); }
	constexpr bool operator<=(const Range& r)const { return to_pair() <= r.to_pair(); }
	constexpr bool operator>(const Range& r)const { return to_pair() > r.to_pair(); }
	constexpr bool operator>=(const Range& r)const { return to_pair() >= r.to_pair(); }
	constexpr Range& operator<<=(T n) { x -= n; y -= n; return *this; }
	constexpr Range& operator>>=(T n) { x += n; y += n; return *this; }
	constexpr Range& operator*=(T n) { x *= n; y *= n; return *this; }
	constexpr Range operator<<(T n)const { return Range(*this) <<= n; }
	constexpr Range operator>>(T n)const { return Range(*this) >>= n; }
	constexpr Range operator*(T n)const { return Range(*this) *= n; }
	constexpr Range& operator&=(const Range& r) {
		if (intersects(r)) { x = std::max(x, r.x); y = std::min(y, r.y); } else { *this = nil(); } return *this;
	}
	constexpr Range& operator|=(const Range& r) {
		if (intersects(r) || adjacent(r)) { x = std::min(x, r.x); y = std::max(y, r.y); } else { *this = nil(); } return *this;
	}
	constexpr Range operator&(const Range& r)const { return Range(*this) &= r; }
	constexpr Range operator|(const Range& r)const { return Range(*this) |= r; }
	constexpr bool include(T n)const { return x <= n && n <= y; }
	constexpr bool intersects(const Range& r)const { return std::max(x, r.x) <= std::min(y, r.y); }
	constexpr bool contains(const Range& r)const { return x <= r.x && r.y <= y; }
	constexpr bool adjacent(const Range& r)const { return y + 1 == r.x || r.y + 1 == x; }
	constexpr T size()const { return *this ? max<T>(0, y - x + 1) : 0; }
	constexpr T sum()const { return (x + y) * size() / 2; }
	friend ostream& operator<<(ostream& os, const Range& r) {
		return (r == Range::nil()) ? (os << "[nil]") : (os << '[' << r.x << ", " << r.y << ']');
	}
	friend istream& operator>>(istream& is, Range& r) { return is >> r.x >> r.y; }
};
template<class T>constexpr Range equal_range(const T& a, const Range& r) {
	auto L = lower_bound(a.begin(), a.end(), r.x) - a.begin(), R = upper_bound(a.begin(), a.end(), r.y) - a.begin();
	return L == R ? Range::nil() : Range(L, R, true);
}