cmake_minimum_required(VERSION 3.16)

project(_0003_parent_child_relate LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(_0003_parent_child_relate
  main.cpp
  libs/test_pt.h source/test_pt.cpp
)
target_link_libraries(_0003_parent_child_relate Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS _0003_parent_child_relate
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
