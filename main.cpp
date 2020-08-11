#include <iostream>

#include "LinkedList.hpp"

int main() {

	LinkedList li;

	std::cout << li.size() << '\n';

	li.push_back(1)
		.push_back(2)
		.push_back(3);

	std::cout << li.size() << '\n';

	return 0;
}