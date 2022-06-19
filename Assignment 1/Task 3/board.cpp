#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "board.h"
#include "piece.h"


board::board(std::string pieceList){

	//Declare variables
	std::string line, Move;
	numWhitePieces = 0;
	numBlackPieces = 0;

	//Open the file to be processed.
	std::ifstream inputFile;
	inputFile.open(pieceList);

	//Get the side to move.
	char sideMove;
	inputFile >> sideMove;
	sideToMove = sideMove;

	//Move command. 
	inputFile >> Move;
	move = Move;

	//Dynamically allocate memory for the chessboard.
	chessboard = new std::string *[8];
	for (int i=0;	i<8;	i++){
		chessboard[i] = new std::string[8];
		for (int j=0;	j<8;	j++){
			chessboard[i][j] = '-';
		}
	}

	//Get the number of black and whhite pieces.
	while (inputFile >> line){
		char pieceSide, comma;
		std::string pieceName;
		int xCoord, yCoord;

		std::stringstream ss(line);
		ss >> pieceSide >> comma;
		getline(ss,pieceName,',');
		ss >> xCoord >> comma >> yCoord;

		if (pieceSide == 'w'){
			if (pieceName == "king"){
				chessboard[xCoord][yCoord] = "wK";
			}
			else if (pieceName == "queen"){
				chessboard[xCoord][yCoord] = "wq";
			}
			else if (pieceName == "knight"){
				chessboard[xCoord][yCoord] = "wk";
			}
			else if (pieceName == "bishop"){
				chessboard[xCoord][yCoord] = "wb";
			}
			else if (pieceName == "rook"){
				chessboard[xCoord][yCoord] = "wr";
			}
			else if (pieceName == "pawn"){
				chessboard[xCoord][yCoord] = "wp";	
			}
			numWhitePieces++;
		}

		else{
			if (pieceSide == 'b'){
				if (pieceName == "king"){
					chessboard[xCoord][yCoord] = "bK";
				}
				else if (pieceName == "queen"){
					chessboard[xCoord][yCoord] = "bq";
				}
				else if (pieceName == "knight"){
					chessboard[xCoord][yCoord] = "bk";
				}
				else if (pieceName == "bishop"){
					chessboard[xCoord][yCoord] = "bb";
				}
				else if (pieceName == "rook"){
					chessboard[xCoord][yCoord] = "br";
				}
				else if (pieceName == "pawn" ){
					chessboard[xCoord][yCoord] = "bp";	
				}
				numBlackPieces++;
			}
		}
	}

	//Dynamically allocate memory for the black and white pieces.
	blackPieces = new piece *[numBlackPieces];
	whitePieces = new piece *[numWhitePieces];

	//Set file marker to the third line of file.
	inputFile.clear();
	inputFile.seekg(10);	

	//Declare variables of the board pieces. 
	int xC, yC;	 
	char pSide, ch;
	std::string pName;
	
	//Store pieces in their repsective colour arrays.
	int black=0, white=0;
	for (int index=0;	index<numBlackPieces+numWhitePieces;	index++){

		inputFile >> line;

		std::stringstream xs(line);
		xs >> pSide >> ch;
		getline(xs,pName,',');
		xs >> xC >> ch >> yC;

		if (pSide == 'w'){
			whitePieces[white++] = new piece (pName, pSide, xC, yC);
		}
		else{
			if (pSide == 'b'){
				blackPieces[black++] = new piece (pName, pSide, xC, yC);
			}
		}		
	}
	
	//Close file.
	inputFile.close();
}


//Deconstructor
board::~board(){

	//Deallocate the memory for the black pieces.
	for (int index=0;	index<numBlackPieces;	index++)
		delete blackPieces[index];
	delete [] blackPieces;

	//Deallocate the memory for the white pieces.
	for (int index=0;	index<numWhitePieces;	index++)
		delete whitePieces[index];
	delete [] whitePieces;

	//Deallocate the memory for the chessboard.
	for (int index=0;	index<8;	index++)
		delete [] chessboard[index];
	delete [] chessboard;

	std::cout << "Num Pieces Removed: " << numBlackPieces + numWhitePieces << std::endl;
}


