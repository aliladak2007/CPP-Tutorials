#include <iostream>
#include <string>

class Account {
private:
	int _accountNumber;

protected:
	double _balance = 0.0;

public:
	Account(int accountNumber, double initialBalance) :
		_accountNumber(accountNumber), _balance(initialBalance) {};
};

class SavingsAccount : public Account {
private:
	double _interestRate;

public:
	SavingsAccount(int accountNumber, double initialBalance, double interestRate)
		: Account(accountNumber, initialBalance), _interestRate(interestRate) {};

	void applyInterest() {
		_balance += _balance * _interestRate;
		std::cout << "New balance after applying interest: " << _balance << std::endl;
	}
};

int main() {
	SavingsAccount s(12345, 1000.0, 0.05);
	s.applyInterest();  // uses protected _balance from the base
	return 0;
}
