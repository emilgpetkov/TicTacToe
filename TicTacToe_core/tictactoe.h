#ifndef TICTACTOE_CORE_H
#define TICTACTOE_CORE_H

#include "tictactoe_core_global.h"

#include <memory>
#include <map>
#include <string>

#include "handle.h"

class TicTacToe;
class PlayArea;
class Player;

typedef std::shared_ptr<TicTacToe> TicTacToePtr;
typedef std::shared_ptr<PlayArea> PlayAreaPtr;
typedef std::shared_ptr<Player> PlayerPtr;

class TICTACTOE_CORESHARED_EXPORT TicTacToe
{
public:
	~TicTacToe() = default;

	static TicTacToePtr getInstance();
	void createPlayArea(int nNumbOfCells);
	void resetPlayArea() const;
	bool addPayer(const std::string& sName);
	void setCurrentPlayer(const std::string& sName);
	std::string currentPlayer() const;
	void pickCell(int nCell);
	void playerResetPickedCells(const std::string& sName);
	void setPlayerSymbol(const std::string& sName, char symbol);
	char getPlayerSymbol(const std::string& sName) const;
	int getPlayerScore(const std::string& sName) const;
	bool hasPlayerWon(const std::string& sName) const;
	void playerIncreaseScore(const std::string& sName);
	Handle<Player> getPlayer(std::string sName);
	const Handle<Player> getPlayer(std::string sName) const;
	bool allCellsPicked() const;
	bool hasGameStarted() const;

private:
	TicTacToe();
	TicTacToe(const TicTacToe&) = default;
	TicTacToe(TicTacToe&&) = default;

	const TicTacToe& operator=(const TicTacToe&);

	static TicTacToePtr m_pInstance;
	//PlayAreaPtr m_pPlayArea;
	std::map<std::string, Handle<Player> > m_mapPlayers;
	std::string m_sCurrPlayer;

};

#endif // TICTACTOE_CORE_H
