#include "gravitysystem.h"

// Constructors/Destructors
//

GravitySystem::GravitySystem ( ) {
  time = 0;
}

GravitySystem::~GravitySystem ( ) {
  unsigned int i;

  for ( i=CelestialBodies.size(); i>0; --i ) {
    CelestialBody * cb = CelestialBodies.at ( i-1 );
    delete cb;
  }

  CelestialBodies.clear();
}

void GravitySystem::reset() {
  unsigned int i;

  for ( i=CelestialBodies.size(); i>0; --i ) {
    CelestialBody * cb = CelestialBodies.at ( i-1 );
    delete cb;
  }

  CelestialBodies.clear();

  time = 0;
}

void GravitySystem::addCelestialBody ( CelestialBody* celestialbody ) {
  CelestialBodies.push_back ( celestialbody );
}

CelestialBody * GravitySystem::getCelestialBodyById (int id) {
  unsigned int i;
  for (i = CelestialBodies.size()-1; i>=0; --i) {
    CelestialBody * cb = CelestialBodies.at(i);
    if ( cb->getId() == id) {
      return cb;
    }
  }
  return 0;
}