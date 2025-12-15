#include "composite_shape.h"

using namespace std;

composite_shape::composite_shape(shared_ptr<shape> a, shared_ptr<shape> b) :
	s1(a), s2(b) {}

bool composite_shape::contains(const point& p) const {
	return s1->contains(p) || s2->contains(p);
}

string composite_shape::description() const {
	return "composite shape of (" + s1->description() + ") and (" + s2->description() + ")";
}

void composite_shape::scale(double factor) {
	s1->scale(factor);
	s2->scale(factor);
}
