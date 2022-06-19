//Specification file for piece class
#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>


//piece class declaration
class piece
{
	private:
		std::string pieceType;
		char side;
		int xPos;
		int yPos;
		
	public:
		piece();											//Constructor
		piece(piece *newPiece);
		piece(std::string pType, char side, int x, int y);
		~piece();											//Deconstructor
		char getSide();
		int getX();
		int getY();
		void setX(int x);
		void setY(int y);
		void printPiece();		
};


#endif 