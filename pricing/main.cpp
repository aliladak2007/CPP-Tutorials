#include "product.h"
#include "pricing.h"
#include "cheaper-pricing.h"
#include "discount-pricing.h"
#include "eccentric-pricing.h"
#include "simple-pricing.h"
#include "bogof-pricing.h"
#include "successive-discount-pricing.h"
#include "average-pricing.h"
#include "limited-reduction-pricing.h"
#include <iostream>
#include <string>

using namespace std;

void print_bill(pricing &policy) {
	cout << "pricing policy: " << policy.name() << '\n';

	string nm;
	double p;
	int n;
	while (cin >> nm >> p >> n) {
		product item(nm, p);
		cout << n << " x " << nm << ": " << policy.cost(item, n) << '\n';
	}
}

int main() {
	discount_pricing policy_a(10, 0.1);
	eccentric_pricing policy_b;
	cheaper_pricing policy_c(policy_a, policy_b);
	bogof_pricing policy_d;
	successive_discount_pricing policy_e(0.9);
	simple_pricing simple;
	successive_discount_pricing disc(0.9);  // 10% successive discount
	average_pricing avg(simple, disc);
	limited_reduction_pricing policy_f(50.0);  // £50 total reductions available
	print_bill(policy_f);

	return 0;
}
