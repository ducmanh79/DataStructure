#pragma once

#include "DoublyLinkedList.h"
using namespace std;
template<typename T>
class DoublyLinkedListIterator {
private:
	enum class States {BEFORE, DATA, AFTER};

	using Node = DoublyLinkedList<T>;

	const Node* fRoot; //doubly-linked list

	States fState; //iterator state
	const Node* fCurrent; //iterator position

public:
	using Iterator = DoublyLinkedListIterator<T>;

	DoublyLinkedListIterator(const Node* aRoot) {
		fRoot = aRoot;
	}

	const T& operator*() const {
		return fCurrent->getPayLoad();
	}
	Iterator& operator++() {
		switch (fState) //we check the iterator state 
		{
			case States::BEFORE: //if iterator is before the first DoublyLinkedList 
				fCurrent = fRoot; //set this iterator to become the first 
				if (fCurrent == NULL) { 
					fState = States::AFTER; //if this iterator is null, it's determined as outside the list
				}
				else{
					fState = States::DATA; //else this node state is inside the list 
				}
				break;
			case States::DATA: //iterator in list
				if (fCurrent == &fRoot->getPrevious()) { //if iterator the last node, cannot move to the next element
					fCurrent = NULL; 
					fState = States::AFTER;
				}
				else {
					fCurrent = &fCurrent->getNext(); //move to next node
				}
				break;
			default:
				break;
		}
		return *this;
	}
	Iterator operator++(int) {
		Iterator temp = *this;
		++(*this);
		return temp;
	}
	Iterator& operator--() {
		switch (fState) {
		case States::DATA: //iterator inside the list
			if (fCurrent == fRoot) {
				fCurrent = NULL; //during the list if the iterator is positioned at first element, the iterator can't decrease
				fState = States::BEFORE; //break
			}
			else {
				fCurrent = &fCurrent->getPrevious();
			}
			break;
		case States::AFTER: //iterator outside the list
			fCurrent = fRoot;
			if (fCurrent == NULL) {
				fState = States::BEFORE;
			}
			fCurrent = &fCurrent->getPrevious();
			fState = States::DATA;
			break;
		default:
			break;
		}
		return *this;
	}
	Iterator operator--(int) {
		Iterator temp = *this;
		--(*this);
		return temp;
	}
	bool operator==(const Iterator& aOtherIter) const {
		return (fRoot == aOtherIter.fRoot && fCurrent == aOtherIter.fCurrent
			&& fState == aOtherIter.fState);
	}
	bool operator!=(const Iterator& aOtherIter) const {
		return !(*this == aOtherIter);
	}

	Iterator begin() const {
		Iterator temp = rend();
		++temp;
		return temp;
	}
	Iterator end() const {
		Iterator temp = *this;
		temp.fCurrent = NULL;
		temp.fState = States::AFTER;
		return temp;
	}
	Iterator rbegin() const {
        Iterator temp = end();          
        --temp;                         
        return temp;
	}
	Iterator rend() const {
		Iterator temp = *this;
		temp.fCurrent = NULL;
		temp.fState = States::BEFORE;
		return temp;
	}
};