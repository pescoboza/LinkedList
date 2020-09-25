#include <iostream>
#include <string>

#include "LinkedList.hpp"

void test_2(){
	
	LinkedList<std::string> li;
	li.push_back("Hello")
		.push_back("how")
		.push_back("are")
		.push_back("you?");
	
	auto size{li.size()};

	for (unsigned i{ 0U }; i < size; i++) {
		std::cout << li[i] << '\n';
	}
	std::cout << "\n\n";
	return;
}

void test_1() {
	LinkedList<int> li;
	std::cout << std::boolalpha << "empty: " << li.empty() << "  size: " << li.size() << "\n\n";


	li.push_back(70)
		.push_back(71)
		.push_back(72)
		.push_back(73)
		.push_back(74)
		.push_back(75)
		.push_back(76)
		.push_back(77)
		.pop_back()
		.pop_back();

	li.back() = 123123;

	unsigned size{ li.size() };

	std::cout << std::boolalpha << "empty: " << li.empty() << "  size: " << li.size() << "\n\n";

	for (unsigned i{ 0U }; i < size; i++) {
		std::cout << li[i] << std::endl;
	}
}

void test_3() {
	LinkedList<std::string> li;
	li.emplace(0, "hello")
		.emplace(1, "bye");
	
	auto size{li.size()};
	for (unsigned i{ 0U }; i < size; i++) {
		std::cout << li[i] << std::endl;
	}
}

int main() {

	// test_1();
	// test_2();
	test_3();



	return 0;
}