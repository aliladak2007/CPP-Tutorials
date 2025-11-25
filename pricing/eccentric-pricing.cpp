#include "eccentric-pricing.h"

using namespace std;

eccentric_pricing::eccentric_pricing() :
	pricing("by length") {}

double eccentric_pricing::cost(const product &p, int n) {
	return p.name().size() * n;
}
