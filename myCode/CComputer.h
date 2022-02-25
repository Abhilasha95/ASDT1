/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CCOMPUTER.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CCOMPUTER_H
#define CCOMPUTER_H

#include "CPlayer.h"

class CComputer:public CPlayer
{
private:

	bool traverseCheckOffenceDefence(CBoard *pBoard, const CPosition& parentPos, unsigned int travStyle, unsigned short strategy);

	CPosition getNewPiecePos(CBoard *pBoard, const CPosition& opponentMovePos, unsigned short moveCtr);

	enum checkStrategy {OFFENCE, DEFENCE};
public:
	CComputer();
	CComputer(std::string name, unsigned int piece);


	virtual ~CComputer();

    /**
	 * function of the player to place a piece on a board
	 *@param board the Board in which the game is being played
	 *@return position at which the piece was successfully placed
	 */
	CPosition placePiece(CBoard *pBoard, const CPosition& opponentMovePos, unsigned short moveCtr);
};

#endif /* CCOMPUTER_H_ */
