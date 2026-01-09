project(phash)

add_library(phash STATIC)

target_sources(
    phash PRIVATE
    main.cpp
    ImageHash.cpp
    ImageHash.hpp
    phash.cpp
    phash.hpp
)

target_include_directories(phash PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
