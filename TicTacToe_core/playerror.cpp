#include "playerror.h"

PlayError::PlayError(const std::string &sText)
	: m_sText(sText)
{

}

PlayError::~PlayError()
{

}

CellOwnerConflict::CellOwnerConflict()
	: PlayError("Cell already has an Owner assigned")
{

}

CellOwnerConflict::~CellOwnerConflict()
{

}

AllCellWerePicked::AllCellWerePicked()
	: PlayError("All cells were already picked")
{

}

AllCellWerePicked::~AllCellWerePicked()
{

}
