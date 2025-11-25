#include "simple-pricing.h"

using namespace std;

simple_pricing::simple_pricing() : pricing("simple") {}

double simple_pricing::cost(const product &p, int n) {
	return p.price() * n;
}
