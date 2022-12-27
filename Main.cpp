
/*
	Основные конструкции C++.
	Модуль 8. Шаблоны  
	8.8. Домашнее задание
*/

#include <iostream>
#include <string>
#include <locale>
#include "classArray.h"

using namespace std;

void test() {
	cout << "Array int" << endl;
	int* arri = new int[10]{ 0,1,2,3,4,5,6,7,8,9 };
	ClassArray<int> a1(arri, 10);
	for (int i = 0; i < 10; ++i) { cout << a1[i] << " "; }

	cout << "\n\nArray double" << endl;
	double* arrd = new double[10]{ 0.99, 1.32, 0.32, 3.21, 4.87, 5.654, 6.98, 7.0923, 8.54, 9.564321 };
	ClassArray<double> a2(arrd, 10);
	for (int i = 0; i < 10; ++i) { cout << a2[i] << " "; }

	cout << "\n\nArray string" << endl;
	string* arrs = new string[10]{ "Сначала", "был", "свет", "и", "это", "32", "6.98", "было", "8", "ярко" };
	ClassArray<string> a3(arrs, 10);
	for (int i = 0; i < 10; ++i) { cout << a3[i] << " "; }

	//cout << endl;
	//int* arrni = nullptr;
	//ClassArray<int> ast1(arrni, 10);

	//cout << endl;
	//double* arrnd = nullptr;
	//ClassArray<double> ast2(arrnd, 20);

	cout << endl;
	char* arrnc = nullptr;
	ClassArray<char> ast3(arrnc, 30);

	//cout << endl;
	//string* arrns = nullptr;
	//ClassArray<string> ast4(arrns, 40);


}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru-RU");

	try {
		test();
	}
	catch ( BadArray<int>& e) {
		e.show(); cout << endl;
		cout << "int\t" << e.what() << endl;
	}
	catch (BadArray<double>& e) {
		e.show(); cout << endl;
		cout << "double\t" << e.what() << endl;
	}
	catch (BadArray<char>& e) {
		e.show(); cout << endl;
		cout << "char\t" << e.what() << endl;
	}
	catch (BadArray<string>& e) {
		e.show(); cout << endl;
		cout << "string\t" << e.what() << endl;
	}

	return 0;
}