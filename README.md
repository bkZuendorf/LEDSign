# LEDSign
This project provides 3D-Model, hardware and source code of a project for a simple LEDSign. It has been designed for a prject in the CRBK upper grammar school.

## Hardware PCB
There are different versions of the PCB-Board.

The main difference between the plattforms is the used microcontroller plattform:
- Arduino Nano
- WEMOS D1 Mini

All PCB-boards allow to drive up to 8 logical groups of LEDs using the shift register including output drivers. 

Some of them have special features like:
- Brightness control by use of a LDR (Light Dependend Resistor) on one of the analog inputs
- Button to react on user input
- Temperature Sensor (Dallas DS18B20 or DHT11/DHT22)


## Software
The Software mainly provides a class for accessing the LED-PCB board with it's features. Easily allows to set/unset LEDs and use the features like brightness dependend dimming.
