/**
 *  Copyright (C) 2021  Teslafly
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef THERMOCOUPLE_H
#define THERMOCOUPLE_H

#include "PinConfig.h"

#ifdef TEMPERATURE_SENSOR_MAX31855
    #include <MAX31855.h>
#elif defined TEMPERATURE_SENSOR_MAX6675
    #include <max6675.h>
#else
    #error No sensor type defined. Please define one
#endif


class ThermocoupleBase {
public:
    ThermocoupleBase(void);
    float read_temperature(void);

private:
    #ifdef TEMPERATURE_SENSOR_MAX31855
	    MAX31855 thermocouple;
    #elif defined TEMPERATURE_SENSOR_MAX6675
	    MAX6675 thermocouple;
    #endif
};

#endif