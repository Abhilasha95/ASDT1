/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CTICTACTOEBOARD.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CTICTACTOEBOARD_H
#define CTICTACTOEBOARD_H

#include "CBoard.h"

class CTicTacToeBoard : public CBoard
{
public:
	/**
	 * Creates a new TicTacToe Board and initializes the fields with the default values
	 *@return none
	 */
	CTicTacToeBoard();

	/**
	 * Frees the memory allocated by this ReversiBoard.
	 * @return none
	 */
	~CTicTacToeBoard();
};
/********************
**  CLASS END
*********************/
#endif /* CTICTACTOEBOARD_H */
