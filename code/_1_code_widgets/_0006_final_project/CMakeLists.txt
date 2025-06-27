cmake_minimum_required(VERSION 3.16)

project(_0006_final_project VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Svg)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Svg)

set(PROJECT_SOURCES
        main.cpp



)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(_0006_final_project
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        rsc_f.qrc
        _1_menuconfig.h _1_menuconfig.cpp _1_menuconfig.ui
        z_widget_style.h
        z_widget_style.cpp
        _a_login_to_broker.h _a_login_to_broker.cpp _a_login_to_broker.ui
        _b_config_logic_layer.h _b_config_logic_layer.cpp _b_config_logic_layer.ui
        _c_update_mqtt_info.h _c_update_mqtt_info.cpp _c_update_mqtt_info.ui
        _d_update_wifi_info.h _d_update_wifi_info.cpp _d_update_wifi_info.ui
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET _0006_final_project APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(_0006_final_project SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(_0006_final_project
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(_0006_final_project PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                        Qt6::Svg)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example._0006_final_project)
endif()
set_target_properties(_0006_final_project PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS _0006_final_project
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(_0006_final_project)
endif()
