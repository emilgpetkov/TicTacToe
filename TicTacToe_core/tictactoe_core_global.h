#ifndef TICTACTOE_CORE_GLOBAL_H
#define TICTACTOE_CORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TICTACTOE_CORE_LIBRARY)
#  define TICTACTOE_CORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define TICTACTOE_CORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // TICTACTOE_CORE_GLOBAL_H
