#pragma once 
#include "DoublyLinkedList.h" 
#include "DoublyLinkedListIterator.h" 
#include <stdexcept> 
using namespace std;
template<typename T>
class List
{
private:
	// auxiliary definition to simplify node usage 
	using Node = DoublyLinkedList<T>;
	Node *fRoot; // the first element in the list 
	size_t fCount; // number of elements in the list 
public:
	// auxiliary definition to simplify iterator usage 
	using Iterator = DoublyLinkedListIterator<T>;
	List() {
		fRoot = NULL;
		fCount = 0;
	} // default constructor 
	List(const List& aOtherList) {
		for (Iterator f = aOtherList.begin(); f != aOtherList.end(); ++f) {
			push_back(*f);
		}
	} // copy constructor 
	List& operator=(const List& aOtherList) {
		fRoot = NULL;
		fCount = 0;
		for (Iterator a = this->begin(); a != this->end(); a++) { //remove if exist 
			this->remove(*a);
		}
		for (Iterator f = aOtherList.begin(); f != aOtherList.end(); ++f) {
			push_back(*f);
		}
		return *this;
	} // assignment operator 
	~List()                                                             // destructor - frees all nodes
	{
		while (fRoot != nullptr)
		{
			if (fRoot != &fRoot->getPrevious())                       // more than one element
			{
				Node * lTemp = const_cast<Node*>(&fRoot->getPrevious()); // select last

				lTemp->isolate();                                       // remove from list
				delete lTemp;                                           // free
			}
			else
			{
				delete fRoot;                                           // free last
				break;                                                  // stop loop
			}
		}
	}
	bool isEmpty() const {
		if (this->fCount == 0) {
			return true;
		}
		return false;
	}
	size_t size() const {
		if (isEmpty()) {
			return 0;
		}
		else {
			return fCount;
		}
	} // list size 
	void push_front(const T& aElement) {
		Node *el = new Node(aElement);
		if (isEmpty()) {
			fRoot = el;
		}
		else {
			fRoot->push_front(*el);
			fRoot = el;
		}
		fCount += 1;
	}// adds aElement at front 
	void push_back(const T& aElement) {
		Node* el = new Node(aElement);
		if (isEmpty()) {
			fRoot = el;
		}
		else {
			Node* a = (Node*)&fRoot->getPrevious();
			a->push_back(*el);
		}
		fCount += 1;
	} // adds aElement at back 
	void remove(const T& aElement)                                 // removefirst match from list
	{
		Node* lNode = fRoot;                                            // start at first

			while (lNode != nullptr)                                      // Are there still nodes available ?
			{
				if (**lNode == aElement)                                  // Have we found the node ?
				{
					break;                                                  // stop thesearch
				}
				if (lNode != &fRoot->getPrevious())                       // not reached last
				{
					lNode = const_cast<Node*>(&lNode->getNext());           // go to next
				}
				else
				{
					lNode = nullptr;                                        // stop search
				}
			}

		// At this point we have either reached the end or found the node.
		if (lNode != nullptr)                                         // We have found the node.
		{
			if (fCount != 1)                                          // not the last element
			{
				if (lNode == fRoot)
				{
					fRoot = const_cast<Node*>(&fRoot->getNext());       // make next root
				}
			}
			else
			{
				fRoot = nullptr;                                        // list becomes empty
			}

			lNode->isolate();                                           // isolate node
				delete lNode;                                               // release node's memory
				fCount--;                                                   // decrement count
		}
	}
	const T& operator[](size_t aIndex) const {
		Node* el = fRoot;
		if (aIndex >= fCount)
		{
			throw std::range_error("Index out of range");
		}

		for (size_t i = 0; i < aIndex; i++)
		{
			el = (Node*) &el->getNext();
		}

		return **el;
	} // list indexer 
	Iterator begin() const {
		Iterator it(fRoot);
		return it.begin();
	} // return a forward iterator 
	Iterator end() const {
		Iterator it(fRoot);
		return it.end();
	} // return a forward end iterator 
	Iterator rbegin() const {
		Iterator it(fRoot);
		return it.rbegin();
	} // return a backwards iterator 
	Iterator rend() const {
		Iterator it(fRoot);
		return it.rend();
	} // return a backwards end iterator 
	// move features 
	List(List&& aOtherList) {
		fRoot = aOtherList.fRoot;
		fCount = aOtherList.fCount;
		aOtherList.fRoot = NULL;
		aOtherList.fCount = 0;
	} // move constructor 

	void push_front(T&& aElement) {
		Node* el = new Node(move(aElement));

		if (isEmpty())
		{
			fRoot = el;
		}
		else
		{
			fRoot->push_front(*el);
			fRoot = el;
		}
		fCount += 1;
	} // adds aElement at front 
	void push_back(T&& aElement) {
		Node* el = new Node(move(aElement));

		if (isEmpty())
		{
			fRoot = el;
		}
		else
		{
			Node* a = (Node*) &fRoot->getPrevious();
			a->push_back(*el);
		}
		fCount += 1;
	} // adds aElement at back 
};
