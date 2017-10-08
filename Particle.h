//
// Created by dgeorgak on 10/5/17.
//

#ifndef PARTICLEFIRESIMULATION_PARTICLE_H
#define PARTICLEFIRESIMULATION_PARTICLE_H

namespace SDLScreen {

  class Particle {
  public:
    Particle();

    double getX() {return m_x;}
    double getY(){return m_y;}
    void update(int interval);

    virtual ~Particle() {}; //this is a clion bug, destructor=default cannot be used with heap alloc classes

  private:

    // x-y system of coordinates
    double m_x;
    double m_y;
    //double m_xspeed;
    //double m_yspeed;

    //transform from x-y system to polar system, we need and angle and a speed
    double m_direction;
    double m_speed;

  };

}
#endif //PARTICLEFIRESIMULATION_PARTICLE_H
