#ifndef BOOK_H
#define BOOK_H

#include "product.h"
#include <string>

class book : public product {
	const std::string _isbn;

public:
	book(const std::string &n, int p, const std::string &i);

	virtual std::string description() const override;
};

#endif
