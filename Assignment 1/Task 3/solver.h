//Specification file for game class
#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include <string>
#include "board.h"

//game class declaration
class solver
{
	private:
		board **boards;
	public:
		solver (std::string game);
		~solver();
};

#endif

