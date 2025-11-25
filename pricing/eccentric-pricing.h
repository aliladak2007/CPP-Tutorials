#ifndef ECCENTRIC_PRICING_H
#define ECCENTRIC_PRICING_H

#include "pricing.h"

class eccentric_pricing : public pricing {
public:
	eccentric_pricing();

	double cost(const product &p, int n) override;
};

#endif
