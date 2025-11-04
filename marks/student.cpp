#include "student.h"
#include "stats.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const double exam_weight = 0.7;
const double pass_mark = 40;

// Initialize student info
student::student(const string &name, double e) :
	n(name), exam(e) {}

// Add a task mark
void student::add_task(double m) {
	tasks.push_back(m);
}

double student::mark() const {
	return exam_weight*exam + (1 - exam_weight)*coursework();
}

double student::mark_with_average() const {
	return exam_weight*exam + (1 - exam_weight)*coursework_average();
}

double student::mark_with_largest() const {
	return exam_weight*exam + (1 - exam_weight)*coursework_largest();
}

double student::coursework() const {
	if (tasks.size() == 0)
		return 0;
	return median(tasks);
}

double student::coursework_average() const {
	if (tasks.size() == 0)
		return 0;
	return average(tasks);
}

double student::coursework_largest() const {
	if (tasks.size() == 0)
		return 0;
	//return *max_element(tasks.begin(), tasks.end()); // alternative implementation
	double best = tasks[0];
	for (double x : tasks) {
		if (x > best)
			best = x;
	}
	return best;
}

bool passed(const student& s) {
	return s.mark() >= pass_mark;
}

bool compare_names(const student& x, const student& y) {
        return x.name() < y.name();
}
