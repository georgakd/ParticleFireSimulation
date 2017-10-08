//
// Created by dgeorgak on 10/5/17.
//
#include <cstdlib>
#include <cmath>
#include "Particle.h"


namespace SDLScreen {

  Particle::Particle() : m_x(0), m_y(0) {

    // x-y
    //m_x = ((2.0 * rand())/RAND_MAX) - 1;
    //m_y = ((2.0 * rand())/RAND_MAX) - 1;
    //m_xspeed = 0.001 * (((2.0 * rand())/RAND_MAX) - 1); //assign random speeds
    //m_yspeed = 0.001 * (((2.0 * rand())/RAND_MAX) - 1);

    // polar
    m_direction = (2.0 * M_PI * rand())/RAND_MAX;
    m_speed = (0.0001 * rand())/RAND_MAX;

  }

  void Particle::update(int interval) {

    // x-y
    // m_x += m_xspeed;
    // m_y += m_yspeed;
    // make sure the values stay between [-1,1]
    //if(m_x <= -1.0 || m_x >= 1.0) m_xspeed = -m_xspeed;
    // if(m_y <= -1.0 || m_y >= 1.0) m_yspeed = -m_yspeed;

    // polar
    double xspeed = m_speed * cos(m_direction);
    double yspeed = m_speed * sin(m_direction);
    m_x += xspeed * interval; //ensure somehow the similar speed
    m_y += yspeed * interval;

  }


}