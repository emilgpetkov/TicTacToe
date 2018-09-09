#include "playarea.h"

#include "handle.h"
#include "playcell.h"
#include "player.h"

#include <algorithm>

#include <iostream>

PlayAreaPtr PlayArea::m_pInstance = nullptr;

PlayAreaPtr PlayArea::getInstance()
{
	if (! m_pInstance)
	{
		m_pInstance = PlayAreaPtr(new PlayArea);
	}

	return m_pInstance;
}

void PlayArea::createPlayArea(int nNumbOfCells)
{
	if (! m_vecCells.empty())
	{
		m_vecCells.clear();
	}

	for (int i = 0; i < nNumbOfCells; i++)
	{
		m_vecCells.push_back(Handle<PlayCell>(i, PlayCellPtr(new PlayCell)));
	}
}

void PlayArea::pickCell(PlayerPtr pPlayer, uint nCell) throw (PlayError)
{
	if (nCell >= m_vecCells.size())
	{
		return;
	}

	if (m_nPickedCells == m_cnAllCellsPicked)
	{
		throw AllCellWerePicked();
	}

	if (m_vecCells[nCell]->owner() != nullptr)
	{
		throw CellOwnerConflict();
	}

	m_nPickedCells += 1 << nCell;

	m_vecCells[nCell]->setOwner(pPlayer);
	pPlayer->pickCell(nCell);
}

void PlayArea::resetPlayArea()
{
	//void (*f)(Handle<PlayCell>) = [](Handle<PlayCell> hCell) { hCell->resetOwner(); };
	std::for_each(m_vecCells.begin(), m_vecCells.end(), [](Handle<PlayCell> hCell) { hCell->resetOwner(); });
	m_nPickedCells = 0;
}

bool PlayArea::hasPlayerWon(PlayerPtr pPlayer) const
{
	int pickedCells = pPlayer->pickedCells();

	if ((pickedCells & kRow0) == kRow0) return true;
	if ((pickedCells & kRow1) == kRow1) return true;
	if ((pickedCells & kRow2) == kRow2) return true;

	if ((pickedCells & kCol0) == kCol0) return true;
	if ((pickedCells & kCol1) == kCol1) return true;
	if ((pickedCells & kCol2) == kCol2) return true;

	if ((pickedCells & kDia0) == kDia0) return true;
	if ((pickedCells & kDia1) == kDia1) return true;

	return false;
}

bool PlayArea::allCellsPicked() const
{
	return m_nPickedCells == m_cnAllCellsPicked;
}

bool PlayArea::hasGameStarted() const
{
	return m_nPickedCells != 0;
}

PlayArea::PlayArea()
{
	m_vecCells.clear();
	m_nPickedCells = 0;
}
