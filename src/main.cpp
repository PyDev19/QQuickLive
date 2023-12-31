#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include "watcher.hpp"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Watcher watcher(engine);
    engine.rootContext()->setContextProperty("watcher", &watcher);

    engine.load("qrc:/qml/Main.qml");

    QList<QObject*> root_objects = engine.rootObjects();
    if (root_objects.empty()) { return -1; }

    return app.exec();
}

