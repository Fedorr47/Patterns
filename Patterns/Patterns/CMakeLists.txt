# CMakeList.txt : CMake project for Patterns, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

add_subdirectory ("PIMPL/ProxyPimpl")
add_subdirectory ("PIMPL/MovCopyPIMPL")
add_subdirectory ("PIMPL/BackPimpl")
# Add source to this project's executable.
file(GLOB_RECURSE GLOB_SOURCE "*.cpp")
SET(SOURCES ${GLOB_SOURCE})

file(GLOB_RECURSE GLOB_HEADER "*.h")
set(HEADER_FILES ${GLOB_HEADER})
# Add source to this project's executable.
add_executable (Patterns ${SOURCES} ${HEADERS})

# TODO: Add tests and install targets if needed.
