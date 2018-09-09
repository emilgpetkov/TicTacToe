import QtQuick 2.10
import QtQuick.Window 2.10

Window {
    visible: true
    width: mainPanelForm.width
    height: mainPanelForm.height
    title: qsTr("Tic Tac Toe")

    MainPanel {
        id: mainPanelForm
    }
}
