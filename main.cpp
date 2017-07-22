/*This is the code for BullCowGame
 this file is for 
*/


#include <iostream>
#include <string>

#include "FBullCowGame.h"


using FText = std::string;
using int32 = int;


void PrintIntro();
FText GetValidGuess();

void PlayGame();
bool AskToPlayAgain();





FBullCowGame BCGame;


int32 main(){
	

	do {
		PrintIntro();
		PlayGame();
	} 
	while (AskToPlayAgain());

	return	0;
}




void PlayGame(){

	BCGame.Reset();
	// loop for the number of turns asking for guess

	for (int32 i = 0; i < BCGame.GetMaxTries() ; i++) {

		
		
		FText Guess = GetValidGuess(); // TODO check for valid guess

		
		//submit the valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		//print number of bulls and cows
		BCGame.PrintBullCowCount(BullCowCount);



	}
	// TODO summarize the game
}

bool AskToPlayAgain() {
	std::cout << "Do you wanna play again? (y/n)\n";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return (( (Response[0] == 'y') || (Response[0] == 'Y') ) ? true : false);
}



FText GetValidGuess() {
	EWordStates status = EWordStates::Invalid_Status;
	FText Guess = "";
	do {
		// get a guess from the player
		std::cout << "Enter your guess: ";
		
		//cin >> Guess;
		std::getline(std::cin, Guess);

		status = BCGame.CheckGuessValidity(Guess);

		switch (status) {
		case EWordStates::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letters word\n";
			break;
		case EWordStates::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case EWordStates::Not_Lowcase:
			std::cout << "Please enter all lowercase.\n";
		default:
			std::cout << "Valid input accepted\n";
		}
		std::cout << std::endl;
	} while (status != EWordStates::OK);
	return Guess;
	
}


void PrintIntro() {
	// Introduce the game
	
	std::cout << "Welcome to Buils and Cows" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm think of?" << std::endl;
	std::cout << std::endl;
	return;
}