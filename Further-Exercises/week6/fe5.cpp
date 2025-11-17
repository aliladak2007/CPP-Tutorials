#include <iostream>
#include <string>
#include <limits>


class Book {
private:
    std::string title;
    std::string author;
    int pages;

public:
	Book() : title(""), author(""), pages(0) {}

    void input() {
        std::cout << "Enter title: ";
        std::getline(std::cin, title);
		std::cout << "Enter author: ";
		std::getline(std::cin, author);
		std::cout << "Enter number of pages: ";
		std::cin >> pages;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void print() const {
        std::cout << "Title: " << title << "\n"
            << "Author: " << author << "\n"
            << "Pages: " << pages << "\n";
    }
};

int main() {
    Book b;

    b.input();
    b.print();

    return 0;
}