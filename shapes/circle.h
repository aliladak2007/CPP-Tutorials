#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class circle : public shape {
	point centre;
	double radius;
public:
	circle(const point &c, double r);

	virtual bool contains(const point &p) const override;

	virtual std::string description() const override;

	virtual void scale(double factor) override;
};

#endif
