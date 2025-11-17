#include<iostream>

class A {
public:
	A() { std::cout << "A ctor\n"; }
	~A() { std::cout << "A dtor\n"; }
};

class B {
public:
	B() { std::cout << "B ctor\n"; }
	~B() { std::cout << "B dtor\n"; }
};

class C : public A {
public:
	B b;
	C() { std::cout << "C ctor\n"; }
	~C() { std::cout << "C dtor\n"; }
};

int main() {
	{
		A a;
		B b;
		C c;
	}

	return 0;
}
