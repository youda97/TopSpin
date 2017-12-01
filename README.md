# TopSpin
http://mathtourist.blogspot.ca/2011/10/oval-track-puzzles.html

A circular chain of numbers in some non sorted order. By preforming one of 3 moves you need to place the numbers into order.

The three possible moves are:
1.	Shifting the chain to the left
2.	Shifting the chain to the right
3.	Spinning the top

When we spin the top we are placing a subset of 4 numbers into the chain but in reverse order. When we shift left or right we only affect the numbers that are available to spin. We can either shift the chain left or right (changing the 4 at the top that can be reversed) or we can turn the top over reversing the numbers at the top.

This is a C++ implementation of this game.

