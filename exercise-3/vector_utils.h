//
// Created by mahmo on 13/10/2025.
//
#pragma once
#include <iosfwd>
#include <vector>
#include <string>

std::vector<double> read_vector(std::istream &in);

double max_value(const std::vector<double>& v);

double min_value(const std::vector<double>& v);

void write_vector(const std::vector<double> &v, std::ostream& out);

void reverse_vector(std::vector<double> &v);

const std::string& longest(const std::vector<std::string>& v);
//VECTOR_UTILS_H
