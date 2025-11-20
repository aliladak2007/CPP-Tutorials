#include <iostream>
#include <string>

class Person {
private:
	std::string _name;
	int _age;

public:
	Person(const std::string& name, int age) : _name(name), _age(age) {};
	virtual void display() const {
		std::cout << "Name: " << _name << "\nAge: " << _age << std::endl;
	}
};

class Student : public Person {
private:
	int _studentId;

public:
	Student(const std::string& name, int age, int studentId)
		: Person(name, age), _studentId(studentId) {};
	void display() const override {
		Person::display();  // call base class method
		std::cout << "Student ID: " << _studentId << std::endl;
	}
};

int main() {
	std::cout << "Test 1: Direct Person and Student objects\n";
	Person p("Alice", 30);
	Student s("Bob", 20, 12345);

	std::cout << "\nPerson p.display():\n";
	p.display();

	std::cout << "\nStudent s.display():\n";
	s.display();

	s.Person::display();

	return 0;
}
