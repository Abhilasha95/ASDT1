/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CHUMAN.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CHUMAN_H
#define CHUMAN_H
#include "CPlayer.h"
class CHuman : public CPlayer
{
private:
    /**
     * Method to get the Position of the new piece
     * The method prompts the human player to enter the new piece position
     * @param board the generic Board in which the players are playing
     * @return the Position calculates for entering new
     * piece on the board
     */
	CPosition getNewPiecePos(CBoard *pBoard, const CPosition& opponentMovePos, unsigned short moveCtr);

public:
	CHuman();
	CHuman(std::string name, unsigned int piece);
	virtual ~CHuman();

    /**
	 * function of the player to place a piece on a board
	 *@param board the Board in which the game is being played
	 *@return position at which the piece was successfully placed
	 */
	CPosition placePiece(CBoard *pBoard, const CPosition& opponentMovePos, unsigned short moveCtr);

};
/********************
**  CLASS END
*********************/
#endif /* CHUMAN_H */
