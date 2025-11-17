#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class product { // products in some store
	const std::string _name;
	const int _price; // price in pennies

public:
	product(const std::string &n, int p);

	int price() const { return _price; }

	virtual std::string description() const { return _name; }

	virtual ~product() {}
};

void print_product(std::ostream &out, const product &p);

#endif
