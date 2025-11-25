#include "limited-reduction-pricing.h"
#include <algorithm>  // std::min

limited_reduction_pricing::limited_reduction_pricing(double initial_reduction)
    : pricing("limited reduction"), remaining(initial_reduction)
{
}

double limited_reduction_pricing::cost(const product& p, int n) {
    double full = p.price() * n;

    // how much of the pot we can use on this purchase
    double used = std::min(full, remaining);

    remaining -= used;          // reduce the pot
    return full - used;         // customer pays the rest
}
