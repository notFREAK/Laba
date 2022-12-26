#include "Header.h"

RectangMatrix::RectangMatrix() : Matrix::Matrix() {
	length = 0;
}

RectangMatrix::RectangMatrix(int order, int length) {
	count++;
	this->order = order;
	this->length = length;
	if (order == 0 || length == 0) {
		throw MyException("filling in an empty matrix");
	}
	try {
	matrix = new int* [order];
	for (int i = 0; i < order; i++) {
		matrix[i] = new int[length];
		for (int j = 0; j < order; j++)
		{
			matrix[i][j] = 0;
		}
	}
	}
	catch (bad_alloc& ex) {
		throw MyException(ex.what());
	}
	catch (...) {
		throw MyException("uncorrent data size in constructor");
	}
}

RectangMatrix::RectangMatrix(int order, int length, int** matrix) {
	if (order == 0 || length == 0) {
		throw MyException("filling in an empty matrix");
	}
	try {
		this->order = order;
		this->length = length;
		this->matrix = new int* [order];
		for (int i = 0; i < order; i++) {
			this->matrix[i] = new int[length];
			for (int j = 0; j < length; j++)
			{
				this->matrix[i][j] = matrix[i][j];
			}
		}
		count++;
	}
	catch (bad_alloc &ex) {
		throw MyException(ex.what());
	}
	catch (...) {
		throw MyException("uncorrent data size in constructor");
	}
}

RectangMatrix::~RectangMatrix()
{}

int RectangMatrix::getMatrix(int x, int y)
{
	if (x < 0 || x >= order || y < 0 || y >= length) {
		throw MyException("Index error");
	}
	return matrix[x][y];
}

void RectangMatrix::Print()
{
	if (order == 0) {
		throw MyException("Operation with empty matrix");
	}
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

void RectangMatrix::Transposition()
{
	if (order != length)
	{
		throw MyException("matrix with different sizes");
	}
	if (order == 0) {
		throw MyException("Operation with empty matrix");
	}
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
}

void RectangMatrix::Sum(const RectangMatrix& B)
{
	if (order != length)
	{
		throw MyException("matrix with different sizes");
	}
	if (order == 0) {
		throw MyException("Operation with empty matrix");
	}
	if (B.order == order && B.length == length)
	{
		for (int i = 0; i < order; i++)
		{
			for (int j = 0; j < length; j++)
			{
				matrix[i][j] += B.matrix[i][j];
			}
		}
	}
}


RectangMatrix RectangMatrix::operator+(const RectangMatrix& B)
{
	if (order == 0 || length == 0) {
		throw MyException("Operation with empty matrix");
	}
	if (B.order != order && B.length != length)
	{
		throw MyException("matrix with different sizes");
	}
	try {
		int** newMatrix = new int*[order];
		for (int i = 0; i < order; i++)
		{
			newMatrix[i] = new int[length];
			for (int j = 0; j < length; j++)
			{
				newMatrix[i][j] = matrix[i][j] + B.matrix[i][j];
			}
		}
		return RectangMatrix(order, length, newMatrix);
	}
	catch (...) {
		throw MyException("out of memory");
	}
}

RectangMatrix::operator int** ()
{
	if (order == 0 || length == 0) {
		throw MyException("Operation with empty matrix");
	}
	try {
		int** newMatrix = new int* [order];;
		for (int i = 0; i < order; i++)
		{
			newMatrix[i] = new int[length];;
			for (int j = 0; j < length; j++)
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

RectangMatrix operator-(const RectangMatrix& A, const RectangMatrix& B)
{
	if (B.order == 0 || B.length == 0) {
		throw MyException("Operation with empty matrix");
	}
	if (B.order != A.order && B.length != A.length)
	{
		throw MyException("matrix with different sizes");
	}
	try {
		int** newMatrix = new int* [A.order];;
		for (int i = 0; i < A.order; i++)
		{
			newMatrix[i] = new int[A.length];;
			for (int j = 0; j < A.length; j++)
			{
				newMatrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
			}
		}
		return RectangMatrix(A.order, A.length, newMatrix);
	}
	catch (...) {
		throw MyException("out of memory");
	}
}

RectangMatrix& operator--(RectangMatrix& A)
{
	if (A.order == 0 || A.length == 0) {
		throw MyException("Operation with empty matrix");
	}
	for (int i = 0; i < A.order; i++)
	{
		for (int j = 0; j < A.length; j++)
		{
			A.matrix[i][j]--;
		}
	}
	return A;
}

RectangMatrix operator--(RectangMatrix& A, int)
{
	if (A.order == 0 || A.length == 0) {
		throw MyException("Operation with empty matrix");
	}
	RectangMatrix newValue(A);
	--A;
	return newValue;
}

RectangMatrix& operator++(RectangMatrix& A)
{
	if (A.order == 0 || A.length == 0) {
		throw MyException("Operation with empty matrix");
	}
	for (int i = 0; i < A.order; i++)
	{
		for (int j = 0; j < A.length; j++)
		{
			A.matrix[i][j]++;
		}
	}
	return A;
}

RectangMatrix operator++(RectangMatrix& A, int)
{
	if (A.order == 0 || A.length == 0) {
		throw MyException("Operation with empty matrix");
	}
	RectangMatrix newValue(A);
	++A;
	return newValue;
}


