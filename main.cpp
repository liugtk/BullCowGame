#include <iostream>
#include <string>

#include "FBullCowGame.h"



void PrintIntro();
std::string GetGuess();

void PlayGame();
bool AskToPlayAgain();

	FBullCowGame BCGame;

int main(){
	

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
	for (int i = 0; i < BCGame.GetMaxTries() ; i++) {
		std::string Guess = GetGuess();
		//repeat the guess back to them
		std::cout << "Your guess was: " << Guess << std::endl << std::endl;
	}
}

bool AskToPlayAgain() {
	std::cout << "Do you wanna play again? (y/n)\n";
	std::string Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return (( (Response[0] == 'y') || (Response[0] == 'Y') ) ? true : false);
}



std::string GetGuess() {
	// get a guess from the player
	std::cout << "Enter your guess: ";
	std::string Guess = "";
	//cin >> Guess;
	std::getline(std::cin, Guess);
	return Guess;
}


void PrintIntro() {
	// Introduce the game
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Buils and Cows" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm think of?" << std::endl;
	std::cout << std::endl;
	return;
}