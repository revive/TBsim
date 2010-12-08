/*
    Class provides Calculation functions
    Copyright (C) 2010  Xun Chen <xun.revive.gmail.com>

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

#ifndef CACULATION_H
#define CACULATION_H
#include <vector>

class CelestialBody;
class Caculation {
  public:
    /**
    * Evolution a set celestial bodies in one step.
    */
    virtual void stepEvolution(std::vector<CelestialBody*> bodies) = 0;
};

#endif // CACULATION_H
