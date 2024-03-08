#include <iostream>
#include "../List/List.h"

int main() 
{
	DoublyLinkedList<int> list1 = { 1, 2, 3 };

	//act
	list1 << 4;
	std::cout << list1;
}