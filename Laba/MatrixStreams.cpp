#include "Header.h"

ostream& operator<<(ostream& os, RectangMatrix& A)
{
	if (A.order == 0 || A.length == 0) {
		throw MyException("Operation with empty matrix");
	}
	try {
		if (!os.good())
			throw MyException("I/O failure");
		os << A.getOrder() << A.length << endl;
		for (int i = 0; i < A.length; i++)
		{
			for (int j = 0; j < A.getOrder(); j++)
			{
				os << A.getMatrix(i, j) << '\t';
			}
			os << endl;
		}
		return os;
	}
	catch (const exception& e) {
		throw MyException(e.what());
	}
	catch (...) {
		throw MyException("out of memory");
	}
}

ostream& operator<<(ostream& os, Matrix& A)
{
	if (A.order == 0) {
		throw MyException("Operation with empty matrix");
	}
	try {
		if (!os.good())
			throw MyException("I/O failure");
		os << A.getOrder() << endl;
		for (int i = 0; i < A.getOrder(); i++)
		{
			for (int j = 0; j < A.getOrder(); j++)
			{
				os << A.getMatrix(i, j) << '\t';
			}
			os << endl;
		}
		return os;
	}
	catch (const exception& e) {
		throw MyException(e.what());
	}
	catch (...) {
		throw MyException("out of memory");
	}
}

istream& operator>>(istream& is, Matrix& A)
{
	try {
		if (!is.good())
			throw MyException("I/O failure");
		if (A.order > 0) {
			for (int i = 0; i < A.order; i++)
				delete[] A.matrix[i];
			delete[] A.matrix;
		}
		is >> A.order;
		A.matrix = new int* [A.order];
		for (int i = 0; i < A.order; i++)
		{
			A.matrix[i] = new int[A.order];
			for (int j = 0; j < A.order; j++)
			{
				is >> A.matrix[i][j];
			}
		}
		return is;
	}
	catch (const exception& e) {
		throw MyException(e.what());
	}
	catch (...) {
		throw MyException("out of memory");
	}
}

void Matrix::write(ofstream* out)
{
	if (order == 0) {
		throw MyException("Operation with empty matrix");
	}
	try {
		if (!out->is_open())
			throw MyException("I/O file failure");
		out->write((char*)&(this->order), sizeof(int));
		for (int i = 0; i < order; i++)
		{
			for (int j = 0; j < order; j++)
			{
				out->write((char*)&(this->matrix[i][j]), sizeof(int));
			}
		}
	}
	catch (const exception& e) {
		throw MyException(e.what());
	}
	catch (...) {
		throw MyException("out of memory");
	}
}

void Matrix::read(ifstream* in)
{
	if (order == 0) {
		throw MyException("Operation with empty matrix");
	}
	try {
		if (!in->is_open())
			throw MyException("I/O file failure");
		if (order > 0) {
			for (int i = 0; i < order; i++)
				delete[] matrix[i];
			delete[] matrix;
		}
		in->read((char*)&(this->order), sizeof(int));
		matrix = new int* [order];
		for (int i = 0; i < order; i++)
		{
			matrix[i] = new int[order];
			for (int j = 0; j < order; j++)
			{
				in->read((char*)&(this->matrix[i][j]), sizeof(int));
			}
		}
	}
	catch (const exception& e) {
		throw MyException(e.what());
	}
	catch (...) {
		throw MyException("out of memory");
	}
}
