#include "Point2DSet.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
void Point2DSet::add(const Point2D& aPoint) {
	fPoints.push_back(aPoint);
}

void Point2DSet::add(Point2D&& aPoint) {
	fPoints.push_back(aPoint);
}

void Point2DSet::removeLast() {
	fPoints.pop_back();
}

bool Point2DSet::doesNotTurnLeft(const Point2D& aPoint) const {

	if (aPoint.isClockwise(fPoints[size() - 1], fPoints[size() - 2])) {
		return true;
	}
	return false;
}


void Point2DSet::populate(const std::string& aFileName) {
	fstream myfile;
	myfile.open(aFileName);
	for (int i = 0; i < 2; i++) {
		myfile.ignore(3, '\n');
	}
	Point2D a;
	while (myfile >> a) {
		fPoints.push_back(a);
	}
}

bool orderByCoordinates(const Point2D& aLeft, const Point2D& aRight) {
	if (aLeft.magnitude() > aRight.magnitude()) {
		return true;
	}

	return false;
}

bool orderByPolarAngle(const Point2D& aLHS, const Point2D& aRHS) {
	if (aLHS.isCollinear(aRHS)) {
		return aLHS.magnitude() > aRHS.magnitude(); //greates length
	}

	if (aLHS.direction() < aRHS.direction()) {
		return true;
	}//smaller angle

	return false;
}

void Point2DSet::buildConvexHull(Point2DSet& aConvexHull) {
	sort(orderByPolarAngle);
	auto p0 = fPoints.begin();
	auto y = fPoints.begin() + 1;
	for (y; y != fPoints.end(); y++) {
		if ((y->getY() < p0->getY()) || (p0 == y && y->getX() < p0->getX())) {
			p0 = y;
		}
	}
	std::rotate(fPoints.begin(), p0, fPoints.end());

	if (fPoints.size() < 3) {
		return;
	}
	aConvexHull.add(fPoints[0]);
	aConvexHull.add(fPoints[1]);
	aConvexHull.add(fPoints[2]);
	for (size_t i = 3; i < size(); i++)
	{
		while (aConvexHull.doesNotTurnLeft(fPoints[i]))
		{
			aConvexHull.removeLast();
		}
		aConvexHull.add(fPoints[i]);
	}
}

size_t Point2DSet::size() const {
	return fPoints.size();
}

void Point2DSet::clear(){
	fPoints.clear();
}

void Point2DSet::sort(Comparator aComparator) {
	stable_sort(fPoints.begin(), fPoints.end(), aComparator);
}

const Point2D& Point2DSet::operator[] (size_t aIndex) const {
	return fPoints.at(aIndex);
}

Point2DSet::Iterator Point2DSet::begin() const {
	return fPoints.begin();
}

Point2DSet::Iterator Point2DSet::end() const {
	return fPoints.end();
}