#ifndef POUND_PRODUCT_H
#define POUND_PRODUCT_H

#include "product.h"

class pound_product : public product {
public:
	pound_product(const std::string& name);

	virtual std::string description() const override;
};

#endif // !POUND_PRODUCT_H