import QtQuick 2.4
import QtQuick.Layouts 1.3

Rectangle {
    id: playersColumn
    width: parent.width
    height: {
        return rowPlayer1.height * 1.10 + rowPlayer2.height;
    }

    anchors.left: parent.left
    anchors.right: parent.right
    Layout.fillWidth: true

    PlayerRow {
        id: rowPlayer1
        Layout.alignment: Qt.AlignTop
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top

//        playerCell.symbol: qsTr("X")
//        playerName: qsTr("Player 1")
//        playerScore: qsTr("0")
    }

    PlayerRow {
        id: rowPlayer2
        Layout.alignment: Qt.AlignBottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: rowPlayer1.bottom
        anchors.bottomMargin: 0.1 * height

//        playerCell.symbol: qsTr("O")
//        playerName: qsTr("Player 2")
//        playerScore: qsTr("0")
    }

    Component.onCompleted: {
        //console.log("playersColumn")
    }

    property alias player1: rowPlayer1.player
    property alias symbolPlayer1: rowPlayer1.playerSymbol
    property alias namePlayer1: rowPlayer1.playerName
    property alias scorePlayer1: rowPlayer1.playerScore
    property alias colorPlayer1: rowPlayer1.color

    property alias player2: rowPlayer2.player
    property alias symbolPlayer2: rowPlayer2.playerSymbol
    property alias namePlayer2: rowPlayer2.playerName
    property alias scorePlayer2: rowPlayer2.playerScore
    property alias colorPlayer2: rowPlayer2.color

}
