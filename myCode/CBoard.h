/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CBOARD.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CBOARD_H
#define CBOARD_H

/**
 * Represents a  board which constitutes of an array of Fields.
 * It will handle all the functionalities, related to a Board
 * */

#include "CField.h"

#define DEBUG_MODE 1

class CBoard
{
protected:
	int m_noOfRows;
	int m_noOfCols;

public:
	/**
	 * 2D Array of type Fields to store the field elements in the board.
	 */
	CField **m_board;

    /**
     * Initializes the Board to to its intial state
     * @return none
     */
	void initBoard();

   /**
	 * Creates a new Board and initializes the fields with the default values
	 *@return none
	 */
    CBoard();

    /**
     * Frees the memory allocated by this ReversiBoard.
     * @return none
     */
    ~CBoard();

    /**
     * @return the integer containing  row size of the reversi board
     */
    int getRowSize();

    /**
     * @return the integer containing  column size of the reversi board
     */
    int getColSize();

    /**
     * Sets the state of the Field in a particular position in the Reversiboard
     * to the desired state values provided as argument. The position and color willl be set
     *
     * @param position the desired field
     * @param color the color to be assigned to the Field with the passe dposition in Reversiboard
     * @return the boolean containing information if the Field state could be set successfully
     */
    bool setField(const CPosition& position, unsigned int piece);

    /**
     * Prompts the user to enter a new Piece for the next move
     * The user enters the desired position where he has to place his piece
     * The color of the Field will be assigned according to the piece color of the player
     * @return the boolean containing information if new piece could be inserted successfully
     */
    bool insertPiece(const CPosition& position, unsigned int piece);

    enum Traversal
    {
    	TR_VERT_UP,
    	TR_VERT_DOWN,
    	TR_HORIZ_LE,
    	TR_HORIZ_RI,
    	TR_DIAG_LT,
    	TR_DIAG_RB,
    	TR_DIAG_LB,
    	TR_DIAG_RT
    };
};
/********************
**  CLASS END
*********************/

#endif /* CBOARD_H */
