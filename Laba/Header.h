#pragma once
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class Matrix
{
protected:
	int order;
	int** matrix;
	static int count;
public:
	Matrix();
	Matrix(int order);
	Matrix(int order, int** matrix);	
	Matrix(const Matrix &obj);
	~Matrix();
	static int getCount();
	int getOrder();
	virtual int getMatrix(int x, int y);
	virtual void Print();
	virtual void Transposition();
	virtual void Sum(const Matrix &B);
	Matrix operator+(const Matrix &B);
	friend bool operator<(const Matrix& A, const Matrix& B);
	friend Matrix operator-(const Matrix& A, const Matrix& B);
	friend Matrix& operator--(Matrix& A);
	friend Matrix operator--(Matrix& A, int);
	friend Matrix& operator++(Matrix& A);
	friend Matrix operator++(Matrix& A, int);
	operator int** ();
	friend ostream& operator<< (ostream& os, Matrix& A);
	friend istream& operator>> (istream& is, Matrix& A);
	void write(ofstream* out);
	void read(ifstream* in);
};

class UnitMatrix : public Matrix {
public:
	UnitMatrix();
	UnitMatrix(int order);
	~UnitMatrix();
	virtual void Transposition() override;
};

class RectangMatrix : public Matrix {
	int length;
public:
	RectangMatrix();
	RectangMatrix(int order, int length);
	RectangMatrix(int order, int length, int** matrix);
	~RectangMatrix();
	virtual int getMatrix(int x, int y) override;
	virtual void Print() override;
	virtual void Transposition() override;
	virtual void Sum(const RectangMatrix& B);
	RectangMatrix operator+(const RectangMatrix& B);
	friend RectangMatrix operator-(const RectangMatrix& A, const RectangMatrix& B);
	friend RectangMatrix& operator--(RectangMatrix& A);
	friend RectangMatrix operator--(RectangMatrix& A, int);
	friend RectangMatrix& operator++(RectangMatrix& A);
	friend RectangMatrix operator++(RectangMatrix& A, int);
	operator int**();
	friend ostream& operator<< (ostream& os, RectangMatrix& A);
	friend istream& operator>> (istream& is, RectangMatrix& A);
	void write(ofstream* out);
	void read(ifstream* in);
};

class MyException : public std::exception
{
private:
	std::string m_error;
public:
	MyException(std::string error);
	const char* what() const noexcept {
		return m_error.c_str();
	}
};
