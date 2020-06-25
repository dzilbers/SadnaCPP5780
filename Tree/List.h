// List.h
#ifndef __LIST_H
#define __LIST_H

#include<iostream>

template <typename T> class List;
template <typename T> void makeSet(List<T>&);
template <typename T> std::istream& operator>>(std::istream&, List<T>&);

//------------------------------------------------
// Class List - Arbitrary size Lists
// Permits insertion and removal only from the front of the List
//------------------------------------------------
template <typename T>
class List {
protected:
	//--------------------------------------------
	// inner class Node a single element for the Nodeed List
	//--------------------------------------------
	class Node {
		T   _value;
		Node* _next;
	public:
		// constructor
		Node(int val, Node* nxt) : _value(val), _next(nxt) {}
		Node(const Node& src) : _value(src._value), _next(src._next) {}
		// data areas
		T   value() const { return _value; } // getter only
		Node* next() const { return _next; }  // getter
		void  next(Node* nxt) { _next = nxt; }   // setter
	}; //end of class Node

public:
	// constructors
	List() : head(nullptr) {}
	List(const List&);
	List(List&&);
	~List();
	// operations
	List& operator = (const List& other);
	List& operator = (List&& lst);

	friend void makeSet<>(List&);
	template <typename T> friend List merge(List&, List&);

	void insert(T key);
	void remove(T key);
	void add(T value);
	T  firstElement() const;
	bool search(const T&) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();

	friend std::istream& operator>> <>(std::istream&, List&);
	template <typename T> friend std::ostream& operator<<(std::ostream&, const List&);
protected:
	// data field
	Node* head;
};

template <typename T>
List<T>::List(const List& other) {}

template <typename T>
List<T>::List(List&& other) {}

template <typename T>
List<T>::~List() {}

template <typename T>
List<T>& List<T>::operator=(const List& other) { return *this; }

template <typename T>
List<T>& List<T>::operator=(List&& other) { return *this; }

template <typename T>
void List<T>::clear() {}

template <typename T>
bool List<T>::isEmpty() const {}

template <typename T>
void List<T>::insert(T key) {}

template <typename T>
void List<T>::remove(T key) {}

template <typename T>
void List<T>::add(T val) {}

template <typename T>
T List<T>::firstElement() const { T value; return value; }

template <typename T>
bool List<T>::search(const T& val) const { return false; }

template <typename T>
void List<T>::removeFirst() {}

template <typename T>
List<T> merge(List<T>& lst1, List<T>& lst2) { List<T> lst; return lst; }

template <typename T>
void makeSet(List<T>& lst) {}

template <typename T>
std::ostream& operator<<(std::ostream& out, const List<T>& lst) { return out; }

template <typename T>
std::istream& operator>>(std::istream& in, List<T>& lst) { return in; }

#endif //__LIST_H