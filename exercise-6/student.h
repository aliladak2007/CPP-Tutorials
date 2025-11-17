#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

// Q5: n and exam are conceptually immutable after construction.
// In this program they are kept non-const so that student remains
// assignable and can be sorted/stored in std::vector.

// record of a student's marks in a module
class student {
	std::string n; // student name
	double exam; // exam mark
	std::vector<double> tasks; // marks for coursework tasks

public:
	// Initialize student info
	student(const std::string &name, double e);

	// The name of the student
	const std::string &name() const { return n; }

	// Add a task mark
	void add_task(double m);

	// The total mark for the module
	double mark() const;
	double mark_with_average() const;
	double mark_with_largest() const;

private:
	// The coursework mark for the module
	double coursework() const;
	double coursework_average() const;
	double coursework_largest() const;
};

// Has the student passed the module?
bool passed(const student& s);

// Less-than comparison of student names
bool compare_names(const student& x, const student& y);

#endif
