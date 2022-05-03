#pragma once
template<typename T>
class DoublyLinkedList {
private:
	T fPayLoad;
	DoublyLinkedList* fNext;
	DoublyLinkedList* fPrevious;

public:
	explicit DoublyLinkedList(const T& aPayLoad) {
		fPayLoad = aPayLoad;
		fNext = this;
		fPrevious = this;
	}
	explicit DoublyLinkedList(T&& aPayLoad) {
		fPayLoad = aPayLoad;
		fNext = this;
		fPrevious = this;
	}

	DoublyLinkedList& push_front(DoublyLinkedList& aNode) {
		aNode.fNext = this; //aNode comes before this so Next of aNode will be this
		aNode.fPrevious = fPrevious; //inserted between this and fPrevious so aNode.fPrevious will become the current fPrevious
		fPrevious->fNext = &aNode; //current fPrevious's Next will become aNode
		fPrevious = &aNode; // set fPrevious of this become aNode
		return aNode;
	}
	DoublyLinkedList& push_back(DoublyLinkedList& aNode) {
		aNode.fPrevious = this; //aNode comes after this so Previous of aNode will be this
		aNode.fNext = fNext; // aNode next will be come the current fNext of this
		fNext->fPrevious = &aNode; // current fNext's fPrevious will become aNode
		fNext = &aNode; //set fNext of this become aNode

		return aNode;
	}
	void isolate() {
		fPrevious->fNext = fNext; //set fNext of fPrevious become the fNext of removed node
		fNext->fPrevious = fPrevious; //set the previous of next node become fPrevious of removed node
		fNext, fPrevious = NULL;
	}

	void swap(DoublyLinkedList& aNode) {
		T temp = fPayLoad;
		fPayLoad = aNode;
		aNode = temp;
	}

	const T& operator*() const {
		return getPayLoad();
	}
	const T& getPayLoad() const {
		return fPayLoad;
	}
	const DoublyLinkedList& getPrevious() const {
		return *fPrevious;
	}
	const DoublyLinkedList& getNext() const
	{
		return *fNext;
	}
};