#include <iostream>
#include <string>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

using namespace std;

// -----------------------------------------------------------------------------
// Question 1: Check if age is within a specific range.
// Demonstrates simple conditional branching with if–else.
// -----------------------------------------------------------------------------
void checkAge()
{
    int age;
    cout << "Enter your age: ";
    cin >> age;

    // Compare age against given thresholds
    if (age < 18)
    {
        cout << age << " is too young\n";
    }
    else if (age > 30)
    {
        cout << age << " is too old\n";
    }
    else
    {
        cout << age << " is the right age\n";
    }
}

// -----------------------------------------------------------------------------
// Question 2: Print a personalised greeting with a decorative underline.
// Demonstrates string concatenation and loop-based output.
// -----------------------------------------------------------------------------
void printPersonalGreeting()
{
    cout << "Enter your name: ";

    string name;
    // Use getline to capture full name (including spaces)
    getline(cin, name);

    // Construct greeting message
    string greeting = "Hello, " + name + "!";

    // Print greeting
    cout << greeting << "\n";

    // Print a line of '=' characters equal in length to greeting
    for (int i = 0; i < greeting.size(); i++)
    {
        cout << "=";
    }
    cout << "\n"; // move to next line after underline
}

// -----------------------------------------------------------------------------
// Question 3: Random number guessing game.
// Demonstrates random number generation, loops, and conditional hints.
// -----------------------------------------------------------------------------
void randomNumberGame()
{
    // Seed random number generator with current time
    srand(time(nullptr));

    int n = 20;                    // upper bound for random number
    int secret = rand() % n + 1;   // secret number between 1 and n

    cout << "Guess a number between 1 and " << n << ": ";

    int guess;
    int counter = 1;               // count number of attempts
    cin >> guess;

    // Loop until user guesses correctly
    while (guess != secret) {
        if (guess > secret)
            cout << "Wrong! Number is less than that! Guess again: ";
        else
            cout << "Wrong! Number is more than that! Guess again: ";

        cin >> guess;
        counter++;
    }

    // Success message
    cout << "Correct!\n";

    // Handle singular/plural wording for tries
    if (counter == 1)
        cout << "You guessed it in " << counter << " try!\n";
    else
        cout << "You guessed it in " << counter << " tries!\n";
}

// -----------------------------------------------------------------------------
// main(): Entry point — uncomment desired function to run.
// -----------------------------------------------------------------------------
int main()
{
    // Only one function should be active at a time when testing.
    // Each function reads from cin; mixing can cause input conflicts.

    // checkAge();           // Uncomment to test Question 1
    printPersonalGreeting(); // Uncomment to test Question 2
    // randomNumberGame();   // Uncomment to test Question 3

    return 0;
}
