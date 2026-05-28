#pragma once
#include <iostream>
using namespace std;

template <class T> 
class clsDynamicArray
{

protected :

	int _Size;
	T* _TempArray;

public :

	T* OriginalArray;

	clsDynamicArray(int Size = 0) {

		if (Size < 0)
			Size = 0;

		_Size = Size;
		OriginalArray = new T[_Size];

	}

	~clsDynamicArray() {

		delete[]OriginalArray;

	}

	bool SetItem(int index , T value) {

		if (index > _Size || index < 0) {

			return false;

		}

	    OriginalArray[index] = value;
		return true;

	}

	void PrintList() {

		for (int i = 0; i < _Size; i++) {

			cout << OriginalArray[i] << " ";

		}

	}

	bool IsEmpty() {

		return _Size == 0;

	}

	int Size() {

		return _Size;

	}

	void Resize(int NewSize) {

		if (NewSize < 0)
			NewSize = 0;

		if (NewSize < _Size)
			_Size = NewSize;

		_TempArray = new T[_Size];

		for (int i = 0; i < _Size; i++) {

			_TempArray[i] = OriginalArray[i];

		}

		_Size = NewSize;

		delete []OriginalArray;
		
		OriginalArray = _TempArray;
		
	}

	T GetItem(int index) {

		return OriginalArray[index];

	}

	void Reverse() {

		_TempArray = new T[_Size];

		for (int i = 0; i <= _Size - 1 ; i++) {

			_TempArray[i] = OriginalArray[_Size - 1 - i];

		}

		delete []OriginalArray;

		OriginalArray = _TempArray;

	}

	void Clear() {

		_Size = 0;

		_TempArray = new T[0];

		delete[] OriginalArray;

		OriginalArray = _TempArray;

	}

	void DeleteItemAt(int index) {

		if (index < 0 || index > _Size)
			return;

		_TempArray = new T[_Size - 1];

		for (int i = 0 , j = 0 ; i < _Size; i++) {

			if (i == index)
				continue;

			_TempArray[j++] = OriginalArray[i];

		}

		delete[] OriginalArray;

		OriginalArray = _TempArray;

		_Size--;

	}

	void DeleteFirstItem() {

		DeleteItemAt(0);

	}

	void DeleteLastItem() {

		DeleteItemAt(_Size - 1);

	}

	int Find(T value) {

		for (int i = 0; i < _Size; i++) {

			if (OriginalArray[i] == value)
				return i;

		}

		return -1;

	}

	bool DeleteItem(T value) {

		int index = Find(value);

		if (index == -1)
			return false;

		DeleteItemAt(index);
		return true;

	}

	void InsertAt(int index , T value) {

		if (index < 0 || index > _Size)
			return;



		_Size++;

		_TempArray = new T[_Size];

		for (int i = 0; i < index ; i++) {
			
			_TempArray[i] = OriginalArray[i];

		}

		_TempArray[index] = value;

		for (int i = index; i < _Size - 1; i++) {

			_TempArray[i + 1] = OriginalArray[i];

		}

		delete[] OriginalArray;

		OriginalArray = _TempArray;

	}

	void InsertAtBeginning(T value) {

		InsertAt(0, value);

	}

	void InsertAtEnd(T value) {

		InsertAt(_Size, value);

	}

	void InsertAfter(int index, T value) {

		if (index >= _Size)
			InsertAt(_Size - 1, value);
		else
			InsertAt(index + 1, value);

	}

	void InsertBefore(int index, T value) {

		if (index < 1)
			InsertAt(0, value);
		else
			InsertAt(index - 1, value);

	}

};

