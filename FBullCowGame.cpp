#include "FBullCowGame.h"



void FBullCowGame::Reset() {
	constexpr int MAX_TRIES = 3;

	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	return;
}

int FBullCowGame::GetMaxTries() const {
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const {
	return 0;
}

bool FBullCowGame::IsGameWon() const {
	return false;
}




bool FBullCowGame::CheckGuessValidity(std::string) {
	return false;
}

bool FBullCowGame::PlayAgain() {
	return false;
}

FBullCowGame::FBullCowGame() {
	Reset();

}


FBullCowGame::~FBullCowGame() {
}

bool FBullCowGame::IsIsogram(std::string) {
	return false;
}
