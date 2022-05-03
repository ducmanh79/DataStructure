#pragma once
#include "IntVector.h"
#include "IntSorter.h"
#include "IntVectorIterator.h"
#include "CocktailShakerSort.h"
#include <iostream>
#include <stdexcept>
using namespace std;
IntVector::IntVector(const int aArrayOfIntergers[], size_t aNumberOfElements) {
	fNumberOfElements = aNumberOfElements;
	fElements = new int[fNumberOfElements];
	for (size_t i = 0; i < fNumberOfElements; i++) {
		fElements[i] = aArrayOfIntergers[i];
	}
}
IntVector::~IntVector() {
	delete[] fElements;
}
size_t IntVector::size() const {
	return fNumberOfElements;
}
bool IntVector::inRangeCheck(int arr[], size_t A, size_t B, size_t n) {
	bool inR1 = false, inR2 = false;
	for (int i = 0; i < n; i++) {
		if (arr[i] == arr[A]) {
			inR1 = true;
		}
	}
	for (int j = 0; j < n; j++) {
		if (arr[j] == arr[B]) {
			inR2 = true;
		}
	}
	if (inR1 && inR2)
		return true;
	else
		return false;
}
void IntVector::swap(size_t aSourceIndex, size_t aTargetIndex) {
	int temp = 0;

	if (inRangeCheck(fElements, aSourceIndex, aTargetIndex, fNumberOfElements)) {
		temp = fElements[aSourceIndex];
		fElements[aSourceIndex] = fElements[aTargetIndex];
		fElements[aTargetIndex] = temp;
	}
	else {
		throw std::out_of_range("illegal vector index");
	}

}

void IntVector::sort(const IntSorter& aSorter) {
	aSorter(*this);
}

const int IntVector::operator[](size_t aIndex) const {
	if (aIndex < fNumberOfElements) {
		return fElements[aIndex];
	}
	else {
		throw out_of_range("illegal vector index");
	}
}
IntVectorIterator IntVector::begin() const {
	return IntVectorIterator(*this,0);
}

IntVectorIterator IntVector::end() const {
	return IntVectorIterator(*this, size());
}