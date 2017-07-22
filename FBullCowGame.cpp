#include "FBullCowGame.h"



void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 3;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = "plane";
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

int32 FBullCowGame::GetMaxTries() const {	return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const {	return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }




EWordStates FBullCowGame::CheckGuessValidity(FString Guess) {
	//if the guess is not a isogram TODO
	//if is not all lower case TODO
	if (Guess.length() != GetHiddenWordLength()) { // if the length is wrong
		return EWordStates::Wrong_Length;
	}
	else if (!IsLowerCase(Guess) ) {
		return EWordStates::Not_Lowcase;
	}
	else if ( !IsIsogram(Guess) ) {
		return EWordStates::Not_Isogram;
	}
	else {
		return EWordStates::OK;
	}

	
}

bool FBullCowGame::PlayAgain() {
	std::cout << "Do you wanna play again? (y/n)\n";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return (((Response[0] == 'y') || (Response[0] == 'Y')) ? true : false);
}


FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {// receive a valid guess, increments turn and returns count.
	
	MyCurrentTry++;
	FBullCowCount BullCowCount;

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
	if (BullCowCount.Bulls == HiddenWordLength)
		bGameIsWon = true;
	else
		bGameIsWon = false;
	return BullCowCount;
}

void FBullCowGame::PrintBullCowCount(FBullCowCount BullCowCount) {
	std::cout << "Bulls = " << BullCowCount.Bulls;
	std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
	std::cout << std::endl;
}

void FBullCowGame::PrintGameSummary()
{
	if (bGameIsWon) {
		std::cout << "WELL DONE!!! YOU WON.\n\n";
	}
	else {
		std::cout << "YOU LOSE.\n\n";
	}
}

FBullCowGame::FBullCowGame() {
	Reset();

}


FBullCowGame::~FBullCowGame() {
}

bool FBullCowGame::IsIsogram(FString word) const
{
	//treat 0 and 1 letter word as isogram
	if (word.length() >= 1) { // when the length is larger, check if it is a Isogram.
		TMap <char, bool> LetterSeen;
		for (char Letter : word) {
			Letter = tolower(Letter);
			if (LetterSeen[Letter]) {// if the lettr is in the map 
				return false;// we do not have an isogram
			}
			else {
				LetterSeen[Letter] = true; // add the letter in otherwise
			}
		}
	}
	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (char Letter : Word) {
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}

