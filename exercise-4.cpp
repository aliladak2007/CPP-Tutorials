#include <vector>
#include <algorithm>
#include <stdexcept>
#include <list>
#include <iostream>
#include <map>
#include <iomanip>
#include <sstream>   // for the simple word_value_stats demo
#include <string>
#include <cmath>
#include "exercise-3/stats.h"
#include "exercise-3/vector_utils.h"   // if you call anything from here

using namespace std;

// -----------------------------------------------------------------------------
// Statistics for vectors and lists
// Implements median and several average variants using indices, iterators,
// and ranged-for loops. Also includes list-specific utilities for scaling,
// maximum, deletion, deduplication, and simple word statistics tasks.
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// average_iterator(vector<double>)
// Impl: Iterator-based loop using const_iterators.
// -----------------------------------------------------------------------------
double average_iterator(const vector<double>& v) {
    const auto n = v.size();
    if (n == 0)
        throw domain_error("average of an empty vector");

    double sum = 0;
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        sum += *it;
    }
    return sum / n;
}

// -----------------------------------------------------------------------------
// average_range_based(vector<double>)
// Impl: Ranged-for loop using const references.
// -----------------------------------------------------------------------------
double average_range_based(const vector<double>& v) {
    const auto n = v.size();
    if (n == 0)
        throw domain_error("average of an empty vector");

    double sum = 0;
    for (const auto& value : v) {
        sum += value;
    }
    return sum / n;
}

// -----------------------------------------------------------------------------
// average_iterator_lists(list<double>)
// Impl: Iterator-based loop on std::list (no indexing).
// Note: list::size() can be non-constant on some lib impls; acceptable here.
// -----------------------------------------------------------------------------
double average_iterator_lists(const list<double>& l) {
    const auto n = l.size();
    if (n == 0)
        throw domain_error("average of an empty list");

    double sum = 0;
    for (auto it = l.cbegin(); it != l.cend(); ++it) {
        sum += *it;
    }
    return sum / n;
}

// -----------------------------------------------------------------------------
// average_range_based_lists(list<double>)
// Impl: Ranged-for loop on std::list.
// -----------------------------------------------------------------------------
double average_range_based_lists(const list<double>& l) {
    const auto n = l.size();
    if (n == 0)
        throw domain_error("average of an empty list");

    double sum = 0;
    for (const auto& value : l) {
        sum += value;
    }
    return sum / n;
}

// -----------------------------------------------------------------------------
// scale_iterator(s, vs)
// Goal: In-place multiply every element by s using an iterator loop.
// Note: Requires non-const iterator because elements are modified.
// -----------------------------------------------------------------------------
void scale_iterator(double s, list<double>& vs) {
    for (auto it = vs.begin(); it != vs.end(); ++it) {
        *it = (*it) * s;
    }
}

// -----------------------------------------------------------------------------
// scale_range_based(s, vs)
// Goal: In-place multiply every element by s using a ranged-for loop.
// -----------------------------------------------------------------------------
void scale_range_based(double s, list<double>& vs) {
    for (auto& value : vs) {
        value = value * s;
    }
}

// -----------------------------------------------------------------------------
// max_value_iterator(vector<double>)
// Pre:  v non-empty. Throws if empty.
// Impl: Seeds from first element, then scans with const_iterators.
// -----------------------------------------------------------------------------
double max_value_iterator(const vector<double>& v) {
    const auto n = v.size();
    if (n == 0)
        throw domain_error("max value of an empty vector");

    double max_val = v[0];
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        if (*it > max_val)
            max_val = *it;
    }
    return max_val;
}

// -----------------------------------------------------------------------------
// max_value_iterator_list(list<double>)
// Pre:  l non-empty. Throws if empty.
// Impl: Seed from first element, then iterate from the second.
// -----------------------------------------------------------------------------
double max_value_iterator_list(const list<double>& l) {
    if (l.empty())
        throw domain_error("max value of an empty list");

    auto it = l.cbegin();
    double max_val = *it; // seed from first
    ++it;                 // start at second (or end if size == 1)
    for (; it != l.cend(); ++it) {
        if (*it > max_val)
            max_val = *it;
    }
    return max_val;
}

// -----------------------------------------------------------------------------
// max_value_range_based_list(list<double>)
// Pre:  l non-empty. Throws if empty.
// Impl: Seed from front(); ranged-for compares all.
// -----------------------------------------------------------------------------
double max_value_range_based_list(const list<double>& l) {
    if (l.empty())
        throw domain_error("max value of an empty list");

    double max_val = l.front();
    for (const auto& value : l) {
        if (value > max_val)
            max_val = value;
    }
    return max_val;
}

// -----------------------------------------------------------------------------
// delete_first_zero(list<double>&)
// Goal: Remove only the first value equal to 0 (exact comparison).
// Impl: Erase then break to avoid invalid iterator use beyond erase.
// -----------------------------------------------------------------------------
void delete_first_zero(list<double>& vs) {
    for (auto it = vs.begin(); it != vs.end(); ++it) {
        if (*it == 0) {
            vs.erase(it);
            break; // stop after deleting the first zero
        }
    }
}

// -----------------------------------------------------------------------------
// remdups(list<string>&)
// Goal: Remove adjacent duplicate strings, keeping the first of each run.
// Impl: Two-iterator "window": prev stays at run head; it scans forward.
// Erase returns the next valid iterator; do not increment on erase.
// Edge: Empty and single-element lists are no-ops.
// -----------------------------------------------------------------------------
void remdups(list<string>& ws) {
    if (ws.empty())
        return;

    auto prev = ws.begin();
    auto it = prev;
    ++it;

    while (it != ws.end()) {
        if (*it == *prev) {
            it = ws.erase(it); // erase duplicate; prev stays
        }
        else {
            prev = it;         // advance run head
            ++it;              // move to the next candidate
        }
    }
}

