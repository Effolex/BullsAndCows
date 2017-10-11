#include "FbullCowGame.h"

FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const{ return MyHiddenWord.length(); }

bool FBullCowGame::isGameWon()const { return bGameIsWon; }

void FBullCowGame::Reset(){
	
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	FString HIDDEN_WORD ="plan";
	MyHiddenWord = HIDDEN_WORD;
	CurrentTry = 1;
	bGameIsWon = false;
	return;
}

//recieves a VALID  guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmiteGuess(FString Guess){
	
	CurrentTry++;
	FBullCowCount BullCowCount;

	//loop through all letters in the HiddenWord
	for (int32 i = 0; i < GetHiddenWordLength(); i++) {
		//compare letters against the Guess
		for (int32 j = 0; j < GetHiddenWordLength(); j++) {
			if (Guess[j] == MyHiddenWord[i]) {
				if (i == j) {
					BullCowCount.Bulls++;
				}//if
				else {
					BullCowCount.Cows++;
				}//else
			}
			
		}//forj
	}//fori
	if (BullCowCount.Bulls == GetHiddenWordLength())
		bGameIsWon = true;
	else
		bGameIsWon - false;
	return BullCowCount;
}



EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const{
	/*
	if ( ) {
		return EGuessStatus::OK;
	}
	else if () {
		return EGuessStatus::OK;
	}
	else if () {
		return EGuessStatus::OK;
	}*/
	if ((Guess.length()) != GetHiddenWordLength())
		return EGuessStatus::Wrong_Length;
	else
		return EGuessStatus::OK;
		
}
