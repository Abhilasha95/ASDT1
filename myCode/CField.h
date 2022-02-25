/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CFIELD.H
* Author          :
* Description     :
*
*
****************************************************************************/


#ifndef CFIELD_H
#define CFIELD_H

/**
 * Represents a Field which constitutes a Reversi board or any Board Game.
 * It will handle all the functionalities,  validity checks, and calculations
 * with regards to Field.
 * */

#include "CPosition.h"

class CField
{
private:

public:
    bool m_state;
    CPosition m_position;
    unsigned int m_piece;

    /**
     * Creates a new Field with and initializes its members to default value.
     * @return none
     */
    CField();

    /**
     * Creates a new Field with and initializes its members to
	 * values passed into as arguments
     *
     * @param state the desired state of the field. TRUE or FALSE
     * which denotes that the field is occupied or not
     * @param Position the desired Position to be assigned to the Field
     * @param color the desired Color to be assigned to the Field
     * @return none
     */
    CField(bool state, const CPosition& Position, unsigned int color);

    /**
     * Frees the memory allocated by this vector.
     * @return none
     */
    ~CField();

    /**
      * Returns the current state of the Field
      * @return boolean value representing the state of the Field
      */
    bool getState();
    /**
      * Returns the boolean value which identifies if the Field is Empty or not
      * @return boolean value representing if filed is empty or not
      */
    bool isEmpty();
    /**
       * Sets the state of the field
       * @return none
       */
    void setState();

    enum stoneTypes {STONE_0, STONE_X, STONE_NIL};

};
/********************
**  CLASS END
*********************/
#endif /* CFIELD_H */
