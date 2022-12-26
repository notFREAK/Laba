#include "Header.h"
#include "Queue.h"

void lab3() {
	int** b = new int* [6];
	for (int i = 0; i < 6; i++)
	{
		b[i] = new int[6];
		for (int j = 0; j < 6; j++)
		{
			b[i][j] = 1 + i * 6 + j;
		}
	}
	Matrix A(6, b);
	cout << endl << A << endl;
	cin >> A;
	cout << endl << A << endl;
	ofstream fout("NewFile.txt", ios::out);
	if (!fout) {
		cout << "Îøèáêà" << endl;
		return;
	}
	fout << A << endl;
	fout.close();
	ifstream fin("NewFile.txt", ios::in);
	if (!fin) {
		cout << "Îøèáêà" << endl;
		return;
	}
	Matrix B;
	fin >> B;
	fin.close();
	cout << endl << B << endl;
	ofstream bout("BinaryFile.dat", ios::binary | ios::app);
	if (!bout) {
		cout << "Îøèáêà" << endl;
		return;
	}
	A.write(&bout);
	bout.close();
	ifstream bin("BinaryFile.dat", ios::binary);
	if (!bin) {
		cout << "Îøèáêà" << endl;
		return;
	}
	B.read(&bin);
	bin.close();
	cout << endl << B << endl;
}

void lab4() {
	int** b = new int* [6];
	for (int i = 0; i < 6; i++)
	{
		b[i] = new int[6];
		for (int j = 0; j < 6; j++)
		{
			b[i][j] = 1 + i * 6 + j;
		}
	}
	Matrix A(6, b);
	UnitMatrix B(6);
	for (int i = 0; i < 6; i++)
	{
		delete b[i];
	}
	for (int i = 0; i < 6; i++)
	{
		b[i] = new int[5];
		for (int j = 0; j < 5; j++)
		{
			b[i][j] = 1 + i * 5 + j;
		}
	}
	RectangMatrix C(6, 5, b);
	Matrix* main;
	main = &A;
	A.Print();
	main = &B;
	B.Print();
	main = &C;
	C.Print();
}

void lab7() {
	Queue<int> Q;
	int a = 3, b = 2, c = 1, d = 5, f = 4;
	Q.insertFront(a);
	Q.Print();
	Q.insertFront(b);
	Q.Print();
	Q.insertFront(c);
	Q.Print();
	Q.insertRear(d);
	Q.Print();
	Q.insertNumber(f, 3);
	Q.Print();
	Q.deleteNumber(3);
	Q.Print();
	Q.deleteFront();
	Q.Print();
	Q.deleteRear();
	Q.Print();
	cout << Q.getNumber(1) << endl;
}

void lab5() {
	int** b = new int* [6];
	for (int i = 0; i < 6; i++)
	{
		b[i] = new int[6];
		for (int j = 0; j < 6; j++)
		{
			b[i][j] = 1 + i * 6 + j;
		}
	}
	Matrix A(6, b);
	UnitMatrix B(6);
	for (int i = 0; i < 6; i++)
	{
		delete b[i];
	}
	for (int i = 0; i < 6; i++)
	{
		b[i] = new int[5];
		for (int j = 0; j < 5; j++)
		{
			b[i][j] = 1 + i * 5 + j;
		}
	}
	RectangMatrix C(6, 5, b);
	Queue<Matrix> Q;
	Q.insertFront(A);
	Q.insertFront(B);
	Q.insertFront(C);
	Q.Print();
}

int main() {
	lab5();
	return 0;
}