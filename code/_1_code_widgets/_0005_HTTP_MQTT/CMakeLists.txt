cmake_minimum_required(VERSION 3.16)

project(_0005_HTTP_MQTT VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Mqtt Network)#<<<<<<<<<<<<
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Mqtt Network)#<<<<<<<<<<

set(PROJECT_SOURCES
        main.cpp
        mqtt_test.cpp
        mqtt_test.h
        mqtt_test.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(_0005_HTTP_MQTT
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        http_test.h http_test.cpp http_test.ui
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET _0005_HTTP_MQTT APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(_0005_HTTP_MQTT SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(_0005_HTTP_MQTT
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(_0005_HTTP_MQTT PRIVATE
                Qt${QT_VERSION_MAJOR}::Widgets
                Qt6::Mqtt
                Qt6::Network)#<<<<<<<<<<<<<<<<<<<<<<<<<<<

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example._0005_HTTP_MQTT)
endif()
set_target_properties(_0005_HTTP_MQTT PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS _0005_HTTP_MQTT
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(_0005_HTTP_MQTT)
endif()
