//
// Created by mahmo on 13/10/2025.
//
#include "vector_utils.h"
#include <stdexcept>
#include <utility>    // std::swap
#include <istream>
#include <ostream>
#include <string>


using namespace std;

double min_value(const std::vector<double>& v) {
    const std::size_t n = v.size();
    if (n == 0) throw std::domain_error("min value of an empty vector");
    double min_val = v[0];
    for (std::size_t i = 1; i < n; ++i)
        if (v[i] < min_val) min_val = v[i];
    return min_val;
}


double max_value(const std::vector<double>& v) {
    const std::size_t n = v.size();
    if (n == 0) throw std::domain_error("max value of an empty vector");
    double max_val = v[0];
    for (std::size_t i = 1; i < n; ++i)
        if (v[i] > max_val) max_val = v[i];
    return max_val;
}

void write_vector(const std::vector<double>& v, std::ostream& out) {
    const std::size_t n = v.size();
    for (std::size_t i = 0; i < n; ++i) {
        out << v[i];
        if (i + 1 < n) out << ' ';
    }
}


void reverse_vector(std::vector<double>& v) {
    const std::size_t n = v.size();
    if (n == 0) return;
    std::size_t left = 0, right = n - 1;
    while (left < right) {
        std::swap(v[left], v[right]);
        ++left;
        --right;
    }
}

vector<double> read_vector(istream &in) {
    vector<double> v;
    double x;
    while (in >> x)
        v.push_back(x);
    return v;
}

const std::string& longest(const std::vector<std::string>& v) {
    if (v.empty()) throw std::domain_error("longest of an empty vector");
    std::size_t best = 0;
    for (std::size_t i = 1; i < v.size(); ++i)
        if (v[i].size() > v[best].size()) best = i;
    return v[best];
}

