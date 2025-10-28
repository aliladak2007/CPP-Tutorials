#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <sstream>

using namespace std;

bool is_negative(int x) {
	return x < 0;
}

int count_negatives_predicate(const list<int>& l) {
	return count_if(l.cbegin(), l.cend(), is_negative);
}

int count_negatives_lambda(const list<int>& l) {
	return count_if(l.cbegin(), l.cend(), [](int x) {return x < 0; });
}