#ifndef CELLHANDLE_H
#define CELLHANDLE_H

#include <memory>

template <class T>
class Handle
{
	typedef std::shared_ptr<T> TPtr;

public:
	Handle(int nId = 0, TPtr ptr = nullptr)
		: m_nId(nId)
		, m_pPtr(ptr)
	{}
	~Handle() = default;

	bool isValid() const { return m_pPtr != nullptr; }

	inline void bindCell(TPtr ptr) { m_pPtr = ptr; }
	inline TPtr get() { return m_pPtr; }
	inline const TPtr get() const { return m_pPtr; }

	inline T* operator ->() { return m_pPtr.get(); }
	inline const T* operator ->() const { return m_pPtr.get(); }

private:
	int m_nId;
	TPtr m_pPtr;
};

#endif // CELLHANDLE_H
