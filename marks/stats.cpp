#include "stats.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

// the median of the values in a vector
// requires: v.size() > 0
double median(vector<double> v) {
	const auto n = v.size();
	if (n == 0)
		throw domain_error("median of an empty vector");
	// sort the whole vector
	sort(v.begin(), v.end());
	const auto middle = n/2;
	if (n%2 == 1) // size is odd
		return v[middle];
	else // size is even
		return (v[middle-1] + v[middle])/2;
}

// the average of the values in a vector
// requires: v.size() > 0
double average(const vector<double> &v) {
	const auto n = v.size();
	if (n == 0)
		throw domain_error("average of an empty vector");
	double sum = 0;
        for (double x : v)
		sum += x;
	return sum / n;
}
