/*
  This file is part of Orto idroponico Fablab Imperia

  Orto idroponico Fablab Imperia is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Nome-Programma is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Nome-Programma.  If not, see <http://www.gnu.org/licenses/>.
*/

// Include for external Adafruit ADC
#include <Adafruit_ADS1X15.h>


#ifndef DEVICE_PARAMETERS
#define DEVICE_PARAMETERS

// WiFi network SSID and PASSWORD
#define ORTO_WEB_SSID_BASENAME "OrtoWeb"
#define ORTO_WEB_SSID_PASSWD "OrtoWeb12345"

// ADC type: define the correct type of ADC (ADS1015 is a 12 bit resolution ADC, ADS1115 is a 16 bit ADC)
//#define ADC_ADS1015
#define ADC_ADS1115

#define LCD_I2C_ADDRESS 0x27
#define LCD_ROWS 4
#define LCD_COLS 20


// Update time of sensors shown in display
#define TIME_BETWEEN_DISPLAY_VALUES 1000

// After MANUAL_CONTROL_PUMP_TIMEOUT ms all pumps will be turned off (without any other command)
#define MANUAL_CONTROL_PERISTALTIC_PUMP_TIMEOUT 500


// Debug serial communication baudrate
#define SERIAL_BAUDRATE 115200







// Usually you don't need to edit the parameters below (if you use the same hardware)


// EEPROM used size, see eeprom.ino
#define EEPROM_USED_SIZE 15


/*  ATTENTION! DEFAULT VALUES ARE DEPRECATED!       *
    Use web interface to set parameters at runtime
    Parameters will be saved into internal EEPROM
    and retrived at startup                         */
// Duration of one water pump cycle in seconds, set to 0 to keep the pump always on
#define DEFAULT_TIME_WATER_PUMP_CYCLE (0)                                               // Put brackets around expressions like (60*60) [1 hour] because of operator precedence
// Time in seconds of water pump activity in a complete cycle (it's ignored if TIME_WATER_PUMP_CYCLE is zero)
#define DEFAULT_TIME_WATER_PUMP_ACTIVE 15                                               // Put brackets around expressions like (60*60) [1 hour] because of operator precedence

//Time the acid and fertilizer pumps remain ON acter activation in ms
#define DEFAULT_TIME_PERISTALTIC_PUMP_ON 1*1000L
//Time in seconds between two consecutives sensor reads. If the value is below/up the the threshold the pump is acivated (acid or fertlizer)
#define DEFAULT_TIME_BETWEEN_SENSOR_READS 60

//PH Threshold vale (if sensor value is higher, acid pump turns ON)
#define DEFAULT_THRESHOLD_VALUE_PH 6
//PH Threshold vale (if  value is higher, acid pump turns ON)
#define DEFAULT_THRESHOLD_VALUE_CONDUCTIVITY 900



#ifdef ADC_ADS1015
#define ADC_MAX_VALUES 2047     // 2^(12-1) - 1
#elif defined(ADC_ADS1115)
#define ADC_MAX_VALUES 32767    // 2^(16-1) - 1
#endif
#define ADC_MAX_VOLTAGE 6.144

#ifdef ADC_ADS1115
#define ADAFRUIT_ADC Adafruit_ADS1115
#elif defined(ADC_ADS1015)
#define ADAFRUIT_ADC Adafruit_ADS1015
#else
#error "No ADC type definition, define the used type in parameters.hpp (https://github.com/fablab-imperia/orto-idroponico)";
#endif

#endif
