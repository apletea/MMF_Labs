#pragma once
class node
{
private:
	int data;
	node *next;
	void swapNode(int &a, int &b);
public:
	node();
	node(int a);
	~node();
	void addToNode(int a);
	node* deleteFromNode(int a);
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



