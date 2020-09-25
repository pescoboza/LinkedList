#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <exception>
#include <memory>

template <typename T>
class LinkedList
{
	struct Node;
	using NodePtr = std::unique_ptr<Node>;

	struct Node{
		T m_data;
		NodePtr m_next;

		Node(const T &value);
	};

	NodePtr m_head;
	Node *m_tail;

	// Retrieves the last node unique ptr of the list
	// Complexity: O(n)
	NodePtr &getLast();

public:
	LinkedList();

	// Returns the size of the list
	// Complexity: O(n)
	size_t size() const;

	// Rerturns the value at position n
	// Complexity: O(n)
	T at(size_t n) const;
	T& at(size_t n);

	// Syntax wrapper for Linkedlist::at()
	T operator[](size_t n) const;
	T &operator[](size_t n);

	// Returns the value at the tail of the list
	// Complexity: O(1)
	T back() const;
	T& back();

	// Returns the value at the head of the list
	// Complexity: O(1)
	T front() const;
	T &front();

	// Inserts a copy of the value at the tail
	// Complexity: O(n)
	LinkedList &push_back(T value);

	// Discards the value at the tail
	// Complexity: O(1)
	LinkedList &pop_back();

	// Whether or not the list is empty
	// Conplexity: O(1)
	bool empty() const;
};

template<typename T>
inline LinkedList<T>::Node::Node(const T& value) : m_data{ value }, m_next{ nullptr } {}

template<typename T>
inline typename LinkedList<T>::NodePtr& LinkedList<T>::getLast(){
	NodePtr* it{ &m_head };
	while ((*it)->m_next){
		it = &(*it)->m_next;
	}
	return *it;
}

template<typename T>
inline LinkedList<T>::LinkedList() : m_head{ nullptr }, m_tail{ nullptr } {}

template<typename T>
inline size_t LinkedList<T>::size() const {
 	if (!m_head) 
		return 0U;
 	size_t s{1U};
 	const NodePtr *node{&m_head};
 	while ((*node)->m_next){
 		node = &(*node)->m_next;
 		s++;
 	}
 	return s;
 }

template<typename T>
inline T LinkedList<T>::at(size_t n) const {
	const NodePtr* node{ &m_head };
	for (size_t i{ 0U }; i < n; i++){
		if (!node)
			throw std::out_of_range{ "Index out of range." };
		node = &(*node)->m_next;
	}
}

template<typename T>
inline T& LinkedList<T>::at(size_t n) {
 	NodePtr *node{&m_head};
 	for (size_t i{0U}; i < n; i++){
 		if (!node)
 			throw std::out_of_range{"Index out of range."};
 		node = &(*node)->m_next;
 	}

 	return (*node)->m_data;
}

template<typename T>
inline T LinkedList<T>::operator[](size_t n) const{
	return at(n);
}

template<typename T>
inline T& LinkedList<T>::operator[](size_t n){
	return at(n);
}

template<typename T>
inline T LinkedList<T>::back() const{
	return m_tail->m_data;
}

template<typename T>
inline T& LinkedList<T>::back(){
	return m_tail->m_data;
}

template<typename T>
inline T LinkedList<T>::front() const{
	return at(0);
}

template<typename T>
inline T& LinkedList<T>::front(){
	return at(0);
}

template<typename T>
inline LinkedList<T>& LinkedList<T>::push_back(T value){
 	if (!m_head){
 		// First element, make it the tail
 		m_head = std::make_unique<Node>(value);
 		m_tail = m_head.get();
 	}
 	else{
 		// Already something in, to straight to the tail
 		m_tail->m_next = std::make_unique<Node>(value);
 		m_tail = m_tail->m_next.get();
 	}

 	return *this;
 }

template<typename T>
inline LinkedList<T>& LinkedList<T>::pop_back(){
 	if (m_head){
 		getLast().reset();
 		m_tail = getLast().get();
 	}
 	return *this;
}

template<typename T>
inline bool LinkedList<T>::empty() const{
	return static_cast<bool>(m_head);
}

#endif // !LINKED_LIST_HPP