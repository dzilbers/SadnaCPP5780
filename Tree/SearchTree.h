#ifndef __SEARCH_TREE_H_
#define __SEARCH_TREE_H_

#include "Tree.h"

template <typename T, typename Key>
class SearchTree : public BinaryTree<T, Key> {
	using typename BinaryTree<T, Key>::GetKey;
	using typename BinaryTree<T, Key>::ValueProc;
	using BinaryTree<T, Key>::root;
	using BinaryTree<T, Key>::_getKey;
public:
	SearchTree() {}
	SearchTree(GetKey getKey, ValueProc del) : BinaryTree<T, Key>(getKey, del) {}
	SearchTree(const SearchTree&) = delete;
	SearchTree(SearchTree&&) = delete;
	SearchTree& operator=(const SearchTree&) = delete;
	SearchTree& operator=(SearchTree&&) = delete;

	// protocol for search trees
	void add(T value);
	bool search(Key key) const { return search(root, key); }
	void remove(Key key);
	int level(Key key) const;

private:
	using Node = typename BinaryTree<T, Key>::Node;
	void add(Node*, T);
	bool search(Node*, Key) const;

};

template <typename T>
class SearchTreeSimple : public SearchTree<T, T> {};

template <typename T, typename Key>
void SearchTree<T, Key>::add(T val) {
	// add value to binary search tree
	if (root == nullptr) {
		root = new Node(val);
	}
	else
		add(root, val);
}

template <typename T, typename Key>
bool SearchTree<T, Key>::search(Node* current, Key key) const {
	// see if argument value occurs in tree
	if (current == nullptr)
		return false; // not found
	if (_getKey(current->value) == key)
		return true;
	if (_getKey(current->value) < key)
		return search(current->right, key);
	else
		return search(current->left, key);
}

template <typename T, typename Key>
void SearchTree<T, Key>::add(Node* current, T val)
{
	if (_getKey(current->value) < _getKey(val))
		// add to right subtree
		if (current->right == nullptr)
			current->right = new Node(val);
		else
			add(current->right, val);
	else
		// add to left subtree
		if (current->left == nullptr)
			current->left = new Node(val);
		else
			add(current->left, val);
}

template <typename T, typename Key>
void SearchTree<T, Key>::remove(Key key) {
	//HOME WORK!
}

template <typename T, typename Key>
int SearchTree<T, Key>::level(Key key) const {
	//HOME WORK!
	return 0;
}

#endif // __SEARCH_TREE_H_
