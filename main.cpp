// SDL: Simple DirectMedia Layer is a cross-platform development library designed to provide low level access
// to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D.
#include <iostream>
#include <iomanip>
#include "Screen.h"
#include "Swarm.h"


int main() {

  srand(time(0));
  const static int xhalf_limit = SDLScreen::Screen::SCREEN_WIDTH/2;
  const static int yhalf_limit = SDLScreen::Screen::SCREEN_HEIGHT/2;

  SDLScreen::Screen screen;
  SDLScreen::Swarm swarm;
  SDLScreen::Particle particle;

  if(!screen.init()) {
    std::cout << "SDL could not be initialized" << std::endl;
  }


  while(true) {

    // in order for colors to alter smoothly we will feed the sin(x) with the return value of the clock ticks
    // we will need to provide a proper sin function slowly ranging from 0 to 255, we do not want MAX=256
    int elapsed = SDL_GetTicks();
    screen.clear(); // clear the buffer in order to get the particle movement illusion
    swarm.update(elapsed);

    unsigned char red = static_cast<unsigned char>(1 + sin(elapsed*0.0001)*128);
    unsigned char green = static_cast<unsigned char>(1 + sin(elapsed*0.0002)*128);
    unsigned char blue = static_cast<unsigned char>(1 + sin(elapsed*0.0003)*128);

    const SDLScreen::Particle * const pParticles = swarm.getParticles();
    for (int i=0; i<SDLScreen::Swarm::NPARTICLES; i++) {
      particle = pParticles[i];
      auto x = static_cast<int>((particle.getX() + 1) * xhalf_limit);
      auto y = static_cast<int>(particle.getY() * xhalf_limit + yhalf_limit);

      screen.setPixel(x, y, red, green, blue);
    }



    //Draw the screen
    screen.update();


    if(!screen.processEvents()) {
      break;
    }


  }

  screen.close();

  return EXIT_SUCCESS;
}