#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;

	FBullCowCount BullCowCount;

	int32 HiddenWordLenght = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLenght; MHWChar++) 
	{
		for (int32 GChar = 0; GChar < HiddenWordLenght; GChar++) 
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar]) 
			{
				if (MHWChar == GChar) 
				{
					BullCowCount.Bulls++;
				}
				else 
				{
					BullCowCount.Cows++;
				}

			}
		}
	}
		return BullCowCount;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}
