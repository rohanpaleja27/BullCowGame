#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
void PrintGuess(string Guess);
bool AskToPlayAgain();

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
	// Introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << endl;
	cout << endl;
	return;
}

void PlayGame()
{
	//loop for number of turns
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 0; count < NUMBER_OF_TURNS; count++)
	{
		string Guess = GetGuess();
		PrintGuess(Guess);
	}
	return;
}

string GetGuess()
{
	// get the guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}
void PrintGuess(string Guess)
{
	// Repeat guess back do them
	cout << "Your guess was: " << Guess << endl;
	cout << endl;
	return;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again? (y/n) : ";
	string Response = "";
	getline(cin, Response);
	return ((Response[0] == 'y') || (Response[0] == 'Y'));

}
