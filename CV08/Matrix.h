#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <iostream>

template<typename T>
class Matrix {
public:
	Matrix(int rows, int cols);
	Matrix(const Matrix<T>& m);
	~Matrix();

	void set(int row, int col, T value);
	void setFromArray(T* arr);
	T& get(int row, int col);
	const T& get(int row, int col) const;
	Matrix<T> transposition() const;
	Matrix<T> product(const Matrix& m) const;
	Matrix<T> product(T scalar) const;
	Matrix<T> total(const Matrix& m) const;
	Matrix<T> total(T skalar) const;
	bool compare(const Matrix& m) const;
	void print() const;

	template<typename R>
	Matrix<R> castTo() const;
private:
	T** matrix;
	int rows;
	int cols;
};

template<typename T>
Matrix<T>::Matrix(int aRows, int aCols) {
	if (aRows < 1 || aCols < 1) {
		throw std::invalid_argument("Index out of bounds.");
	}
	matrix = new T * [aRows];
	for (int i = 0; i < aRows; i++) {
		matrix[i] = new T[aCols];
	}
	this->rows = rows;
	this->cols = cols;
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& m) {
	rows = m.rows;
	cols = m.cols;

	matrix = new T * [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new T[cols];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			set(i, j, m.get(i, j));
		}
	}
}

template<typename T>
Matrix<T>::~Matrix() {
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

template<typename T>
void Matrix<T>::set(int aRow, int aCol, T value) {
	if (aRow > rows || aCol > cols || aRow < 0 || aCol < 0) {
		throw std::invalid_argument("Index out of bounds.");
	}
	matrix[aRow][aCol] = value;
}

template<typename T>
void Matrix<T>::setFromArray(T* arr) {
	int index = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = arr[index++];
		}
	}
}

template<typename T>
T& Matrix<T>::get(int aRow, int aCol) {
	if (aRow > rows || aCol > cols || aRow < 0 || aCol < 0) {
		throw std::invalid_argument("Index out of bounds.");
	}
	return matrix[aRow][aCol];
}

template<typename T>
const T& Matrix<T>::get(int aRow, int aCol) const {
	if (aRow > rows || aCol > cols || aRow < 0 || aCol < 0) {
		throw std::invalid_argument("Index out of bounds.");
	}
	return matrix[aRow][aCol];
}

template<typename T>
Matrix<T> Matrix<T>::transposition() const {
	if (rows != cols) {
		throw std::runtime_error("Rows and columns are not identical.");
	}

	Matrix<T>* tMatrix = new Matrix<T>(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			tMatrix->set(j, i, matrix[i][j]);
		}
	}
	return *tMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::product(const Matrix& m) const {
	if (cols != m.rows) {
		throw std::runtime_error("Rows and columns are not identical.");
	}

	Matrix* temp = new Matrix<T>(rows, m.cols);
	for (int i = 0; i < temp->rows; i++) {
		for (int j = 0; j < temp->cols; j++) {
			temp->set(i, j, matrix[i][j] * m.get(i, j));
		}
	}
	return *temp;
}

template<typename T>
Matrix<T> Matrix<T>::product(T scalar) const {
	Matrix temp(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; i < cols; i++) {
			temp[i][j] = matrix[i][j] * scalar;
		}
	}
	return temp;
}

template<typename T>
Matrix<T> Matrix<T>::total(const Matrix& m) const {
	if (m.cols != cols && m.rows != rows) {
		throw std::runtime_error("Rows and columns are not identical.");
	}

	Matrix temp = new Matrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; i < cols; i++) {
			temp.set(i, j, matrix[i][j] + m.get(i, j));
		}
	}
	return temp;
}

template<typename T>
Matrix<T> Matrix<T>::total(T skalar) const {
	Matrix temp(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; i < cols; i++) {
			temp[i][j] = matrix[i][j] + skalar;
		}
	}
	return temp;
}

template<typename T>
bool Matrix<T>::compare(const Matrix& m) const {
	if (m.cols != cols && m.rows != rows) {
		return false;
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; i < cols; i++) {
			if (matrix[i][j] != m.get(i, j)) {
				return false;
			}
		}
	}
	return true;
}

template<typename T>
void Matrix<T>::print() const {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; i < cols; i++) {
			std::cout << std::to_string(matrix[i][j]);
		}
	}
}

template<typename T>
template<typename R>
Matrix<R> Matrix<T>::castTo() const {
	Matrix<R>* newMatrix = new Matrix<R>(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			newMatrix->set(i, j, static_cast<R>(matrix[i][j]));
		}
	}
	return *newMatrix;
}

#endif // MATRIX_H