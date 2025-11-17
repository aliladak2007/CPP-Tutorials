#include<iostream>
#include<string>

class BankAccount {
private:
	std::string owner;
	double balance;

public:
	BankAccount(const std::string& o, double b) : owner(o), balance(b) {}

	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
		}
	}

	void withdraw(double amount) {
		if (amount > 0 && amount <= balance) {
			balance -= amount;
		}
		else {
			std::cerr << "Insufficient funds or invalid amount." << std::endl;
		}
	}

	double getBalance() const {
		return balance;
	}
};

int main() {
	BankAccount acc("Ali", 1000.0);
	acc.deposit(200.0);
	acc.withdraw(150.0);

	std::cout << "Current balance: " << acc.getBalance() << '\n';
	return 0;
}
