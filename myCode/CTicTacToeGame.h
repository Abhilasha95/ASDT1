/*
 * CTicTacToeGame.h
 *
 *  Created on: 18-Nov-2019
 *      Author: Anoop
 */

#ifndef CTICTACTOEGAME_H_
#define CTICTACTOEGAME_H_
#include "CTicTacToeConsole.h"
#include  "CComputer.h"
#include "CHuman.h"

class CTicTacToeGame
{
	CBoard *m_pBoard;
	CDisplay *m_pBoardDisplay;
	CPlayer *m_pPlayers[2]; //Pointer to an array of 2 players
	CPlayer *pCurrPlayer;
public:
	CTicTacToeGame();
	CTicTacToeGame(CPlayer *pPlayers[], CBoard *pBoard, CDisplay *pDisplay);

	void play();

	virtual ~CTicTacToeGame();

	/**
	 * Method to check if the Game is completed according to its rules
	 * @param none
	 * @return the boolean flag if the game is completed(TRUE) or not(FALSE)
	 */
	bool isGameFinished(const CPosition &newPiecePos);

	bool traverseCheckWin(const CPosition& parentPos, unsigned int travStyle);

};

#endif /* CTICTACTOEGAME_H_ */
