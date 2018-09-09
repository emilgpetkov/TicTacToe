#ifndef TICTACTOEGUI_H
#define TICTACTOEGUI_H

#include <QObject>

#include <memory>

#include <tictactoe.h>

class TicTacToeGUI;
typedef std::shared_ptr<TicTacToeGUI> TicTacToeGUIPtr;

class TicTacToeGUI : public QObject
{
	Q_OBJECT
public:
	explicit TicTacToeGUI(QObject *parent = nullptr);

	Q_INVOKABLE bool addPlayer(QString sName);
	Q_INVOKABLE void createPlayArea(int nNumbOfCells);
	Q_INVOKABLE void resetPlayArea() const;
	Q_INVOKABLE void setCurrentPlayer(QString sName);
	Q_INVOKABLE QString currentPlayer() const;
	Q_INVOKABLE bool pickCell(int nCell);
	Q_INVOKABLE void playerResetPickedCells(QString sName);
	Q_INVOKABLE void setPlayerSymbol(QString sName, QString symbol);
	Q_INVOKABLE char getPlayerSymbol(QString sName) const;
	Q_INVOKABLE int getPlayerScore(QString sName) const;
	Q_INVOKABLE bool hasPlayerWon(QString sName) const;
	Q_INVOKABLE void playerIncreaseScore(QString sName);
	Q_INVOKABLE bool allCellsPicked() const;
	Q_INVOKABLE bool hasGameStarted() const;

signals:

public slots:

private:
	TicTacToeGUI(const TicTacToeGUI&) = default;
	TicTacToeGUI(TicTacToeGUI&&) = default;

	const TicTacToeGUI& operator=(const TicTacToeGUI&);
};

#endif // TICTACTOEGUI_H
