/*
This is the console executable, that makes use of the BullCow class.
Acts as the view in the MVC pattern, and is responsible for all
user interaction. For game logic, see the FBullCowGame class..
*/



#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// To make syntax Unreal friendly
using int32 = int;
using FText = std::string;

// function prototypes outside of class
// Large functons for game play
void PrintIntro();
void PlayGame();
FText GetValidGuess();
void PrintGuess(FText Guess);
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGAME; // instantiate a new game, which we reuse across plays

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
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGAME.GetHiddenWordLength()  << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
	return;
}

// plays a single game to completion
void PlayGame()
{
	BCGAME.Reset();
	int32 MaxTries = BCGAME.GetMaxTries();

	//loop for number of turns while the game is 
	// NOT won and there are still tries remaining
	while (! BCGAME.IsGameWon() && BCGAME.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();
		FBullCowCount BullCowCount = BCGAME.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		PrintGuess(Guess);
	}
	PrintGameSummary();
	return;
	
}

// Function will loop continuosly till it recieves a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid;
	do
	{
		// get the guess from the player
		int32 CurrentTry = BCGAME.GetCurrentTry();
		std::cout << "Enter guess #" << CurrentTry << " of " << BCGAME.GetMaxTries() << ": ";
		
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
			break;  // assume guess is valid
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);   
	return Guess;
	
	
}

void PrintGuess(FText Guess)
{
	// Repeat guess back do them
	std::cout << "Your guess was: " << Guess << std::endl;
	std::cout << "You have " << BCGAME.GetMaxTries() - BCGAME.GetCurrentTry()+1 << " guesses left" << std::endl;
	std::cout << std::endl;
	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word? (y/n) : ";
	FText Response = "";
	std::getline(std::cin, Response);
	return ((Response[0] == 'y') || (Response[0] == 'Y'));

}

void PrintGameSummary()
{
	if (BCGAME.IsGameWon())
	{
		std::cout << "Congratulations! You Win! " << std::endl;
	}
	else
	{
		std::cout << "Better Luck Next Time!" << std::endl;
	}

	return;
}
