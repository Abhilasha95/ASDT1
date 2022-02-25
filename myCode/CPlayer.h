/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CPLAYER.H
* Author          :
* Description     :
*
*
****************************************************************************/
#ifndef CPLAYER_H
#define CPLAYER_H

/**
 * Represents a Class of Player. Each player has a color of his piece and
 * switches action during alternate steps of the game
 * */

#include <string>
#include <iostream>

#include "CTicTacToeBoard.h"

class CPlayer
{
protected:
    /**
     * Stores the point of the player
     */
    unsigned int  m_points;
public:
    /**
     * stores the name of the Player
     */
    std::string m_name;

    /**
     *Stores the type/Color of piece used by the player.
     */
    unsigned int m_piece;

    /**
     * Creates a new Player with the default values
     * @return none
     */
    CPlayer();

    /**
     * Creates a new Player with given name and color of Piece
     *
     * @param name the name of the player, which is a string
     * @param piece the type of the player's Piece
     * @return none
     */
    CPlayer(std::string name, unsigned int piece);

    /**
     * Frees the memory allocated by this vector.
     */
    virtual ~CPlayer();


    /**
      * Function to increment the Points of the player.
      */
    void incrementPoints();

    /**
     * Prints the details and name of the Player.
     *
     * @param printOption  the option entered by the user
     * Option to print the Player details or the player name based on the option Enum
     */
    void printPlayer(unsigned int printOption);

    /**
     * Returns the Points of the Player, an unsigned integer
     *@return the integer containing points of the Player
     */
    unsigned int getPoints();

    /**
     * Method to get the Position of the new piece
     * The method varies for different Child classes of Person
     * @param board the generic Board in which the players are playing
     * @return the Position calculates for entering new
     * piece on the board
     */
    virtual CPosition getNewPiecePos(CBoard *pBoard, const CPosition& opponentMovePos, unsigned short moveCtr);

    /**
	 *Virtual function of the player to place a piece on a board
	 * The child classes must provide the definition according to their behaviors
	 *@param board the Board in which the game is being played
	 *@return position at which the piece was successfully placed
	 */
	virtual CPosition placePiece(CBoard *pBoard, const CPosition& opponentMovePos, unsigned short moveCtr);

    /**
     * Initialises a  Player with given name and type of Piece
     * @param name the name of the player, which is a string
     * @param piece the type of the player's Piece
     * @return none
     */
     void initPlayer(std::string name, unsigned int piece);

    enum Players {PLAYER_1, PLAYER_2};

    enum PlayerPrintOptions {PRINT_NAME, PRINT_DETAILS};
};

#endif /* CPLAYER_H */