// -----------------------------------------------------------------------------
// count_word_occurrences()
// Goal: Read words from stdin, count frequency, and print a star histogram.
// Impl: map<string,int> for alphabetical output; prints word<TAB>stars.
// Notes: Tokens are whitespace-delimited, case-sensitive, punctuation kept.
// -----------------------------------------------------------------------------
void count_word_occurrences() {
    map<string, int> count; // word -> frequency

    string w;
    while (cin >> w)
        ++count[w];

    for (const auto& p : count) {
        string stars;
        stars.reserve(p.second);          // optional micro-optimisation
        for (int i = 0; i < p.second; ++i)
            stars.push_back('*');
        cout << p.first << '\t' << stars << '\n';
    }
}

// -----------------------------------------------------------------------------
// word_value_stats(in, out)
// Goal: Read (word, number) pairs and print per-word average and median.
// Impl: map<string, vector<double>> buckets; reuse average/median above.
// Output format example:
//   abc: average = 2.66667, median = 3
// Notes: Uses 5 d.p. for average. Median printed later by caller logic.
//       This function currently prints the left half and label for median;
//       complete the formatting as required by your brief.
// -----------------------------------------------------------------------------
void word_value_stats(std::istream& in, std::ostream& out) {
    map<string, vector<double>> buckets;

    string w;
    double value;
    // Build buckets: word -> list of values
    while (in >> w >> value) {
        buckets[w].push_back(value);
    }

    // For each word, compute average (non-mutating) and median (on a copy)
    for (const auto& kv : buckets) {
        const string& word = kv.first;
        const vector<double>& values = kv.second;

        // Average via ranged-for version (does not mutate)
        const double avg = average_range_based(values);

        // Median on a copy, since median(vector<double>) sorts its argument
        vector<double> tmp = values;
        const double med = median(tmp);

        // Print word and average to 5 d.p.; caller to finish median formatting
        // print "word: average = <avg>, median = <med>"
        out << word << ": average = ";
        if (fabs(avg - round(avg)) < 1e-9) {
            // whole number: print with no dp
            out << fixed << setprecision(0) << avg;
        }
        else {
            // not whole: print to 5 dp
            out << fixed << setprecision(5) << avg;
        }

        // median: always no dp, as you wanted
        out << ", median = " << fixed << setprecision(0) << med << '\n';

        // Complete printing of med as per your chosen formatting policy.
        // Example policy:
        //   - if med is "integerish", print as int
        //   - else print with fixed << setprecision(5)
        // Then add newline.
    }
}

int main() {
    // ---- vector median / averages ----
    {
        vector<double> v{ 1, 3, 2, 4 };
        cout << "median(v)              expected 2.5   got " << median(v) << "\n";
        cout << "average(v) idx         expected 2.5   got " << average(v) << "\n";
        cout << "average(v) iterator    expected 2.5   got " << average_iterator(v) << "\n";
        cout << "average(v) range       expected 2.5   got " << average_range_based(v) << "\n\n";
    }

    // ---- list averages ----
    {
        list<double> l{ 2, 2, 2, 2 };
        cout << "average(list) iterator expected 2     got " << average_iterator_lists(l) << "\n";
        cout << "average(list) range    expected 2     got " << average_range_based_lists(l) << "\n\n";
    }

    // ---- scale (iterator + range) ----
    {
        list<double> l{ 1.5, -2.0, 0.5 };
        scale_iterator(2.0, l); // -> {3, -4, 1}
        cout << "scale_iterator         expected 3 -4 1   got ";
        for (double x : l) cout << x << ' ';
        cout << "\n";
    }
    {
        list<double> l{ 1.0, 2.0, 3.0 };
        scale_range_based(-1.0, l); // -> {-1, -2, -3}
        cout << "scale_range_based      expected -1 -2 -3 got ";
        for (double x : l) cout << x << ' ';
        cout << "\n\n";
    }

    // ---- maximum (vector + list) ----
    {
        vector<double> v{ -10, -3, -7 };
        cout << "max(vector)            expected -3    got " << max_value_iterator(v) << "\n";
    }
    {
        list<double> l{ 5, 12, 9, 12, 11 };
        cout << "max(list) iterator     expected 12    got " << max_value_iterator_list(l) << "\n";
        cout << "max(list) range        expected 12    got " << max_value_range_based_list(l) << "\n\n";
    }

    // ---- delete_first_zero ----
    {
        list<double> l{ 0, 2, 0, 3 };
        delete_first_zero(l); // -> {2, 0, 3}
        cout << "delete_first_zero      expected 2 0 3 got ";
        for (double x : l) cout << x << ' ';
        cout << "\n\n";
    }

    // ---- remdups (adjacent only) ----
    {
        list<string> ws{ "a","a","b","b","b","a" };
        remdups(ws); // -> {"a","b","a"}
        cout << "remdups                expected a b a  got ";
        for (const auto& s : ws) cout << s << ' ';
        cout << "\n\n";
    }

    // ---- word_value_stats (simple demo with the brief’s sample) ----
    {
        istringstream in("abc 3\ndef 4\nabc 1\nabc 4\n");
        cout << "word_value_stats       expected:\n"
            "                        abc: average = 2.66667, median = 3\n"
            "                        def: average = 4, median = 4\n"
            "                       got:\n";
        word_value_stats(in, cout);
        cout << "\n";
    }

    // ---- count_word_occurrences (optional quick demo) ----
    // If you want to see it, paste input then send EOF (Ctrl+Z Enter on Windows / Ctrl+D on Linux/macOS).
    // cout << "Type words then EOF for count_word_occurrences demo:\n";
    // count_word_occurrences();

    return 0;
}
