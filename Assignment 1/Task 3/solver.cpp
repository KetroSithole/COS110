#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "board.h"
#include "piece.h"
#include "solver.h"

struct Divide
{
	std::string gameName;
	int priority;
};

int numLines = 0;

solver::solver (std::string game)
{
	std::string line;
	char comma;
	int index=0;

	std::ifstream inputFile;
	inputFile.open(game);

	while (inputFile >> line)
	{
		numLines++;
	}

	Divide TestDivide[numLines];
	Divide Print[numLines];
	boards = new board *[numLines];

	board **x = new board *[numLines];

	inputFile.clear();
	inputFile.seekg(0);

	while (inputFile >> line)
	{
		std::stringstream ss(line);
		getline(ss,TestDivide[index].gameName,',');
		ss >> TestDivide[index].priority;

		getline(ss,Print[index].gameName,',');
		ss >> Print[index].priority;
		index++;
	}


	for (int i=0;	i<numLines;	i++)
	{
		x[i] = new board (TestDivide[i].gameName);

	}

	

	for (int i=0;	i<numLines;	i++)
	{
		
		for (int j=0;	j<numLines;	j++)
		{
			if (TestDivide[i].priority < TestDivide[j].priority )
			{
				std::swap(TestDivide[i] , TestDivide[j]);
				
			}
			
			

		}
	}

	for (int i=0;	i<numLines;	i++)
	{
		boards[i] = new board (TestDivide[i].gameName);
		
		std::cout << "[" << TestDivide[i].priority << "] ";
		boards[i]->determineIfCheckMate();
	}

}


solver::~solver()
{
	for (int index=0;	index<numLines;	index++)
		delete boards[index];
	delete [] boards;

	std::cout << "Num Boards Deleted: " << numLines << std::endl;
}


