#include "Game.h"

Game::Game(int max) : maxNumber(max), playerGuess(0), randomNumber(0), numOfGuesses(0) {
std::srand(static_cast<unsigned>(std::time(nullptr)));
randomNumber = std::rand() % maxNumber + 1;
std::cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber << " as a maximum value\n";
}

Game::~Game() {
std::cout << "GAME DESTRUCTOR: object cleared from stack memory\n";
}
void Game::play() {
do {
std::cout << "Give your guess between 1-" << maxNumber << ": ";
std::cin >> playerGuess;
numOfGuesses++;

if (playerGuess < randomNumber) {
std::cout << "Your guess is too small\n";
} else if (playerGuess > randomNumber) {
std::cout << "Your guess is too big\n";
        }
} while (playerGuess != randomNumber);

printGameResult();
}

void Game::printGameResult() {
std::cout << "Your guess is right = " << randomNumber << "\n";
std::cout << "You guessed the right answer = " << randomNumber
              << " with " << numOfGuesses << " guesses\n";
}
