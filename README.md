# nØst
This repository is an example on how to use protopie to simulate an NEST interface. The project entails the following components:

* A smartphone connected over wifi or USB (enable USB debugging)
* A 3D printed smartphone mount that allows a ring mount and angular sensor mount ([STL base](base.stl) - [STL head](head.stl) - [STEP base](base.step))
* A laser cutted gear set ([svg gears](gears.svg))
* A Grove - Rotary Angle Sensor(P) ([wall mount model](https://wiki.seeedstudio.com/Grove-Rotary_Angle_Sensor/))
* An [Arduino Nano Grove Hat](https://www.seeedstudio.com/Grove-Shield-for-Arduino-Nano-p-4112.html)
* An Arduino Nano connected to a computer ([Arduino code](arduino.ino))
* [Protopie Connect](https://www.protopie.io/blog/complete-guide-protopie-connect)
* [This protopie protype](protopie.pie)

The ring mount is placed over the protopie app to allow ring interactions. These ring movements are captures through the gears by the rotary angle sensor. The Arduino maps the values of the sensor to four variables: (1) temperature, (2) indicator rotation, (3) red value and (4) blue value. These data gent sent over the serial connecten and are read by protopie connect. Protopie connect dispatches these signals to the protopie prototpe that listens to these variables and reacts when it receives input (by changing the text, the color and the rotation).
