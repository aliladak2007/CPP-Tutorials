#include <iostream>
#include <string>

class Shape {
private:
	std::string _type;

public:
	Shape(const std::string& type) : _type(type) {};
};

class Circle : public Shape {
private:
	double _radius;

public:
	Circle(double radius)
		: Shape("Circle"), _radius(radius) {
	};
};

int main() {
	Circle c(5.0);
	return 0;
}