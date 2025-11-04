#include "student.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// read student data from stream
vector<student> read_students(istream &in) {
	vector<student> v;
	string line;
	while (getline(cin, line)) {
		istringstream line_s(line);
		string name;
		double x;
		if (line_s >> name >> x) {
			v.push_back(student(name, x));
			student &s = v.back();
			while (line_s >> x)
				s.add_task(x);
		}
	}
	return v;
}

void print_pass_then_fail(const std::vector<student>& students) {
	std::vector<student> passed_students;
	std::vector<student> failed_students;

	for (const student& s : students) {
		if (passed(s)) {
			passed_students.push_back(s);
		}
		else {
			failed_students.push_back(s);
		}
	}
	std::sort(passed_students.begin(), passed_students.end(), compare_names);
	std::sort(failed_students.begin(), failed_students.end(), compare_names);
	
	std::cout << "Passing students:\n";
	for (const student& s : passed_students) {
		std::cout << s.name() << ": " << s.mark() << '\n';
	}

	std::cout << "Failing students:\n";
	for (const student& s : failed_students) {
		std::cout << s.name() << ": " << s.mark() << '\n';
	}
}

void print_by_mark_desc(std::vector<student> students) {
	std::sort(students.begin(), students.end(),
		[] (const student& a, const student& b) {
			return a.mark() > b.mark(); });

	for (const student& s : students) {
		std::cout << s.name() << ": " << s.mark() << '\n';
	}
}

int count_at_least(const std::vector<student>& students, double threshold) {
	return std::count_if(students.cbegin(), students.cend(),
		[threshold](const student& s) {
			return s.mark() >= threshold; });
}


std::vector<student> make_test_students() {
	student a("Ali", 70);
	a.add_task(60);
	a.add_task(100);

	student b("Bilal", 50);
	b.add_task(40);

	student c("Zara", 30);        // should fail
	// no tasks

	std::vector<student> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	return v;
}

void run_tests() {
	auto v = make_test_students();

	std::cout << "count_at_least 40: "
		<< count_at_least(v, 40) << "\n";

	std::cout << "\npass then fail:\n";
	print_pass_then_fail(v);

	std::cout << "\nsorted by mark desc:\n";
	print_by_mark_desc(v);

	std::cout << "\nmarks with different coursework rules:\n";
	for (const auto& s : v) {
		std::cout << s.name()
			<< " median: " << s.mark()
			<< " avg: " << s.mark_with_average()
			<< " largest: " << s.mark_with_largest()
			<< "\n";
	}
}


int main() {
	run_tests();
	//auto students = read_students(cin);

	//// arrange the student records in alphaetical order
	//sort(students.begin(), students.end(), compare_names);

	//// write the names and total marks
	//streamsize prec = cout.precision();
	//for (const student &s : students) {
	//	cout << s.name() << ": " << setprecision(3) << s.mark() <<
	//		setprecision(prec) << '\n';
	//}
	//cout << count_if(students.cbegin(), students.cend(), passed) <<
	//	" passed out of " << students.size() << '\n';
	return 0;
}
