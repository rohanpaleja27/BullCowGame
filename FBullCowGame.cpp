#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() 
{ 
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES=8;
	const FString HIDDEN_WORD = "planet";
	bGameIsWon = false;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	return;
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	// receives VALID guess, increments turn and returns count
	MyCurrentTry++;
	FBullCowCount BullCowCount; // will have Bulls and Cows initialized to zero

	// loop through all letters in hidden word 
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		// compare letters against guess
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
	if (BullCowCount.Bulls == HiddenWordLength)
	{
		bGameIsWon = true;
	} 
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}





EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) // If guess isn't an isogram  	
	{
		return EGuessStatus::Not_Isogram; //TODO write method
	}
	else if (false)// if the guess isn't all lowercase   
	{
		EGuessStatus::Not_Lowercase; //TODO write method
	}
	else if (Guess.length() != GetHiddenWordLength()) // if the guess isn't the right length
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK; //otherwise, return OK
	}
	
}
