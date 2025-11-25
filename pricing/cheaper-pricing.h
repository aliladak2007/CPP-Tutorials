#ifndef CHEAPER_PRICING_H
#define CHEAPER_PRICING_H

#include "pricing.h"

// cheaper of two pricing schemes
class cheaper_pricing : public pricing {
	pricing &policy1;
	pricing &policy2;

public:
	cheaper_pricing(pricing &p1, pricing &p2);

	double cost(const product &p, int n) override;
};

#endif
