#pragma once

class IntVector;
class IntSorter {
public:
	virtual ~IntSorter() {};
	virtual void operator() (IntVector& aContainer) const {};
};
