/*
 * CHuman.cpp
 *
 *  Created on: 17-Nov-2019
 *      Author: Anoop
 */

#include "CHuman.h"

CHuman::CHuman()
{
	// TODO Auto-generated constructor stub

}

CHuman::~CHuman()
{
	// TODO Auto-generated destructor stub
}

CHuman::CHuman(std::string name, unsigned int piece)
{
	initPlayer(name, piece);
}

CPosition CHuman::placePiece(CBoard *pBoard, const CPosition& opponentMovePos, unsigned short moveCtr)
{
	CPosition newPiecePos = getNewPiecePos(pBoard, opponentMovePos, moveCtr);
	pBoard->insertPiece(newPiecePos, m_piece);
	return newPiecePos;
}

CPosition CHuman::getNewPiecePos(CBoard *pBoard, const CPosition& opponentMovePos, unsigned short moveCtr)
{
	CPosition posOfNewPiece;
	CPosition validRangePos = CPosition(pBoard->getRowSize()-1, pBoard->getColSize()-1);
	//Boolean flag to check if the users new entry was set successfully
	bool bFieldSetSuccess = FALSE; //Initialized to false
	bool bFieldEmpty = TRUE; //Initialized to false
	do
	{
		//Asks user to enter new position. Validity check done based on range.
		std::cout << std::endl << "ENTER NEW PIECE POSITION ";
		posOfNewPiece = CPosition(validRangePos);
//
//		CPosition posArray[9] = { CPosition(2,0),
//								  CPosition(1,0),
//								  CPosition(1,1),
//								  CPosition(2,1),
//								  CPosition(2,2)};
//		static unsigned short posArrCtr = 0;
//		posOfNewPiece = posArray[posArrCtr++];

		bFieldEmpty = !pBoard->m_board[posOfNewPiece.row][posOfNewPiece.col].getState();

		if(!bFieldEmpty) //Check if  Field is occupied
		{
			bFieldEmpty = FALSE;
			//If it is occupied, set bFieldFree = ask user to enter a different position for inserting his Piece
			std::cout << std::endl << "FIELD IS OCCUPIED! PLEASE ENTER A FREE FIELD. " << std::endl;
		}
		else
		{
			bFieldSetSuccess = TRUE;
		}
	}
	while(!bFieldSetSuccess);
	return posOfNewPiece;
}
