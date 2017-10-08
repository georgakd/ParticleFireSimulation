//
// Created by dgeorgak on 10/4/17.
//
#include <iomanip>
#include "Screen.h"

namespace SDLScreen {

  Screen::Screen() : m_window(nullptr), m_renderer(nullptr), m_texture(nullptr), m_buffer(nullptr) {}


  bool Screen::init() {

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
      std::cout << "SDL init failed:" << SDL_GetError() << std::endl;
      return false;

    }

    m_window = SDL_CreateWindow("Particle Fire Explosion",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, // initial x, y pos
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(m_window == nullptr) {
      std::cout << "SDL window creation failed:" << SDL_GetError() << std::endl;
      SDL_Quit();
      return false;
    }

    // SDL_RENDERER_PRESENTVSYNC ensures that the renderer is in sync with the vertical refresh of the screen
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,  SDL_TEXTUREACCESS_STATIC,
                                             SCREEN_WIDTH, SCREEN_HEIGHT);

    if(m_renderer == nullptr) {
      std::cout << "Could not create renderer" << SDL_GetError() << std::endl;
      SDL_DestroyWindow(m_window);
      SDL_Quit();
      return false;
    }
    if(m_texture == nullptr) {
      std::cout << "Could not create texture" << SDL_GetError() << std::endl;
      SDL_DestroyRenderer(m_renderer);
      SDL_DestroyWindow(m_window);
      SDL_Quit();
      return false;
    }

    // Allocate memory for the pixels on the screen
    m_buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT] {};

    return true;

  }

  void Screen::update() {
    // Update texture rectangle with new pixel data
    SDL_UpdateTexture(m_texture, nullptr, m_buffer, SCREEN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    // Copy a portion of texture to the rendering target
    SDL_RenderCopy(m_renderer, m_texture, nullptr, nullptr);
    // Present render to window
    SDL_RenderPresent(m_renderer);

  }

  bool Screen::processEvents() {
    SDL_Event event;
    // the latest event in the queue waiting to be processed
    while(static_cast<bool>(SDL_PollEvent(&event))) {
      if (event.type == SDL_QUIT) {
        return false;
      }

    }
    return true;
  }

  void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

    //rather inefficient
    if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
      return;
    }

    Uint8 alpha = 0xFF;
    Uint32 color = 0;

    color += red;
    color = color << 8;
    color += green;
    color = color << 8;
    color += blue;
    color = color << 8;
    color += alpha;


    m_buffer[y*SCREEN_WIDTH + x] = color;
    // we set width to 8 like 0x12345678 and we fill with zeros the extra space
    //std::cout << std::setfill('0') << std::setw(8) << std::hex << color << std::endl;


  }

  void Screen::close() {

    delete [] m_buffer;
    SDL_DestroyTexture(m_texture);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();

  }

  void Screen::clear() {

    // replace deprecate memset
    //memset(m_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32)); // get a white screen with 255, black with 0
    std::fill_n(m_buffer, SCREEN_WIDTH*SCREEN_HEIGHT, 0);

  }

}
