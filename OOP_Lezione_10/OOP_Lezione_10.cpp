#include<iostream>
#include"LinkedList.h"

int main() {
	setlocale(LC_ALL, "Russian");
	LinkedList list;
	list.AddHead(56);
	list.AddHead(4);
	list.AddHead(7);
	list.AddHead(78);
	list.AddTail(103);
	list.AddTail(13);
	list.AddTail(73);
	list.AddTail(11);
	list.ShowList();
	std::cout << '\n';
	std::cout << list.FindElement(1)->GetData() << "\n\n";

	list.DeleteElement(1);
	list.ShowList();
	std::cout << "\n\n";
	LinkedList list2;
	list2.AddHead(2);
	list2.AddTail(7);
	list2.ShowList();
	list2.DeleteElement(1);
	std::cout << '\n';
	list2.ShowList();
	std::cout << "\n\n";
	LinkedList list3;
	list3.AddHead(9);
	list3.ShowList();

	list3.DeleteElement(1);
	list3.ShowList();
	std::cout << "\n\n";
	list.DeleteList();
	list.ShowList();





	return 0;
}