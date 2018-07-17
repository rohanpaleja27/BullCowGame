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
FText GetValidGuess();
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
		FText Guess = GetValidGuess();
		FBullCowCount BullCowCount = BCGAME.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		PrintGuess(Guess);
	}
	return;
	// TODO: Summarize game
}

// Function will loop continuosly till it recieves a valid guess
FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid;
	do
	{
		// get the guess from the player
		int32 CurrentTry = BCGAME.GetCurrentTry();
		std::cout << "Enter guess #" << CurrentTry << ": ";
		FText Guess = "";
		std::getline(std::cin, Guess);
		Status = BCGAME.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGAME.GetHiddenWordLength() << " letter word." << std::endl;
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters." << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a word in lowercase letters." << std::endl;
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	
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
