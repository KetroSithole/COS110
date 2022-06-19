//Specification file for board class
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include "piece.h"

//board class declaration
class board
{
	private:
		int numWhitePieces;
		int numBlackPieces;
		piece **whitePieces;
		piece **blackPieces;
		std::string **chessboard;
		std::string move;
		char sideToMove;
		void applyMove();

	public:
		board(std::string pieceList);
		~board();
		void determineIfCheckMate ();
		bool checkIfPieceHasCheck (std::string pieceType, int xPos , int yPos, int kingX, int kingY);	
};
#endif