#pragma once 
#include "BNode.h" 
template<typename T>
class BinarySearchTreeIterator;

template<typename T>
class BinarySearchTree
{
private:
	BNode<T>* fRoot;

public:
	using Iterator = BinarySearchTreeIterator<T>;

	BinarySearchTree() {
		//set can be empty
		fRoot = &BNode<T>::NIL;
	}
	~BinarySearchTree() {
		std::remove(NULL);
	}

	bool empty() const {
		return fRoot->empty();
	}
	bool insert(const T& aKey) {
		if (empty()) {
			return fRoot = new BNode<T>(aKey);
		}
		return fRoot->insert(aKey);
	}
	bool remove(const T& aKey) {
		return fRoot->remove(aKey, fRoot);
	}

	size_t height() const {
		return fRoot->height();
	}
	Iterator begin() const {
		// iterator positioned at root of tree
		return Iterator(fRoot);
	}
	Iterator end() const {
		// iterator positioned at end of tree (NIL)
		return Iterator(&BNode<T>::NIL);
	}

};