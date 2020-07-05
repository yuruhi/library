// description : pair
template <class T> struct Pair {
	T x, y;
	constexpr Pair() : x(), y() {}
	constexpr Pair(T _x, T _y) : x(_x), y(_y) {}
	constexpr Pair(const pair<T, T> &xy) : x(xy.first), y(xy.second) {}
	constexpr Pair operator+() const {
		return *this;
	}
	constexpr Pair operator-() const {
		return {-x, -y};
	}
	constexpr Pair operator+(const Pair &p) const {
		return Pair(*this) += p;
	}
	constexpr Pair operator-(const Pair &p) const {
		return Pair(*this) -= p;
	}
	constexpr Pair operator*(const Pair &p) const {
		return Pair(*this) *= p;
	}
	constexpr Pair operator/(const Pair &p) const {
		return Pair(*this) /= p;
	}
	constexpr Pair operator%(const Pair &p) const {
		return Pair(*this) %= p;
	}
	constexpr Pair operator+(T n) const {
		return Pair(*this) += n;
	}
	constexpr Pair operator-(T n) const {
		return Pair(*this) -= n;
	}
	constexpr Pair operator*(T n) const {
		return Pair(*this) *= n;
	}
	constexpr Pair operator/(T n) const {
		return Pair(*this) /= n;
	}
	constexpr Pair operator%(T n) const {
		return Pair(*this) %= n;
	}
	constexpr Pair &operator+=(const Pair &p) {
		x += p.x;
		y += p.y;
		return *this;
	}
	constexpr Pair &operator-=(const Pair &p) {
		x -= p.x;
		y -= p.y;
		return *this;
	}
	constexpr Pair &operator*=(const Pair &p) {
		x *= p.x;
		y *= p.y;
		return *this;
	}
	constexpr Pair &operator/=(const Pair &p) {
		x /= p.x;
		y /= p.y;
		return *this;
	}
	constexpr Pair &operator%=(const Pair &p) {
		x %= p.x;
		y %= p.y;
		return *this;
	}
	constexpr Pair &operator+=(T n) {
		x += n;
		y += n;
		return *this;
	}
	constexpr Pair &operator-=(T n) {
		x -= n;
		y -= n;
		return *this;
	}
	constexpr Pair &operator*=(T n) {
		x *= n;
		y *= n;
		return *this;
	}
	constexpr Pair &operator/=(T n) {
		x /= n;
		y /= n;
		return *this;
	}
	constexpr Pair &operator%=(T n) {
		x %= n;
		y %= n;
		return *this;
	}
	constexpr bool operator==(const Pair &p) const {
		return x == p.x && y == p.y;
	}
	constexpr bool operator!=(const Pair &p) const {
		return x != p.x || y != p.y;
	}
	constexpr bool operator<(const Pair &p) const {
		return x < p.x || (!(p.x < x) && y < p.y);
	}
	constexpr bool operator>(const Pair &p) const {
		return p < *this;
	}
	constexpr bool operator<=(const Pair &p) const {
		return !(p < *this);
	}
	constexpr bool operator>=(const Pair &p) const {
		return !(*this < p);
	}
	constexpr int operator[](int i) const {
		return i == 0 ? x : i == 1 ? y : 0;
	}
	constexpr pair<T, T> to_pair() const {
		return {x, y};
	}
	constexpr Pair yx() const {
		return {y, x};
	}
	constexpr operator tuple<T &, T &>() {
		return tuple<T &, T &>(x, y);
	}
	static constexpr bool cmp_y(const Pair<T> &p1, const Pair<T> &p2) {
		return p1.yx() < p2.yx();
	}
	static constexpr T get_x(const Pair<T> &p) {
		return p.x;
	}
	static constexpr T get_y(const Pair<T> &p) {
		return p.y;
	}
	friend ostream &operator<<(ostream &os, const Pair &p) {
		return os << p.x << ' ' << p.y;
	}
	friend istream &operator>>(istream &is, Pair &p) {
		return is >> p.x >> p.y;
	}
};
namespace std {
	template <class T> struct tuple_size<Pair<T>> : integral_constant<size_t, 2> {};
	template <size_t N, class T> struct tuple_element<N, Pair<T>> { using type = T; };
}  // namespace std
template <size_t N, class T> T get(const Pair<T> &p) {
	return N == 0 ? p.x : p.y;
}