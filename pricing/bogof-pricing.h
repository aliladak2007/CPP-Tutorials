#ifndef BOGOF_H
#define BOGOF_H

#include "pricing.h"

// Buy One Get One Free pricing scheme
class bogof_pricing : public pricing {
public:
	bogof_pricing();
	double cost(const product& p, int n) override;

};

#endif // BOGOF_H