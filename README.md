
# Automatic Irrigation system based on Soil mositure levels
This aims to check the relationship the palnt and water-use efficiency in a range of biophysical and socio-economic contexts.

#### Other Hardware requirements
* Arduino Board with wifi/Bluetooth module
* Smartphone with the Blynk app installed
* DHT11 Temperature and Humidity Sensor
* Capacitive Soil Moisture Sensor
* Water Level Sensor???
* Relay Module
* Breadboard and Jumper Wires

### How to connect?
1. Development Board <-------------> Capacitive Soil Humidity Sensor

Capacitive soil humidity sensor one

A0<----->AOUT

3.3V<----->VCC

GND<----->GND

2. Development Board<------------->Four-Channel Relay

VCC<------>VIN

GND<------>GND

D2<-------->IN1

D3<--------->IN2

D4<--------->IN4

D5<--------->IN5

4 of the normally open ports of the four-channels-Relay connect to the positive pole
of the 5V power supply, the normally closed port is suspended. 4 of the relay common
ports are connected to the positive poles of 4 pumps, and the negative poles of 4
pumps are connected to the negative pole of 5V power supply.

`NB:`
*There are total four lines of 'if(value4>550)' in the 'loop' function. This
is the statement that controls the start of the pump. The values inside need
to be reset according to the water needs of the plants and flowers.*

### Connection Diagram

![Image](ConnectionDiagram.png "picha")

## Limitations/ challenges

1. power supply >> Solution is solar power with a backup battery
2. Good weather protection material from the elements of mother nature
3. Information relay to phone app/email/sms
4. Affordability and scalability
5. Land terrain
6. What happened if water in tank is empty?? Then ur water pump may burn in dry run conditions... You should embedd two project in a single project.. I. E. 
Smart irrigation system with automatic water level control using ultrasonic sensor.. So it gives sustainable solutions zero maintenance...

Included sensor libraries;

- Temperature and Humindity sensor module