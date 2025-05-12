cmake_minimum_required(VERSION 3.16)

project(_0004_manage_dynamic_memory LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(_0004_manage_dynamic_memory
  main.cpp
  libs/test_pointer.h source/test_pointer.cpp
)
target_link_libraries(_0004_manage_dynamic_memory Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS _0004_manage_dynamic_memory
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
