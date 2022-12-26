#include "Header.h"

int Matrix::count = 0;

Matrix::Matrix() 
{
	count++;
	order = 0;
	matrix = NULL;
}

Matrix::Matrix(int order) 
{
	count++;
	this->order = order;
	try {
		matrix = new int* [order];
		for (int i = 0; i < order; i++) {
			matrix[i] = new int[order];
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

Matrix::Matrix(int order, int** matrix)
{
	this->order = order;
	count++;
	try {
	this->matrix = new int* [order];
		for (int i = 0; i < order; i++) {
			this->matrix[i] = new int[order];
			for (int j = 0; j < order; j++)
			{
				this->matrix[i][j] = matrix[i][j];
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

Matrix::Matrix(const Matrix &obj)
{
	order = obj.order;
	count++;
	try {
		matrix = new int* [order];
		for (int i = 0; i < order; i++) {
			matrix[i] = new int[order];
			for (int j = 0; j < order; j++)
			{
				matrix[i][j] = obj.matrix[i][j];
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

Matrix::~Matrix() {
	if (order > 0) {
		for (int i = 0; i < order; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
	count--;
}

void Matrix::Print() {
	if (order == 0) {
		throw MyException("Operation with empty matrix");
	}
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

int Matrix::getOrder() {
	return order;
}

int Matrix::getMatrix(int x, int y)
{
	if (x < 0 || x >= order || y < 0 || y >= order) {
		throw MyException("Index error");
	}
	return matrix[x][y];
}

void Matrix::Transposition() {
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

int Matrix::getCount()
{
	return count;
}

void Matrix::Sum(const Matrix& B)
{
	if (order == 0) {
		throw MyException("Operation with empty matrix");
	}
	if (B.order == order)
	{
		for (int i = 0; i < order; i++)
		{
			for (int j = 0; j < order; j++)
			{
				matrix[i][j] += B.matrix[i][j];
			}
		}
	}
}




