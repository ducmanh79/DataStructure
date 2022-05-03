#pragma once
#pragma once 
#include <stdexcept>
template<typename S>
struct BNode
{
	S key;
	BNode<S>* left;
	BNode<S>* right;
	static BNode<S> NIL;
	const S& findMax()const {
		if (empty())
			throw std::domain_error("Error tree empty");

		if (right->empty()) {
			return key;
		}
		else {
			right->findMax();
		}
	}
	const S& findMin() const {
		if (empty())
			throw std::domain_error("Error tree empty");

		if (left->empty()) {
			return key;
		}
		else {
			left->findMin();
		}
	}
	bool remove(const S& aKey, BNode<S>* aParent) {
		BNode<S>* x = this;
		BNode<S>* y = aParent;
		// find value of removing node
		while (!x->empty()) {
			if (aKey == x->key)
				break;

			y = x;
			x = aKey < x->key ? x->left : x->right;
		}

		if (x->empty())
			return false;
		// delete from the leaf of left or right
		if (!x->left->empty()) {
			const S& aKey = x->left->findMax();
			x->key = aKey;
			x->left->remove(aKey, x);
		}
		else {
			if (!x->right->empty()) {
				const S& aKey = x->right->findMin();
				x->key = aKey;
				x->right->remove(aKey, x);
			}
			else {
				if (y->left == x) {
					y->left = &NIL;
				}
				else {
					y->right = &NIL;
				}
				delete x;
			}
		}
		return true;
	}
	BNode() {
		left = &NIL;
		right = &NIL;
	}
	BNode(const S& aKey) {
		key = aKey;
		left = &NIL;
		right = &NIL;
	}
	BNode(S&& aKey) {
		key = std::move(aKey);
		left = &NIL;
		right = &NIL;
	}
	~BNode() {
		//remove nodes which is null
		remove(NULL, this);
	}
	bool empty() const {
		return this == &NIL;
	}
	bool leaf() const {
		if (left == &NIL && right == &NIL) {
			return true;
		}
		return false;
	}
	size_t height() const {
		if (leaf())
			return 0; //leaves are all at height zero

		return max(left->height(), right->height()) + 1; //distances from nodes to leaves
	}
	bool insert(const S& aKey) {
		BNode<S>* x = this;
		BNode<S>* y = &BNode<S>::NIL;

		while (!x->empty()) {
			y = x;
			if (aKey == x->key) {
				return false;
			}

			x = aKey < x->key ? x->left : x->right;
			//cout << "X" << x->key << endl;
			//cout << "Y" << y->key << endl;
		}

		BNode<S>* z = new BNode<S>(aKey);

		if (y->empty()) {
			return false;
		}
		else {
			if (aKey < y->key) {
				y->left = z;;
			}
			else {
				y->right = z;
			}
		}
		return true;
	}
};
template<typename S>
BNode<S>
BNode<S>::NIL;