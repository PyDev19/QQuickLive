#include "watcher.hpp"

Watcher::Watcher(QQmlApplicationEngine &engine, QObject *parent): QObject(parent), engine(engine) {
    QString watch_directory = QDir::currentPath();
    directory = new QDir(watch_directory);

    watcher = new QFileSystemWatcher(this);
    watcher_add_files(watch_directory);

    qDebug() << watcher->files();
    qDebug() << watcher->directories();

    connect(watcher, SIGNAL(directoryChanged(QString)), this, SLOT(directory_changed(QString)));
    connect(watcher, SIGNAL(fileChanged(QString)), this, SLOT(file_changed(QString))); 
}

void Watcher::watcher_add_files(QString path) {
    watcher->addPath(path);

    QDir dir(path);
    QStringList subdirs = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    foreach (const QString &subdir, subdirs) {
        QString subpath = path + QDir::separator() + subdir;
        watcher_add_files(subpath);
    }

    QStringList files = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);
    foreach (const QString &file, files) {
        QString filepath = path + QDir::separator() + file;
        watcher->addPath(filepath);
    }
}

void Watcher::directory_changed(const QString &path) {
    emit watchedDirectoryChanged(path);
    watcher_add_files(path);
}

void Watcher::file_changed(const QString &path) {
    emit watchedDirectoryChanged(path);
}

void Watcher::clear_cache() {
    engine.clearComponentCache();
}

QString Watcher::get_path() {
    return directory->absolutePath();
}
