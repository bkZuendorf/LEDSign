# LEDSign
<table>
  <tr><td><img src="https://github.com/user-attachments/assets/60272a0f-e9ad-422b-9be2-8f105eeffbec" height="400"/></td><td><img src="https://github.com/user-attachments/assets/32ceee8c-6525-4c8e-ae65-d7121a615efe" height="200"/></td></tr>
</table>

This project provides 3D-Model, hardware and source code for a simple LEDSign. It has been designed for a project in the CRBK upper grammar school.

A instruction on how to build a LEDSign you can find [here](ANLEITUNG.md).

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

## Versions <a name="versions"></a>
|HW-Version|Kompatible SW|µC|Besonderheiten|
|---|---|---|---|
|before 24|LEDSign23.0N|Arduino Nano|Taster, LDR - nur SW dimming|
|LEDSign24.1N|LEDSign24.1N|Arduino Nano|Taster, LDR|
|LEDSign24.2N|LEDSign24.2N|Arduino Nano|Taster, LDR und DS18B20|
|LEDSign24.3N|LEDSign24.2N|Arduino Nano|Taster, LDR und DS18B20, andere Platzierung|
