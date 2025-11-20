#include <iostream>
#include <string>

class Animal {
public:
	Animal() {};
	virtual void speak() const {
		std::cout << "Animal sound" << std::endl;
	}
};

class Dog : public Animal {
	public:
	Dog() {};
	void speak() const override {
		std::cout << "Woof!" << std::endl;
	}
};

int main() {
	Dog d;
	d.speak();          // Dog object: prints "Woof!"

	Animal* a = &d;
	a->speak();         // Base pointer to Dog: also prints "Woof!" (dynamic dispatch)

	return 0;
}
