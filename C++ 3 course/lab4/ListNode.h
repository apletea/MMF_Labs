#pragma once



template <typename Item> class ListNode
{
private:
	Item data;
	ListNode<Item> *next;
	ListNode<Item> *head;
	void swapNode(Item &a, Item &b);
public:
	ListNode();
	ListNode(Item a);
	~ListNode();
	void addToNode(Item a);
	ListNode<Item>* deleteFromNode(Item a);
	void sortNodeBublSort();
	void sortNodeTokenSort();
	void sortNodeMergeSort();
	void showList();
	void randList();
	bool isempty();
	void deleteallnode();
	void deletefirst();
	void deletelast();
	void print();
	void deletkelem(int k);
};



