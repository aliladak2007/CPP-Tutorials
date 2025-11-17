#include "book.h"
#include <string>

using namespace std;

book::book(const string &n, int p, const string &i) :
	product(n, p), _isbn(i) {}

string book::description() const {
	return '"' + product::description() + '"' +
		", ISBN " + _isbn;
}
