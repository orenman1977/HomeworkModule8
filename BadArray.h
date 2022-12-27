

// класс-шаблон исключения
#pragma once
#include <exception>
#include <iostream>
using namespace std;

template<typename T>
class BadArray : public exception
{
	size_t _lenght;
	size_t _index;
	T* _myarray;
public:
	BadArray(T* myarray, size_t arrlenght, size_t index);
	void show();
	size_t getLenght();
	size_t getIndex();
	T* getArrayptr();
};

template<typename T>
inline BadArray<T>::BadArray(T* myarray, size_t arrlenght, size_t index) :_lenght(arrlenght), _index(index), _myarray(myarray) {}
template<typename T>
void BadArray<T>::show() { cout << "\nBadArray: lenght = " << _lenght << " index = " << _index << " array = " << _myarray; }
template<typename T>
size_t BadArray<T>::getLenght() { return this->_lenght; }
template<typename T>
size_t BadArray<T>::getIndex() { return this->_index; }
template<typename T>
T* BadArray<T>::getArrayptr() { return this->_myarray; }
