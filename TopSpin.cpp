#include "TopSpin.h"
#include <iostream>

using namespace std;

// An implementation of templated class "TopSpin"

TopSpin::TopSpin()
{
	TopSpin(20, 4);
}

TopSpin::TopSpin(int lSize, int wS)
{
	if (wS > lSize)
		wS = lSize;

	listSize = lSize;
	wSize = wS;
	tape = new CircularDoublyLinkedList<int>(lSize, wS);

}

TopSpin::~TopSpin()
{
	delete tape;
}


CircularDoublyLinkedList<int> * TopSpin::getTape() {
	return tape;
}

void TopSpin::shiftLeft()
{
	tape->stepLeft();
}

void TopSpin::shiftRight()
{
	tape->stepRight();
}

void TopSpin::spin()
{
	
	for (int i = 0; i < wSize / 2; i++) {
		int p = tape->getBracketPosition() + i;
		int rhs = ((tape->getBracketPosition() + wSize - 1)%listSize) - i;
		tape->swap(p, rhs);
	}
}

bool TopSpin::isSolved()
{
	int k;
	for (int i = tape->getHeadPosition(); i < (listSize + tape->getHeadPosition()); i++) {
		int index1 = (i % listSize);
		int index2 = ((index1+1) % listSize);
		int first = tape->findValue(index1);
		int second = tape->findValue(index2);

		first = (first + 1);
		if (first > listSize) first = 1;
        	if (first != second)
	            return false;
	}
 
	return true;
}



ostream& operator<<(ostream& os, const TopSpin& t)
{
	int middle = (t.listSize) / 2;
	for (int i = t.tape->getHeadPosition(), j = 1; i < (t.listSize + t.tape->getHeadPosition()); i++, j++) {
		int index = (i % t.listSize);
		int firstBracket = (middle - (t.wSize / 2) + 1);
		if (j == firstBracket) {
			os << " [ ";
		}
		else if (j == firstBracket + t.wSize) {
			os << " ] ";
		}

		os << " " << t.tape->findValue(index) << " ";
	}

	return os;
}
