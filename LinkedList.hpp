#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <stdexcept>
#include <memory>

class LinkedList {
	struct Node;
	using NodePtr = std::unique_ptr<Node>;
	
	struct Node {
		int m_data;
		NodePtr m_next;

		Node(int value);
	};

	NodePtr m_head;
	Node* m_tail;

	// Retrieves the last node of the list
	// Complexity: O(n)
	NodePtr& getLast();

public:
	LinkedList();
	
	// Returns the size of the list
	// Complexity: O(n)
	size_t size() const;

	// Rerturns the value at position n
	// Complexity: O(n)
	int at(size_t n) const;
	int& at(size_t n);
	
	// Syntax wrapper for Linkedlist::at()
	int operator[](size_t n) const;
	int& operator[](size_t n);

	// Returns the value at the tail of the list
	// Complexity: O(1)
	int back() const;
	int& back();

	// Returns the value at the head of the list
	// Complexity: O(1)
	int front() const;
	int& front();

	// Inserts a copy of the value at the tail
	// Complexity: O(n)
	LinkedList& push_back(int value);
	
	// Discards the value at the tail
	// Complexity: O(1)
	LinkedList& pop_back();

	// Whether or not the list is empty
	// Conplexity: O(1)
	bool empty() const;
	
};



#endif // !LINKED_LIST_HPP