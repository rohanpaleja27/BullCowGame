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

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// receives VALID guess, increments turn and returns count
	//increment turn
	MyCurrentTry++;
	//setup return variable
	FBullCowCount BullCowCount; // will have Bulls and Cows initialized to zero
	// loop through all letters in guess 
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		// compare letters against truth word
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			// if the match then
			if (Guess[i] == MyHiddenWord[j])
			{
				if (i == j)
				{
					BullCowCount.Bulls += 1;
				}
				else
				{
					BullCowCount.Cows += 1;
				}
			}
				// increment bulls in same place
				// increment bulls if not
		}
	}
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
