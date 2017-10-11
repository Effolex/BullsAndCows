/*
This is the console executable, that makes use of  the BullCow class
This act as the view in a MVC pattern, and is responsible for all
user interaction. For game Logic see the FBullCowGame class.
*/
//Pre Processor
#include <iostream>
#include <string>
#include "FbullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();


FBullCowGame BCGame; // instance a new game



int main() {
	bool playagain;
	do {
		PrintIntro();
		PlayGame();
		//add a game sumary
		playagain = AskToPlayAgain();
	}while (playagain);

	return 0;
}

void PrintIntro() {

	//TODO Introducing the game
	std::cout << "\nWelcome to Bulls And Cows" << std::endl
		<< "Can you guess the "
		<< BCGame.GetHiddenWordLength()
		<< " letter isogram I'm thinking of?" << std::endl;
	return;
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//loop asking for guesses while not won
	// and still tryies remaining
	while(!BCGame.isGameWon() && BCGame.GetCurrentTry() <= MaxTries){//TODO change from FOR to WHILE
		FText Guess = GetValidGuess();
		
	


		FBullCowCount BullCowCount = BCGame.SubmiteGuess(Guess);

		//print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
		std::cout << "This was your guess: " << Guess << std::endl;
	}//for

	//TODO summarise game
}

//loop until the user guves a valid guess
FText GetValidGuess() {

	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << std::endl << "Current Try: " << CurrentTry << "! What's is your guess?";

		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status){
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a lowercase guess! \n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters! \n";
			break;
		default:
			break;
			/*
			Not_Isogram,
			Not_Lowercase*/
		}

	} while (Status != EGuessStatus::OK);
	return Guess;
	
}

bool AskToPlayAgain () {
	int32 playagain = 0;
	std::cout << std::endl << "Do you want to play again? 1-Yes 2-Not" << std::endl;
	std::cin >> playagain;
	if (playagain == 1) {
		BCGame.Reset();
		return true;
	}
	if (playagain == 2) {
		return false;
	}
	else {
		return false;
	}
}



