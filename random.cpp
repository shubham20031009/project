#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;

    std::cout << "Welcome to the Guess the Number game!\n";
    std::cout << "I have chosen a number between 1 and 100. Can you guess it?\n";

    int userGuess;

    // Continue looping until the user guesses the correct number
    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        // Provide feedback on the user's guess
        if (userGuess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else if (userGuess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the correct number, which was " << secretNumber << "!\n";
            break;
        }
    }

    return 0;
}
