#include <iostream>
#include "LinkedList.h"



int main() {
	LinkedList<int> lst;

	lst.push_back(3);

	std::cout << lst.getAt(0) << std::endl;
	std::cout << lst.getSize() << std::endl;

	lst.insertAt(0, 123);

	std::cout << lst.getAt(0) << std::endl;

	lst.insertAt(1, 322);

	std::cout << lst.getAt(1) << std::endl;
	std::cout << lst.getAt(2) << std::endl;
	return 0;
}