#include "product.h"
#include "book.h"
#include "cd.h"
#include "pound_product.h"
#include <iostream>

using namespace std;

int main() {
	product p1("Hobnobs", 133);
	cd p2("Espresso", 3167, "Sabrina Carpenter");
	pound_product p4("Chewing gum");
	print_product(cout, p4);
	print_product(cout, p1);
	print_product(cout, p2);
	return 0;
}
