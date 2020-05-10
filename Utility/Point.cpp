// shortcut : Point
// description : Point
struct Point {
	static int H, W;
	static const vector<Point> d;
	static void set_range(int _H, int _W) { H = _H; W = _W; }
	static constexpr Point zero() { return { 0,0 }; }
	static constexpr Point one() { return { 1,1 }; }
	int x, y;
	constexpr Point() :x(0), y(0) {}
	constexpr Point(int _x, int _y) : x(_x), y(_y) {}
	constexpr Point(const pair<int, int>& xy) : x(xy.first), y(xy.second) {}
	Point(int n) :x(n% W), y(n / W) {}
	constexpr Point operator+()const { return *this; }
	constexpr Point operator-()const { return { -x,-y }; }
	constexpr Point operator+(const Point& p)const { return Point(*this) += p; }
	constexpr Point operator-(const Point& p)const { return Point(*this) -= p; }
	constexpr Point operator*(const Point& p)const { return Point(*this) *= p; }
	constexpr Point operator/(const Point& p)const { return Point(*this) /= p; }
	constexpr Point operator%(const Point& p)const { return Point(*this) %= p; }
	constexpr Point operator+(int n)const { return Point(*this) += n; }
	constexpr Point operator-(int n)const { return Point(*this) -= n; }
	constexpr Point operator*(int n)const { return Point(*this) *= n; }
	constexpr Point operator/(int n)const { return Point(*this) /= n; }
	constexpr Point operator%(int n)const { return Point(*this) %= n; }
	constexpr Point& operator+=(const Point& p) { x += p.x; y += p.y; return *this; }
	constexpr Point& operator-=(const Point& p) { x -= p.x; y -= p.y; return *this; }
	constexpr Point& operator*=(const Point& p) { x *= p.x; y *= p.y; return *this; }
	constexpr Point& operator/=(const Point& p) { x /= p.x; y /= p.y; return *this; }
	constexpr Point& operator%=(const Point& p) { x %= p.x; y %= p.y; return *this; }
	constexpr Point& operator+=(int n) { x += n; y += n; return *this; }
	constexpr Point& operator-=(int n) { x -= n; y -= n; return *this; }
	constexpr Point& operator*=(int n) { x *= n; y *= n; return *this; }
	constexpr Point& operator/=(int n) { x /= n; y /= n; return *this; }
	constexpr Point& operator%=(int n) { x %= n; y %= n; return *this; }
	constexpr bool operator==(const Point& p)const { return x == p.x && y == p.y; }
	constexpr bool operator!=(const Point& p)const { return x != p.x || y != p.y; }
	bool operator<(const Point& p)const { return to_i() < p.to_i(); }
	bool operator<=(const Point& p)const { return to_i() <= p.to_i(); }
	bool operator>(const Point& p)const { return to_i() > p.to_i(); }
	bool operator>=(const Point& p)const { return to_i() >= p.to_i(); }
	constexpr int operator[](int i)const { return i == 0 ? x : i == 1 ? y : 0; }
	bool in_range()const { return 0 <= x && x < W && 0 <= y && y < H; }
	int to_i()const { return x + y * W; }
	constexpr pair<int, int> to_pair()const { return { x,y }; }
	int dist(const Point& p)const { return std::abs(x - p.x) + std::abs(y - p.y); }
	Point abs(const Point& p)const { return { std::abs(x - p.x),std::abs(y - p.y) }; }
	Point abs()const { return { std::abs(x), std::abs(y) }; }
	Point& swap() { std::swap(x, y); return *this; }
	vector<Point> adjacent4()const {
		vector<Point> v(4); for (int i = 0; i < 4; ++i)v[i] = *this + d[i]; return v;
	}
	vector<Point> adjacent8()const {
		vector<Point> v(8); for (int i = 0; i < 8; ++i)v[i] = *this + d[i]; return v;
	}
	vector<Point> adj4_in_range()const {
		vector<Point> v; for (const auto& P : adjacent4())if (P.in_range())v.push_back(P); return v;
	}
	vector<Point> adj8_in_range()const {
		vector<Point> v; for (const auto& P : adjacent8())if (P.in_range())v.push_back(P); return v;
	}
	constexpr Point left()const { return { x - 1,y }; }
	constexpr Point right()const { return { x + 1,y }; }
	constexpr Point up()const { return { x,y - 1 }; }
	constexpr Point down()const { return { x,y + 1 }; }
	constexpr Point moved(char c)const { return Point(*this).move(c); }
	constexpr Point& move(char c) {
		switch (c) {
		case 'L':case 'l':case 'W':case '>':x--; break;
		case 'R':case 'r':case 'E':case '<':x++; break;
		case 'U':case 'u':case 'N':case '^':y--; break;
		case 'D':case 'd':case 'S':case 'v':y++; break;
		}
		return *this;
	}
	constexpr Point rotate90() { return { y,-x }; }
	constexpr Point rotate180() { return { -x,-y }; }
	constexpr Point rotate270() { return { -y,x }; }
	friend ostream& operator<<(ostream& os, const Point& p) { return  os << '(' << p.x << ", " << p.y << ')'; }
	friend istream& operator>>(istream& is, Point& p) { return is >> p.x >> p.y; }
};
int Point::H, Point::W;
const vector<Point> Point::d{ {0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1} };