#ifndef SUCCESSIVE_DISCOUNT_PRICING_H
#define SUCCESSIVE_DISCOUNT_PRICING_H

#include "pricing.h"

class successive_discount_pricing : public pricing {
private:
	double rate;

public:
	successive_discount_pricing(double rate);
	double cost(const product& p, int n) override;
};
#endif // SUCCESSIVE_DISCOUNT_PRICING_H