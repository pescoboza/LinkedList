#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <exception>
#include <memory>

class LinkedList {
	struct Node;
	using NodePtr = std::unique_ptr<Node>;
	
	struct Node {
		int m_data;
		NodePtr m_next;
	};

	NodePtr m_head;

public:
	LinkedList();
	size_t size() const;

	int at(size_t n) const;
	int& at(size_t n);
	
	int operator[](size_t n) const;
	int& operator[](size_t n);

	

};

inline LinkedList::LinkedList() : m_head{ nullptr }{}

inline size_t LinkedList::size() const{
	if (!m_head) return 0U;
	size_t s{0U};
	const NodePtr* node{&m_head};
	while ((*node)->m_next) {
		node = &(*node)->m_next;
		s++;
	}
	return s;
}

int LinkedList::at(size_t n) const{
	if (!m_head) return 0U;
	
	size_t i{0U};
	const NodePtr* node{ &m_head };
	while (i++ != n) {
		if (!node) throw std::out_of_range{"Index out of range."};
		node = &(*node)->m_next;
	}
	return (*node)->m_data;
}

inline int& LinkedList::at(size_t n) {
	size_t i{ 0U };
	const NodePtr* node{ &m_head };
	while (i++ != n) {
		if (!node) throw std::out_of_range{ "Index out of range." };
		node = &(*node)->m_next;
	}
	return (*node)->m_data;
}

inline int LinkedList::operator[](size_t n) const{
	return at(n);
}

inline int& LinkedList::operator[](size_t n){
	return at(n);
}





#endif // !LINKED_LIST_HPP

