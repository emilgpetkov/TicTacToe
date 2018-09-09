#include "tictactoe.h"

#include "player.h"
#include "playarea.h"

TicTacToePtr TicTacToe::m_pInstance = nullptr;

TicTacToePtr TicTacToe::getInstance()
{
	if (! m_pInstance)
	{
		m_pInstance = TicTacToePtr(new TicTacToe);
	}

	return m_pInstance;
}

void TicTacToe::createPlayArea(int nNumbOfCells)
{
	PlayArea::getInstance()->createPlayArea(nNumbOfCells);
}

void TicTacToe::resetPlayArea() const
{
	PlayArea::getInstance()->resetPlayArea();
}

bool TicTacToe::addPayer(const std::string &sName)
{
	if (m_mapPlayers.find(sName) != m_mapPlayers.end())
	{
		return false;
	}

	return m_mapPlayers.insert(std::make_pair(sName, Handle<Player>(m_mapPlayers.size(), PlayerPtr(new Player(sName))))).second;
}

Handle<Player> TicTacToe::getPlayer(std::string sName)
{
	if (m_mapPlayers.find(sName) != m_mapPlayers.end())
	{
		return m_mapPlayers.at(sName);
	}

	return Handle<Player>();
}

const Handle<Player> TicTacToe::getPlayer(std::string sName) const
{
	if (m_mapPlayers.find(sName) != m_mapPlayers.end())
	{
		return m_mapPlayers.at(sName);
	}

	return Handle<Player>();
}

bool TicTacToe::allCellsPicked() const
{
	return PlayArea::getInstance()->allCellsPicked();
}

bool TicTacToe::hasGameStarted() const
{
	return PlayArea::getInstance()->hasGameStarted();
}

void TicTacToe::setCurrentPlayer(const std::string& sName)
{
	if (getPlayer(sName).isValid())
	{
		m_sCurrPlayer = sName;
		return;
	}

	m_sCurrPlayer = "";
}

std::string TicTacToe::currentPlayer() const
{
	return m_sCurrPlayer;
}

void TicTacToe::pickCell(int nCell)
{
	Handle<Player> hPlayer = getPlayer(m_sCurrPlayer);

	if (! hPlayer.isValid())
	{
		return;
	}

	PlayArea::getInstance()->pickCell(hPlayer.get(), nCell);
}

void TicTacToe::playerResetPickedCells(const std::string &sName)
{
	Handle<Player> hPlayer = getPlayer(sName);

	if (! hPlayer.isValid())
	{
		return;
	}

	hPlayer->resetPickedCells();
}

void TicTacToe::setPlayerSymbol(const std::string& sName, char symbol)
{
	Handle<Player> hPlayer = getPlayer(sName);

	if (! hPlayer.isValid())
	{
		return;
	}

	hPlayer->setSymbol(symbol);
}

char TicTacToe::getPlayerSymbol(const std::string &sName) const
{
	Handle<Player> hPlayer = getPlayer(sName);

	if (! hPlayer.isValid())
	{
		return '\0';
	}

	return hPlayer->symbol();
}

int TicTacToe::getPlayerScore(const std::string &sName) const
{
	Handle<Player> hPlayer = getPlayer(sName);

	if (! hPlayer.isValid())
	{
		return 0;
	}

	return hPlayer->score();
}

bool TicTacToe::hasPlayerWon(const std::string &sName) const
{
	Handle<Player> hPlayer = getPlayer(sName);

	if (! hPlayer.isValid())
	{
		return false;
	}

	return PlayArea::getInstance()->hasPlayerWon(hPlayer.get());
}

void TicTacToe::playerIncreaseScore(const std::string &sName)
{
	Handle<Player> hPlayer = getPlayer(sName);

	if (! hPlayer.isValid())
	{
		return;
	}

	hPlayer->increaseScore();
}

TicTacToe::TicTacToe()
	: m_sCurrPlayer("")
{
	//m_pInstance = nullptr;
	m_mapPlayers.clear();
}
