#ifndef COMPOSITE_SHAPE_H
#define COMPOSITE_SHAPE_H

#include "shape.h"
#include <memory>
#include <string>

class composite_shape : public shape {
	std::shared_ptr<shape> s1;
	std::shared_ptr<shape> s2;

public:
	composite_shape(std::shared_ptr<shape> a, std::shared_ptr<shape> b);

	virtual bool contains(const point& p) const override;

	virtual std::string description() const override;

	virtual void scale(double factor) override;
};

#endif COMPOSITE_SHAPE_H
