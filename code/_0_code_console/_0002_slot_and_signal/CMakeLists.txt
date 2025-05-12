cmake_minimum_required(VERSION 3.16)

project(slot_and_signal LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(slot_and_signal
  main.cpp
  libs/test.h source/test.cpp
  main.h
)
target_link_libraries(slot_and_signal Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS slot_and_signal
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
