/*
    3D vector calculus
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

#ifndef VECTOR3_H
#define VECTOR3_H

/*!
  Vector in 3D space.
  This class provides vector calulation functions in 3d space.
  The vector is defined in the Cartesian coordinate system.
*/
class Vector3 {
public:

  /*!
   * Constructor with 3 numbers
   * The function construct a vector (x, y, z)
   * @param x x component of the vector
   * @param y y component of the vector
   * @param z z component of the vector
   */
  Vector3 (double x = 0 , double y = 0, double z = 0);

  /*!
   * Constructor with an existing vector
   * The function construct a vector from an existing vector.
   * @param v another vector.
   */
  Vector3 (const Vector3 &v);

  Vector3 & operator+= (const Vector3& v);
  Vector3 & operator-= (const Vector3& v);
  /**
   * Get the x component of the vector
   * Get the x component of the vector in Cartesian coordinate system
   *
   * @return x component
   */
  double getX() const {return x;};

  /**
   * Get the y component of the vector
   * Get the y component of the vector in Cartesian coordinate system
   *
   * @return y component
   */
  double getY() const {return y;};

  /**
   * Get the z component of the vector
   * Get the z component of the vector in Cartesian coordinate system
   *
   * @return z component
   */
  double getZ() const {return z;};

  /**
   * Set the x component of the vector
   *
   * @param x the given x component
   */
  void setX (double x) { this->x = x; };

  /**
   * Set the y component of the vector
   *
   * @param y the given x component
   */
  void setY (double y) { this->y = y; };

  /**
   * Set the z component of the vector
   *
   * @param z the given x component
   */
  void setZ (double z) { this->z = z; };

  /**
   * Get the distance to the original point
   *
   * @return the distance to the original point
   */
  double getR() const;

  /**
   * Normalize the vector.
   * This function normalize the vectory (set r to 1).
   * Zero vector can't be normalized.
   */
  void normalize();

  /**
   * Scale the vector
   *
   * @param a the scale factor
   */
  void scale (double a);

  /**
   * invert the vector
   *
   */
  void invert();

  /**
   * Get the phi angle
   * Phi angle is defined as the angle between the x axis.
   * to the projection of the vector in x-y plane, counter-clockwise.
   *
   * @return the phi angle in radius.
   */
  double getPhi() const;

  /**
   * Get the theta angle
   * Theta angle is defined as the angle between the vector and the z axis.
   *
   * @return the theta angle, in radius.
   */
  double getTheta() const;

  /**
   * vector addition.
   *
   * @param v vector to be added.
   *
   * @return the addition of the two vector.
   */
  Vector3 add (const Vector3& v);
  /**
   * vector addition.
   *
   * @param v vector to be added.
   *
   * @return the addition of the two vector. It is a vector.
   */
  Vector3 operator+ (const Vector3& v);

  /**
   * vector substraction
   *
   * @param v subtrahend vector
   *
   * @return the subtraction of the two vector. It is a vector
   */
  Vector3 subtract (const Vector3& v);

  /**
   * vector substraction
   *
   * @param v subtrahend vector
   *
   * @return the subtraction of the two vector. It is a vector
   */
  Vector3 operator- (const Vector3 & v);

  /**
   * dot production of two vector
   * The dot production of two vector v1(x1, y1, z1) and v2(x2, yz, z2) is
   * defined as x1*x2+y1*y2+z1*z2
   *
   * @param v the vector in calculation.
   *
   * @return the dot product.
   */
  double dotProduct (const Vector3 &);

  /**
   * The cross product.
   * The cross product of two vectors is also a vector
   *
   * @param v the vector in calculation.
   *
   * @return the resulted vecotr
   */
  Vector3 crossProduct (const Vector3& v);

  /**
   * The cross product.
   * The cross product of two vectors is also a vector
   *
   * @param v the vector in calculation.
   *
   * @return the resulted vecotr
   */
  Vector3 operator* (const Vector3 & v);
private:
  double x;   /*! x component of the vector */
  double y;   /*! y component of the vector */
  double z;   /*! z component of the vector */
};

#endif // VECTOR3_H
