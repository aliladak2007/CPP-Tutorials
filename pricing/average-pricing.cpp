#include "average-pricing.h"

average_pricing::average_pricing(pricing& a, pricing& b)
    : pricing("average pricing"), p1(a), p2(b)
{
}

double average_pricing::cost(const product& p, int n) {
    // STEP: fill logic
	double cost1 = p1.cost(p, n);
	double cost2 = p2.cost(p, n);
	return (cost1 + cost2) / 2.0;
}
