#include "player.h"

#include <iostream>

Player::Player(const std::string &sName)
	: m_sName(sName)
	, m_chSymbol('X')
	, m_nScore(0)
	, m_nPickedCells(0)
	//, m_nCountPickedCells(0)
	//, m_nColor(0xffffff)
{

}

Player::~Player()
{
	//std::cout << "~Player: " << m_sName << std::endl;
}
