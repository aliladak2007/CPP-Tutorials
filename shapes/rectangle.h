#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class rectangle : public shape {
	point corner;
	double width, height;
public:
	rectangle(const point &c, double w, double h);

	virtual bool contains(const point &p) const override;

	virtual std::string description() const override;

	virtual void scale(double factor) override;
};

#endif
