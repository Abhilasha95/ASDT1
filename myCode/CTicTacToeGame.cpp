/*
 * CTicTacToeGame.cpp
 *
 *  Created on: 18-Nov-2019
 *      Author: Anoop
 */

#include "CTicTacToeGame.h"

using namespace std;

CTicTacToeGame::CTicTacToeGame()
{
	m_pBoard = new CTicTacToeBoard;
	m_pBoardDisplay = new CTicTacToeConsole;
	pCurrPlayer = nullptr;

	unsigned short userOpt = 0;

	string playerName;

	for(int i = 0; i < 2; i++)
	{
		cout << endl << "Player " << i+1 << endl;
		cout << "0:HUMAN 1:COMPUTER \nEnter user option : ";
		cin >> userOpt;

		if(userOpt == 0)
		{
			cout << "Enter player name : ";
			cin >> playerName;
			if(i == CField::STONE_0)
				m_pPlayers[i] = new CHuman(playerName, CField::STONE_0);
			else if(i == CField::STONE_X)
				m_pPlayers[i] = new CHuman(playerName, CField::STONE_X);
		}
	    else if(userOpt == 1)
		{
	    	static unsigned short computerCtr = 1;
	    	playerName = "Computer_" + to_string(computerCtr++);
			if(i == CField::STONE_0)
				m_pPlayers[i] = new CComputer(playerName, CField::STONE_0);
			else if(i == CField::STONE_X)
				m_pPlayers[i] = new CComputer(playerName, CField::STONE_X);
		}
	}
}

CTicTacToeGame::~CTicTacToeGame()
{
	// TODO Auto-generated destructor stub
}

CTicTacToeGame::CTicTacToeGame(CPlayer *pPlayers[], CBoard *pBoard, CDisplay *pDisplay)
{

}

void CTicTacToeGame::play()
{
	CPosition prevMovePos;
	bool bFinished = FALSE;
	m_pBoardDisplay->printBoard(m_pBoard);
	for (unsigned short moveCtr = 0; moveCtr < 9; moveCtr++)
	{
		pCurrPlayer = m_pPlayers[moveCtr%2];
		pCurrPlayer->printPlayer(CPlayer::PRINT_NAME);
		CPosition newPiecePos = m_pPlayers[moveCtr%2]->placePiece(m_pBoard, prevMovePos, moveCtr+1);
		m_pBoardDisplay->printBoard(m_pBoard);
		bFinished = isGameFinished(newPiecePos);

		if (bFinished)
		{
			cout << endl << "Winner is : ";
			pCurrPlayer->printPlayer(CPlayer::PRINT_NAME);
			break;
		}
	}
	if (!bFinished)
	{
		cout << endl << "Match Drawn !!!";
	}
}

bool CTicTacToeGame::isGameFinished(const CPosition &newPiecePos)
{
	bool bGameWon = FALSE;

	CPosition parentTop = CPosition(0, newPiecePos.col);
	CPosition parentLeft = CPosition(newPiecePos.row, 0);

	if((newPiecePos.row == newPiecePos.col) || (abs(newPiecePos.row - newPiecePos.col)%2) == 0)
	{
		if(newPiecePos.row == 1 && newPiecePos.col == 1)
		{
			bGameWon = bGameWon || traverseCheckWin(CPosition(0,0), CBoard::TR_DIAG_RB);
			bGameWon = bGameWon || traverseCheckWin(CPosition(2,0), CBoard::TR_DIAG_RT);
		}
		else if (abs(newPiecePos.row - newPiecePos.col) == 2)
		{
			bGameWon = bGameWon || traverseCheckWin(CPosition(2,0), CBoard::TR_DIAG_RT);
		}
		else if (abs(newPiecePos.row - newPiecePos.col) == 0)
		{
			bGameWon = bGameWon || traverseCheckWin(CPosition(0,0), CBoard::TR_DIAG_RB);
		}
	}

	bGameWon = bGameWon || traverseCheckWin(parentTop, CBoard::TR_VERT_DOWN);
	bGameWon = bGameWon || traverseCheckWin(parentLeft, CBoard::TR_HORIZ_RI);

	return bGameWon;
}

bool CTicTacToeGame::traverseCheckWin(const CPosition& parentPos,	unsigned int travStyle)
{
	bool bGameWinFound = TRUE;

	CPosition itPos, travIncr;
	itPos = parentPos;

	//	Use the condition for different Traversal modes to calculate the traversal incrementer Index
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

	for (unsigned short i = 0; i < m_pBoard->getRowSize(); i++)
	{
		bGameWinFound = bGameWinFound && (m_pBoard->m_board[itPos.row][itPos.col].m_piece == pCurrPlayer->m_piece);
		itPos = itPos + travIncr;
	}

	return bGameWinFound;
}
