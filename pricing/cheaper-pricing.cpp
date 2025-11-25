#include "cheaper-pricing.h"
#include <algorithm>

using namespace std;

// cheaper of two pricing schemes

cheaper_pricing::cheaper_pricing(pricing &p1, pricing &p2) :
	pricing("cheaper of " + p1.name() + " and " + p2.name()),
	policy1(p1), policy2(p2) {}

double cheaper_pricing::cost(const product &p, int n) {
	return min(policy1.cost(p, n), policy2.cost(p, n));
}
