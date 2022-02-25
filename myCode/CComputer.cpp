/*
 * CComputer.cpp
 *
 *  Created on: 17-Nov-2019
 *      Author: Anoop
 */

#include "CComputer.h"

CComputer::CComputer()
{

}

CComputer::CComputer(std::string name, unsigned int piece)
{
	initPlayer(name, piece);
}

CComputer::~CComputer()
{

}

CPosition CComputer::getNewPiecePos(CBoard *board, const CPosition& opponentMovePos, unsigned short moveCtr)
{
	CPosition newPiecePos;
	CPosition oppntMovePos = CPosition(opponentMovePos.row, opponentMovePos.col);

	/**
	 * Finding Offence/Defence Position
	 * Iterate through the board grid
	 * Find Empty Field
	 * Find the parentLeft and parentTop Positions
	 * If row = col, assign (0,0) and (2,0) as parentCells
	 */
	CPosition leftParentPos, topParentPos, diagLtParPos(0,0), diagLbParPos(2,0);

	//Stores the offense, defense and the random placement position
	CPosition offensePos, defencePos, randomPos;

	bool bIsOffDefPosFound = FALSE;

	//Checking for offense or defense Position

	for(unsigned short itStrategy = OFFENCE; itStrategy <= DEFENCE; itStrategy++)
	{
		for(unsigned short row = 0; row < board->getRowSize(); row ++)
		{
			for(unsigned short col = 0; col < board->getColSize(); col ++)
			{
				//Find Empty Field
				if(board->m_board[row][col].isEmpty())
				{
					leftParentPos = CPosition(row, 0);
					topParentPos = CPosition(0, col);
					randomPos = CPosition(row, col);

					//Check if the iterated empty field is a diagonal
					if((row == col) || (abs(row-col)%2 == 0))
					{
						if(row == 1 && col == 1)
						{
							bIsOffDefPosFound = bIsOffDefPosFound || traverseCheckOffenceDefence(board, diagLtParPos, CBoard::TR_DIAG_RB, itStrategy);
							bIsOffDefPosFound = bIsOffDefPosFound || traverseCheckOffenceDefence(board, diagLbParPos, CBoard::TR_DIAG_RT, itStrategy);
						}
						else if (abs(row - col) == 2)
						{
							bIsOffDefPosFound = bIsOffDefPosFound || traverseCheckOffenceDefence(board, diagLbParPos, CBoard::TR_DIAG_RT, itStrategy);
						}
						else if (abs(row - col) == 0)
						{
							bIsOffDefPosFound = bIsOffDefPosFound || traverseCheckOffenceDefence(board, diagLtParPos, CBoard::TR_DIAG_RB, itStrategy);
						}

					}
					bIsOffDefPosFound = bIsOffDefPosFound || traverseCheckOffenceDefence(board, leftParentPos, CBoard::TR_HORIZ_RI, itStrategy);
					bIsOffDefPosFound = bIsOffDefPosFound || traverseCheckOffenceDefence(board, topParentPos, CBoard::TR_VERT_DOWN, itStrategy);


					if(bIsOffDefPosFound)
					{
						return CPosition(row, col);
					}
				}
			}
		}
	}

	//Checking for Random Position

	//Check if this Computer player is the first player
		bool bIsFirstPlayer = (moveCtr%2 == 1);
		unsigned short myMoveCtr;

		//Get the move number of the current player
		if(bIsFirstPlayer)
			myMoveCtr = moveCtr/2 + 1;
		else
			myMoveCtr = moveCtr/2;

		//Checking for Random Position
		//If the move is the first move, then you are the first player. Place the piece in the corner (2,0)

		if(moveCtr == 1)
		{
			return CPosition(2, 0);
		}

		//If the move is the second move you are Player 2, place the piece in the center position
		else if(moveCtr == 2)
		{
			if(myMoveCtr == 1)
			{
				if(board->m_board[1][1].isEmpty())
				{
					return CPosition(1,1);
				}
			}
		}

		//If the move is the third move
		else if(moveCtr == 3)
		{
			//you are the first player, check if the previous move of the opponent was in (0,0)(1,0)(0,1)
			// In that case place your piece in (2,2)
			if((oppntMovePos == CPosition(0,0)) || (oppntMovePos == CPosition(1,0)) || (oppntMovePos == CPosition(0,1)))
			{
				if(board->m_board[0][0].isEmpty())
				{
					std::cout << std::endl << "Random";
					return CPosition(2,2);
				}
			}

			//you are the first player, check if the previous move of the opponent was in (2,1)(2,2)(1,2)
			// In that case place your piece in (2,2)
			if((oppntMovePos == CPosition(2,1)) || (oppntMovePos == CPosition(2,2)) || (oppntMovePos == CPosition(1,2)))
			{
				if(board->m_board[0][0].isEmpty())
				{
					std::cout << std::endl << "Random";
					return CPosition(0,0);
				}
			}
		}

		else
		{
			for(unsigned short row = 0; row < board->getRowSize(); row ++)
					{
						for(unsigned short col = 0; col < board->getColSize(); col ++)
						{
							//Find Empty Field
							if(board->m_board[row][col].isEmpty())
							{
								std::cout << std::endl << "Random";
								return CPosition(row, col);
							}
						}
					}
		}

		return CPosition(0,0);
}

