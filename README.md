# QQuickLive
QQuickLive is a live reloader tool designed for QML development. It allows you to dynamically reload QML files and update your application in real-time during development, providing a faster and more efficient development workflow.
## Precautions
When running this app, please keep in mind the following:
- This app scans the files and folders of the directories it is run from, it also scans the subdirectories for files and keeps going until there are no more subdirectories found in the folder you ran it from. So when running the executable from the terminal make sure you are in the folder that contains all your QML files and the folders that those QML files import.
- This app can't understand root contexts defined from C++ that are meant to be used in QML, so if you are trying to make use of that it won't work but the ui will still be displayed
- This app can work with `Window` and `ApplicationWindow` types but if you are using those there will be a seperate app popup along with a white rectangle in the middle of your screen. If you do not want this simply replace the `Window` or `ApplicationWindow` with an `Item` type instead, this will render your QML ui in the main app window rather than open a popup.
- This app also needs a `Main.qml` file as an entry point for your UI to be displayed so when running the executable from the terminal make sure you run it from the directory that contains your `Main.qml`
## Installation
Currently this application only works on Windows, you can find it [here](https://github.com/PyDev19/QQuickLive/releases/download/v1.0.0/QQuickLive.exe). You should place the binary in a folder that is included in your path, preferably in the qt installation folder or home directory.
