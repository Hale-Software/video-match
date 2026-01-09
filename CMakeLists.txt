cmake_minimum_required(VERSION 3.28...3.30)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/common")
include(versionconfig)

project(video-match VERSION ${VM_VERSION_CANONICAL} LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT DEFINED VM_BUILD_TYPE)
    set(VM_BUILD_TYPE ${CMAKE_BUILD_TYPE})
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/templates/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)

#add_definitions( -DMAGICKCORE_QUANTUM_DEPTH=16 )
#add_definitions( -DMAGICKCORE_HDRI_ENABLE=1 )

set(Qt6_DIR "/Users/drew/Qt/6.10.0/macos/lib/cmake/Qt6")
#set(ImageMagick_Magick++_LIBRARY "/Users/drew/Projects/ImageMagick-7.0.10/include/ImageMagick-7")

find_package(Qt6 REQUIRED COMPONENTS Widgets)
#find_package(OpenCV REQUIRED)
#find_package(ImageMagick 7 REQUIRED COMPONENTS Magick++)

#include_directories(${ImageMagick_INCLUDE_DIRS})

#add_subdirectory(phash)

add_executable(video-match)

target_include_directories(video-match PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

include(cmake/ui-dialogs.cmake)
include(cmake/ui-settings.cmake)
include(cmake/ui-utility.cmake)

target_sources(
        video-match PRIVATE
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${CMAKE_CURRENT_BINARY_DIR}/config.h
)

target_link_libraries(video-match PRIVATE
        Qt::Widgets
        #${OpenCV_LIBS}
)

set_target_properties(video-match PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS video-match
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_finalize_executable(video-match)
