#include<iostream>
#include<string>

class Car {
private:
	std::string brand;
	int year;

public:
	Car(const std::string& b, int y) : brand(b), year(y) {}

	void display() const {
		std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
 	}
};

int main() {
	Car c("Toyota", 2015);
	c.display();
	return 0;
}