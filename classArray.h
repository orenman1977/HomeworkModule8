/* шаблоны надо полностью описывать в заголовочном файле!!! */

// класс-шаблон контейнер
#pragma once
#include <iostream>
#include "BadArray.h"

template<typename T = int>
class ClassArray
{
	size_t _array_lenght;
	T* _array;
	size_t _index;

public:
	ClassArray();
	ClassArray(T* _array, size_t _array_lenght);
	~ClassArray();

	size_t getLenght();
	size_t getIndex();
	T* getArray();
	T& operator[](size_t i);
};

template<typename T>
inline ClassArray<T>::ClassArray() : _array_lenght(0), _array(nullptr), _index(0) {}

template<typename T>
inline ClassArray<T>::ClassArray(T* array, size_t array_lenght) : _array_lenght(array_lenght), _array(array), _index(0) {
	if (_array == nullptr || _array_lenght > (1 << 20)) {
		cout << "start" << endl;
		throw BadArray<T>(_array, _array_lenght, _index);
	}
	cout << "end" << endl;
}

template<typename T>
inline ClassArray<T>::~ClassArray() { delete[] _array; }

template<typename T>
inline size_t ClassArray<T>::getLenght() { return this->_array_lenght; }

template<typename T>
inline size_t ClassArray<T>::getIndex() { return this->_index; }

template<typename T>
inline T* ClassArray<T>::getArray() { return this->_array; }

template<typename T>
inline T& ClassArray<T>::operator[](size_t i) {	return this->_array[i]; }
