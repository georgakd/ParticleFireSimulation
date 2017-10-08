//
// Created by dgeorgak on 10/5/17.
//

#ifndef PARTICLEFIRESIMULATION_SWARM_H
#define PARTICLEFIRESIMULATION_SWARM_H

#include "Particle.h"

// Swarm class represents tha collection of particles

namespace SDLScreen {

  class Swarm {
  public:
    const static int NPARTICLES = 5000;

  public:
    Swarm();
    void update(int elapsed);
    virtual ~Swarm();

    //pointer to particle cannot be changed
    Particle const *getParticles() {return m_pParticles;}

  private:
    Particle *m_pParticles;
    int lastTime;
  };

}
#endif //PARTICLEFIRESIMULATION_SWARM_H
