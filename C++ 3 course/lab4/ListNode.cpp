#include "stdafx.h"
#include "ListNode.h"
#include <iostream>
using namespace std;
template<typename Item> ListNode<Item>::ListNode() {
	data = NULL;
	head = this;
}


template<typename Item> ListNode<Item>::~ListNode() {
}

template<typename Item> ListNode<Item>::ListNode(Item a) {
	data = a;
	head = this;
}

template<typename Item> void ListNode<Item>::swapNode(Item &a, Item &b) {
	Item c = a;
	a = b;
	b = c;
}

template<typename Item> void ListNode<Item>::sortNodeBublSort() {
	if (this == nullptr || this->next == nullptr)
		return;
	ListNode<Item> *resta = this;
	while (resta->next != nullptr) {
		resta = resta->next;
	}
	ListNode<Item> *tail = resta;
	resta = this;
	while (resta != tail) {
		ListNode<Item> * tmp = this;
		while (tmp->next != tail) {
			if (tmp->data > tmp->next->data) {
				swapNode(tmp->data, tmp->next->data);
			}
			tmp = tmp->next;
		}
		if (tmp->data > tmp->next->data) {
			swapNode(tmp->data, tmp->next->data);
		}
		tail = tmp;
	}
}

template<typename Item> void ListNode<Item>::sortNodeMergeSort() {
	if (this == nullptr || this->next == nullptr)
		return;
	int  a = this->data;
	ListNode<Item> *newHead = new ListNode(a);
	ListNode<Item> *pointer = this->next;

	while (pointer != nullptr) {
		ListNode<Item> * innerPointer = newHead;
		ListNode<Item> * next = pointer->next;

		if (pointer->data <= newHead->data) {
			ListNode<Item> * oldHead = newHead;
			newHead = pointer;
			newHead->next = oldHead;
		}
		else {
			while (innerPointer->next != nullptr) {

				if (pointer->data > innerPointer->data && pointer->data <= innerPointer->next->data) {
					ListNode<Item>* oldNext = innerPointer->next;
					innerPointer->next = pointer;
					pointer->next = oldNext;
				}

				innerPointer = innerPointer->next;
			}

			if (innerPointer->next == nullptr && pointer->data > innerPointer->data) {
				innerPointer->next = pointer;
				pointer->next = nullptr;
			}

		}
		pointer = next;
	}

}



template<typename Item> void ListNode<Item>::sortNodeTokenSort() {
	if (this == nullptr || this->next == nullptr)
		return;
	ListNode<Item> *head = this;
	while (head != nullptr) {
		ListNode<Item> *min = head;
		ListNode<Item> *tmp = head;
		while (tmp != nullptr) {
			if (min->data > tmp->data)
				min = tmp;
			tmp = tmp->next;
		}
		swapNode(head->data, min->data);
		head = head->next;
	}
}

template<typename Item> ListNode<Item>  *ListNode<Item>::deleteFromNode(Item a) {
	ListNode<Item> * tmp = this;
	if (tmp->data == a) {
		return this->next;
	}
	while (tmp->next->data != a) {
		tmp = tmp->next;
	}
	tmp = tmp->next->next;
	return this;
}

template<typename Item> void ListNode<Item>::addToNode(Item num) {
	ListNode<Item> * tmp = this;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	tmp->next = new ListNode<Item>(num);
}

template<typename Item> void ListNode<Item>::showList() {
	ListNode<Item> * tmp = new ListNode<Item>();
	tmp = this;
	while (tmp->next != nullptr) {
		cout << tmp->data << "  ";
		tmp = tmp->next;
	}
	cout << tmp->data << endl;
}

template<typename Item> void ListNode<Item>::randList() {
	ListNode<Item> * tmp = this;
	while (tmp->next != nullptr) {
		tmp->data = rand() % 15;
		tmp = tmp->next;
	}
	tmp->data = rand() % 15;
}

template<typename Item> bool ListNode<Item>::isempty() {
	if (this == nullptr)
		return true;
	return false;
}

template<typename Item> void ListNode<Item>::deleteallnode() {
	ListNode<Item> * tmp = this;
	while (tmp) {
		ListNode * dlt = this;
		tmp = tmp->next;
		delete dlt;
	}

}

template<typename Item> void ListNode<Item>::deletefirst() {
	if (this) {
		ListNode<Item> * tmp = this->next;
		this->next = tmp->next;

	}
}

template<typename Item> void ListNode<Item>::deletelast() {
	ListNode<Item>*tmp = this;
	while (tmp->next->next) {
		tmp = tmp->next;
	}
	tmp->next = nullptr;
}

template<typename Item> void ListNode<Item>::print() {
	ListNode<Item> *tmp = this;
	while (tmp) {
		cout << tmp->data << " ->";
		tmp = tmp->next;
	}
	cout << "null" << endl;
}

template<typename Item> void ListNode<Item>::deletkelem(int k) {
	int i = 2;
	ListNode<Item> * tmp = this;
	while (tmp && i != k) {
		tmp = tmp->next;
		i++;
	}
	tmp->next = tmp->next->next;
}



