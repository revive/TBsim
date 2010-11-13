/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

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

#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

#include <string>
#include "massobj.h"

class CelestialBody : public MassObj {
public:
  CelestialBody (double m = 1.);
  int getId();
  std::string getName() const;
  void setName(const std::string &);
private:
  int id;
  std::string name;
};

#endif // CELESTIALBODY_H
