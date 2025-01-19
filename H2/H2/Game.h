#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <cstdlib>
#include <ctime>

class Game {
private:
int maxNumber;
int playerGuess;
int randomNumber;
int numOfGuesses;

public:
Game(int max);
~Game();
void play();
void printGameResult();
};

#endif // GAME_H
