#include"LinkedList.h"
#include<iostream>

LinkedList::LinkedList():_head(nullptr),_tail(nullptr),_size(0){}

void LinkedList::AddTail(int data) {
	Node* newTail = new Node(data);
	_size++;

	if (_head == nullptr) {
		_head = newTail;
		_tail = newTail;
		return;
	}

	_tail->prev = newTail;
	newTail->next = _tail;
	_head->next = newTail;
	_tail = newTail;
	_tail->prev = _head;

}

void LinkedList::AddHead(int data) {
	Node* newHead = new Node(data);
	_size++;

	if (_head == nullptr) {
		_tail = newHead;
		_head = newHead;
		return;
	}

	_head->next = newHead;
	newHead->prev = _head;
	newHead->next = _tail;
	_head = newHead;

}

void LinkedList::ShowList() {
	if (_size == 0) {
		std::cout << "Нет элементов.\n";
		return;
	}
	int index = 0;
	for (Node* nodePtr = _head; index != _size; nodePtr = nodePtr->prev, index++) {
		std::cout << "Data: " << nodePtr->GetData() << '\n';
	}
}

void LinkedList::DeleteElement(int index) {
	if (_size==1) {
		_size--;
		delete(_head);
		return;
	}
	
	Node* deleted = FindElement(index);
	Node* prevDeleted = deleted->prev;
	
	Node* nextDeleted = deleted->next;

	prevDeleted->next = nextDeleted;

	nextDeleted->prev = prevDeleted;
	if (deleted == _head) {
		_head = deleted->prev;
	}
	else if (deleted == _tail) {
		_tail = deleted->next;
	}
	_size--;
	delete(deleted);
}

Node* LinkedList::FindElement(int index) {
	if (index<=0 || index>_size) {
		return nullptr;
	}
	if (index == 1)return _head;
	if (index == _size)return _tail;
	Node* nodePtr = _head;
	index--;
	while (index != 0) {
		nodePtr = nodePtr->prev;
		index--;
	}
	return nodePtr;
}

void LinkedList::DeleteList() {

	Node* nodePtr = _tail;
	while (_size > 0) {
		nodePtr = nodePtr->next;
		delete(_tail);
		_tail = nodePtr;
		_size--;
	}
}