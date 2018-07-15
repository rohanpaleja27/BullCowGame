#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
void PrintGuess(std::string Guess);
bool AskToPlayAgain();

FBullCowGame BCGAME; // instantiate a new game

int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0;
}

void PrintIntro()
{
	// Introduce the game
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	
	int MaxTries = BCGAME.GetMaxTries();
	//loop for number of turns
	for (int count = 0; count < MaxTries; count++)
	{
		std::string Guess = GetGuess();
		PrintGuess(Guess);
	}
	return;
}

std::string GetGuess()
{
	int CurrentTry = BCGAME.GetCurrentTry();
	// get the guess from the player
	std::cout << "Enter guess #" << CurrentTry << ": ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}
void PrintGuess(std::string Guess)
{
	// Repeat guess back do them
	std::cout << "Your guess was: " << Guess << std::endl;
	std::cout << std::endl;
	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) : ";
	std::string Response = "";
	std::getline(std::cin, Response);
	return ((Response[0] == 'y') || (Response[0] == 'Y'));

}
