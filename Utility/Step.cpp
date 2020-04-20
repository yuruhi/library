// shortcut : Step
// description : python の range
template<class T>struct Step {
	class It {
		T a, b, c;
	public:
		constexpr It(): a(T()), b(T()), c(T()) {}
		constexpr It(T _b, T _c, T _s): a(_b), b(_c), c(_s) {}
		constexpr It& operator++() { --b; a += c; return *this; }
		constexpr It operator++(int) { It tmp = *this; --b; a += c; return tmp; }
		constexpr const T& operator*()const { return a; }
		constexpr const T* operator->()const { return &a; }
		constexpr bool operator==(const It& other)const { return b == other.b; }
		constexpr bool operator!=(const It& other)const { return !(b == other.b); }
		constexpr T start()const { return a; }
		constexpr T count()const { return b; }
		constexpr T step()const { return c; }
	};
	constexpr Step(T b, T c, T s) : be(b, c, s) {}
	constexpr It begin()const { return be; }
	constexpr It end()const { return en; }
	constexpr T start()const { return be.start(); }
	constexpr T count()const { return be.count(); }
	constexpr T step()const { return be.step(); }
	operator vector<T>()const { return as_vector(); }
	vector<T> as_vector()const {
		vector<T> res; res.reserve(count());
		each([&](T i) {res.push_back(i); });
		return res;
	}
	template<class F>void each(F f)const { for (T i : *this)f(i); }
	template<class F>auto map(F f)const {
		vector<decay_t<result_of_t<F(T)>>> res; res.reserve(count());
		each([&](T i) {res.push_back(f(i)); });
		return res;
	}
	template<class F>int count_if(F f)const {
		int res = 0; each([&](T i) {i += f(i); }); return res;
	}
	template<class F>vector<T> select(F f)const {
		vector<T> res; each([&](T i) {if (f(i))res.push_back(i); }); return res;
	}
	template<class F>auto sum(F f)const {
		decay_t<result_of_t<F(T)>> res = 0; each([&](T i) {res += f(i); }); return res;
	}
	using value_type = T;
	using iterator = It;
private:
	It be, en;
};
template<class T>inline constexpr auto step(T a) { return Step<T>(0, a, 1); }
template<class T>inline constexpr auto step(T a, T b) { return Step<T>(a, b - a, 1); }
template<class T>inline constexpr auto step(T a, T b, T c) { return Step<T>(a, (b - a - 1) / c + 1, c); }