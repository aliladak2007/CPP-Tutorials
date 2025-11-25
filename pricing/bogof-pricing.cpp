#include "bogof-pricing.h"
#include <cmath>

using namespace std;

// Buy One Get One Free pricing scheme

bogof_pricing::bogof_pricing() : pricing("Buy One Get One Free") {}

double bogof_pricing::cost(const product& p, int n) {
	int chargeable_items = static_cast<int>(ceil(n / 2.0));
	return chargeable_items * p.price();
}