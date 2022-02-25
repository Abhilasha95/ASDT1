/*
 * CPosition.h
 *
 *  Created on: 16-Nov-2019
 *      Author: Anoop
 */

#ifndef CPOSITION_H_
#define CPOSITION_H_


#include <iostream>
#include <list>

#include "Constants.h"



class CPosition
{
private:
    static int m_rowCnt;
    static int m_colCnt;
public:
    int row;
    int col;



    enum COLOR {BLACK=1, WHITE, NO_COLOR };


    enum PrintOptions{ PRINT_LINE, PRINT_STD};

    /**
      * Creates a new Pos with and initializes its members to default value.
      * @return none
      */
	CPosition();
	   /**
	     * Frees the memory allocated by this vector.
	     * @return none
	     */
	~CPosition();

    /**
     * Creates a new Pos with the given row and column with integer values.
     *
     * @param row denotes the row the Pos with type integer
     * @param col denotes the column the Pos with type integer
     * @return none
     */
    CPosition(int row, int col);

    /**
     * Creates a new Pos by taking inputs from the user.
     * The constraints to the input is checked and is passed as
     * parameter the constructor
     *
     * @param validRangePos denotes limits of the Pos row and column
     * @return none
     */
    CPosition(const CPosition& validRangePos);

    /**
     * overloaded assignment operator.
     *
     * @param orig is the RHS of the assignment operation
     * @return none
     */
    CPosition& operator=(const CPosition &orig);

    /**
     * overloaded + operator.
     *
     * @param addent is the RHS of the assignment operation
     * @return the summed Pos value
     */
    CPosition operator+(const CPosition &addent);

    /**
     * overloaded equality comparison.
     *
     * @param orig is the RHS of the check equality operation
     * to which the object values are compared to
     * @return the boolean equality check result of the two indices
     */
    bool operator==(const CPosition &orig);

    /**
     * Checks if the current Pos is within the valid Pos range.
     *
     * @param validRangePos is the limit range of the Pos
     * @return the boolean value representing weather the Pos in valid range
     */
    bool isPosInRange(const CPosition& validRangePos);

    /**
     * Function to print the Pos in a custom format.
     * User gives option in the form of an unsigned integer Enum.
     * The Pos can be printed in the form (row, column)
     * @param option Option entered by the user
     * @return none
     */
    void print(unsigned int option);

    /**
     * Function to get the row.
     * @param none
     * @return integer value containing the row
     */
    int getRow();


    /**
     * Function to get the Column.
     * @param none
     * @return integer value containing the column
     */
    int getCol();

    /**
     * Checks the validity of the position by comparing with the valid range
     * @param none
     * @return boolean validity status of the position
     */
    bool isPosValid();
};
#endif /* CPOSITION_H_ */
