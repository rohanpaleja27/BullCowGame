#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuess();

int main()
{
	PrintIntro();
	GetGuess();

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

string GetGuess()
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