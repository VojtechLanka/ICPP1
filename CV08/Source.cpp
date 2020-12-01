#include "Matrix.h"
#include <iostream>

int main() {
	Matrix<int> matrix{ 2,2 };
	int arr[] = { 1,2,3,4 };
	matrix.setFromArray(arr);
	matrix.print();
	std::cout << "----------------------------------------" << std::endl;

	Matrix<int> tMatrix = matrix.transposition();
	tMatrix.print();
	std::cout << "----------------------------------------" << std::endl;

	Matrix<int> producMatrix = matrix.product(tMatrix);
	producMatrix.print();
	std::cout << "----------------------------------------" << std::endl;

	Matrix<double> matrixDouble = matrix.castTo<double>();
	matrixDouble.print();
	std::cout << "----------------------------------------" << std::endl;

	std::cout << "matrix identicla to tMatrix  = " << matrix.compare(tMatrix) << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	Matrix<int> matrixA{ 2,2 };
	Matrix<int> matrixB{ 2,2 };
	int valueArray[] = { 1,2,3,4 };
	matrixA.setFromArray(valueArray);
	matrixB.setFromArray(valueArray);

	std::cout << "matrixB identicla to matrixB  = " << matrixA.compare(matrixB) << std::endl;
	system("pause");
	return 0;
}