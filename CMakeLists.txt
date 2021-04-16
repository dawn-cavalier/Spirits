cmake_minimum_required(VERSION 3.17)
project(Spirits)

set(CMAKE_CXX_STANDARD 14)

add_executable(Spirits main.cpp)

# SFML
include_directories(headers /usr/include Dependencies/SFML-2.5.1/include)

set(SFML_ROOT "Dependencies/SFML-2.5.1")


if(POLICY CMP0074)
    cmake_policy(SET CMP0074 NEW)
endif()

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    link_directories("Dependencies/SFML-2.5.1")
    target_link_libraries(Spirits ${SFML_LIBRARIES})
endif()

if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()