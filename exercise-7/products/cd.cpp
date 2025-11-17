#include "cd.h"
#include <string>

using namespace std;

cd::cd(const string& n, int p, const string& a) : product(n, p), _artist(a) {}

string cd::description() const {
	return product::description() +
		", Artist: " + _artist;
}