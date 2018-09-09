#ifndef PLAYERROR_H
#define PLAYERROR_H


#include <string>

class PlayError
{
public:
	PlayError(const std::string& sText);
	virtual ~PlayError();

	inline const std::string& text() const { return m_sText; }

private:
	std::string m_sText;
};

class CellOwnerConflict : public PlayError
{
public:
	CellOwnerConflict();
	virtual ~CellOwnerConflict();
};

class AllCellWerePicked : public PlayError
{
public:
	AllCellWerePicked();
	virtual ~AllCellWerePicked();
};

#endif // PLAYERROR_H
