#pragma once
#include "ClsDblLinkedList.h"
using namespace std;


template <class T> class clsMyQueue
{

protected :

	ClsDblLinkedList <int> _DblLinkedList;

public : 

	void push(T Item) {

		_DblLinkedList.InsertAtEnd(Item);

	}

	void Print() {

		_DblLinkedList.PrintList();

	}

	int Size() {

		return _DblLinkedList.Size();

	}

	bool IsEmpty() {

		return _DblLinkedList.IsEmpty();

	}

	int front() {

		return _DblLinkedList.GetItem(0);

	}

	int back() {

		return _DblLinkedList.GetItem(Size() - 1);

	}

	void pop() {

		_DblLinkedList.DeleteFirstNode();

	}

	T GetItem(int index) {

		return _DblLinkedList.GetItem(index);

	}

	void reverse() {

		_DblLinkedList.Reverse();

	}

	void UpdateItem(int index , T NewValue) {

		_DblLinkedList.UpdateItem(index, NewValue);

	}

	void InsertAfter(int index, T value) {

		_DblLinkedList.InsertAfter(index , value);

	}

	void InsertAtFront(T value) {

		_DblLinkedList.InsertAtBeginning(value);

	}

	void InsertAtBack(T value) {

		_DblLinkedList.InsertAtEnd(value);

	}

	void Clear() {

		_DblLinkedList.Clear();

	}

};

