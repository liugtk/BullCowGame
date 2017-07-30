/*This is the code for BullCowGame
 this file is for 
*/


#include <iostream>
#include <string>

#include "FBullCowGame.h"

// to make syntax Unreal friendly
using FText = std::string;
using int32 = int;


void PrintIntro();
FText GetValidGuess();

void PlayGame();






FBullCowGame BCGame; //instantiate a new game, which we will keep using it 


int32 main(){
	

	do {
		PrintIntro();
		PlayGame();
	} 
	while ( BCGame.PlayAgain() );

	return	0;
}




void PlayGame() { // play a single game

	BCGame.Reset();
	
	// play the game while there is try remained and the game is not won
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= BCGame.GetMaxTries()  ) {
		FText Guess = GetValidGuess(); 
		//submit the valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		//print number of bulls and cows
		BCGame.PrintBullCowCount(BullCowCount);
	}
	// summary the game
	BCGame.PrintGameSummary();

	return;
}




FText GetValidGuess() {
	EWordStates status = EWordStates::Invalid_Status;
	FText Guess = "";
	do {
		std::cout << "Try " << BCGame.GetCurrentTry() << " ";
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
			break;
		default:
			std::cout << "Valid input accepted\n";
			break;
		}
		std::cout << std::endl;
	} while (status != EWordStates::OK);
	return Guess;
	
}


void PrintIntro() {
	// Introduce the game
	
	std::cout << "Welcome to Buils and Cows, a fun game." << std::endl;
	std::cout << "           }    {         ____" << std::endl;
	std::cout << "           (o  o)        (o  o)   " << std::endl;
	std::cout << "   /-------\\  /          \\  /-------\\  " << std::endl;
	std::cout << "  / | Bull | o              o|  Cow  | \\ " << std::endl;
	std::cout << " *  | ---- |                 | ----- |  * " << std::endl;
	std::cout << "    ^      ^                 ^       ^    " << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm think of?" << std::endl;
	std::cout << "Try 1 out of " << BCGame.GetMaxTries() << "tries";
	std::cout << std::endl;
	return;
}