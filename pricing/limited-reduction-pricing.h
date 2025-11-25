#ifndef LIMITED_REDUCTION_PRICING_H
#define LIMITED_REDUCTION_PRICING_H

#include "pricing.h"

class limited_reduction_pricing : public pricing {
    double remaining;   // amount of reductions left

public:
    // starts with some amount of reductions, e.g. 100.0
    limited_reduction_pricing(double initial_reduction);

    double cost(const product& p, int n) override;
};

#endif
