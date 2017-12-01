#include "TopSpin.h"
#include <iostream>
#include <ctime> 
#include <conio.h> 

using namespace std;

int main() {
	srand(unsigned(time(NULL)));
	char option;
	int ans;

	TopSpin * spinner = new TopSpin(20, 4); //Creates a TopSpin object of size 20 and spinSize 4.

	//Asks the user for a number of random moves to initialize the puzzle with
	cout << "Please enter a number of random moves to initialize the game: ";
	cin >> ans;

	//A random move shifting left randomly 1-19 pieces followed by a spin.
	for (int i = 0; i < ans %19 + 1; i++) {
		int j = ((rand() % 19) + 1);
		for (i = 0; i < j; i++) {
			spinner->shiftLeft();
		}
		spinner->spin();
	}

	//menu which asks if they want to : shift, spin, or quit
	cout << "\nPress RIGHT to move right, LEFT to move left, SPACE to spin, or ESC to exit\n" << endl;
	cout << *spinner << endl;

	while (true) {	
		do
		{
			option = _getch();
		} while (option != 27 && option != 77 && option != 75 && option != 32);

		//execute the requested shift, spin or exit
		if (option == 27) {
			cout << "Please try again ..." << endl;
			break; //exits loop
		}
		else if (option == 75) { // move left
			spinner->shiftLeft();
			cout << *spinner << endl;
		}
		else if (option == 77) { // move right
			spinner->shiftRight();
			cout << *spinner << endl;
		}
		else if (option == 32) { // spin
			spinner->spin();
			cout << *spinner << endl;
			//displays the following message when puzzle is solved
			if (spinner->isSolved()) {
				cout << "\n CONGRATULATIONS! \n" << endl;
				break; //exits loop
			}
		}
	}
	system("pause");
}