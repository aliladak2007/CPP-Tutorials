#include "pound_product.h"
#include <string>

using namespace std;

pound_product::pound_product(const string& name) : product(name, 100) {}

std::string pound_product::description() const {
    // You can customise this, or just reuse the base description
    return product::description() + " (one-pound item)";
}