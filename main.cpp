/*
This is the console executable, that makes use of the BullCow class.
Acts as the view in the MVC pattern, and is responsible for all
user interaction. For game logic, see the FBullCowGame class..
*/


#include <iostream>
#include <string>
#include "FBullCowGame.h"

using int32 = int;
using FText = std::string;

void PrintIntro();
void PlayGame();
FText GetGuess();
void PrintGuess(FText Guess);
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
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGAME.GetHiddenWordLength()  << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	
	BCGAME.Reset();
	int32 MaxTries = BCGAME.GetMaxTries();

	//loop for number of turns
	// TODO change from for to while loop 
	for (int32 count = 0; count < MaxTries; count++)
	{
		FText Guess = GetGuess();
		FBullCowCount BullCowCount = BCGAME.SubmitGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
		// TODO Check Validation of Guesses
		// TODO Submit valid guess to get bulls and cows
		// TODO Print number of bulls and cows
		PrintGuess(Guess);
	}
	return;
	// TODO: Summarize game
}

FText GetGuess()
{
	int32 CurrentTry = BCGAME.GetCurrentTry();
	// get the guess from the player
	std::cout << "Enter guess #" << CurrentTry << ": ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}
void PrintGuess(FText Guess)
{
	// Repeat guess back do them
	std::cout << "Your guess was: " << Guess << std::endl;
	std::cout << std::endl;
	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) : ";
	FText Response = "";
	std::getline(std::cin, Response);
	return ((Response[0] == 'y') || (Response[0] == 'Y'));

}
