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
#include <Arduino.h>

ThermocoupleBase::ThermocoupleBase(void) :
    #ifdef TEMPERATURE_SENSOR_MAX31855
        thermocouple(thermoCLK, thermoCS, thermoDO)
    #elif defined TEMPERATURE_SENSOR_MAX6675
        thermocouple(thermoCLK, thermoCS, thermoDO)
    #elif defined TEMPERATURE_SENSOR_MAX31850
        oneWire(thermo_onewire_dat),
        thermocouples(&oneWire)
    #endif
{
    #ifdef TEMPERATURE_SENSOR_MAX31855
        thermocouple.begin();

    #elif defined TEMPERATURE_SENSOR_MAX31850
         // connect onewire_dat pullup to this pin instead of 3.3v. prevents strapping issues on boot with esp32/8266.
        pinMode(onewirepullup_pin, OUTPUT);
        digitalWrite(onewirepullup_pin, HIGH); 
        delay(100);

        thermocouples.begin();

        // Serial.println("found %f onewire thermocouples\n", thermocouples.getDeviceCount());

        #ifdef defined onewire_thermocouple1_address
        // use address if defined. otherwise choose the first device
            thermocouple1 = onewire_thermocouple1_address;
        #else
            if (!thermocouples.getAddress(thermocouple1, 0)) {
                Serial.println("Unable to find address for Device 0");
            } else {
                Serial.println("Found onewire thermocouple");
            }

            // print the device address so we can add to code
            Serial.println("Thermocouple address: ");
            for (uint8_t i = 0; i < 8; i++) {
                if (thermocouple1[i] < 16) {
                    Serial.print("0");
                }
                Serial.print(thermocouple1[i], HEX);
            }
            Serial.println();
            
        #endif
    #endif
}

float ThermocoupleBase::read_temperature(){
    #ifdef TEMPERATURE_SENSOR_MAX31855
        thermocouple.read();
        return thermocouple.getTemperature();
    #elif defined TEMPERATURE_SENSOR_MAX6675
        return thermocouple.readCelsius();
    #elif defined TEMPERATURE_SENSOR_MAX31850
        // 3 retries
        float tempC = 0;
        for(int i =0; i < 3; i++)
        {
            thermocouples.requestTemperatures();
            delay(1); // wait 1ms for conversion to finish
            tempC = thermocouples.getTempC(thermocouple1);

            if(tempC == -127.00){
                // Serial.println("Thermocouple Error: MAX31855 bad data, retrying.");
            } else {
                return tempC;
            }
        }
        //controller.mode(ERROR_OFF);
        return -1.0;
    #endif
}