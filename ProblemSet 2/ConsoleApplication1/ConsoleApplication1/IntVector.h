#pragma once

#include <cstddef>
#include "IntSorter.h"

#include "CocktailShakerSort.h"
#include "IntVectorIterator.h"
class IntVector {
private:
	int* fElements;
	size_t fNumberOfElements;

public:
	IntVector(const int aArrayOfIntegers[], size_t aNumberOfElements = 0);
	~IntVector();

	size_t size() const;

	void swap(size_t aSourceIndex, size_t aTargerIndex);

	void sort(const IntSorter& aSorter);
	bool inRangeCheck(int arr[], size_t A, size_t B, size_t n);
	const int operator[](size_t aIndex) const;
	const IntVector getObject() {
		return *this;
	};
	IntVectorIterator begin() const;
	IntVectorIterator end() const;
};

