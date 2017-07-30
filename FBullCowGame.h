#pragma once
#include <iostream>
#include <string>
#include <map>


#define TMap std::map


using int32 = int;
using FString = std::string;
using FText = std::string;

// define the struct for reture two variable
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStates {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowcase
};


class FBullCowGame
{
public:

	FBullCowGame(); // constructor
	
	void Reset(); 
	int32 GetMaxTries () const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;

	EWordStates CheckGuessValidity(FString);
	bool PlayAgain();
	// Counts bulls & Cows, and increase try number # it assuming valid guess.
	FBullCowCount SubmitValidGuess(FString);
	void PrintBullCowCount(FBullCowCount);
	void PrintGameSummary();
	
	//provide a 

	
	~FBullCowGame();

private:
	int MyCurrentTry;
	
	bool bGameIsWon = false;
	FString MyHiddenWord;

	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;

};




