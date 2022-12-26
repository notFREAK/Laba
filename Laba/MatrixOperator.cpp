#include "Header.h"

Matrix Matrix::operator+(const Matrix& B)
{
	if (order == 0) {
		throw MyException("Operation with empty matrix");
	}
	if (B.order == order)
	{
		throw MyException("matrix with different sizes");
	}
	try {
		int** newMatrix = new int* [order];
		for (int i = 0; i < order; i++)
			{
				newMatrix[i] = new int[order];
				for (int j = 0; j < order; j++)
				{
					newMatrix[i][j] = matrix[i][j] + B.matrix[i][j];
				}
			}
		return Matrix(order, newMatrix);
	}
	catch (...) {
		throw MyException("out of memory");
	}
}

Matrix::operator int** ()
{
	try {
		int** newMatrix = new int* [order];;
		for (int i = 0; i < order; i++)
		{
			newMatrix[i] = new int[order];;
			for (int j = 0; j < order; j++)
			{
				newMatrix[i][j] = matrix[i][j];
			}
		}
		return newMatrix;
	}
	catch (...) {
		throw MyException("out of memory");
	}
}

bool operator<(const Matrix& A, const Matrix& B)
{
	return (A.order < B.order);
}

Matrix operator-(const Matrix& A, const Matrix& B)
{
	if (B.order == A.order)
	{
		throw MyException("matrix with different sizes");
	}
	if (A.order == 0) {
		throw MyException("Operation with empty matrix");
	}
	try {
		int** newMatrix = new int* [A.order];;
		for (int i = 0; i < A.order; i++)
		{
			newMatrix[i] = new int[A.order];;
			for (int j = 0; j < A.order; j++)
			{
				newMatrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
			}
		}
		return Matrix(A.order, newMatrix);
	}
	catch (...) {
		throw MyException("out of memory");
	}
}


Matrix& operator--(Matrix& A)
{
	if (A.order == 0) {
		throw MyException("Operation with empty matrix");
	}
	for (int i = 0; i < A.order; i++)
	{
		for (int j = 0; j < A.order; j++)
		{
			A.matrix[i][j]--;
		}
	}
	return A;
}

Matrix operator--(Matrix& A, int)
{
	if (A.order == 0) {
		throw MyException("Operation with empty matrix");
	}
	Matrix newValue(A);
	--A;
	return newValue;
}

Matrix& operator++(Matrix& A)
{
	if (A.order == 0) {
		throw MyException("Operation with empty matrix");
	}
	for (int i = 0; i < A.order; i++)
	{
		for (int j = 0; j < A.order; j++)
		{
			A.matrix[i][j]++;
		}
	}
	return A;
}

Matrix operator++(Matrix& A, int)
{
	if (A.order == 0) {
		throw MyException("Operation with empty matrix");
	}
	Matrix newValue(A);
	++A;
	return newValue;
}