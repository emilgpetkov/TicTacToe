import QtQuick 2.0

Rectangle {
    id: msgBox
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter

    height: {
        return 1. / 3. * parent.height
    }

    width: parent.width * 0.90

    radius: 0.05 * height

    property alias id: msgBox
    property alias label: label.text

    border.color: "#bbbbbb"
    border.width: {
        return 0.15 * radius
    }

    color: "#dddddd"

    signal msgBoxOkClicked()

    Text {
        id: label
        text: "Hello World"
        font.pixelSize: {
            return 0.10 * parent.height
        }

        horizontalAlignment: Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter

        width: parent.width
        wrapMode: Text.Wrap

        anchors.top: parent.top
        anchors.topMargin: 0.25 * parent.height
    }

    Rectangle {
        id: btnOK

        height: btnLabel.font.pixelSize * 2.0
        width: {
            return 0.2 * parent.width
        }

        property var btnColorDefault: String("#aaaaaa")
        property var btnColorHovered: String("#cccccc")

        radius: 0.1 * height
        color: btnColorDefault
        border.color: "#999999"
        border.width: 0.35 * radius

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: label.bottom
        anchors.topMargin: {
            return 0.15 * parent.height
        }

        property alias btnLabel: btnLabel

        Text {
            id: btnLabel
            text: qsTr("OK")
            font.pixelSize: label.font.pixelSize
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                parent.parent.visible = false
                msgBoxOkClicked()
            }

            onEntered: {
                btnOK.color = btnOK.btnColorHovered
            }

            onExited: {
                btnOK.color = btnOK.btnColorDefault
            }
        }
    }

//    MouseArea {
//        anchors.fill: parent
//    }
}
