#include<iostream>
#include <cassert>
#include<string>

class Rectangle {
private:
	double width;
	double height;

public:
	Rectangle(double w, double h) : width(w), height(h) {}
	
	double area() const {
		return width * height;
	}

	double perimeter() const {
		return 2 * (width + height);
	}

	void resize(double w, double h) {
		width = w;
		height = h;
	}
};


int main() {
    // Test 1: basic rectangle
    Rectangle r1(3.0, 4.0);
    std::cout << "r1 area: " << r1.area() << "\n";          // expect 12
    std::cout << "r1 perimeter: " << r1.perimeter() << "\n"; // expect 14

    assert(r1.area() == 12.0);
    assert(r1.perimeter() == 14.0);

    // Test 2: resize and test again
    r1.resize(5.0, 2.0);
    std::cout << "r1 area after resize: " << r1.area() << "\n";         // expect 10
    std::cout << "r1 perimeter after resize: " << r1.perimeter() << "\n"; // expect 14

    assert(r1.area() == 10.0);
    assert(r1.perimeter() == 14.0);

    // Test 3: square
    Rectangle square(5.0, 5.0);
    std::cout << "square area: " << square.area() << "\n";          // expect 25
    std::cout << "square perimeter: " << square.perimeter() << "\n"; // expect 20

    assert(square.area() == 25.0);
    assert(square.perimeter() == 20.0);

    std::cout << "All tests passed.\n";
    return 0;
}