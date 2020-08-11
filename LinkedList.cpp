#include "LinkedList.hpp"

LinkedList::Node::Node(int value) : m_data{ value }, m_next{ nullptr }{}


LinkedList::LinkedList() : m_head{ nullptr }, m_tail{ nullptr }{}

size_t LinkedList::size() const {
	if (!m_head) return 0U;
	size_t s{ 0U };
	const NodePtr* node{ &m_head };
	while ((*node)->m_next) {
		node = &(*node)->m_next;
		s++;
	}
	return s;
}

int LinkedList::at(size_t n) const {
	if (!m_head) return 0U;

	size_t i{ 0U };
	const NodePtr* node{ &m_head };
	while (i++ != n) {
		if (!node) throw std::out_of_range{ "Index out of range." };
		node = &(*node)->m_next;
	}
	return (*node)->m_data;
}

int& LinkedList::at(size_t n) {
	size_t i{ 0U };
	const NodePtr* node{ &m_head };
	while (i++ != n) {
		if (!node) throw std::out_of_range{ "Index out of range." };
		node = &(*node)->m_next;
	}
	return (*node)->m_data;
}

int LinkedList::operator[](size_t n) const {
	return at(n);
}

int& LinkedList::operator[](size_t n) {
	return at(n);
}

LinkedList& LinkedList::push_back(int value) {
	m_tail->m_next = std::make_unique<Node>(value);
	m_tail = m_tail->m_next.get();
	return *this;
}