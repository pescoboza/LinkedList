#include <iostream>
#include <string>

#include "LinkedList.hpp"

template <typename T>
void print(LinkedList<T>& li, const char* sep = "\n", std::ostream& out = std::cout) {
	size_t size{li.size()};
	for (size_t i{ 0U }; i < size; i++) 
		out << li[i] << sep;
}

void test_2(){
	
	LinkedList<std::string> li;
	li.push_back("Hello")
		.push_back("how")
		.push_back("are")
		.push_back("you?");
	
	auto size{li.size()};
	print(li);
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
	print(li);
}

void test_3() {
	LinkedList<int> li;
	li.emplace(0, 11)
		.emplace(1, 12)
		.emplace(2, 13)
		.emplace_back(1231)
		.emplace_back(1111111)
		.emplace(1,455)
		.emplace_front(666666666)
		.emplace_front(666666667)
		.push_front(1000)
		.pop_front()
		.pop_front()
		.pop_back();
	
	print(li);
}

void test_4() {
	LinkedList<int> li;
	li.emplace_back(11)
		.emplace_back(12)
		.emplace_back(13)
		.emplace_back(14)
		.emplace_back(15)
		.emplace_back(16)
		.erase(4);
	print(li);
}

void test_5() {
	LinkedList<long long int> li;
	li.emplace_back(55)
		.emplace_back(77)
		.emplace_back(44)
		.emplace_back(22)
		.emplace_back(11)
		.emplace_back(33)
		.emplace_back(99)
		.emplace_back(88);
	std::cout << "Unsorted:\n";
	print(li, " ");
	
	li.sort();
	std::cout << "\n\nSorted:\n";
	print(li, " ");
}

int main() {
	try {
		// test_1();
		// test_2();
		// test_3();
		// test_4();
		test_5();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}