bool board::checkIfPieceHasCheck (std::string pieceType, int xPos , int yPos, int kingX, int kingY){

	//Pawn
	if (pieceType == "pawn"){
		if (sideToMove == 'w'){
			if ( (kingX == xPos-1 && kingY == yPos-1) || (kingX == xPos-1 && kingY == yPos+1) )
				return true;
		}
		else{
			if (sideToMove == 'b'){
				if ( (kingX == xPos+1 && kingY == yPos-1) || (kingX == xPos+1 && kingY == yPos+1) )
					return true;
			}
		}
	}

	//Knight
	else if (pieceType == "knight"){
		if ( (kingX == xPos-2 && kingY == xPos-1 ) || (kingX == xPos-2 && kingY == yPos+1) || (kingX == xPos+2 && kingY == yPos-1)
			|| (kingX == xPos+2 && kingY == yPos+1) || (kingX == xPos-1 && kingY == yPos-2)|| (kingX == xPos-1 && kingY == yPos+2)
			|| (kingX == xPos+1 && kingY == yPos-2) || (kingX == xPos+1 && kingY == yPos+2) ){
			return true;
		}
	}
	
	//Rook 
	else if(pieceType == "rook"){
		for (int yIndex = yPos;	yIndex<8;	yIndex++){
			if (kingX == xPos && kingY == yIndex)
				return true;
		}

		for (int yIndex = yPos;	yIndex>=0;	yIndex--){
			if (kingX == xPos && kingY == yIndex)
				return true;
		}
		
		for (int xIndex = xPos;	xIndex<8;	xIndex++){
			if (kingX == xIndex && kingY == yPos)
				return true;
		}

		for (int xIndex = xPos;	xIndex>=0;	xIndex--){
			if (kingX == xIndex && kingY == yPos)
				return true;
		}
	}

	//Bishop
	else if(pieceType == "bishop"){
		for (int xIndex=xPos;	xIndex>=0;	xIndex--){
			if (yPos >= 0){
				if (kingY == yPos && kingX == xIndex)
					return true;
			}
			yPos--;
		}

		for (int xIndex=xPos;	xIndex>=0;	xIndex--){
			if (yPos < 8){
				if (kingY == yPos && kingX == xIndex){
					return true;
				}
			}
			yPos++;
		}

		for (int xIndex=xPos;	xIndex < 8;	xIndex++){
			if (yPos >= 0){
				if (kingY == yPos && kingX == xIndex)
					return true;
			}
			yPos--;
		}

		for (int xIndex=xPos;	xIndex < 8;	xIndex++){
			if (yPos < 8){
				if (kingY == yPos && kingX == xIndex)
					return true;
			}
			yPos++;
		}
	}

	//Queen
	else if (pieceType == "queen"){
		for (int xIndex=xPos;	xIndex>=0;	xIndex--){
			if (yPos >= 0){
				if (kingY == yPos && kingX == xIndex)
					return true;
			}
			yPos--;
		}

		for (int xIndex=xPos;	xIndex>=0;	xIndex--){
			if (yPos < 8){
				if (kingY == yPos && kingX == xIndex)
					return true;
			}
			yPos++;
		}

		for (int xIndex=xPos;	xIndex < 8;	xIndex++){
			if (yPos >= 0){
				if (kingY == yPos && kingX == xIndex)
					return true;
			}
			yPos--;
		}

		for (int xIndex=xPos;	xIndex < 8;	xIndex++){
			if (yPos < 8){
				if (kingY == yPos && kingX == xIndex)
					return true;
			}
			yPos++;
		}

		for (int yIndex = yPos;	yIndex<8;	yIndex++){
			if (kingX == xPos && kingY == yIndex)
				return true;
		}

		for (int yIndex = yPos;	yIndex>=0;	yIndex--){
			if (kingX == xPos && kingY == yIndex)
				return true;
		}
		
		for (int xIndex = xPos;	xIndex<8;	xIndex++){
			if (kingX == xIndex && kingY == yPos)
				return true;
		}

		for (int xIndex = xPos;	xIndex>=0;	xIndex--){
			if (kingX == xIndex && kingY == yPos)
				return true;
		}
	}

	return false;
}


void board::applyMove(){

	int curX,curY,newX,newY;
	char comma; 
	std::stringstream ss(move);
	ss >> curX >> comma >> curY >> comma >> newX >> comma >> newY;

	chessboard[newX][newY] = chessboard[curX][curY];
	chessboard[curX][curY] = "-";

	if (sideToMove == 'w'){
		for (int index=0;	index<numWhitePieces;	index++){
			if (whitePieces[index]->getX() == curX && whitePieces[index]->getY() == curY){
				whitePieces[index]->setX(newX);
				whitePieces[index]->setY(newY);
			}
		}
	}

	else{
		if (sideToMove == 'b'){
			for (int index=0;	index<numBlackPieces;	index++){
				if (blackPieces[index]->getX() == curX && blackPieces[index]->getY() == curY){
					blackPieces[index]->setX(newX);
					blackPieces[index]->setY(newY);
				}
			}
		}
	}	
}

