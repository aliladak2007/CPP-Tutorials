#include "rectangle.h"

using namespace std;

rectangle::rectangle(const point &c, double w, double h) :
	corner(c), width(w), height(h) {}

bool rectangle::contains(const point &p) const {
	return corner.x() <= p.x() && p.x() <= corner.x() + width &&
		corner.y() <= p.y() && p.y() <= corner.y() + height;
}

string rectangle::description() const {
	return "rectangle of width " + to_string(width) +
		" and height " + to_string(height) +
		" at " + show_point(corner);
}

void rectangle::scale(double factor) {
	width *= factor;
	height *= factor;

	corner = point(corner.x() * factor, corner.y() * factor);
}
