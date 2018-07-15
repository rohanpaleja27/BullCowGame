#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame
{
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	bool CheckGuessValidity(FString); //TODO make a more rich return value.
	void Reset(); //TODO make a more rich return value.
	// Provide a method for counting bulls & cows, and incrementing try number
private:
	// see constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
};