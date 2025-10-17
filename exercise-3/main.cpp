#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iomanip>

#include "stats.h"
#include "vector_utils.h"

using namespace std;

namespace {
    int tests_run = 0;
    int tests_failed = 0;

    bool almost_equal(double a, double b, double eps = 1e-9) {
        return std::abs(a - b) <= eps;
    }

    void expect_true(bool cond, const string& name) {
        ++tests_run;
        if (!cond) {
            ++tests_failed;
            cout << "[FAIL] " << name << '\n';
        } else {
            cout << "[PASS] " << name << '\n';
        }
    }

    template<typename Functor>
    void expect_throws(const string& name, Functor f) {
        ++tests_run;
        try {
            f();
            ++tests_failed;
            cout << "[FAIL] " << name << " (no exception)\n";
        } catch (const std::exception&) {
            cout << "[PASS] " << name << '\n';
        }
    }

    void test_average() {
        vector<double> v{1, 2, 3, 4};
        expect_true(almost_equal(average(v), 2.5), "average basic");
        expect_throws("average empty throws", []{ vector<double> e; (void)average(e); });
    }

    void test_median() {
        vector<double> v1{3, 1, 2};
        expect_true(almost_equal(median(v1), 2.0), "median odd");
        vector<double> v2{10, 2, 4, 8};
        expect_true(almost_equal(median(v2), (4.0 + 8.0) / 2.0), "median even");
        expect_throws("median empty throws", []{ vector<double> e; (void)median(e); });
    }

    void test_score() {
        vector<double> v1{1, 2, 3};
        expect_true(almost_equal(score(v1), 2.0), "score 3 elems");
        vector<double> v2{5, 5, 5, 5};
        expect_true(almost_equal(score(v2), 5.0), "score all equal");
        vector<double> v3{10, 1, 2, 9, 9}; // drop 1 and 10, average of 2,9,9 = 20/3
        expect_true(almost_equal(score(v3), 20.0/3.0), "score mixed");
        expect_throws("score <3 throws", []{ vector<double> v{1,2}; (void)score(v); });
    }

    void test_min_max() {
        vector<double> v{-5, -2, -3, 7, 0};
        expect_true(almost_equal(min_value(v), -5.0), "min_value mixed");
        expect_true(almost_equal(max_value(v), 7.0), "max_value mixed");
        expect_throws("min_value empty throws", []{ vector<double> e; (void)min_value(e); });
        expect_throws("max_value empty throws", []{ vector<double> e; (void)max_value(e); });
    }

    void test_write_vector() {
        vector<double> v{1, 2, 3};
        ostringstream out;
        write_vector(v, out);
        expect_true(out.str() == "1 2 3", "write_vector spacing");
        vector<double> empty{};
        ostringstream out2;
        write_vector(empty, out2);
        expect_true(out2.str().empty(), "write_vector empty prints nothing");
    }

    void test_reverse_vector() {
        vector<double> v{1, 2, 3, 4, 5};
        reverse_vector(v);
        expect_true((v == vector<double>({5,4,3,2,1})), "reverse_vector odd");
        vector<double> w{1, 2, 3, 4};
        reverse_vector(w);
        expect_true((w == vector<double>({4,3,2,1})), "reverse_vector even");
        vector<double> s{};
        reverse_vector(s); // should be safe no-op
        expect_true(s.empty(), "reverse_vector empty safe");
    }

    void test_read_vector() {
        istringstream in("1 2 3 10");
        vector<double> v = read_vector(in);
        expect_true((v == vector<double>({1,2,3,10})), "read_vector basic");
        istringstream in2(""); // no numbers
        vector<double> e = read_vector(in2);
        expect_true(e.empty(), "read_vector empty");
    }

    void test_longest() {
        vector<string> words{"alpha", "z", "pineapple", "pear", "strawberry"};
        expect_true(longest(words) == "strawberry", "longest basic");
        vector<string> tie{"aaa", "bbb", "cccc", "dddd"}; // both cccc and dddd length 4
        // Your implementation keeps the first max-length element
        expect_true(longest(tie) == "cccc", "longest tie picks first");
        expect_throws("longest empty throws", []{ vector<string> e; (void)longest(e); });
    }

    void run_all_tests() {
        test_average();
        test_median();
        test_score();
        test_min_max();
        test_write_vector();
        test_reverse_vector();
        test_read_vector();
        test_longest();

        cout << "\nTests run: " << tests_run
             << "  Failed: " << tests_failed
             << "  Passed: " << (tests_run - tests_failed) << '\n';
    }
}

int main() {
    run_all_tests();
    return 0;
}
