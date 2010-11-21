#ifndef GRAVITYSYSTEM_H
#define GRAVITYSYSTEM_H

#include <vector>
#include "celestialbody.h"
/**
  * class GravitySystem
  * This class is used to describe a system with n celestial bodies interacting with each other by gravity.
  */

class GravitySystem {

public:
  /**
   * Empty Constructor
   */
  GravitySystem ();

  /**
   * Empty Destructor
   */
  ~GravitySystem ();

  /**
   * Get the time
   * @return double
   */
  double getTime ( ) {
    return time;
  }

  /**
   * add a celestial body into the system.
   * @param  celestialbody
   */
  void addCelestialBody ( CelestialBody * celestialbody );

  /**
   * Get the list of celestial bodies.
   * @return std::vector<CelestialBodies *>
   */
  std::vector<CelestialBody *> getCelestialBodies ( ) const {
    return CelestialBodies;
  }

  /**
   * Set the time of the system.
   * @param  t
   */
  void setTime ( double t ) {
    time = t;
  }

  /**
   * Reset the system by setting the time to be 0 and clearing the list of celestial bodies.
   */
  void reset ( ) ;

  /**
   * Evoluation to the state after the time given by deltaTime.
   * @param  deltaTime The period to the next state.
   */
  void Evolution ( double deltaTime );

  /**
  * Get a celestial body by its id.
  * @param id the id of the body
  * @return the celestialbody, 0 if not found.
  */
  CelestialBody * getCelestialBodyById ( int id );

private:
  /**
   * Time of the system.
  */
  double time;

  /**
   * celestial bodies in the system.
  */
  std::vector<CelestialBody*> CelestialBodies;
};

#endif // GRAVITYSYSTEM_H
