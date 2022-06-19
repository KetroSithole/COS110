#include <iostream>
#include <string>
#include "piece.h"

//Default constructor
piece::piece()
{ 
}


piece::piece(piece *newPiece)
{
	this->pieceType = newPiece->pieceType;
	this->side = newPiece->side;
	this->xPos = newPiece->xPos;
	this->yPos = newPiece->yPos;
		
}


piece::piece(std::string pType, char side, int x, int y)
{	
	pieceType = pType;
	this->side = side;
	xPos = x;
	yPos = y;
}


piece::~piece()
{
	std::cout << "(" << xPos << "," << yPos << ") " << side << " " << pieceType <<" " << "deleted" << std::endl;
}

void piece::setX(int x)
{
	this->xPos = x;
}


void piece::setY(int y)
{
	this->yPos = y;
}


void piece::printPiece()
{
	std::cout << side << " " << pieceType << " " << "at [" << xPos << "," << yPos <<"]" << std::endl; 
}



char piece::getSide()
{
	return side;
}


int piece::getX()
{
	return xPos;
}


int piece::getY()
{
	return yPos;
}



		
