/*
 * CTicTacToeBoard.cpp
 *
 *  Created on: 16-Nov-2019
 *      Author: Anoop
 */

#include "CTicTacToeBoard.h"

CTicTacToeBoard::CTicTacToeBoard()
{
	m_noOfRows = MAX_BOARD_ROW;
	m_noOfCols = MAX_BOARD_COL;

	//Dynamically creating Tic Tac Board with size 3X3
	m_board = new CField*[m_noOfRows];
	for(unsigned short row = 0; row < m_noOfRows; ++row)
		m_board[row] = new CField[m_noOfCols];

	for(int row = 0; row < m_noOfRows; row++)
	{
		for(int col = 0; col <m_noOfCols; col++)
		{
			m_board[row][col] = CField(FALSE, CPosition(row, col), CField::STONE_NIL);
		}
	}
}

CTicTacToeBoard::~CTicTacToeBoard()
{
}

