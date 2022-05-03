#pragma once
#include <cstddef>;

class IntVector;
class IntVectorIterator {
private:
	const IntVector& fContainer;
	size_t fPosition;

public:
	IntVectorIterator(const IntVector& aContainer, size_t aStart);
	//IntVectorIterator(const IntVectorIterator&);
	const int operator*() const;
	IntVectorIterator& operator++();
	IntVectorIterator operator++(int);
	bool operator==(const IntVectorIterator& aRHS) const;
	bool operator!=(const IntVectorIterator& aRHS) const;
	IntVectorIterator begin() const;
	IntVectorIterator end() const;
};