//
// Created by dgeorgak on 10/4/17.
//

#ifndef PARTICLEFIRESIMULATION_SCREEN_H
#define PARTICLEFIRESIMULATION_SCREEN_H
#include <iostream>
#include <SDL.h>


namespace SDLScreen {

  class Screen {
  public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;

  public:
    Screen();
    bool init();
    void update();
    bool processEvents();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void close();
    void clear();

    virtual ~Screen() = default;

  private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer;


  };

}
#endif //PARTICLEFIRESIMULATION_SCREEN_H
