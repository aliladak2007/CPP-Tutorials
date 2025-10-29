#include <algorithm>   // count, count_if, find, remove_if, partition, iter_swap
#include <vector>
#include <list>
#include <string>
#include <sstream>     // not used here; kept if you add I/O later
#include <iterator>    // prev, next
#include <iostream>

using namespace std;

// ============================================================================
// Utilities and small predicates
// ============================================================================

// Predicate: true if x is negative.
// Used with std::count_if over integer ranges.
bool is_negative(int x) {
    return x < 0;
}

// Predicate: true if x is even.
// Used with std::remove_if over integer ranges.
bool is_even(int x) {
    return x % 2 == 0;
}

// ============================================================================
// 1) Count negatives in a list<int>
//    a) using a named predicate
//    b) using a lambda expression
//    Both versions run in O(n) time and do not modify the list.
// ============================================================================

// Count values < 0 using a named predicate.
int count_negatives_predicate(const list<int>& l) {
    return count_if(l.cbegin(), l.cend(), is_negative);
}

// Count values < 0 using a lambda inline.
int count_negatives_lambda(const list<int>& l) {
    return count_if(l.cbegin(), l.cend(),
        [](int x) { return x < 0; });
}

// ============================================================================
// 2) Count zeroes before the first 1 in a list<int>
//    Find the first 1 with std::find, then count zeroes in [begin, it).
//    If there is no 1, std::find returns end and we count over the whole list.
//    Runs in O(n).
// ============================================================================

int no_of_zeroes_before_first_one(const list<int>& l) {
    auto it = find(l.cbegin(), l.cend(), 1);   // position of first 1, or end
    return count(l.cbegin(), it, 0);           // count zeroes strictly before that
}

// ============================================================================
// 3) Split a CSV line on commas, preserving empty fields
//    Every comma is a separator. n commas yield n + 1 fields.
//    Examples:
//      ""          -> {""}
//      ","         -> {"", ""}
//      "a,b"       -> {"a","b"}
//      "abc,,d,ef,"-> {"abc","","d","ef",""}
//    Runs in O(n). No trimming or skipping.
// ============================================================================

vector<string> split_csv(const string& s) {
    vector<string> result;
    result.reserve(static_cast<size_t>(count(s.begin(), s.end(), ',')) + 1);

    auto i = s.begin();
    while (true) {
        auto j = find(i, s.end(), ',');        // next separator or end
        result.emplace_back(i, j);             // pushes empty string if i == j
        if (j == s.end()) break;               // last field was added
        i = j + 1;                             // advance exactly one past the comma
    }
    return result;
}

// ============================================================================
// 4) Count empty strings in a vector<string>
//    Use std::count_if with s.empty().
//    Runs in O(n).
// ============================================================================

size_t count_empty_strings(const vector<string>& v) {
    return count_if(v.cbegin(), v.cend(),
        [](const string& s) { return s.empty(); });
}

// ============================================================================
// 5) Remove all even numbers from a list<int>
//    Uses the erase-remove idiom with std::remove_if.
//    Modifies the list in place. Runs in O(n).
//    Note: for std::list, a member function l.remove_if(pred) is also available.
// ============================================================================

void remove_even_numbers(list<int>& l) {
    l.erase(remove_if(l.begin(), l.end(), is_even), l.end());
}

void remove_even_numbers_lambda(list<int>& l) {
    l.erase(remove_if(l.begin(), l.end(),
        [](int x) { return x % 2 == 0; }),
        l.end());
}

// ============================================================================
// 6) Count strings longer than n in a vector<string>
//    Use std::count_if. Cast s.size() to int to avoid signed/unsigned warnings.
//    Runs in O(n).
// ============================================================================

int count_longer(const vector<string>& v, int n) {
    return count_if(v.cbegin(), v.cend(),
        [n](const string& s) { return static_cast<int>(s.size()) > n; });
}

