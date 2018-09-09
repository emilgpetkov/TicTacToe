import QtQuick 2.0

Rectangle {
    id: cell

    width: 100
    height: 100

    border.color: "#555555"
    border.width: 0.35 * radius

    radius: {
        return 0.10 * width;
    }

    property alias id: cell
    property alias symbol: label.text
    property alias enabled: mouseArea.enabled
    property int idx: 0

    Text {
        id: label
        text: ""
        anchors.fill: parent
        horizontalAlignment: Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter
        font.pixelSize: {
            return 0.75 * height;
        }
    }

    signal cellClicked(int idx)

    MouseArea {
        id: mouseArea
        enabled: true
        anchors.fill: parent
        onClicked: //cell.cellClicked(idx)
        {
            //cell.symbol = String.fromCharCode(TictactoeGUI.getPlayerSymbol(TictactoeGUI.currentPlayer()))
            cell.cellClicked(idx)
            //parent.color = "#0000ff"
            //tictactoeEngine.getInstance();
        }
    }
}
