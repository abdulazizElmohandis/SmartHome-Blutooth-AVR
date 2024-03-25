# SmartHome-Bluetooth-AVR

## Remote Controlled Home using Mobile Bluetooth with ATmega32 Microcontroller

### Electronics Components:
- HC-05 Bluetooth Module (or HC-06)
- ATmega32 MCU
- LED's
- Stepper motor
- Servo Motor

### Project Goal:
Control Room Door, Window, and lights of the room.

The system allows controlling the home by a mobile phone application through Bluetooth. Two subsystems are implemented: 
1. Safety door that could be opened by the mobile application by entering a username and password.
2. Light on/off that could be controlled also by the mobile phone. The system supports 5 users with different names and passwords. In case of entering the name or password incorrectly 5 times, the system should give an alarm.

### Requirements:
- Bluetooth electronics application on Android lets you customize a control panel for you (or any other Bluetooth application).
- Any SDK (or IDE) to build and burn the code. PlatformIO extension in VScode is used in this project (you could use any other IDE). If you use PlatformIO, please configure the programmer you use. In my case, it's USBasp AVR programmer. For more info see this [Documentation](https://docs.platformio.org/en/stable/platforms/atmelavr.html#configuration).
- In the Bluetooth mobile app, send '=' at the end of any string message sent (or change in code).

This is my control panel in the app used:


![418905404_749492866942031_1453407393499220000_n](https://github.com/abdulazizElmohandis/SmartHome-Blutooth-AVR/assets/53541270/0d975303-4850-43d0-a216-b753d9a865b7)



