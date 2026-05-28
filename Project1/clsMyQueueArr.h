#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

template <class T>
class clsMyQueueArr
{

protected :

	clsDynamicArray <T> _DynamicArray;

public :


	void push(T Item) {

		_DynamicArray.InsertAtEnd(Item);

	}

	void Print() {

		_DynamicArray.PrintList();

	}

	int Size() {

		return _DynamicArray.Size();

	}

	bool IsEmpty() {

		return _DynamicArray.IsEmpty();

	}

	T front() {

		return _DynamicArray.GetItem(0);

	}

	T back() {

		return _DynamicArray.GetItem(Size() - 1);

	}

	void pop() {

		_DynamicArray.DeleteFirstItem();

	}

	T GetItem(int index) {

		return _DynamicArray.GetItem(index);

	}

	void reverse() {

		_DynamicArray.Reverse();

	}

	void UpdateItem(int index, T NewValue) {

		_DynamicArray.SetItem(index, NewValue);

	}

	void InsertAfter(int index, T value) {

		_DynamicArray.InsertAfter(index, value);

	}

	void InsertAtFront(T value) {

		_DynamicArray.InsertAtBeginning(value);

	}

	void InsertAtBack(T value) {

		_DynamicArray.InsertAtEnd(value);

	}

	void Clear() {

		_DynamicArray.Clear();

	}


};

