#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

using namespace std;

FBullCowGame BCGame;

void PrintIntro() 
{
	constexpr int32 WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows \n";
	std::cout << "Can You guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
	return;
}

FText GetGuessAndPrintBack()
{
	int32 CurrentTry = BCGame.GetCurrentTry(); 

	//get a guess from the player
	std::cout <<"Try " << CurrentTry << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);

	//print the guess back
	std::cout << "Your guess was: " << Guess << std::endl;
	return Guess;
}

void PlayGame()
{
	BCGame.GetMaxTries();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;

	for (int32 count = 1; count <= MaxTries; count++)
	{

		FText Guess = GetGuessAndPrintBack();
		
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls; 
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
	}
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play forever? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
	std::cout << std::endl;
}


//app start
int32 main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	std::cout << std::endl;
	return 0;
}