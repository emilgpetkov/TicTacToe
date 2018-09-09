#ifndef PLAYAREA_H
#define PLAYAREA_H

#include <memory>
#include <vector>
#include <bitset>

#include "handle.h"
#include "playerror.h"

class PlayArea;
class Player;
class PlayCell;

typedef unsigned int uint;
typedef std::shared_ptr<PlayArea> PlayAreaPtr;
typedef std::shared_ptr<Player> PlayerPtr;

class PlayArea
{
public:
	~PlayArea() = default;

	static PlayAreaPtr getInstance();
	void createPlayArea(int nNumbOfCells);
	void pickCell(PlayerPtr pPlayer, uint nCell) throw (PlayError);
	void resetPlayArea();
	bool hasPlayerWon(PlayerPtr pPlayer) const;
	bool allCellsPicked() const;
	bool hasGameStarted() const;

private:
	PlayArea();
	PlayArea(const PlayArea&) = default;
	PlayArea(PlayArea&&) = default;

	const PlayArea& operator=(const PlayArea&);

	/*
	 * Indices on PlayArea:
	 * 0 1 2
	 * 3 4 5
	 * 6 7 8
	 *
	 * Col0: 0, 3, 6 => 100100100
	 * Col1: 1, 4, 7 => 010010010
	 * Col2: 2, 5, 8 => 001001001
	 *
	 * Row0: 0, 1, 2 => 111000000
	 * Row1: 3, 4, 5 => 000111000
	 * Row2: 6, 7, 8 => 000000111
	 *
	 * Dia0: 0, 4, 8 => 100010001
	 * Dia1: 2, 4, 6 => 001010100
	 */

	enum WinCells
	{
		kCol0 = 1 + (1 << 3) + (1 << 6),
		kCol1 = kCol0 << 1,
		kCol2 = kCol1 << 1,

		kRow0 = 1 + (1 << 1) + (1 << 2),
		kRow1 = kRow0 << 3,
		kRow2 = kRow1 << 3,

		kDia0 = 1 + (1 << 4) + (1 << 8),
		kDia1 = (1 << 2) + (1 << 4) + (1 << 6)
	};

	static PlayAreaPtr m_pInstance;
	std::vector< Handle<PlayCell> > m_vecCells;

	int m_nPickedCells;

	const int m_cnAllCellsPicked = kRow0 + kRow1 + kRow2;

};
#endif // PLAYAREA_H
