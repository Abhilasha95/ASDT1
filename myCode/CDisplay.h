/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CDISPLAY.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CCDisplay_H_
#define CCDisplay_H_

/**
 * Represents a Class of  Board CDisplayer. It will CDisplay a
 *   board in the form of Matrix
 * */

#include "CBoard.h"

class CDisplay
{
public:

    /**
     * Creates a Console-view and initializes its value to the default state.
     *@return none
     */
    CDisplay();

    /**
     * Creates a Console-view and initializes its pointer to TicTacToeBoard
     * with the address of the created instance of the  board.
     *
     * @param pTicTacToeBoard the address of the created instance of the  board
     * @return none
     */
    CDisplay(CBoard* pBoard);

    /**
     * Virtual function to display a board
     * Prints the  board whose address is stored as a member of the  console view object
     *@return none
     */
    virtual void printBoard(CBoard* pBoard);
};
/********************
**  CLASS END
*********************/

#endif /* CDISPLAY_H */
