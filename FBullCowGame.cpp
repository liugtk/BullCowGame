#include "FBullCowGame.h"



void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 3;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = "plane";
	MyCurrentTry = 1;
	return;
}

int32 FBullCowGame::GetMaxTries() const {	return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const {	return MyHiddenWord.length();}

bool FBullCowGame::IsGameWon() const {
	return false;
}




EWordStates FBullCowGame::CheckGuessValidity(FString Guess) {
	//if the guess is not a isogram
	//if is not all lower case
	//if its length is wrong
	if (Guess.length() != GetHiddenWordLength()) {
		return EWordStates::Wrong_Length;
	}
	else {
		return EWordStates::OK;
	}

	
}

bool FBullCowGame::PlayAgain() {
	return false;
}


FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {// receive a valid guess, increments turn and returns count.
	
	MyCurrentTry++;// increment the count 
	FBullCowCount BullCowCount;// set up  a return variable


	
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++) {// check each letter in Guess, 
		for (int32 j = 0; j < HiddenWordLength; j++) {// compare with each Hiddenword
			
			if (Guess[i] == MyHiddenWord[j]) {
				
				if (i == j) {// when the count is the same => bull
					BullCowCount.Bulls++;
				}
				else {//if the index is not match, then we consider it as a cow.
					BullCowCount.Cows++;
				}
			}
		}
	}
		
	return BullCowCount;
}

void FBullCowGame::PrintBullCowCount(FBullCowCount BullCowCount) {
	std::cout << "Bulls = " << BullCowCount.Bulls;
	std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
	std::cout << std::endl;
}

FBullCowGame::FBullCowGame() {
	Reset();

}


FBullCowGame::~FBullCowGame() {
}

bool FBullCowGame::IsIsogram(FString) {
	return false;
}
