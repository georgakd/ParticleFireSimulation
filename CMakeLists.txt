cmake_minimum_required(VERSION 2.8.4)
project(ParticleFireSimulation)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb")

if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()


# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES main.cpp Screen.cpp Screen.h Particle.cpp Particle.h Swarm.cpp Swarm.h)

add_executable(ParticleFireSimulation ${SOURCE_FILES})
target_link_libraries(ParticleFireSimulation ${SDL2_LIBRARY})