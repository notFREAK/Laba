#include "Header.h"

UnitMatrix::UnitMatrix() : Matrix::Matrix() {};

UnitMatrix::UnitMatrix(int order) : Matrix::Matrix(order) {
	for (int i = 0; i < order; i++)
	{
		matrix[i][i] = 1;
	}
}

UnitMatrix::~UnitMatrix() {};

void UnitMatrix::Transposition() {};


