#include "Vector2D.h"
# define M_PI          3.141592653589793238462643383279502884
Vector2D::Vector2D(double aX, double aY) {
	this->fX = aX;
	this->fY = aY;
}

void Vector2D::setX(double aX) {
	this->fX = aX;
}

double Vector2D::getX() const{
	return this->fX;
}

void Vector2D::setY(double aY) {
	this->fY = aY;
}

double Vector2D::getY() const{
	return this->fY;
}

Vector2D Vector2D::operator+(const Vector2D& aRHS) const {
	Vector2D newvt;
	newvt.setX(this->fX + aRHS.fX);
	newvt.setY(this->fY + aRHS.fY);
	return newvt;
}

Vector2D Vector2D::operator-(const Vector2D& aRHS) const {
	Vector2D newvt;
	newvt.setX(this->fX - aRHS.fX);
	newvt.setY(this->fY - aRHS.fY);
	return newvt;
}

double Vector2D::magnitude() const{
	return sqrt(pow(this->fX, 2) + pow(this->fY, 2));
}

double Vector2D::direction() const {
	return atan2(this->fY, this->fX) * 180 / M_PI;
}
double Vector2D::dot(const Vector2D& aRHS) const{
	if ((this->fX == 0 && this->fY == 0) || (aRHS.fX == 0 && aRHS.fY == 0)) {
		return 0;
	}
	return (this ->fX * aRHS.fX) + (this->fY * aRHS.fY);
}

double Vector2D::cross(const Vector2D& aRHS) const {
	return this->fX * aRHS.fY - this->fY * aRHS.fX;
}

double Vector2D::angleBetween(const Vector2D& aRHS) const {
	double angle = 0;
	if (this->magnitude() == 0 || aRHS.magnitude() == 0) {
		angle = 0;
	}
	else {
		angle = acos(this->dot(aRHS) / (this->magnitude() * aRHS.magnitude()));
	}
	return angle * 180 / M_PI;
}
std::ostream& operator<<(std::ostream& aOutStream, const Vector2D& aObject) {
	aOutStream << "[" << aObject.getX() << "," << aObject.getY() << "]";
	return aOutStream;
}

std::istream& operator>>(std::istream& aInStream, Vector2D& aObject) {
	aInStream >> aObject.fX >> aObject.fY;
	return aInStream;
}
