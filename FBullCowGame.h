#pragma once
#include <string>




class FBullCowGame
{
public:

	FBullCowGame(); // constructor
	
	void Reset(); // TODO
	int GetMaxTries () const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(std::string);
	bool PlayAgain();

	
	~FBullCowGame();

private:
	int MyCurrentTry;
	int MyMaxTries = 10;
	bool IsIsogram(std::string);

};




