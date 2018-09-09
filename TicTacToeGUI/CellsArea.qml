import QtQuick 2.4
import QtQuick.Layouts 1.3
import org.egp.TicTacToeGUI.app 1.0

Grid {
    id: cellsArea
    height: {
        return columns * cell0.height + 2 * spacing
    }
    width: height
    Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
    spacing: 8
    Layout.fillWidth: false
    rows: 3
    columns: 3

    property string currSymbol: {
        return String.fromCharCode(TictactoeGUI.getPlayerSymbol(TictactoeGUI.currentPlayer()))
    }

    signal cellPicked(int idx)

    function handleCellClicked(idx)
    {
        //console.log("handleCellClicked: idx: " + idx)

        if (! TictactoeGUI.pickCell(idx))
        {
            return
        }

        var symbol = String.fromCharCode(TictactoeGUI.getPlayerSymbol(TictactoeGUI.currentPlayer()))

        if (idx === cell0.idx) cell0.symbol = symbol
        if (idx === cell1.idx) cell1.symbol = symbol
        if (idx === cell2.idx) cell2.symbol = symbol
        if (idx === cell3.idx) cell3.symbol = symbol
        if (idx === cell4.idx) cell4.symbol = symbol
        if (idx === cell5.idx) cell5.symbol = symbol
        if (idx === cell6.idx) cell6.symbol = symbol
        if (idx === cell7.idx) cell7.symbol = symbol
        if (idx === cell8.idx) cell8.symbol = symbol

        cellPicked(idx)
    }

    function resetCellsSymbol()
    {
        cell0.symbol = ""
        cell1.symbol = ""
        cell2.symbol = ""
        cell3.symbol = ""
        cell4.symbol = ""
        cell5.symbol = ""
        cell6.symbol = ""
        cell7.symbol = ""
        cell8.symbol = ""
    }

    Cell {
        id: cell0
        idx: 0
    }

    Cell {
        id: cell1
        idx: 1
    }

    Cell {
        id: cell2
        idx: 2
    }

    Cell {
        id: cell3
        idx: 3
    }

    Cell {
        id: cell4
        idx: 4
    }

    Cell {
        id: cell5
        idx: 5
    }

    Cell {
        id: cell6
        idx: 6
    }

    Cell {
        id: cell7
        idx: 7
    }

    Cell {
        id: cell8
        idx: 8
    }

    Component.onCompleted: {
        cell0.cellClicked.connect(handleCellClicked)
        cell1.cellClicked.connect(handleCellClicked)
        cell2.cellClicked.connect(handleCellClicked)
        cell3.cellClicked.connect(handleCellClicked)
        cell4.cellClicked.connect(handleCellClicked)
        cell5.cellClicked.connect(handleCellClicked)
        cell6.cellClicked.connect(handleCellClicked)
        cell7.cellClicked.connect(handleCellClicked)
        cell8.cellClicked.connect(handleCellClicked)

        TictactoeGUI.createPlayArea(9)
    }
}
