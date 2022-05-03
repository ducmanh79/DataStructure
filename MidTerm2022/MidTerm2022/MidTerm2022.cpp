#include <iostream> 
#include "Point2DSet.h" 
#include "Point2D.h"
#include "Vector2D.h"
using namespace std;
//#define P1
//#define P2
#define P3
void runP1() {
	cout << "P1" << endl;
	Vector2D a(1, 4);
	Vector2D b(4, 6);
	Vector2D c = a + b; //operator test
	Vector2D d = a - b; //operator test
	cout << "Vector a length " << a.magnitude() << endl; //magnitude test
	cout << "Vector a direction " << a.direction() << endl; //direction test
	cout << "Vector a dot b " << a.dot(b) << endl; //dot test
	cout << "Vector a cross b " << a.cross(b) << endl; //cross test
	cout << c << endl; //overload operator test
	Vector2D e;
	cout << "input vector" << endl;
	cin >> e;
	cout << e << endl; //input operator test
}
void runP2() {
	cout << "P2" << endl;
	Point2D a("p01", -5, -6);
	Point2D b("p00", 6, -4);
	Point2D h("p03", 8, 0);
	Point2D x("", 4, 0);
	Point2D z("", 2, 0);
	cout << "Direction from a to origin " << a.direction() << endl; //direction test
	Vector2D g = a - b;
	cout << "Operator - test " << g << endl;
	cout << "Length from a to origin " << a.magnitude() << endl;
	if (x.isCollinear(z)) {
		cout << "O (0,0)" << "X" << x <<"Z" << z <<"is colinear" << endl;
	}
	if (a < b) {
		cout << "a is smaller than b" << endl;
	}
	cout << "input point" << endl;
	Point2D e;
	cin >> e;
	cout << "Vector inputed: " << e << endl;
	if (a.isClockwise(b, h)) {
		cout << "A" << a<< "B" << b << "H" << h << "is clockwise" << endl;
	}
}
void runP3() {
	cout << "P3" << endl;
	Point2DSet lSet;
	lSet.populate("points.txt");
	cout << "Points:" << endl;
	for (const Point2D& p : lSet)
	{
		cout << p << endl;
	}
	Point2DSet lConvexHull;
	lSet.buildConvexHull(lConvexHull);
	cout << "Convex hull:" << endl;
	size_t lSize = lConvexHull.size();
	for (size_t i = 0; i < lSize; i++)
	{
		cout<< lConvexHull[i].getId()
			<< " - "
			<< lConvexHull[(i + 1) % lSize].getId() << endl;
	}

}
void main()
{
#ifdef P1
	runP1();
#endif
#ifdef P2
	runP2();
#endif
#ifdef P3
	runP3();
#endif
}