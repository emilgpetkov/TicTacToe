import QtQuick 2.4
import org.egp.TicTacToeGUI.app 1.0

MainPanelForm {
    id: mainPanel

    property alias id: mainPanel

    playersColumn.width: {
        return cellsArea.width
    }

    width: {
        return cellsArea.width * 1.10
    }

    height: {
        return (playersColumn.height + cellsArea.height) * 1.10
    }

    Rectangle {
        id: darkenFilter
        anchors.fill: parent
        color: "#000000"
        opacity: 0.75
        visible: false
    }

    MessageBox {
        id: msgBox
        visible: false
    }

    MessageBox {
        id: msgBoxDontChange
        visible: false
    }

    function handleCellPicked(idx)
    {
        playersColumn.player1.deselect()
        playersColumn.player2.deselect()
        cellsArea.forceActiveFocus()

        if (TictactoeGUI.hasPlayerWon(TictactoeGUI.currentPlayer()))
        {
            TictactoeGUI.playerIncreaseScore(TictactoeGUI.currentPlayer())
            playersColumn.scorePlayer1 = TictactoeGUI.getPlayerScore(playersColumn.namePlayer1)
            playersColumn.scorePlayer2 = TictactoeGUI.getPlayerScore(playersColumn.namePlayer2)
            TictactoeGUI.playerResetPickedCells(playersColumn.namePlayer1)
            TictactoeGUI.playerResetPickedCells(playersColumn.namePlayer2)
            TictactoeGUI.resetPlayArea()

            cellsArea.enabled = false
            msgBox.visible = true
            darkenFilter.visible = true

            msgBox.label =
                    qsTr("Congratulations, ") + TictactoeGUI.currentPlayer() +
                    qsTr(", you have won the round!")

            cellsArea.resetCellsSymbol()

            return
        }

        if (TictactoeGUI.allCellsPicked())
        {
            TictactoeGUI.playerResetPickedCells(playersColumn.namePlayer1)
            TictactoeGUI.playerResetPickedCells(playersColumn.namePlayer2)
            TictactoeGUI.resetPlayArea()

            cellsArea.enabled = false
            msgBox.visible = true
            darkenFilter.visible = true

            msgBox.label =
                    qsTr("There are no more possible turns left.\nThe round will start over.")

            cellsArea.resetCellsSymbol()

            return
        }

        if (TictactoeGUI.currentPlayer() === playersColumn.namePlayer1)
        {
            TictactoeGUI.setCurrentPlayer(playersColumn.namePlayer2)
        }
        else
        {
            TictactoeGUI.setCurrentPlayer(playersColumn.namePlayer1)
        }
    }

    function handleChangePlayerName(idPlayer)
    {
        if (TictactoeGUI.hasGameStarted())
        {
            cellsArea.enabled = false
            msgBoxDontChange.visible = true
            darkenFilter.visible = true

            msgBoxDontChange.label =
                    qsTr("You may not change a player's name while playing.\nPlease finish the game first.")

            return
        }

        idPlayer.selectAll()
        idPlayer.forceActiveFocus()
    }

    function handlePlayerNameChanged(sPlayerName)
    {
        if (playersColumn.namePlayer1 === playersColumn.namePlayer2)
        {
            cellsArea.enabled = false
            msgBoxDontChange.visible = true
            darkenFilter.visible = true

            msgBoxDontChange.label =
                    qsTr("It is not allowed both players to have the same name. Please change of the names.")

            return
        }

        mainPanel.forceActiveFocus()
        //TictactoeGUI.addPlayer(sPlayerName)
        TictactoeGUI.playerResetPickedCells(sPlayerName)
        TictactoeGUI.resetPlayArea()

        readPlayersData()
    }

    function handleMsgBoxOkClicked()
    {
        //cellsArea.resetCellsSymbol()
        cellsArea.enabled = true
        darkenFilter.visible = false
    }

    function readPlayersData()
    {
        var symbolPlayer1 = playersColumn.symbolPlayer1
        var namePlayer1 = playersColumn.namePlayer1
        var scorePlayer1 = playersColumn.scorePlayer1

        var symbolPlayer2 = playersColumn.symbolPlayer2
        var namePlayer2 = playersColumn.namePlayer2
        var scorePlayer2 = playersColumn.scorePlayer2

        TictactoeGUI.addPlayer(namePlayer1)
        playersColumn.scorePlayer1 = TictactoeGUI.getPlayerScore(symbolPlayer1)
        TictactoeGUI.addPlayer(namePlayer2)
        playersColumn.scorePlayer2 = TictactoeGUI.getPlayerScore(symbolPlayer2)

        TictactoeGUI.setPlayerSymbol(namePlayer1, symbolPlayer1)
        TictactoeGUI.setPlayerSymbol(namePlayer2, symbolPlayer2)

        TictactoeGUI.setCurrentPlayer(namePlayer1)
    }

    Component.onCompleted: {
        playersColumn.player1.playerNameClicked.connect(handleChangePlayerName)
        playersColumn.player1.playerNameChanged.connect(handlePlayerNameChanged)

        playersColumn.player2.playerNameClicked.connect(handleChangePlayerName)
        playersColumn.player2.playerNameChanged.connect(handlePlayerNameChanged)

        cellsArea.cellPicked.connect(handleCellPicked)
        msgBox.msgBoxOkClicked.connect(handleMsgBoxOkClicked)
        msgBoxDontChange.msgBoxOkClicked.connect(handleMsgBoxOkClicked)

        var symbolPlayer1 = 'X'
        var namePlayer1 = qsTr("Player 1")
        var scorePlayer1 = qsTr("0")

        var symbolPlayer2 = qsTr("O")
        var namePlayer2 = qsTr("Player 2")
        var scorePlayer2 = qsTr("0")

        playersColumn.symbolPlayer1 = symbolPlayer1
        playersColumn.namePlayer1 = namePlayer1
        playersColumn.scorePlayer1 = scorePlayer1

        playersColumn.symbolPlayer2 = symbolPlayer2
        playersColumn.namePlayer2 = namePlayer2
        playersColumn.scorePlayer2 = scorePlayer2

        readPlayersData()
        //playersColumn.colorPlayer1 = "#dddddd"

        //console.log(symbolPlayer1)
        //console.log(symbolPlayer2)
    }
}
