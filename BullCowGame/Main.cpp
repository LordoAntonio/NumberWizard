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
	std::cout << "Can You guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
	return;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
		cout << "WOW! YOU WIN! \n";
	else {
		std::cout << "BETTER LUCK NEXT TIME! \n";
	}
}

FText GetGuessAndPrintBack()
{
	int32 CurrentTry = BCGame.GetCurrentTry();

	//get a guess from the player
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		FText Guess = "";
		std::getline(std::cin, Guess);

		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters. \n";
			break;
		case EGuessStatus::Not_Lowercase:
		std::cout << "Please enter all lowercase letters. \n;";
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;

	} while (Status != EGuessStatus::OK);
}

void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	
	for (int32 count = 1; count <= MaxTries; count++)

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetGuessAndPrintBack();
		

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls; 
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl; "\n\n";
	}
	PrintGameSummary();
	return;
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
		void PrintGameSummary();
	} while (bPlayAgain);
	std::cout << std::endl;
	return 0;
}