#include "product.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

product::product(const string &n, int p) : _name(n), _price(p) {}

void print_product(ostream &out, const product &p) {
	streamsize prec = out.precision();
	out << p.description() << ": " << fixed <<
		setprecision(2) << (p.price()/100.0) <<
		setprecision(prec) << " pounds\n";
}
