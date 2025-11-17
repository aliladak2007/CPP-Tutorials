#ifndef CD_H
#define CD_H

#include "product.h"
#include <string>

class cd : public product {
	const std::string _artist;

public:
	cd(const std::string& n, int p, const std::string& a);

	virtual std::string description() const override;
};
#endif // !CD_H
