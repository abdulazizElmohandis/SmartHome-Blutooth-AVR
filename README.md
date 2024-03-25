# SmartHome-Blutooth-AVR
Remote Controlled Home using Mobile Bluetooth using ATmega32 Microcontroller 

Electronics Components: 
HC-05 Bluetooth Module (or HC-06)
-ATmega32 MCU
-LED's
-Stepper motor
-Servo Motor

Project Goal: 
Control Room Door, Window and lights of the room.

The system allows controlling the
home by mobile phone application
through Bluetooth. Two subsystems
are implemented; Safety door that
could be opened by the mobile
application by entering user name
and password, and light on/off that
could be controlled also by the
mobile phone. The system supports
5 users with different names and
password. In case of entering the
name of the password 5 times
wrong, the system should give
alarm.

Requiremnts: 
-Bluetooth electronics application on android let you customize a control panel for you.(or any other bluetooth application)
-Any SDK (or IDE) to build and burn the code. PlatformIO extenstion in VScode is used in this project (you could use any other IDE.)
-If you use PlatformIO please cinfigure the programmer you use in my case it's USBasp AVR programmer.For more info see this  Doccumination. https://docs.platformio.org/en/stable/platforms/atmelavr.html#configuration
-In the blutooth mobile app send '=' at the end of any string message sent. (or change in code).

This is my control panel int the app used:

![418905404_749492866942031_1453407393499220000_n](https://github.com/abdulazizElmohandis/SmartHome-Blutooth-AVR/assets/53541270/0d975303-4850-43d0-a216-b753d9a865b7)



