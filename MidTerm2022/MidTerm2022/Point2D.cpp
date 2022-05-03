#include "Point2D.h"
using namespace std;
# define M_PI          3.141592653589793238462643383279502884

Point2D::Point2D(const string& aId, double aX, double aY) {
	fId = aId;
	fPosition.setX(aX);
	fPosition.setY(aY);
}


Point2D::Point2D() {
	fId = "";
	fPosition.setX(0);
	fPosition.setY(0);
}

static const Point2D gCoordinateOrgin;

const string& Point2D::getId() const {
	return this->fId;
}

void Point2D::setX(const double& aX) {
	this->fPosition.setX(aX);
}

const double Point2D::getX() const {
	return this->fPosition.getX();
}

void Point2D::setY(const double& aY) {
	this->fPosition.setY(aY);
}

const double Point2D::getY() const {
	return this->fPosition.getY();
}

void Point2D::setOrigin(const Point2D& aPoint) {
	this->fOrigin = aPoint.fOrigin;
}

const Point2D& Point2D::getOrigin() const {
	return gCoordinateOrgin;
}

double Point2D::directionTo(const Point2D& aOther) const {
	return atan2(aOther.getY() - this->getY(), aOther.getX() - this->getX());
}

double Point2D::magnitudeTo(const Point2D& aOther) const {
	return sqrt(pow(aOther.getX() - this->getX(),2) + pow(aOther.getY() - this->getY(), 2));
}

Vector2D Point2D::operator-(const Point2D& aRHS) const {
	Vector2D newvt;
	newvt.setX(aRHS.getX() - this->getX());
	newvt.setY(aRHS.getY() - this->getY());
	return newvt;
}

double Point2D::direction() const {
	return atan2(this->getY(), this->getX()) * 180 / M_PI;
}

double Point2D::magnitude() const {
	return sqrt(pow(this->getX(), 2) + pow(this->getY(), 2));
}

bool Point2D::isCollinear(const Point2D& aOther) const {
	double a = gCoordinateOrgin.getX() * (this->getX() - aOther.getX())
		+ this->getX() * (aOther.getY() - gCoordinateOrgin.getY())
		+ aOther.getX() * (gCoordinateOrgin.getY() - this->getY());
	if (a == 0) {
		return true;
	}
	return false;
}

bool Point2D::isClockwise(const Point2D& aP0, const Point2D& aP2) const {
	Vector2D p1p0((this->getX() - aP0.getX()), (this->getY() - aP0.getY()));
	Vector2D p2p0((aP2.getX() - aP0.getX()), (aP2.getY() - aP0.getY()));

	double crossres = p2p0.cross(p1p0);
	if (crossres > 0) {
		return true;
	}
	return false;
}

bool Point2D::operator<(const Point2D& aRHS) const {
	if (this->getY() < aRHS.getY()) {
		return true;
	}
	else if (this->getY() == aRHS.getY()) {
		if (this->getX() < aRHS.getX()) {
			return true;
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream& aOStream, const Point2D& aObject) {
	aOStream << aObject.fId << ":" << " " << "(" << aObject.getX() << "," << aObject.getY() << ")";
	return aOStream;
}

std::istream& operator>>(std::istream& aIStream, Point2D& aObject) {
	double fX, fY;
	aIStream >> aObject.fId >> fX >> fY;
	aObject.setX(fX);
	aObject.setY(fY);
	return aIStream;
}