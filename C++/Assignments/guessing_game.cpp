#include <iostream>
#include <cstdlib>

using namespace std;

bool playGuessingGame(int lowest_number, int highest_number, int chances){
	
	// generates a random game between between 
	// lowest_number and highest_number inclusively
	int guess = rand() % (highest_number - lowest_number + 1) + lowest_number;
	int num;
	
	while(chances != 0) {
		cout << "Enter a number (" << chances << " chances left): ";
		cin >> num; 
		
		// returns true if number matches
		if (num == guess){
			return true;
		} 
		
		else if (guess > num) {
			cout << "The answer is greater than " << num << endl;
		} 
		
		else if (guess < num) {
			cout << "The answer is less than " << num << endl;
		}
		chances--;
	}
	cout << "Answer is " << guess << endl;
	return false;
}

int main(){
	int i = 0;
	bool hasWon = playGuessingGame(6, 7, 1);
	// similar to if...else
	hasWon ? cout << "You Have Won The Game" : cout << "You Have Lossed The Game";
	return 0;
}
