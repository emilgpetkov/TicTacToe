import QtQuick 2.0
import QtQuick.Layouts 1.3

Grid {
    id: symbolCells
    scale: 0.5;

    height: rows * cell0.height + 2 * spacing
    width: columns * cell0.width + 2 * spacing
    anchors.verticalCenter: parent.verticalCenter
    anchors.horizontalCenter: parent.horizontalCenter
    rows: 4
    columns: 4

    Cell {
        id: cell0
        symbol: '☀'
        //scale: scaling
    }

    Cell {
        id: cell1
        symbol: '☂'
        //scale: scaling
    }

    Cell {
        id: cell2
        symbol: '★'
        //scale: scaling
    }

    Cell {
        id: cell3
        symbol: '☆'
        //scale: scaling
    }

    Cell {
        id: cell4
        symbol: '☌'
        //scale: scaling
    }

    Cell {
        id: cell5
        symbol: '☍'
        //scale: scaling
    }

    Cell {
        id: cell6
        symbol: '♀'
        //scale: scaling
    }

    Cell {
        id: cell7
        symbol: '♂'
        //scale: scaling
    }

    Cell {
        id: cell8
        symbol: '♔'
        //scale: scaling
    }

    Cell {
        id: cell9
        symbol: '♕'
        //scale: scaling
    }

    Cell {
        id: cell10
        symbol: '♚'
        //scale: scaling
    }

    Cell {
        id: cell11
        symbol: '♛'
        //scale: scaling
    }

    Cell {
        id: cell12
        symbol: '⚐'
        //scale: scaling
    }

    Cell {
        id: cell13
        symbol: '⚑'
        //scale: scaling
    }

    Cell {
        id: cell14
        symbol: '⚛'
        //scale: scaling
    }

    Cell {
        id: cell15
        symbol: '⚜'
        //scale: scaling
    }

    Component.onCompleted: {
        console.log("height: " + height)
        console.log("width: " + width)
    }
}
