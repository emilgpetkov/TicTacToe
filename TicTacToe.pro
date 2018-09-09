TEMPLATE = subdirs

SUBDIRS += \
    TicTacToeGUI \
    TicTacToe_core

TicTacToeGUI.depends = TicTacToe_core
