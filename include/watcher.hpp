#ifndef WATCHER_HPP
#define WATCHER_HPP

#include <QObject>
#include <QFileSystemWatcher>
#include <QQmlApplicationEngine>
#include <QDir>
#include <qtmetamacros.h>

class Watcher: public QObject {
    Q_OBJECT
public:
    Watcher(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    Q_INVOKABLE void clear_cache();
    Q_INVOKABLE QString get_path();

signals:
    void watchedDirectoryChanged(const QString &path);

public slots:
    void directory_changed(const QString &path);
    void file_changed(const QString &path);

private:
    QFileSystemWatcher *watcher;
    QQmlApplicationEngine &engine;
    QDir *directory;
    
    void watcher_add_files(QString path);
};

#endif
