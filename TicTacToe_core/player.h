#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
public:
	Player(const std::string& sName = "");
	~Player();

	inline void setName(const std::string& sName) { m_sName = sName; }
	inline std::string name() const { return m_sName; }
	inline void setSymbol(char chSymbol) { m_chSymbol = chSymbol; }
	inline char symbol() const { return m_chSymbol; }
	inline void increaseScore() { ++m_nScore; }
	inline int score() { return m_nScore; }
	inline void pickCell(int nCell) { m_nPickedCells += 1 << nCell; }
	inline int pickedCells() const { return m_nPickedCells; }
	inline void resetPickedCells() { m_nPickedCells = 0; }
	//inline void setColor(int nColor) { m_nColor = nColor; }
	//inline int color() const { return color; }

private:
	std::string m_sName;
	char m_chSymbol;
	int m_nScore;
	int m_nPickedCells;
	//int m_nColor;
};

#endif // PLAYER_H
