/*
    The class to represent an object with mass.
    Copyright (C) 2010  Xun Chen <revive@threebody.org>

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

#ifndef MASSOBJ_H
#define MASSOBJ_H

#include "vector3.h"
//! An object with mass
/*!
  This class is used to represent an object with mass.
  It has a position vector p given in Cartesian Coodinate system,
  and a velocity vector.
*/

class MassObj {
public:
  //! The default constructor
  /*!
    The default constructor create a still object with mass m at the original point.
    If the mass is not given, it is set to be the mass of the Sun.
    The initial position is at (0,0,0).
    The initial velocity is set to be (0, 0, 0). That means the object is fixed at the start.
    \param m mass of the object. It must be a positive number. non-positive mass will be set to 1.
  */
  MassObj (double m = 1.);

  MassObj (const Vector3 &p, const Vector3 &v, double m = 1.);
  //! Get Mass
  /*!
    Get mass of the object
    \return mass of the object
  */
  double getMass() const { return mass; };

  //! Get position of the object
  /*!
    \return reference of the position vector
  */
  Vector3 & getPosition() { return position;};

  //! Get Velocity of the object
  /*!
   \return reference of the velocity vector
  */
  Vector3 & getVelocity() { return velocity;};

  //! Set position of the object
  /*!
    \param p position vector
  */
  void setPosition (Vector3 p) { position = p; };

  //! set velocity of the object
  /*!
    \param v velocity vector
  */
  void setVelocity (Vector3 v) { velocity = v; };

  /**
  * Get gravity force from another object
  * \param mo another object.
  * \return gravity force.
  */
  Vector3 getForce (const MassObj & mo);

  /**
  * Get accelaration of the object when force is given.
  * \param g gravity force exerted on the object
  * \return accelaration.
  */
  Vector3 getAccelaration (const Vector3 & g);

  /**
  * Get accelaration of the object in the gravity field of another object
  * \parma mo another mass object
  * \return accelaration.
  */
  Vector3 getAccelaration (const MassObj & mo);
protected:
  const double mass; /*! The mass of the object. */
  Vector3 position;
  Vector3 velocity;
};

#endif // MASSOBJ_H
