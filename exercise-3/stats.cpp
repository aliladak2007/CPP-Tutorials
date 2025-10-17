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
	using vec_size = vector<double>::size_type;
	for (vec_size i = 0; i < n; ++i)
		sum += v[i];
	return sum / n;
}

double score(const std::vector<double>& v) {
	const std::size_t n = v.size();
	if (n < 3) throw std::domain_error("Cannot compute accurate score, not enough data");

	double min_v = v[0];
	double max_v = v[0];
	double sum = 0.0;

	for (std::size_t i = 0; i < n; ++i) {
		if (v[i] < min_v) min_v = v[i];
		if (v[i] > max_v) max_v = v[i];
		sum += v[i];
	}

	const double adjusted_sum = sum - min_v - max_v;
	return adjusted_sum / static_cast<double>(n - 2);
}



