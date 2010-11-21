#include <iostream>
#include <cassert>
#include <string>
#include "vector3.h"
#include "celestialbody.h"
#include "gravitysystem.h"

using namespace std;

int main (int argc, char * argv[]) {
  GravitySystem gs;
  CelestialBody * sun = new CelestialBody(100, 1);
  sun->setName("Sun");
  sun->setPosition(Vector3(0,0,0));
  sun->setVelocity(Vector3(0,0,0));
  CelestialBody * jupiter = new CelestialBody(1, 2);
  jupiter->setName("Jupiter");
  jupiter->setPosition(Vector3(100, 0, 0));
  jupiter->setVelocity(Vector3(1,5,0));
  gs.addCelestialBody(sun);
  gs.addCelestialBody(jupiter);
  cout<<"The system has " << gs.getCelestialBodies().size() << " bodies." <<endl;
  assert(gs.getCelestialBodies().size()==2);
  CelestialBody * body = gs.getCelestialBodyById(1);
  assert (body->getId()==1);
  assert (body->getName() == string("Sun"));
  cout<<"The first body is the "<<body->getName() <<"."<<endl;
  return 0;
}