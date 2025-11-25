#include "successive-discount-pricing.h"
#include <cmath>

using namespace std;

successive_discount_pricing::successive_discount_pricing(double r) :
	pricing("successive discount"), rate(r) {}

double successive_discount_pricing::cost(const product& p, int n) {
	double total = 0.0;

	for (int i = 0; i < n; ++i) {
		total += p.price() * pow(rate, i);
	}
	return total;
}

