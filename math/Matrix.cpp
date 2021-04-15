#pragma once
#include <vector>
#include <cassert>

template <class T> struct Matrix {
public:
	using value_type = T;
	using data_type = std::vector<std::vector<value_type>>;

private:
	std::size_t h, w;
	data_type A;

public:
	static Matrix I(std::size_t n) {
		Matrix A(n);
		for (std::size_t i = 0; i < n; ++i) {
			A[i][i] = 1;
		}
		return A;
	}
	Matrix() {}
	Matrix(std::size_t _h, std::size_t _w) : h(_h), w(_w), A(h, std::vector<T>(w, 0)) {}
	Matrix(std::size_t _h) : h(_h), w(_h), A(h, std::vector<T>(w, 0)) {}
	Matrix(const data_type& _A) : h(_A.size()), w(_A[0].size()), A(_A) {}
	std::size_t height() const {
		return h;
	}
	std::size_t width() const {
		return w;
	}
	const data_type& value() const {
		return A;
	}
	const std::vector<T>& operator[](int i) const {
		return A[i];
	}
	std::vector<T>& operator[](int i) {
		return A[i];
	}
	const data_type& operator*() const {
		return A;
	}
	Matrix& operator+=(const Matrix& B) {
		assert(h == B.height() && w == B.width());
		for (std::size_t i = 0; i < h; ++i) {
			for (std::size_t j = 0; j < w; ++j) {
				A[i][j] += B[i][j];
			}
		}
		return *this;
	}
	Matrix& operator-=(const Matrix& B) {
		assert(h == B.height() && w == B.width());
		for (std::size_t i = 0; i < h; ++i) {
			for (std::size_t j = 0; j < w; ++j) {
				A[i][j] -= B[i][j];
			}
		}
		return *this;
	}
	Matrix& operator*=(const Matrix& B) {
		std::size_t n = B.width();
		assert(w == B.height());
		data_type C(h, std::vector<T>(n, 0));
		for (std::size_t i = 0; i < h; i++) {
			for (std::size_t j = 0; j < n; j++) {
				for (std::size_t k = 0; k < w; k++) {
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
