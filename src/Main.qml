import QtQuick
import QtQml
import QtQuick.Controls

ApplicationWindow {
    id: window
    visible: true
    
    flags:  Qt.Window | Qt.WindowSystemMenuHint | Qt.WindowTitleHint | Qt.WindowMinimizeButtonHint | Qt.WindowMaximizeButtonHint 
            |  Qt.WindowCloseButtonHint | Qt.WindowStaysOnTopHint

    width: main_loader.width
    height: main_loader.height

    Loader {
        id: main_loader
        source: "file:///" + watcher.get_path() + "/Main.qml"
    }

    Connections {
        target: watcher
        function onWatchedDirectoryChanged(path) {
            main_loader.active = false;
            watcher.clear_cache();
            main_loader.setSource("file:///" + watcher.get_path() + "/Main.qml");
            main_loader.active = true;
        }
    }
}
