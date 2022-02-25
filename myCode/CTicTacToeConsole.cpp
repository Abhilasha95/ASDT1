/*
 * CTicTacToeConsole.cpp
 *
 *  Created on: 18-Nov-2019
 *      Author: Anoop
 */

#include "CTicTacToeConsole.h"

CTicTacToeConsole::CTicTacToeConsole()
{
	// TODO Auto-generated constructor stub
}

CTicTacToeConsole::~CTicTacToeConsole()
{
	// TODO Auto-generated destructor stub
}

void CTicTacToeConsole::printBoard(CBoard *pTicTacToeBoard)
{
	std::cout << std::endl << "   ";
	for(int j = 0; j < pTicTacToeBoard->getRowSize(); j++)
	{
		std::cout << j << "   ";
	}

	std::cout << std::endl<< "   ";
	for(int j = 0; j < pTicTacToeBoard->getColSize(); j++)
	{
		std::cout << "----";
	}

	std::cout << std::endl;
	for(int i = 0; i < pTicTacToeBoard->getRowSize(); i++)
	{
		std::cout << i << "| ";
		for(int j = 0; j < pTicTacToeBoard->getColSize(); j++)
		{
			if( pTicTacToeBoard->m_board[i][j].getState())
			{
				if(pTicTacToeBoard->m_board[i][j].m_piece == CField::STONE_0)
					std::cout << "0";
				else if(pTicTacToeBoard->m_board[i][j].m_piece == CField::STONE_X)
					std::cout << "X";
			}
			else
			{
				std::cout << ".";
			}
			std::cout << "   ";
		}
		std::cout << std::endl << std::endl;
	}
}


