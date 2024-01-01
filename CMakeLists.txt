cmake_minimum_required(VERSION 3.16)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(QQuickLive VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)
qt_standard_project_setup()

qt_add_executable(QQuickLive
    src/main.cpp
    src/watcher.cpp
    include/watcher.hpp
)

set_source_files_properties(src/Main.qml PROPERTIES QT_RESOURCE_ALIAS Main.qml)

qt_add_qml_module(QQuickLive
    URI qml
    RESOURCE_PREFIX /
    QML_FILES
        src/Main.qml
)

target_link_libraries(QQuickLive PRIVATE Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick)
target_include_directories(QQuickLive PRIVATE include)
