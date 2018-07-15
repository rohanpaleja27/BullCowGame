#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() 
{ 
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES=8;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	return;
}

BullCowCount FBullCowGame::SubmitGuess(FString)
{
	// receives VALID guess, increments turn and returns count
	//increment turn
	MyCurrentTry++;
	//setup return variable
	BullCowCount BullCowCount; // will have Bulls and Cows initialized to zero
	// loop through all letters in guess 
		// compare letters against truth word
	return BullCowCount;
}



bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}
