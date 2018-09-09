#include "tictactoegui.h"

#include <iostream>

#include <playerror.h>

bool TicTacToeGUI::addPlayer(QString sName)
{
	return TicTacToe::getInstance()->addPayer(sName.toStdString());
}

void TicTacToeGUI::createPlayArea(int nNumbOfCells)
{
	TicTacToe::getInstance()->createPlayArea(nNumbOfCells);
}

void TicTacToeGUI::resetPlayArea() const
{
	TicTacToe::getInstance()->resetPlayArea();
}

void TicTacToeGUI::setCurrentPlayer(QString sName)
{
	TicTacToe::getInstance()->setCurrentPlayer(sName.toStdString());
}

QString TicTacToeGUI::currentPlayer() const
{
	return QString(TicTacToe::getInstance()->currentPlayer().c_str());
}

bool TicTacToeGUI::pickCell(int nCell)
{
	try
	{
		TicTacToe::getInstance()->pickCell(nCell);
		return true;
	}
	catch (const PlayError& e)
	{
		std::cout << "Error! " << e.text() << std::endl;
		return false;
	}
}

void TicTacToeGUI::playerResetPickedCells(QString sName)
{
	TicTacToe::getInstance()->playerResetPickedCells(sName.toStdString());
}

void TicTacToeGUI::setPlayerSymbol(QString sName, QString symbol)
{
	TicTacToe::getInstance()->setPlayerSymbol(sName.toStdString(), symbol.toStdString().at(0));
}

char TicTacToeGUI::getPlayerSymbol(QString sName) const
{
	return TicTacToe::getInstance()->getPlayerSymbol(sName.toStdString());
}

int TicTacToeGUI::getPlayerScore(QString sName) const
{
	return TicTacToe::getInstance()->getPlayerScore(sName.toStdString());
}

bool TicTacToeGUI::hasPlayerWon(QString sName) const
{
	return TicTacToe::getInstance()->hasPlayerWon(sName.toStdString());
}

void TicTacToeGUI::playerIncreaseScore(QString sName)
{
	TicTacToe::getInstance()->playerIncreaseScore(sName.toStdString());
}

bool TicTacToeGUI::allCellsPicked() const
{
	return TicTacToe::getInstance()->allCellsPicked();
}

bool TicTacToeGUI::hasGameStarted() const
{
	return TicTacToe::getInstance()->hasGameStarted();
}

TicTacToeGUI::TicTacToeGUI(QObject *parent)
	: QObject(parent)
{

}
