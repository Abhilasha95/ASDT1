/*
 * CBoard.cpp
 *
 *  Created on: 16-Nov-2019
 *      Author: Anoop
 */

#include "CBoard.h"

CBoard::CBoard()
{
	m_noOfRows = MAX_BOARD_ROW;
	m_noOfCols = MAX_BOARD_COL;
}

CBoard::~CBoard()
{
}


void CBoard::initBoard()
{
}

int CBoard::getRowSize()
{
	return m_noOfRows;
}

int CBoard::getColSize()
{
	return m_noOfCols;
}

bool CBoard::setField(const CPosition &position, unsigned int piece)
{
	bool bFieldSetSuccess = FALSE;

	// If not occupied, set the position
	m_board[position.row][position.col].m_position = position;
	m_board[position.row][position.col].m_piece = piece;
	m_board[position.row][position.col].m_state = TRUE;

	bFieldSetSuccess = TRUE;

	return bFieldSetSuccess;
}

bool CBoard::insertPiece(const CPosition& piecePos, unsigned int piece)
{
	bool bFieldEmpty = !m_board[piecePos.row][piecePos.col].getState();

	if(bFieldEmpty) //Check if  Field is occupied
	{
		setField(piecePos, piece);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
