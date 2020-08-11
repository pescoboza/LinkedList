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

	NodePtr& getLast();

public:
	LinkedList();
	size_t size() const;

	int at(size_t n) const;
	int& at(size_t n);
	
	int operator[](size_t n) const;
	int& operator[](size_t n);

	int back() const;
	int& back();

	LinkedList& push_back(int value);
	LinkedList& pop_back();

	bool empty() const;
	

};



#endif // !LINKED_LIST_HPP