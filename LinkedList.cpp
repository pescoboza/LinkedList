////#include "LinkedList.hpp"
//
// //LinkedList::Node::Node(int value) : m_data{ value }, m_next{ nullptr }{}
//
// LinkedList::NodePtr &LinkedList::getLast()
// {
// 	NodePtr *it{&m_head};
// 	while ((*it)->m_next)
// 	{
// 		it = &(*it)->m_next;
// 	}
// 	return *it;
// }
//
// LinkedList::LinkedList() : m_head{nullptr}, m_tail{nullptr} {}
//
// size_t LinkedList::size() const
// {
// 	if (!m_head)
// 		return 0U;
// 	size_t s{1U};
// 	const NodePtr *node{&m_head};
// 	while ((*node)->m_next)
// 	{
// 		node = &(*node)->m_next;
// 		s++;
// 	}
// 	return s;
// }
//
// int LinkedList::at(size_t n) const
// {
// 	const NodePtr *node{&m_head};
// 	for (size_t i{0U}; i < n; i++)
// 	{
// 		if (!node)
// 			throw std::out_of_range{"Index out of range."};
// 		node = &(*node)->m_next;
// 	}
//
// 	return (*node)->m_data;
// }
//
// int &LinkedList::at(size_t n)
// {
// 	NodePtr *node{&m_head};
// 	for (size_t i{0U}; i < n; i++)
// 	{
// 		if (!node)
// 			throw std::out_of_range{"Index out of range."};
// 		node = &(*node)->m_next;
// 	}
//
// 	return (*node)->m_data;
// }
//
// int LinkedList::operator[](size_t n) const
// {
// 	return at(n);
// }
//
// int &LinkedList::operator[](size_t n)
// {
// 	return at(n);
// }
//
// int LinkedList::back() const
// {
// 	return m_tail->m_data;
// }
//
// int &LinkedList::back()
// {
// 	return m_tail->m_data;
// }
//
// int LinkedList::front() const
// {
// 	return at(0);
// }
//
// int &LinkedList::front()
// {
// 	return at(0);
// }
//
// LinkedList &LinkedList::push_back(int value)
// {
// 	if (!m_head)
// 	{
// 		// First element, make it the tail
// 		m_head = std::make_unique<Node>(value);
// 		m_tail = m_head.get();
// 	}
// 	else
// 	{
// 		// Already something in, to straight to the tail
// 		m_tail->m_next = std::make_unique<Node>(value);
// 		m_tail = m_tail->m_next.get();
// 	}
//
// 	return *this;
// }
//
// LinkedList &LinkedList::pop_back()
// {
// 	if (m_head)
// 	{
// 		getLast().reset();
// 		m_tail = getLast().get();
// 	}
// 	return *this;
// }
//
// bool LinkedList::empty() const
// {
// 	return static_cast<bool>(m_head);
// }
