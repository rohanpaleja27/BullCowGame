#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() 
{ 
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES=8;
	const FString HIDDEN_WORD = "planet";
	
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
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
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		// compare letters against truth word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
		{
			// if they match then
			if (Guess[MHWChar] == MyHiddenWord[GChar])
			{
				if (MHWChar == GChar)
				{					
					BullCowCount.Bulls += 1; // increment bulls 
				}
				else
				{					
					BullCowCount.Cows += 1; // increment cows
				}
			}
		}
	}
	return BullCowCount;
}



bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString) const
{
	return false;
}
