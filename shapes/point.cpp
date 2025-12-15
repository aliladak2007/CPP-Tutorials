#include "point.h"
#include <cmath>
#include <string>

using namespace std;

// the distance between two points
double dist(const point &p1, const point &p2) {
	const double dx = p1.x() - p2.x();
	const double dy = p1.y() - p2.y();
	return sqrt(dx*dx + dy*dy);
}

// string representation
string show_point(const point &p) {
	return "(" + to_string(p.x()) + ", " + to_string(p.y()) + ")";
}