// ============================================================================
// 7) Quicksort for list<int> using std::partition
//    Public wrapper: quickSort(list<int>&)
//    Private helper: quickSort_range(It first, It last)
//    Strategy:
//      - Choose pivot as the last element.
//      - Partition [first, pivot_it) with x < pivot.
//      - Swap pivot into place between the partitions.
//      - Recurse on [first, mid) and (mid, last).
//    Notes:
//      - std::partition works on bidirectional iterators, which std::list has.
//      - prev and next come from <iterator>.
// ============================================================================

static void quickSort_range(list<int>::iterator first, list<int>::iterator last) {
    // Base case: empty range
    if (first == last) return;

    // Base case: single element range
    auto second = first;
    ++second;
    if (second == last) return;

    // Choose pivot as the last element
    auto pivot_it = prev(last);
    int pivot = *pivot_it;

    // Partition everything before the pivot into [< pivot | >= pivot]
    // Important: use [first, pivot_it) as the range, not [first, last)
    auto mid = partition(first, pivot_it,
        [pivot](int x) { return x < pivot; });

    // Place pivot between the two partitions so it is in its final position
    iter_swap(mid, pivot_it);

    // Recurse on the two subranges: [first, mid) and (mid, last) == [next(mid), last)
    quickSort_range(first, mid);
    quickSort_range(next(mid), last);
}

// Public wrapper that hides iterators from callers
void quickSort(list<int>& l) {
    if (l.size() < 2) return;
    quickSort_range(l.begin(), l.end());
}

int main() {
    // 1) count_negatives
    {
        list<int> a{ 3, -2, 0, -7, 5 };
        cout << "count_negatives_predicate: " << count_negatives_predicate(a) << "\n";
        cout << "count_negatives_lambda:    " << count_negatives_lambda(a) << "\n";
    }

    // 2) zeroes before first 1
    {
        list<int> b{ 0, 0, 1, 0 };
        cout << "zeroes before first 1 in {0,0,1,0}: "
            << no_of_zeroes_before_first_one(b) << "\n";
    }

    // 3) split_csv
    {
        string s = "abc,,d,ef,";
        vector<string> fields = split_csv(s);
        cout << "split_csv(\"" << s << "\") = [";
        for (size_t i = 0; i < fields.size(); ++i) {
            if (i) cout << ", ";
            cout << '"' << fields[i] << '"';
        }
        cout << "]\n";

        // 4) count_empty_strings
        cout << "count_empty_strings: " << count_empty_strings(fields) << "\n";
    }

    // 5) remove_even_numbers (predicate and lambda variants)
    {
        list<int> c{ 1,2,3,4,5,6 };
        cout << "before remove_even_numbers: [";
        for (auto it = c.begin(); it != c.end(); ++it) {
            if (it != c.begin()) cout << ", ";
            cout << *it;
        }
        cout << "]\n";
        remove_even_numbers(c);
        cout << "after  remove_even_numbers: [";
        for (auto it = c.begin(); it != c.end(); ++it) {
            if (it != c.begin()) cout << ", ";
            cout << *it;
        }
        cout << "]\n";

        list<int> d{ 2,4,6 };
        remove_even_numbers_lambda(d);
        cout << "after remove_even_numbers_lambda on {2,4,6}: [";
        for (auto it = d.begin(); it != d.end(); ++it) {
            if (it != d.begin()) cout << ", ";
            cout << *it;
        }
        cout << "]\n";
    }

    // 6) count_longer
    {
        vector<string> words{ "a","bbbb","cc","ddddd" };
        cout << "count_longer n=2 on {\"a\",\"bbbb\",\"cc\",\"ddddd\"}: "
            << count_longer(words, 2) << "\n";
    }

    // 7) quickSort using partition
    {
        list<int> q{ 5, 1, 4, 2, 8, 5, 3, 0 };
        cout << "quickSort before: [";
        for (auto it = q.begin(); it != q.end(); ++it) {
            if (it != q.begin()) cout << ", ";
            cout << *it;
        }
        cout << "]\n";

        quickSort(q);

        cout << "quickSort after:  [";
        for (auto it = q.begin(); it != q.end(); ++it) {
            if (it != q.begin()) cout << ", ";
            cout << *it;
        }
        cout << "]\n";
    }

    return 0;
}
