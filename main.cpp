#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

int main()
{
	
	PrintIntro();

	//loop for number of turns
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 0; count < NUMBER_OF_TURNS; count++)
	{
		GetGuessAndPrintBack();
	}

	return 0;
}

void PrintIntro()
{
	// Introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << endl;
	cout << endl;
	return;
}

string GetGuessAndPrintBack()
{
	// get the guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	// Repeat guess back do them
	cout << "Your guess was: " << Guess << endl;
	cout << endl;
	return Guess;
}