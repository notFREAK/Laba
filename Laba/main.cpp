#include "Header.h"
#include "Queue.h"
#include <chrono>
#include <stack>
#include <set>

void lab2() {
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
	int** c = new int* [6];
	for (int i = 0; i < 6; i++)
	{
		c[i] = new int[6];
		for (int j = 0; j < 6; j++)
		{
			c[i][j] = 2 + i * 5 + j;
		}
	}
	Matrix B(6, c);
	A.Print();
	B.Print();
	if (A < B) {
		(A + B).Print();
	}
	else {
		(A + B).Print();
	}
	(A - B).Print();
	A++.Print();
	A.Print();
	(++A).Print();
	for (int i = 0; i < 6; i++)
	{
		delete b[i];
		delete c[i];
	}
	delete b;
	delete c;
}


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
		cout << "������" << endl;
		return;
	}
	fout << A << endl;
	fout.close();
	ifstream fin("NewFile.txt", ios::in);
	if (!fin) {
		cout << "������" << endl;
		return;
	}
	Matrix B;
	fin >> B;
	fin.close();
	cout << endl << B << endl;
	ofstream bout("BinaryFile.dat", ios::binary | ios::app);
	if (!bout) {
		cout << "������" << endl;
		return;
	}
	A.write(&bout);
	bout.close();
	ifstream bin("BinaryFile.dat", ios::binary);
	if (!bin) {
		cout << "������" << endl;
		return;
	}
	B.read(&bin);
	bin.close();
	cout << endl << B << endl;
	for (int i = 0; i < 6; i++)
	{
		delete b[i];
	}
	delete b;
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
	for (int i = 0; i < 6; i++)
	{
		delete b[i];
	}
	delete b;
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
	for (int i = 0; i < 6; i++)
	{
		delete b[i];
	}
	delete b;
}

void lab6() {
	int** b = new int* [6];
	for (int i = 0; i < 6; i++)
	{
		b[i] = new int[6];
		for (int j = 0; j < 6; j++)
		{
			b[i][j] = 1 + i * 6 + j;
		}
	}
	try {
		Matrix A;
		A.Transposition();
	}
	catch (MyException& e) {
		cout << e.what() << endl;
	}
	try {
		Matrix A(-1, b);
	}
	catch (MyException& e) {
		cout << e.what() << endl;
	}
	try {
		Matrix A(6, b);
		Queue <Matrix> Q;
		Q.getNumber(12);
	}
	catch (MyException& e) {
		cout << e.what() << endl;
	}
	for (int i = 0; i < 6; i++)
	{
		delete b[i];
	}
	delete b;
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
	Queue<float> Qf;
	float af = 3.1, bf = 2.1, cf = 1.1, df = 5.1, ff = 4.1;
	Qf.insertFront(af);
	Qf.Print();
	Qf.insertFront(bf);
	Qf.Print();
	Qf.insertFront(cf);
	Qf.Print();
	Qf.insertRear(df);
	Qf.Print();
	Qf.insertNumber(ff, 3);
	Qf.Print();
	Qf.deleteNumber(3);
	Qf.Print();
	Qf.deleteFront();
	Qf.Print();
	Qf.deleteRear();
	Qf.Print();
	cout << Qf.getNumber(1) << endl;
}


void lab8() {
	srand(time(0));
	stack <int> sint;
	stack <class Matrix> smat;
	multiset <int> msint;
	multiset <class Matrix> msmat;
	int sintSr = 0, smatSr = 0, msintSr = 0, msmatSr = 0;
	for (int i = 0; i < 100; i++) {

		int a = rand() % 10;
		Matrix A(a);

		auto start = chrono::high_resolution_clock::now();
		sint.push(a);
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		//cout << duration.count() << '\t';
		sintSr += duration.count();

		start = chrono::high_resolution_clock::now();
		smat.push(A);
		stop = chrono::high_resolution_clock::now();
		duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		//cout << duration.count() << '\t';
		smatSr += duration.count();

		start = chrono::high_resolution_clock::now();
		msint.insert(a);
		stop = chrono::high_resolution_clock::now();
		duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		//cout << duration.count() << '\t';
		msintSr += duration.count();

		start = chrono::high_resolution_clock::now();
		msmat.insert(A);
		stop = chrono::high_resolution_clock::now();
		duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		//cout << duration.count() << endl;
		msmatSr += duration.count();
	}
	cout << "Stack\tInt\tMatrix\tMS\tInt\tMatrix\n";
	cout << "Insert:\t" << sintSr / 100 << '\t' << smatSr / 100 << "\t\t" << msintSr / 100 << '\t' << msmatSr / 100 << endl;
	for (int i = 99; i >= 0; i--) {

		int a = rand() % 10;
		Matrix A(a);
		int eint = sint.top();
		Matrix emat = smat.top();
		auto start = chrono::high_resolution_clock::now();
		sint.pop();
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		//cout << duration.count() << '\t';
		sintSr += duration.count();

		start = chrono::high_resolution_clock::now();
		smat.pop();
		stop = chrono::high_resolution_clock::now();
		duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		//cout << duration.count() << '\t';
		smatSr += duration.count();

		start = chrono::high_resolution_clock::now();
		msint.erase(eint);
		stop = chrono::high_resolution_clock::now();
		duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		//cout << duration.count() << '\t';
		msintSr += duration.count();

		start = chrono::high_resolution_clock::now();
		msmat.erase(emat);
		stop = chrono::high_resolution_clock::now();
		duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		//cout << duration.count() << endl;
		msmatSr += duration.count();
	}
	cout << "Delete:\t" << sintSr / 100 << '\t' << smatSr / 100 << "\t\t" << msintSr / 100 << '\t' << msmatSr / 100 << endl;
}


int main() {
	lab4();
	return 0;
}