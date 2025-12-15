#ifndef POINT_H
#define POINT_H

#include <string>

// a point in two-dimensional space
class point {
	double _x, _y;
public:
	point(double x, double y) : _x(x), _y(y) {}

	double x() const { return _x; }
	double y() const { return _y; }
};

// the distance between two points
double dist(const point &p1, const point &p2);

// string representation
std::string show_point(const point &p);

#endif
