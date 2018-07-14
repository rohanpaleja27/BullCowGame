#include <iostream>
#include <string>

using namespace std;


int main()
{
	// Introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << endl;
	cout << endl;

	// get the guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin,Guess);

	// Repeat guess back do them
	cout << "Your guess was: " << Guess << endl;
	cout << endl;

	return 0;
}