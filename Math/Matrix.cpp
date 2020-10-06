#pragma once
#include <vector>
#include <cassert>
using namespace std;

template <class T> struct Matrix {
	size_t h, w;
	vector<vector<T>> A;

public:
	static Matrix I(size_t n) {
		Matrix A(n);
		for (size_t i = 0; i < n; ++i) {
			A[i][i] = 1;
		}
		return A;
	}
	Matrix() {}
	Matrix(size_t _h, size_t _w) : h(_h), w(_w), A(h, vector<T>(w, 0)) {}
	Matrix(size_t _h) : h(_h), w(_h), A(h, vector<T>(w, 0)){};
	Matrix(const vector<vector<T>>& _A) : h(_A.size()), w(_A[0].size()), A(_A) {}
	size_t height() const {
		return h;
	}
	size_t width() const {
		return w;
	}
	const vector<T>& operator[](int i) const {
		return A[i];
	}
	vector<T>& operator[](int i) {
		return A[i];
	}
	const vector<vector<T>>& operator*() const {
		return A;
	}
	Matrix& operator+=(const Matrix& B) {
		assert(h == B.height() && w == B.width());
		for (size_t i = 0; i < h; ++i) {
			for (size_t j = 0; j < w; ++j) {
				A[i][j] += B[i][j];
			}
		}
		return *this;
	}
	Matrix& operator-=(const Matrix& B) {
		assert(h == B.height() && w == B.width());
		for (size_t i = 0; i < h; ++i) {
			for (size_t j = 0; j < w; ++j) {
				A[i][j] -= B[i][j];
			}
		}
		return *this;
	}
	Matrix& operator*=(const Matrix& B) {
		size_t n = B.width();
		assert(w == B.height());
		vector<vector<T>> C(h, vector<T>(n, 0));
		for (size_t i = 0; i < h; i++) {
			for (size_t j = 0; j < n; j++) {
				for (size_t k = 0; k < w; k++) {
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		A.swap(C);
		return *this;
	}
	Matrix& operator^=(long long k) {
		Matrix B = Matrix::I(h);
		while (k > 0) {
			if (k & 1) {
				B *= *this;
			}
			*this *= *this;
			k >>= 1;
		}
		A.swap(B.A);
		return *this;
	}
	Matrix operator+(const Matrix& B) const {
		return Matrix(*this) += B;
	}
	Matrix operator-(const Matrix& B) const {
		return Matrix(*this) -= B;
	}
	Matrix operator*(const Matrix& B) const {
		return Matrix(*this) *= B;
	}
	Matrix operator^(const long long k) const {
		return Matrix(*this) ^= k;
	}
	Matrix pow(long long k) const {
		return *this ^ k;
	}
};