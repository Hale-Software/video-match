set(COMPANY_NAME "Hale Software LLC")
set(PRODUCT_NAME "VideoMatch Pro")
set(PRODUCT_WEBSITE "https://hale-software.github.io/video-match/")
set(PRODUCT_COMMENTS "Desktop application that recursively scans a directory for duplicate media files")
set(LEGAL_COPYRIGHT "(C) Hale Software LLC")

# Configure default version strings
set(_VM_DEFAULT_VERSION "0" "0" "1")
set(_VM_DEFAULT_VERSION "0" "0" "0" "0")
set(_VM_DEFAULT_VERSION "0" "0" "0" "0")

# Set full and canonical VideoMatch Pro version from current git tag or manual override
if(NOT DEFINED VM_VERSION_OVERRIDE)
    if(NOT DEFINED RELEASE_CANDIDATE
            AND NOT DEFINED BETA
            AND EXISTS "${CMAKE_SOURCE_DIR}/.git")
        execute_process(
                COMMAND git describe --always --tags --dirty=-modified
                OUTPUT_VARIABLE _VM_VERSION
                WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
                RESULT_VARIABLE _VM_VERSION_RESULT
                OUTPUT_STRIP_TRAILING_WHITESPACE)

        if(_VM_VERSION_RESULT EQUAL 0)
            if(${_VM_VERSION} MATCHES "rc[0-9]+$")
                set(RELEASE_CANDIDATE ${_VM_VERSION})
            elseif(${_VM_VERSION} MATCHES "beta[0-9]+$")
                set(BETA ${_VM_VERSION})
            else()
                string(REPLACE "-" "." _CANONICAL_SPLIT ${_VM_VERSION})
                string(REPLACE "." ";" _CANONICAL_SPLIT ${_CANONICAL_SPLIT})
                list(GET _CANONICAL_SPLIT 0 1 2 _VM_VERSION_CANONICAL)
                string(REPLACE "." ";" _VM_VERSION ${_VM_VERSION})
            endif()
        endif()
    endif()

    # Set release candidate version information Must be a string in the format of
    # "x.x.x-rcx"
    if(DEFINED RELEASE_CANDIDATE)
        string(REPLACE "-rc" "." _VM_RELEASE_CANDIDATE ${RELEASE_CANDIDATE})
        string(REPLACE "." ";" _VM_VERSION ${RELEASE_CANDIDATE})
        string(REPLACE "." ";" _VM_RELEASE_CANDIDATE ${_VM_RELEASE_CANDIDATE})
        list(GET _VM_RELEASE_CANDIDATE 0 1 2 _VM_VERSION_CANONICAL)
        # Set beta version information Must be a string in the format of
        # "x.x.x-betax"
    elseif(DEFINED BETA)
        string(REPLACE "-beta" "." _VM_BETA ${BETA})
        string(REPLACE "." ";" _VM_VERSION ${BETA})
        string(REPLACE "." ";" _VM_BETA ${_VM_BETA})
        list(GET _VM_BETA 0 1 2 _VM_VERSION_CANONICAL)
    elseif(NOT DEFINED _VM_VERSION)
        set(_VM_VERSION ${_VM_DEFAULT_VERSION})
        set(_VM_VERSION_CANONICAL ${_VM_DEFAULT_VERSION})
    endif()
else()
    string(REPLACE "." ";" _VM_VERSION "${VM_VERSION_OVERRIDE}")
    string(REPLACE "-" ";" _VM_VERSION_CANONICAL "${VM_VERSION_OVERRIDE}")
    list(GET _VM_VERSION_CANONICAL 0 _VM_VERSION_CANONICAL)
    string(REPLACE "." ";" _VM_VERSION_CANONICAL "${_VM_VERSION_CANONICAL}")
endif()

list(GET _VM_VERSION_CANONICAL 0 VM_VERSION_MAJOR)
list(GET _VM_VERSION_CANONICAL 1 VM_VERSION_MINOR)
list(GET _VM_VERSION_CANONICAL 2 VM_VERSION_PATCH)
list(GET _VM_RELEASE_CANDIDATE 0 VM_RELEASE_CANDIDATE_MAJOR)
list(GET _VM_RELEASE_CANDIDATE 1 VM_RELEASE_CANDIDATE_MINOR)
list(GET _VM_RELEASE_CANDIDATE 2 VM_RELEASE_CANDIDATE_PATCH)
list(GET _VM_RELEASE_CANDIDATE 3 VM_RELEASE_CANDIDATE)
list(GET _VM_BETA 0 VM_BETA_MAJOR)
list(GET _VM_BETA 1 VM_BETA_MINOR)
list(GET _VM_BETA 2 VM_BETA_PATCH)
list(GET _VM_BETA 3 VM_BETA)

string(REPLACE ";" "." VM_VERSION_CANONICAL "${_VM_VERSION_CANONICAL}")
string(REPLACE ";" "." VM_VERSION "${_VM_VERSION}")

if(VM_RELEASE_CANDIDATE GREATER 0)
    message(
            AUTHOR_WARNING
            "******************************************************************************\n"
            "  + VideoMatch Pro - Release candidate detected, VM_VERSION is now: ${VM_VERSION}\n"
            "******************************************************************************"
    )
elseif(VM_BETA GREATER 0)
    message(
            AUTHOR_WARNING
            "******************************************************************************\n"
            "  + VideoMatch Pro - Beta detected, VM_VERSION is now: ${VM_VERSION}\n"
            "******************************************************************************"
    )
endif()

# Define build number cache file
set(BUILD_NUMBER_CACHE
        ${CMAKE_SOURCE_DIR}/cmake/.CMakeBuildNumber
        CACHE INTERNAL "VideoMatch Pro build number cache file")

# Read build number from cache file or manual override
if(NOT DEFINED VM_BUILD_NUMBER AND EXISTS ${BUILD_NUMBER_CACHE})
    file(READ ${BUILD_NUMBER_CACHE} VM_BUILD_NUMBER)
    math(EXPR VM_BUILD_NUMBER "${VM_BUILD_NUMBER}+1")
elseif(NOT DEFINED VM_BUILD_NUMBER)
    set(VM_BUILD_NUMBER "1")
endif()
file(WRITE ${BUILD_NUMBER_CACHE} "${VM_BUILD_NUMBER}")

message(
        STATUS
        "VideoMatch Pro:  Application Version: ${VM_VERSION} - Build Number: ${VM_BUILD_NUMBER}"
)
