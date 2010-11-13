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

#include <math.h>
#include "vector3.h"

Vector3::Vector3 (double x, double y, double z) : x (x), y (y), z (z) {

}

Vector3::Vector3 (const Vector3 &v) : x (v.x), y (v.y), z (v.z) {

}

Vector3& Vector3::operator+= (const Vector3 & v) {
  x += v.x;
  y += v.y;
  z += v.z;
  return *this;
}

Vector3& Vector3::operator-= (const Vector3 & v) {
  x -= v.x;
  y -= v.y;
  z -= v.z;
  return *this;
}

double Vector3::getR() const {
  return sqrt (x*x + y*y + z*z);
}

void Vector3::scale (double a) {
  x *= a;
  y *= a;
  z *= a;
}

void Vector3::invert() {
  scale (-1.);
}

void Vector3::normalize() {
  if (x == 0 && y == 0 && z == 0) return;
  double r = getR();
  x /= r;
  y /= r;
  z /= r;
}

double Vector3::getPhi() const {
  if (x == 0 && y == 0) return 0;
  double phi = acos (x / sqrt (x * x + y * y));
  if (y < 0) {
    phi = 2 * M_PI - phi;
  }
  return phi;
}

double Vector3::getTheta() const {
  if (x == 0 && y == 0 && z == 0) return 0;
  double theta = acos (z / getR());
  return theta;
}

double Vector3::dotProduct (const Vector3 &v) {
  return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::add (const Vector3 &v) {
  const Vector3 & vn = Vector3 (x + v.x, y + v.y, z + v.z);
  return vn;
}

Vector3 Vector3::operator+ (const Vector3 & v) {
  return add (v);
}

Vector3 Vector3::subtract (const Vector3& v) {
  Vector3 vn (x - v.x, y - v.y, z - v.z);
  return vn;
}

Vector3 Vector3::operator- (const Vector3& v) {
  return subtract (v);
}

Vector3 Vector3::crossProduct (const Vector3& v) {
  double xn = y * v.z - z * v.y;
  double yn = z * v.x - x * v.z;
  double zn = x * v.y - y * v.x;
  return Vector3 (xn, yn, zn);
}

Vector3 Vector3::operator* (const Vector3& v) {
  return crossProduct (v);
}
