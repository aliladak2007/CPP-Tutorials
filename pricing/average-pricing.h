#ifndef AVERAGE_PRICING_H
#define AVERAGE_PRICING_H

#include "pricing.h"

class average_pricing : public pricing {
    pricing& p1;
    pricing& p2;

public:
    average_pricing(pricing& a, pricing& b);

    double cost(const product& p, int n) override;
};

#endif
