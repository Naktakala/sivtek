# |========================================================== Projects Settings
cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

find_program(GNU_CXX_COMPILER NAMES gcc)
message(STATUS ${GNU_COMPILER})

if(UNIX AND NOT APPLE)
    add_definitions(-DUNIX_ENV)
elseif(APPLE)
    add_definitions(-DAPPLE_ENV)
    add_definitions(-DUNIX_ENV)
else()
    add_definitions(-DWINDOWS_ENV)
endif()

string(LENGTH "${CMAKE_SOURCE_DIR}/" SOURCE_PATH_SIZE)
add_definitions("-DSOURCE_PATH_SIZE=${SOURCE_PATH_SIZE}")

set( CMAKE_BUILD_TYPE Release ... FORCE )
set(TARGET sivtek)
project(${TARGET} VERSION 0.0.6
                 DESCRIPTION "Silo to VTK Converter"
                 LANGUAGES C CXX)


# |========================================================== Projects Variables
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake_Modules")
set(PROJ_SOURCE "${PROJECT_SOURCE_DIR}/Source")


# |========================================================== Include Modules
include(GNUInstallDirs)
include(Filter)


# |========================================================== Projects Variables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_CXX_COMPILER ${GNU_COMPILER})


# |========================================================== Custom Dependencies
set(PROJECT_DEPENDENCIES "${PROJECT_SOURCE_DIR}/Libs")
set(SILO_ROOT "${PROJECT_DEPENDENCIES}/silo_4.10.2_build")


# |========================================================== Dependencies
set(VTK_DIR "/home/gmovillanueva/Programs/vtk/VTK-8.2.0/build/install")
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})


# |========================================================== Compiler Flags
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")


# |========================================================== Directory Includes
include_directories("${SILO_ROOT}/include")

# |========================================================== Library Directories
link_directories("${SILO_ROOT}/lib")


# |========================================================== Setting Libraries
set(LIBS silo)
set(LIBS ${LIBS} ${VTK_LIBRARIES})
set(LIBS ${LIBS})


# |========================================================== Compile
add_executable(${TARGET})


# |========================================================== Source File Locations
add_subdirectory(Source)


# |========================================================== Linking Everything
target_link_libraries(${TARGET} ${LIBS})
