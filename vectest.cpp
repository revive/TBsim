#include <iostream>
#include <cassert>
#include <math.h>
#include "vector3.h"
#include "massobj.h"

using namespace std;
const double pi = 4.*atan(1.);
const double epsilon = 1.e-15;

int main (int argc, char* argv[]) {
  // This is a test program for the vector3.
  Vector3 v1 (1, 0, 0);
  Vector3 v2 (0, 1, 0);
  Vector3 v3 (0, 0, 1);
  Vector3 v4 (1, 1, 1);

  cout << "v1(1,0,0), v2(0,1,0), v3(0,0,1), v4(1,1,1)" << endl;
  double phi = v1.getPhi();
  assert (phi == 0);
  cout << "Test 1:" << endl;
  cout << "v1.phi() == 0 ... Passed." << endl;
  phi = v2.getPhi();
  assert (phi == pi / 2.);
  cout << "v2.phi() == pi/2 ... Passed." << endl;
  Vector3 v5 = v1 * v2;
  assert (v5.getX() == 0 && v5.getY() == 0 && v5.getZ() == 1);
  cout << "v5 = v1*v2, v5 == v3 ... Passed." << endl;
  v5 += v2;
  assert (v5.getX() == 0 && v5.getY() == 1 && v5.getZ() == 1);
  cout << "v5+=v2, v5 == (0, 1, 1) ... Passed." << endl;
  v5 += v1;
  phi = v5.getPhi();
  assert (fabs(phi-pi/4.) < epsilon);
  cout << "v5=(1,1,1), v5.phi() == pi/4 ... Passed." <<endl;

  MassObj mo(5);
  cout << mo.getPosition().getX() << endl;
  mo.getPosition().setX(5);
  cout << mo.getPosition().getX() << endl;
  mo.setPosition(v5);
  cout << mo.getPosition().getX() << " " << mo.getPosition().getY() << " " << mo.getPosition().getZ()<<endl;

  MassObj m1(0);
  cout << m1.getMass() << endl;
  MassObj m2 (-1);
  cout << m2.getMass() << endl;
  return 0;
}
