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

#ifndef PINCONFIG_H
#define PINCONFIG_H

// select one temperature sensor type
#define TEMPERATURE_SENSOR_MAX6675
// #define TEMPERATURE_SENSOR_MAX31855
// #define TEMPERATURE_SENSOR_MAX31850

#define thermoDO 12 // D7
#define thermoCS 13 // D6
#define thermoCLK 15 // D5

#define RELAY_HEATER_TOP 27
#define RELAY_HEATER_BOTTOM 26
#define RELAY_CONV_FAN 25
#define LED_RED -1
// #define LED_GREEN 1
// #define LED_BLUE 2
#define BUZZER_A 5
#define BUZZER_B 4
// #define PCA9536_SDA 2
// #define PCA9536_SCL 0

#define DEFAULT_TARGET 60
#define MAX_ON_TIME 1000 * 60 * 2
#define MAX_TEMPERATURE 400
#define MIN_TEMP_RISE_TIME 1000 * 40
#define MIN_TEMP_RISE 10
#define CONTROL_HYSTERISIS .01
#define DEFAULT_TEMP_RISE_AFTER_OFF 30.0
#define SAFE_TEMPERATURE 50
#define CAL_HEATUP_TEMPERATURE 90
#define DEFAULT_CAL_ITERATIONS 3
#define WATCHDOG_TIMEOUT 10 * 1000 // miliseconds

#endif