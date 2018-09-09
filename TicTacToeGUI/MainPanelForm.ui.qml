import QtQuick 2.4
import QtQuick.Layouts 1.3

Rectangle {
    id: mainPanel

    property alias playersColumn: playersColumn
    property alias cellsArea: cellsArea

    ColumnLayout {
        id: columnLayout
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        PlayersColumn {
            id: playersColumn
            anchors.top: parent.top
        }

        CellsArea {
            id: cellsArea
            anchors.top: playersColumn.bottom
        }
    }
}
