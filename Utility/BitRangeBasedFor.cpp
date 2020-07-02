// shortcut : BitRangeBasedFor
// description : 部分集合, サイズkの部分集合を列挙
class bit_subset {
	struct it {
		long long sub, s;
		bool f = false;
		it(long long x) : sub(x), s(x) {}
		long long operator*() const {
			return sub;
		}
		void operator++() {
			sub = (sub - 1) & s;
			f |= sub == s;
		}
		bool operator!=(const it &i) const {
			return !f;
		}
	} b, e;

public:
	bit_subset(long long s) : b(s), e(s) {}
	it begin() const {
		return b;
	}
	it end() const {
		return e;
	}
};
class bit_comb {
	struct it {
		long long s;
		it(long long x) : s(x) {}
		long long operator*() const {
			return s;
		}
		void operator++() {
			long long x = s & -s, y = s + x;
			s = ((s & ~y) / x >> 1) | y;
		}
		bool operator!=(const it &i) const {
			return s < i.s;
		}
	} b, e;

public:
	bit_comb(int k, int n) : b((1LL << k) - 1), e(1LL << n) {}
	it begin() const {
		return b;
	}
	it end() const {
		return e;
	}
};