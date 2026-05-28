#pragma once
#include <iostream>
using namespace std;

template <class T> class ClsDblLinkedList 
{

protected :

	int _Size = 0;

public :

	class Node {
	public:

		T _Value;
		Node* _Next;
		Node* _Prev;

	};

	Node* head = NULL;

	void InsertAtBeginning(T value) {

		Node* NewNode = new Node();

		NewNode->_Value = value;
		NewNode->_Next = head;
		NewNode->_Prev = NULL;

		if (head != NULL) {

			head->_Prev = NewNode;

		}

		head = NewNode;
		_Size++;

	}

	void PrintList() {

		Node* Current = head;

		while (Current != NULL) {

			cout << Current->_Value << " ";
			Current = Current->_Next;

		}

	}

	Node *Find(T value) {

		Node* Current = head;

		while (Current != NULL) {

			if (Current->_Value == value)
				return Current;

			Current = Current->_Next;

		}

		return NULL;

	}

	void InsertAfter(Node* Current, T value) {

		if (Current == NULL)
			return;

		Node* NewNode = new Node();

		NewNode->_Value = value;
		NewNode->_Next = Current->_Next;
		NewNode->_Prev = Current;
		if (Current->_Next != NULL) {

			Current->_Next->_Prev = NewNode;

		}
		
		Current->_Next = NewNode;
		_Size++;

	}

	void InsertAtEnd(T value) {

		Node *NewNode = new Node();
		NewNode->_Value = value;
		NewNode->_Next = NULL;

		if (head == NULL) {

			NewNode->_Prev = NULL;
			head = NewNode;
			_Size++;
			return;
		}

		Node* Current = head;

		while (Current->_Next != NULL) {

			Current = Current->_Next;

		}

		Current->_Next = NewNode;
		NewNode->_Prev = Current;
		_Size++;

	}

	void DeleteNode(Node* &NodeToDelete) {

		if (head == NULL || NodeToDelete == NULL)
			return;

		if (head == NodeToDelete) {

			head = NodeToDelete->_Next;
			
			if (head != NULL) {

				head->_Prev = NULL;

			}

			delete NodeToDelete;
			_Size--;
			return;

		}

		if (NodeToDelete->_Next != NULL) {

			NodeToDelete->_Next->_Prev = NodeToDelete->_Prev;

		}

		if (NodeToDelete->_Prev != NULL) {

			NodeToDelete->_Prev->_Next = NodeToDelete->_Next;

		}

		delete NodeToDelete;
		_Size--;

	}

	void DeleteFirstNode() {

		if (head == NULL) {

			return;

		}

		Node* temp = head;

		head = temp->_Next;

		if (head != NULL) {

			head->_Prev = NULL;

		}

		delete temp;
		_Size--;

	}

	void DeleteLastNode() {

		if (head == NULL)
			return;

		if (head->_Next == NULL) {

			delete head;
			head = NULL;
			_Size--;
			return;

		}

		Node* Current = head;

		while (Current->_Next->_Next != NULL) {

			Current = Current->_Next;

		}

		Node* temp = Current->_Next;

		Current->_Next = NULL;
		delete temp;
		_Size--;

	}

	int Size() {

		return _Size;

	}

	bool IsEmpty() {

		return (_Size == 0 ? true : false);

	}

	void Clear() {

		while (_Size > 0) {

			DeleteFirstNode();

		}

	}

	void Reverse() {

		Node* Current = head;

		Node* temp = nullptr;

		while (Current != nullptr) {

			temp = Current->_Prev;
			Current->_Prev = Current->_Next;
			Current->_Next = temp;

			Current = Current->_Prev;

		}

		if (temp != nullptr) {

			head = temp->_Prev;

		}

	}

	Node* GetNode(int index) {

		int Counter = 0;

		if (index > _Size - 1 || index < 0)
			return NULL;

		Node* Current = head;

		while (Current != NULL) {

			if (Counter == index)
				return Current;

			Current = Current->_Next;
			Counter++;

		}

		return NULL;

	}

	T GetItem(int index) {

		Node* ItemNode = GetNode(index);

		if (ItemNode == NULL)
			return NULL;
		else
			return ItemNode->_Value;

	}

	bool UpdateItem(int index, T NewValue) {

		Node* ItemNode = GetNode(index);

		if (ItemNode != NULL) {

			ItemNode->_Value = NewValue;
			return true;

		}
		else {

			return false;

		}
		
	}

	bool InsertAfter(int index, T value) {

		Node* ItemNode = GetNode(index);

		if (ItemNode != NULL) {

			InsertAfter(ItemNode, value);
			return true;

		}
		else
			return false;

	}


};