CPosition CComputer::placePiece(CBoard *board, const CPosition& opponentMovePos, unsigned short moveCtr)
{
	CPosition newPiecePos = getNewPiecePos(board, opponentMovePos, moveCtr);
	board->insertPiece(newPiecePos, m_piece);
	return newPiecePos;
}

bool CComputer::traverseCheckOffenceDefence(CBoard *pBoard, const CPosition& parentPos,	unsigned int travStyle, unsigned short strategy)
{
	bool bFoundPos = FALSE;
	unsigned int myPiece = m_piece;

	CPosition itPos, travIncr;
	itPos = parentPos;

	//	Use the condition for different Traversal modes to calculate the traversal incrementor Index
	switch(travStyle)
	{
	case CBoard::TR_VERT_UP:{ travIncr = CPosition(-1, 0); break;}
	case CBoard::TR_VERT_DOWN:{ travIncr = CPosition(1, 0);  break;}
	case CBoard::TR_HORIZ_LE:{ travIncr = CPosition(0, -1);  break;}
	case CBoard::TR_HORIZ_RI:{ travIncr = CPosition(0, 1);  break;}
	case CBoard::TR_DIAG_LT:{ travIncr = CPosition(-1,-1);  break;}
	case CBoard::TR_DIAG_RB:{ travIncr = CPosition(1,1);  break;}
	case CBoard::TR_DIAG_LB:{ travIncr = CPosition(1,-1);  break;}
	case CBoard::TR_DIAG_RT:{ travIncr = CPosition(-1,1);  break;}
	}

	//Variables to store the occurrence of my piece and opponents piece
	unsigned short myPieceCtr = 0, oppPieceCtr = 0;
	bool bIsMyPiece = FALSE, bIsEmpty = TRUE;

	for (unsigned short i = 0; i < pBoard->getRowSize(); i++)
	{
		//Check if the Iterated Field contain my piece
		bIsMyPiece = (pBoard->m_board[itPos.row][itPos.col].m_piece == myPiece);
		bIsEmpty = pBoard->m_board[itPos.row][itPos.col].isEmpty();

		if(strategy == OFFENCE)
		{
			//Check if the line contains a field with opposite piece
			if((!bIsEmpty) && (!bIsMyPiece))
			{
				return FALSE;
			}
			else if ((!bIsEmpty) && (bIsMyPiece))
			{
				myPieceCtr++;
			}
		}
		else if (strategy == DEFENCE)
		{
			//Check if the line contains a field with my piece
			if((!bIsEmpty) && (bIsMyPiece))
			{
				return FALSE;
			}
			else if ((!bIsEmpty) && (!bIsMyPiece))
			{
				oppPieceCtr++;
			}
		}

		itPos = itPos + travIncr;

		if((myPieceCtr > 1) || (oppPieceCtr > 1))
			bFoundPos = TRUE;
	}

	return bFoundPos;
}

