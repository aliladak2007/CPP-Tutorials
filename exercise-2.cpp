#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>

using namespace std;

// -----------------------------------------------------------------------------
// Q1: Read a series of numbers, compute average and median.
// Demonstrates use of vectors, sorting, and stream manipulators.
// -----------------------------------------------------------------------------
void process_numbers() {
    cout << "Please enter a series of numbers\n";

    auto old = cout.precision();       // Save old precision
    cout << fixed << setprecision(2); // Set precision to 2 decimal places

    vector<double> v;
    double x;

    // Read numbers into the vector until end-of-input
    while (cin >> x)
        v.push_back(x);

    // Compute the sum for average
    double sum = 0;
    for (const double value : v)
        sum += value;

    // Compute and print average (if not empty)
    if (!v.empty()) {
        double avg = sum / v.size();
        cout << "The average is " << avg << '\n';
        cout.unsetf(ios::fixed);
        cout << setprecision(old);   // Restore precision to previous setting
    }

    // Compute and print median
    auto n = v.size();
    cout << n << " numbers\n";

    if (n > 0) {
        sort(v.begin(), v.end()); // Sort values

        auto middle = n / 2;
        double median;

        // Handle even and odd cases
        if (n % 2 == 1)
            median = v[middle];
        else
            median = (v[middle - 1] + v[middle]) / 2;

        cout << "median = " << median << '\n';
    }

    cout << setprecision(old); // Ensure precision reset
}

// -----------------------------------------------------------------------------
// Q2: Compute average after removing smallest and largest values.
// Uses a vector and sorting (O(n log n) time, O(n) space).
// -----------------------------------------------------------------------------
void process_scores() {
    cout << "Please enter a series of numbers\n";
    auto old = cout.precision();
    cout << fixed << setprecision(2);

    vector<double> v;
    double x;

    while (cin >> x)
        v.push_back(x);

    // Must have at least 3 values to drop min and max
    if (v.size() <= 2) {
        cout << "Not enough numbers to compute adjusted average.\n";
        return;
    }

    // Sort values to identify min and max easily
    sort(v.begin(), v.end());

    // Sum all except first and last
    double sum = 0;
    for (auto i = 1; i < v.size() - 1; ++i)
        sum += v[i];

    double avg = sum / (v.size() - 2);
    cout << "The average is " << avg << '\n';

    cout.unsetf(ios::fixed);
    cout << setprecision(old);
}

// -----------------------------------------------------------------------------
// Q3: Count number of words in input stream.
// Demonstrates reading strings and counting tokens.
// -----------------------------------------------------------------------------
void process_words() {
    cout << "Paste or type text, then signal end of input.\n";

    string word;
    int counter = 0;

    while (cin >> word)
        counter++;

    cout << "Total number of words: " << counter << '\n';
}

// -----------------------------------------------------------------------------
// Q4: Find and print the longest word in input.
// Only keeps one word in memory; no need for containers.
// -----------------------------------------------------------------------------
void longest_word() {
    cout << "Paste or type text, then signal end of input.\n";

    string word;
    string longest_word;

    while (cin >> word) {
        if (word.length() > longest_word.length())
            longest_word = word;
    }

    if (!longest_word.empty())
        cout << "Longest word: " << longest_word << '\n';
    else
        cout << "No words entered.\n";
}

// -----------------------------------------------------------------------------
// Q5: Print words in reverse order (one per line).
// Uses a stack to reverse input order (LIFO).
// -----------------------------------------------------------------------------
void print_reverse() {
    cout << "Paste or type text, then signal end of input.\n";

    stack<string> words;
    string word;

    // Push each word onto the stack
    while (cin >> word) {
        if (!word.empty())
            words.push(word);
    }

    // Pop and print in reverse order
    while (!words.empty()) {
        cout << words.top() << '\n';
        words.pop();
    }
}

// -----------------------------------------------------------------------------
// Q6: (Optimised Q2) Compute adjusted average in O(n) time, O(1) space.
// Tracks min, max, sum, and count in one pass; no container required.
// -----------------------------------------------------------------------------
void process_scores_v2() {
    cout << "Please enter a series of numbers\n";

    int old = cout.precision();
    cout << fixed << setprecision(2);

    double x;
    double min, max, sum;
    int count = 0;

    // Initialise with first input (if any)
    if (cin >> x) {
        min = x;
        max = x;
        sum = x;
        count = 1;
    }

    // Process remaining inputs in one pass
    while (cin >> x) {
        if (x < min) min = x;
        if (x > max) max = x;
        sum += x;
        count++;
    }

    // Must have at least 3 numbers to drop extremes
    if (count < 3) {
        cout << "Not enough numbers to compute adjusted average.\n";
        return;
    }

    double adjusted_sum = sum - max - min;
    double adjusted_avg = adjusted_sum / (count - 2);

    cout << "The average is " << adjusted_avg << '\n';

    cout.unsetf(ios::fixed);
    cout << setprecision(old);
}

// -----------------------------------------------------------------------------
// Main entry point — call whichever function you want to test
// -----------------------------------------------------------------------------
int main() {
    process_scores_v2(); // Change this to test different questions
    return 0;
}
