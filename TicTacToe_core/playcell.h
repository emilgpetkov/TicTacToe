#ifndef PLAYCELL_H
#define PLAYCELL_H

#include <memory>

class Player;
typedef std::shared_ptr<Player> PlayerPtr;

class PlayCell
{
public:
	PlayCell();
	~PlayCell() = default;

	inline void setOwner(PlayerPtr pPlayer) { m_pOwner = pPlayer; }
	inline PlayerPtr owner() { return m_pOwner; }
	inline const PlayerPtr owner() const { return m_pOwner; }
	inline void resetOwner() { m_pOwner.reset(); }

private:
	std::shared_ptr<Player> m_pOwner;
};

typedef std::shared_ptr<PlayCell> PlayCellPtr;

#endif // PLAYCELL_H
