cmake_minimum_required(VERSION 3.5)


project(Qt_Tutorials VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


add_executable(Qt_Tutorials
    main.cpp
)

target_link_libraries(Qt_Tutorials PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
