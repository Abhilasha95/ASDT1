/*
 * CTicTacToeConsole.h
 *
 *  Created on: 18-Nov-2019
 *      Author: Anoop
 */

#ifndef CTICTACTOECONSOLE_H_
#define CTICTACTOECONSOLE_H_

#include "CDisplay.h"
#include "CTicTacToeBoard.h"

class CTicTacToeConsole:public CDisplay
{
public:
	CTicTacToeConsole();
	virtual ~CTicTacToeConsole();
    /**
     * function to display a board
     * Prints the  board whose address is stored as a member of the  console view object
     *@return none
     */
    void printBoard(CBoard *pTttBoard);
};

#endif /* CTICTACTOECONSOLE_H_ */
