import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import Toolbar 1.0
import Common 1.0
import Workarea 1.0
import StatusBar 1.0

ApplicationWindow {
    id: _rootWindow
    visible: true
    width: 860
    height: 640
    title: qsTr("Paint")

    header: Pane {
        Material.elevation: 5

        contentItem: ScalableToolBar {
            id: _toolBar
        }
    }

    footer: Pane {
        Material.elevation: 5

        contentItem: StatusBar {
            id: _statusBar
        }
    }

    Workarea {
        width: _rootWindow.width
        height: _rootWindow.height
                - (_rootWindow.header.height * _rootWindow.header.visible) // only when visible
                - _rootWindow.footer.height
    }
}
