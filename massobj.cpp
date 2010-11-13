/*
    The class to represent an object with mass.
    Copyright (C) Xun Chen <revive@threebody.org>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#include <math.h>
#include "massobj.h"

MassObj::MassObj (double m) : mass (m > 0 ? m : 1.), position (Vector3()), velocity (Vector3()) {
}

MassObj::MassObj (const Vector3& p, const Vector3& v, double m)
    : position (p), velocity (v), mass (m > 0 ? m : 1.) {
}

Vector3 MassObj::getAccelaration (const Vector3& g) {
  return Vector3 (g.getX() / mass, g.getY() / mass, g.getZ() / mass);
}

Vector3 MassObj::getForce (const MassObj& mo) {
  // -Gm1m2/|r1-r2|^3.(r1-r2)
  Vector3 deltaP = position - mo.position;
  double deltaR = deltaP.getR();
  Vector3 f = Vector3(deltaP);
  f.invert();
  f.scale(mass*mo.mass/deltaR/deltaR/deltaR);
  return f;
}

Vector3 MassObj::getAccelaration (const MassObj& mo){
  Vector3 f = getForce(mo);
  return getAccelaration(f);
}

