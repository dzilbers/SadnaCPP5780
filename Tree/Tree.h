#ifndef __TREE_H_
#define __TREE_H_

#include <iostream>
//#include "Iterators.h"

enum Mode { PREORDER, INORDER, POSTORDER };

//-----------------------------------
// class BinaryTree (Binary Trees)
// process nodes in Pre/In/Post order
//-----------------------------------
template <typename T, typename Key>
class BinaryTree {
	Mode _mode;

protected:
	//--------------------------------------------------------
	// inner class Node
	// a single Node from a binary tree
	//--------------------------------------------------------
	class Node {
	public:
		Node* left;
		Node* right;
		T value;
		Node(T val) : value(val), left(nullptr), right(nullptr) {}
		Node(T val, Node* l, Node* r) : value(val), left(l), right(r) {}
	}; //end of Node class

	using GetKey = Key(*)(T);
	using ValueProc = void(*)(T);

	GetKey _getKey;
	ValueProc _delete;

	Node* root;
	virtual void process(Node* node, ValueProc pr) const { pr(node->value); }

public:
	BinaryTree(GetKey getKey, ValueProc del) : root(nullptr), _mode(INORDER),
		_getKey(getKey), _delete(del) {}
	BinaryTree() : BinaryTree([](T value) { return(Key)value; }, [](T value) {}) {}
	virtual ~BinaryTree() { if (root != nullptr) clear(root); }
	BinaryTree(const BinaryTree&) = delete;
	BinaryTree(BinaryTree&&) = delete;
	BinaryTree& operator=(const BinaryTree&) = delete;
	BinaryTree& operator=(BinaryTree&&) = delete;

	void mode(Mode mode) { _mode = mode; }
	Mode mode() const { return _mode; }

	bool isEmpty() const { return root == nullptr; }
	void clear() { clear(root); root = nullptr; }
	void process(ValueProc) const;
	void process() const { process([](T value) { std::cout << value << " "; }); };

	virtual void add(T) = 0;
	virtual bool search(Key) const = 0;
	virtual void remove(Key) = 0;

private:
	void preOrder(ValueProc pr) const { preOrder(root, pr); }
	void inOrder(ValueProc pr) const { inOrder(root, pr); }
	void postOrder(ValueProc pr) const { postOrder(root, pr); }
	void clear(Node*);
	void preOrder(Node*, ValueProc) const;
	void inOrder(Node*, ValueProc) const;
	void postOrder(Node*, ValueProc) const;

public:
	int leaves() const;
	int height() const;
	int onlyLeftSons() const;
	void reflect();
};

//----------------------------------------------------------
// class BinaryTree implementation
//----------------------------------------------------------
template <typename T, typename Key>
void BinaryTree<T, Key>::clear(Node* current) {
	if (current != nullptr) { // Release memory associated with children
		clear(current->left);
		clear(current->right);
		_delete(current->value);
		delete current;
	}
}

// preOrder processing of tree rooted at current
template <typename T, typename Key>
void BinaryTree<T, Key>::preOrder(Node* current, ValueProc pr) const {
	// visit Node, left child, right child
	if (current != nullptr) { // process current Node
		process(current, pr);
		// then visit children
		preOrder(current->left, pr);
		preOrder(current->right, pr);
	}
}
// inOrder processing of tree rooted at current
template <typename T, typename Key>
void BinaryTree<T, Key>::inOrder(Node* current, ValueProc pr) const {
	// visit left child, Node, right child
	if (current != nullptr) {
		inOrder(current->left, pr);
		process(current, pr);
		inOrder(current->right, pr);
	}
}
// postOrder processing of tree rooted at current
template <typename T, typename Key>
void BinaryTree<T, Key>::postOrder(Node* current, ValueProc pr) const {
	// visit left child, right child, node
	if (current != nullptr) {
		postOrder(current->left, pr);
		postOrder(current->right, pr);
		process(current, pr);
	}
}

template <typename T, typename Key>
void BinaryTree<T, Key>::process(ValueProc pr) const {
	switch (_mode) {
	case PREORDER:
		preOrder(pr);
		break;
	case INORDER:
		inOrder(pr);
		break;
	case POSTORDER:
		postOrder(pr);
		break;
	}
}

template <typename T, typename Key>
int BinaryTree<T, Key>::leaves()  const {
	/* HOMEWORK */
	return 0;
}

template <typename T, typename Key>
int BinaryTree<T, Key>::height() const {
	/* HOMEWORK */
	return 0;
}

template <typename T, typename Key>
int BinaryTree<T, Key>::onlyLeftSons()  const {
	/* HOMEWORK */
	return 0;
}

template <typename T, typename Key>
void BinaryTree<T, Key>::reflect() {
	/* HOMEWORK */
}

#endif // __TREE_H_
