#pragma once
#include <iostream>
#include <string>

using FString = std::string;
using int32 = int;

//all values initialised to zero
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries()const;
	int32 GetCurrentTry()const;
	int32 GetHiddenWordLength()const;

	bool isGameWon() const;
	EGuessStatus CheckGuessValidity(FString)const;//TODO make a more rich return value
	
	void Reset(); //TODO make a more rich return value
	FBullCowCount SubmiteGuess(FString);

private:
	//let to the constructor to initialize the privates
	int32 MyMaxTries;
	int32 CurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;

};