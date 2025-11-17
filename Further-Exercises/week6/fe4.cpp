#include <iostream>
#include <array>
#include <string>
#include <cassert>

class Grades {
private:
    double scores[5];

public:
    Grades(const std::array<double, 5>& /*s*/) {
        for (double& score : scores) {
            score = 0.0;
        }
    }

    void setScore(int index, double score) {
        if (index < 0 || index >= 5) {
            std::cerr << "Index out of bounds." << std::endl;
        }
        else if (score < 0.0 || score > 100.0) {
            std::cerr << "Score must be between 0 and 100." << std::endl;
        }
        else {
            scores[index] = score;
        }
    }

    double average() const {
        double sum = 0.0;
        for (const double& score : scores) {
            sum += score;
        }
        return sum / 5;
    }
};

int main() {
    // initial dummy array to satisfy constructor signature
    std::array<double, 5> init = { 10, 20, 30, 40, 50 };
    Grades g(init);

    // Test 1: all scores should be zero after construction
    std::cout << "Average after construction (expect 0): "
        << g.average() << "\n";
    assert(g.average() == 0.0);

    // Test 2: set valid scores and check average
    g.setScore(0, 80.0);
    g.setScore(1, 90.0);
    g.setScore(2, 70.0);
    g.setScore(3, 60.0);
    g.setScore(4, 100.0);

    double expected_avg = (80.0 + 90.0 + 70.0 + 60.0 + 100.0) / 5.0;
    std::cout << "Average after setting scores (expect "
        << expected_avg << "): " << g.average() << "\n";
    assert(g.average() == expected_avg);

    // Test 3: invalid index should not crash or modify scores
    g.setScore(-1, 50.0);  // out of bounds
    g.setScore(5, 50.0);   // out of bounds
    assert(g.average() == expected_avg);

    // Test 4: invalid score values should be rejected
    g.setScore(0, -10.0);   // invalid
    g.setScore(1, 150.0);   // invalid
    assert(g.average() == expected_avg);

    std::cout << "All tests passed.\n";
    return 0;
}
