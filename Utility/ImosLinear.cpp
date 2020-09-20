// description : 区間に一次関数を足す
template <class T> class ImosLinear {
	const int N;
	vector<T> X, A, B;
	bool flag = false;

public:
	ImosLinear(int _n) : N(_n), X(_n), A(_n + 1), B(_n + 1) {}
	void add(int l, int r, T a, T b) {  // [l, r) += a + (i - l) * b
		if (l >= r) return;
		assert(!flag);
		l = max(min(l, N), 0);
		r = max(min(r, N), 0);
		A[l] += a - b * l;
		B[l] += b;
		A[r] -= a - b * l;
		B[r] -= b;
	}
	void build() {
		flag = true;
		for (int i = 0; i < N; ++i) {
			X[i] = A[i] + B[i] * i;
			A[i + 1] += A[i];
			B[i + 1] += B[i];
		}
	}
	T operator[](int i) const {
		assert(flag);
		return X[i];
	}
	const vector<T>& operator*() const {
		assert(flag);
		return X;
	}
};