void board::determineIfCheckMate()
{
	applyMove();
	int kX,kY,pX,pY;
	
	int xPiece, yPiece;
	bool checkStatus;
	bool Checkmate = true;
	char sideX;
	std::string piece;

	if (sideToMove == 'w'){
		sideX = 'b';
		for (int xIndex=0;	xIndex<8;	xIndex++){
			for (int yIndex=0;	yIndex<8;	yIndex++){
				if (chessboard[xIndex][yIndex] == "bK"){
					kX = xIndex;
					kY = yIndex;
				}
			}
		}

		for(int x=kX-1; x<=kX+1; x++){
        	for(int y=kY-1; y<=kY+1;y++){
            	if(x>=0 && x<=7 &&y>=0 &&y<=7){
                	checkStatus = false;
                	if(chessboard[x][y]=="-"||chessboard[x][y]== "bK"){
                    	for(int index=0; index<numWhitePieces; index++){
	                        pX = whitePieces[index]->getX();
	                        pY = whitePieces[index]->getY();
	                        
	                       	std::string PIECE;
	                       
	                        if(chessboard[pX][pY] == "wK"){
	                            continue;
	                        }
	                        else if(chessboard[pX][pY] =="wp"){
	                            PIECE = "pawn";
	                        }
	                        else if(chessboard[pX][pY] == "wq"){
	                            PIECE = "queen";
	                        }
	                        else if(chessboard[pX][pY] == "wb"){
	                            PIECE = "bishop";
	                        }
	                        else if(chessboard[pX][pY] == "wk"){
	                            PIECE = "knight";
	                        }
	                        else if(chessboard[pX][pY] == "wr"){
	                            PIECE = "rook";
	                        }

	                        checkStatus =checkIfPieceHasCheck(PIECE,pX,pY,x,y);

	                        if(checkStatus){
	                            Checkmate = true;
	                            break;
	                        }   
	                    }

	                    if(!checkStatus){
	                        Checkmate = false;
	                        std::cout<<"Failed: No Checkmate of "<<sideX<<" King"<<std::endl;
	                        return;
	                    }  
                	}
            	}   
        	}
        }

    	if(Checkmate){ 
   	    	std::cout<<"Success: Checkmate of "<<sideX<<" King at ["<<kX<<","<<kY<<"]"<<std::endl;
    	}
	}	


	else {
		if (sideToMove == 'b'){
			sideX = 'w';
			for (int xIndex=0;	xIndex<8;	xIndex++){
				for (int yIndex=0;	yIndex<8;	yIndex++){
					if (chessboard[xIndex][yIndex] == "wK"){
						kX = xIndex;
						kY = yIndex;
					}
				}
			}

			for(int x=kX-1; x<=kX+1; x++){
	        	for(int y=kY-1; y<=kY+1;y++){
	            	if(x>=0 && x<=7 &&y>=0 &&y<=7){
	                	checkStatus = false;
	                	if(chessboard[x][y]=="-"||chessboard[x][y]== "wK"){
	                    	for(int index=0; index<numWhitePieces; index++){
		                        pX = whitePieces[index]->getX();
		                        pY = whitePieces[index]->getY();
		                        
		                       	std::string PIECE;
		                       
		                        if(chessboard[pX][pY] == "bK"){
		                            continue;
		                        }
		                        else if(chessboard[pX][pY] =="bp"){
		                            PIECE = "pawn";
		                        }
		                        else if(chessboard[pX][pY] == "bq"){
		                            PIECE = "queen";
		                        }
		                        else if(chessboard[pX][pY] == "bb"){
		                            PIECE = "bishop";
		                        }
		                        else if(chessboard[pX][pY] == "bk"){
		                            PIECE = "knight";
		                        }
		                        else if(chessboard[pX][pY] == "br"){
		                            PIECE = "rook";
		                        }

		                        checkStatus =checkIfPieceHasCheck(PIECE,pX,pY,x,y);

		                        if(checkStatus){
		                            Checkmate = true;
		                            break;
		                        }   
		                    }

		                    if(!checkStatus){
		                        Checkmate = false;
		                        std::cout<<"Failed: No Checkmate of "<<sideX<<" King"<<std::endl;
		                        return;
		                    }  
	                	}
	            	}   
	        	}
	        }

	    	if(Checkmate){ 
	   	    	std::cout<<"Success: Checkmate of "<<sideX<<" King at ["<<kX<<","<<kY<<"]"<<std::endl;
	    	}
		}
	}
}	