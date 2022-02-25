/*
 * CField.cpp
 *
 *  Created on: 02-Nov-2019
 *      Author: Anoop
 */

#include "CField.h"

CField::CField()
{
	m_state = FALSE;
	m_position = CPosition(0, 0);
	m_piece = STONE_NIL;
}

CField::CField(bool state, const CPosition& position, unsigned int piece)
{
	m_state = state;
	m_position = position;
	m_piece = piece;
}

CField::~CField()
{
}

bool CField::getState()
{
	return m_state;
}

void CField::setState()
{
	m_state =TRUE;
}

bool CField::isEmpty()
{
	if(m_state == FALSE)
		return TRUE;
	else
		return FALSE;
}
