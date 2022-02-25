/*
 * CPlayer.cpp
 *
 *  Created on: 02-Nov-2019
 *      Author: Anoop
 */

#include "CPlayer.h"

CPlayer::CPlayer(std::string name, unsigned int piece)
{
	initPlayer(name, piece);
}

CPlayer::CPlayer()
{
	m_name = "DEFAULT NAME";
	m_piece = CField::STONE_0;
	m_points = 0;
}

void CPlayer::incrementPoints()
{
	m_points ++;
}

unsigned int CPlayer::getPoints()
{
	return m_points;
}

void CPlayer::printPlayer(unsigned int printOption)
{
	if(printOption == PRINT_NAME)
	{
		std::cout << m_name;
	}
	else if(printOption == PRINT_DETAILS)
	{
		if(m_piece == CPosition::BLACK)
			std::cout << std::endl << m_name << "(B)";
		if(m_piece == CPosition::WHITE)
			std::cout << std::endl << m_name << "(W)";
	}
}

CPlayer::~CPlayer()
{
}


void CPlayer::initPlayer(std::string name, unsigned int piece)
{
	m_name = name;
	m_piece = piece;
	m_points = 0;
}

CPosition CPlayer::placePiece(CBoard *pBoard, const CPosition& opponentMovePos, unsigned short moveCtr)
{
	CPosition newPiecePos;
	return newPiecePos;
}

CPosition CPlayer::getNewPiecePos(CBoard *pBoard, const CPosition& opponentMovePos, unsigned short moveCtr)
{
	CPosition newPiecePos;
	return newPiecePos;
}
