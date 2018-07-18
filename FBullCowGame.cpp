#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() 
{ 
	Reset();
}


int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const {
	TMap <int32, int32> WordLengthToMaxTries{ {3,5}, {4,6}, {5,9}, {6,13}, {7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}


void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet";
	bGameIsWon = false;
	MyCurrentTry = 1;
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

bool FBullCowGame::IsIsogram(FString Guess) const
{
	// Treat 0 and 1 letter words as isogram
	if (Guess.length() <= 1)
	{
		return true;
	}

	//setup our map
	TMap<char, bool> LetterSeen;
	// loop through the word Guess
	for (auto Letter : Guess) // for all letters of the word
	{
		Letter = tolower(Letter); // Changes letter to lowercase
		// add each letter to the map
		if (LetterSeen[Letter] == false)
		{
			LetterSeen[Letter] = true; // if its false, change to true
		}
		else if (LetterSeen[Letter] == true)
		{
			return false; // if its true return false
		}
			
			
	//else return true
	}
	return true; // for cases of something like /0
}

bool FBullCowGame::IsLowercase(FString Guess) const
{
	for (auto Letter : Guess)
	{
		if (!islower(Letter)) // not lowercase
		{
			return false;
		}
	}
	
	return true;
}





EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) // If guess isn't an isogram  	
	{
		return EGuessStatus::Not_Isogram; //TODO write method
	}
	else if (!IsLowercase(Guess))// if the guess isn't all lowercase   
	{
		return EGuessStatus::Not_Lowercase; //TODO write method
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
