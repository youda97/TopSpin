#pragma once
#include "TopSpinADT.cpp"
#include "CircularDoublyLinkedList.cpp"
class TopSpin : TopSpinADT { //TopSpin that inherits from TopSpinADT
public:
	TopSpin(); //constructor
	TopSpin(int lSize, int wS); //constructor that takes the size of the list(representing size of game) and the size of the window
	~TopSpin(); //destructor

	// shifts the pieces 1 to the left
	 void shiftLeft() ;
	//shifts the pieces 1 to the right
	 void shiftRight();
	//reverses the pieces in the spin mechanism, IE if the 4 in the mechanism are
	// 1,4,3,6 we will have 6,3,4,1
	 void spin() ;
	//checks to see if the puzzle is solved that is to say the pieces are in numerical order 1-20
	 bool isSolved();
	 CircularDoublyLinkedList<int> * getTape();
	 friend ostream& operator<<(ostream& os, const TopSpin& t); //overloads the << operator so you can print the board
	 

private:
	int wSize;
	int listSize;
	int currentWindowPosition;
	CircularDoublyLinkedList<int> * tape ;
};

