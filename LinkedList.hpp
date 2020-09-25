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
		template <class ...Args>
		Node(Args&& ...args);

		// Inserts the given node on this node.
		// Complexity: O(1)
		void insertNextTo(NodePtr toInsert);

		// Constructs a node in place with the arguments of its data.
		// Complexity: O(1)
		template <class ...Args>
		void emplace(Args&& ...args);
	};

	NodePtr m_head;
	Node *m_tail;

	// Retrieves the last node unique ptr of the list
	// Complexity: O(n)
	NodePtr &getLast();

	// Retrieves the nth node unique ptr of the list
	// Complexity: O(n)
	NodePtr& getNth(size_t);

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

	// Constructs element in place at given position
	// Complexity: O(n)
	template <class ...Args>
	LinkedList& emplace(size_t pos, Args&&... args);

	// Constructs element in place at back
	// Complexity: O(1)
	template <class ...Args>
	LinkedList& emplace_back(Args&&... args);
	
	// Constructs element in place at front
	// Complexity: O(1)
	template <class ...Args>
	LinkedList& emplace_front(Args&&... args);

	// Inserts a copy of the value at the tail
	// Complexity: O(1)
	LinkedList &push_back(T value);

	// Inserts a copy of the value at the front
	// Complexity: O(1)
	LinkedList& push_front(T value);

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
inline void LinkedList<T>::Node::insertNextTo(NodePtr toInsert){
	if (!toInsert) return;
	if (toInsert->m_next)
		throw std::runtime_error{ "Node to insert has children." };

	if (m_next) {
		NodePtr next{std::move(m_next)};
		m_next = std::move(toInsert);
		m_next->m_next = std::move(next);
	}
	else {
		m_next = std::move(toInsert);
	}
}

template <typename T>
template <class ...Args>
inline void LinkedList<T>::Node::emplace(Args&& ...args) {
	if (m_next) {
		NodePtr next{ std::move(m_next) };
		m_next = std::make_unique<Node>(args...);
		m_next->m_next = std::move(next);
	}
	else {
		m_next = std::make_unique<Node>(args...);
	}
}

template<typename T>
inline typename LinkedList<T>::NodePtr& LinkedList<T>::getLast(){
	NodePtr* it{ &m_head };
	while ((*it)->m_next){
		it = &(*it)->m_next;
	}
	return *it;
}

template<typename T>
inline typename LinkedList<T>::NodePtr& LinkedList<T>::getNth(size_t n) {
	NodePtr* it{ &m_head };
	for (size_t i{ 0U }; i < n; i++) {
		if (!it)
			throw std::out_of_range{ "Index out of range." };
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
	return getNth(n)->m_data;
}

template<typename T>
inline T& LinkedList<T>::at(size_t n) {
	return getNth(n)->m_data;
}

template<typename T>
inline T LinkedList<T>::operator[](size_t n) const{
	return getNth(n)->m_data;
}

template<typename T>
inline T& LinkedList<T>::operator[](size_t n){
	return getNth(n)->m_data;
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
	return getNth(0)->m_data;
}

template<typename T>
inline T& LinkedList<T>::front(){
	return getNth(0)->m_data;
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
 		m_tail->m_next = std::make_unique<Node>();
		m_tail->m_next->m_data = value;
 		m_tail = m_tail->m_next.get();
 	}

 	return *this;
 }

template<typename T>
inline LinkedList<T>& LinkedList<T>::push_front(T value){
	if (!m_head) {
		m_head = std::make_unique<Node>();
		m_tail = m_head.get();
	}
	else {
		NodePtr next{ std::move(m_head) };
		m_head = std::make_unique<Node>();
		m_head->m_next = std::move(next);
		m_tail = getLast().get();
	}
	m_head->m_data = value;
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

template<typename T>
template<class ...Args>
inline LinkedList<T>& LinkedList<T>::emplace(size_t pos, Args&& ...args){
	
	// List is empty 
	if (pos == 0 && !m_head) {
		m_head = std::make_unique<Node>(args...);	
	}
	else {
		// Mine the (pos - 1)th  node
		NodePtr& node{ getNth(pos - 1) };

		// Construct the new node next to it
		node->emplace(args...);
	}


	// Update the tail
	m_tail = getLast().get();

	return *this;
}

template<typename T>
template<class ...Args>
inline LinkedList<T>& LinkedList<T>::emplace_back(Args && ...args){
	m_tail->m_next = std::make_unique<Node>(args...);
	m_tail = m_tail->m_next.get();
	return *this;
}

template<typename T>
template<class ...Args>
inline LinkedList<T>& LinkedList<T>::emplace_front(Args && ...args){
	if (!m_head) {
		m_head = std::make_unique<Node>(args...);
		m_tail = m_head.get();
	}
	else {
		NodePtr next{std::move(m_head)};
		m_head = std::make_unique<Node>(args...);
		m_head->m_next = std::move(next);
		m_tail = getLast().get();
	}
	return *this;
}

template<typename T>
template<class ...Args>
inline LinkedList<T>::Node::Node(Args&& ...args) : m_data{ args... }, m_next{nullptr} {}
