# BarkingDog
Barking Dog alarm using a Raspberry Pi and an Arduino Nano

This projects describes how to set up a barking dog alarm: When someone is at your door, a barking dog sound will be triggered from inside the home.

There are two different parts in this project:

1. The detection/transmitter part to be placed outside near the entrance door and that will send a RF signal when motion is detected. This consist of an arduino nano, a PIR detector and a RF 433Mhz transmitter.

2. The receiver part that will be placed inside the house and connected to an audio amplifier and to some speakers to trigger the barking dog sound when the RF signal is received. This consist of a Raspberry Pi and a RF 433 MHz receiver. 

This github will contain the code to run on the raspberry pi. 
It uses some code from existing project: https://code.google.com/p/rc-switch/

Full instructions for the projects can be found here: 
http://www.instructables.com/id/Barking-Dog-Alarm/

