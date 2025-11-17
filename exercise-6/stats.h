#ifndef GUARD_stats_h
#define GUARD_stats_h

#include <vector>

// the median of the values in a vector
// requires: v.size() > 0
double median(std::vector<double> v);

// the average of the values in a vector
// requires: v.size() > 0
double average(const std::vector<double> &v);

#endif
