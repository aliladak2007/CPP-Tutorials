#ifndef DISCOUNT_PRICING_H
#define DISCOUNT_PRICING_H

#include "pricing.h"

// discount for n or more items
class discount_pricing : public pricing {
	int _threshold;
	double _discount;

public:
	discount_pricing(int n, double d);

	double cost(const product &p, int n) override;
};

#endif
