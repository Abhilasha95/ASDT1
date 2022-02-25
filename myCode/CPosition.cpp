/*
 * CPosition.cpp
 *
 *  Created on: 16-Nov-2019
 *      Author: Anoop
 */

#include "CPosition.h"

//Defining the static variables
int CPosition::m_colCnt = 0;
int CPosition::m_rowCnt = 0;


void debug(std::string locName)
{
	std::cout << std::endl << "Inside: " << locName << std::endl << std::flush;;
}

CPosition::CPosition()
{
	// TODO Auto-generated constructor stub
	row = 0;
	col = 0;
}

CPosition::CPosition(int r, int c)
{
	row = r;
	col = c;
}

CPosition::CPosition(const CPosition& validRangePos)
{
	CPosition validRngPos = CPosition(validRangePos.row, validRangePos.col);

	bool bValidEntry = FALSE;
	do
	{
		std::cout << std::endl;
		std::cout << "row : ";
		std::cin >> row;
		std::cout << "col : ";
		std::cin >> col;

		//Checking entry for validity
		bool bRowInRange = ((0 <= row) && (row <= validRangePos.row));
		bool bColInRange = ((0 <= col) && (col <= validRangePos.col));
		bValidEntry = (bRowInRange && bColInRange);

		if(!bValidEntry)
		{
			std::cout << std::endl << "Invalid Entry. Enter in the Valid range :";
			validRngPos.print(PRINT_LINE);
		}
		if(bValidEntry)
			break;
	}
	while(!bValidEntry);
}

CPosition& CPosition::operator=(const CPosition &orig)
{
	row = orig.row;
	col = orig.col;
	return *this;
}

CPosition::~CPosition()
{
	//Dummy destructor
}

void CPosition::print(unsigned int option)
{
	if(option == PRINT_LINE)
		std::cout <<  "(" << row << ", " << col << ") ";
	else if(option == PRINT_STD)
	{
		std::cout << std::endl;
		std::cout << "row : " << row;
		std::cout << std::endl;
		std::cout << "col : " << col;
	}
}

bool CPosition::isPosInRange(const CPosition& validRangePos)
{
	CPosition validRngPos = CPosition(validRangePos.row, validRangePos.col);

	bool bPosInRange = FALSE;

	//Checking entry for validity
	bool bRowInRange = ((0 <= row) && (row <= validRangePos.row));
	bool bColInRange = ((0 <= col) && (col <= validRangePos.col));
	bPosInRange = (bRowInRange && bColInRange);

	return bPosInRange;
}

CPosition CPosition::operator +(const CPosition &addent)
{
	CPosition sum = CPosition(row + addent.row, col + addent.col);
	return sum;
}

bool CPosition::operator ==(const CPosition &orig)
{
	if((row == orig.row) && (col == orig.col))
		return TRUE;
	else
		return FALSE;
}

int CPosition::getRow()
{
	return row;
}

int CPosition::getCol()
{
	return col;
}

bool CPosition::isPosValid()
{
	return isPosInRange(CPosition(m_rowCnt, m_colCnt));
}
