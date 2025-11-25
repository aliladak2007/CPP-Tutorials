#include "discount-pricing.h"

using namespace std;

discount_pricing::discount_pricing(int n, double d) :
	pricing("discount of " + to_string(d) + " for " + to_string(n) + " or more items"),
	_threshold(n), _discount(d) {}

double discount_pricing::cost(const product &p, int n) {
	double total = p.price() * n;
	if (n >= _threshold)
		total *= 1 - _discount;
	return total;
}
