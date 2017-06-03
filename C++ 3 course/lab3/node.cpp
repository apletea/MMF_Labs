#include "stdafx.h"
#include "node.h"
#include <iostream>
using namespace std;
node::node(){
	data = NULL;
}


node::~node(){
}

node::node(int a){
	data = a;
}

void node::swapNode(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

void node::sortNodeBublSort() {
	if (this == nullptr || this->next == nullptr)
		return;
	node *resta = this;
	while (resta->next != nullptr) {
		resta = resta->next;
	}
	node *tail = resta;
	resta = this;
	while (resta != tail) {
		node * tmp = this;
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

void node::sortNodeMergeSort() {
	if (this == nullptr || this->next == nullptr)
		return;
	int  a = this->data;
	node *newHead = new node(a);
	node *pointer = this->next;

	while (pointer != nullptr) {
		node * innerPointer = newHead;
		node * next = pointer->next;

		if (pointer->data <= newHead->data) {
			node * oldHead = newHead;
			newHead = pointer;
			newHead->next = oldHead;
		}
		else {
			while (innerPointer->next != nullptr) {

				if (pointer->data > innerPointer->data && pointer->data <= innerPointer->next->data) {
					node* oldNext = innerPointer->next;
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



void node::sortNodeTokenSort() {
	if (this == nullptr || this->next == nullptr)
		return;
	node *head = this;
	while (head != nullptr) {
		node *min = head;
		node *tmp = head;
		while (tmp != nullptr) {
			if (min->data > tmp->data)
				min = tmp;
			tmp = tmp->next;
		}
		swapNode(head->data, min->data);
		head = head->next;
	}
}

node* node::deleteFromNode(int a) {
	node * tmp = this;
	if (tmp->data == a) {
		return this->next;
	}
	while (tmp->next->data != a) {
		tmp = tmp->next;
	}
	tmp = tmp->next->next;
	return this;
}

void node::addToNode(int num) {
	node * tmp = this;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	tmp->next = new node(num);
}

void node::showList() {
	node * tmp = this;
	while (tmp->next != nullptr) {
		cout << tmp->data << "  ";
		tmp = tmp->next;
	}
	cout << tmp->data << endl;
}

void node::randList() {
	node * tmp = this;
	while (tmp->next != nullptr) {
		tmp->data = rand() % 15;
		tmp = tmp->next;
	}
	tmp->data = rand() % 15;
}

bool node::isempty() {
	if (this == nullptr)
		return true;
	return false;
}

void node::deleteallnode() {
	node * tmp = this;
	while (tmp) {
		node * dlt = this;
		tmp = tmp->next;
		delete dlt;
	}

}

void node::deletefirst() {
	if (this) {
		node * tmp = this->next;
		this->next = tmp->next;
		
	}
}

void node::deletelast() {
	node *tmp = this;
	while (tmp->next->next) {
		tmp = tmp->next;
	}
	tmp->next = nullptr;
}

void node::print() {
	node *tmp = this;
	while (tmp) {
		cout << tmp->data << " ->";
		tmp = tmp->next;
	}
	cout << "null" << endl;
}

void node::deletkelem(int k) {
	int i = 2;
	node * tmp = this;
	while (tmp && i != k) {
		tmp = tmp->next;
		i++;
	}
	tmp->next = tmp->next->next;
}



