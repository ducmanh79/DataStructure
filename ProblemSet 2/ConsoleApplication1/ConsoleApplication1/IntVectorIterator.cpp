#include "IntVector.h"
#include "IntVectorIterator.h"

IntVectorIterator::IntVectorIterator(const IntVector& aContainer, size_t aStart) : fContainer(aContainer), fPosition(aStart) {

}
//IntVectorIterator::IntVectorIterator(const IntVectorIterator& source) : fContainer(source.fContainer),fPosition(source.fPosition) {
//
//};

const int IntVectorIterator::operator*() const {
	return fContainer[fPosition];
}

IntVectorIterator& IntVectorIterator::operator++() {
	fPosition++;
	return *this;
}

IntVectorIterator IntVectorIterator::operator++(int) {
	IntVectorIterator temp = *this;
	++(*this);
	return temp;
}

bool IntVectorIterator::operator==(const IntVectorIterator& aRHS) const {
	return (&fContainer == &aRHS.fContainer) && (fPosition == aRHS.fPosition);
}

bool IntVectorIterator::operator!=(const IntVectorIterator& aRHS) const {
	return !(*this == aRHS);
}

IntVectorIterator IntVectorIterator::begin() const {
	IntVectorIterator Result = *this;
	Result.fPosition = 0;
	return Result;
}

IntVectorIterator IntVectorIterator::end() const {
	IntVectorIterator Result = *this;
	Result.fPosition = Result.fContainer.size();
	return Result;
}