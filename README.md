# ParticleFireSimulation
Simulation of particle fire explosion using SDL2 library.
Classes design: Particle, Swarm (collection of particles), Buffer(for storing pixels), Texture, Renderer, Screen.
Details about SDL2: http://wiki.libsdl.org/

In order to build the project follow these steps:
- Download cmake and follow installation guide (https://cmake.org/install/)
- Create the cmake-build-debug directory and clear it if it has results from a previous build
- Go to cmake-build-debug and run: cmake -D CMAKE_CXX_FLAGS="-std=c++11 -O0 -ggdb" ..
- Run make
- Run the program
