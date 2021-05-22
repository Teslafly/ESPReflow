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

#include "Thermocouple.h"

ThermocoupleBase::ThermocoupleBase(void) :
    #ifdef TEMPERATURE_SENSOR_MAX31855
        thermocouple(thermoCLK, thermoCS, thermoDO)
    #elif defined TEMPERATURE_SENSOR_MAX6675
        thermocouple(thermoCLK, thermoCS, thermoDO)
    #endif
{

#ifdef TEMPERATURE_SENSOR_MAX31855
	thermocouple.begin();
#endif
}

float ThermocoupleBase::read_temperature(void){
    #ifdef TEMPERATURE_SENSOR_MAX31855
        thermocouple.read();
        return thermocouple.getTemperature();
    #elif defined TEMPERATURE_SENSOR_MAX6675
        return thermocouple.readCelsius();
    #endif
}