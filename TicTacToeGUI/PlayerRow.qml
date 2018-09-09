import QtQuick 2.4
import QtQuick.Layouts 1.3

Rectangle {
    id: playerRow
    height: {
        return playerCell.height * 1.20 * playerCell.scale;
    }

    anchors.left: parent.left
    anchors.right: parent.right

    property alias player: playerName;
    property alias playerCell: playerCell;
    property alias playerSymbol: playerCell.symbol;
    property alias playerName: playerName.text;
    property alias playerScore: playerScore.text;
    property alias color: playerCell.color

    Cell {
        id: playerCell
        enabled: false
        scale: 0.50
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: {
            return -scale * width / 2.0
        }
    }

     TextInput {
        id: playerName
        text: qsTr("Player")
        horizontalAlignment: Text.AlignLeft
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: playerCell.right
        font.pixelSize: 18
        //enabled: false

        signal playerNameClicked(TextInput idPlayer)
        signal playerNameChanged(string sPlayerName)

        Keys.onPressed: {
            if (event.key === Qt.Key_Enter || event.key === Qt.Key_Return)
            {
                //console.log("Keys.onPressed: " + event.key)
                //parent.enabled = false
                playerNameChanged(playerName.text)
            }
        }

        onFocusChanged: {
            //playerName.deselect()
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
               // playerName.selectAll()
                //playerName.forceActiveFocus()
                //parent.enabled = true
                playerName.playerNameClicked(playerName)
            }
        }
    }

    Text {
        id: playerScore
        text: qsTr("0")
        horizontalAlignment: Text.AlignRight
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        font.pixelSize: 18
    }
}
