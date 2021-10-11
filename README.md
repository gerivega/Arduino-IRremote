# Arduino-IRremote
Support for Multiple IR Receivers for Arduino IRremote v3.4.0

This project will allow multiple IR Receivers to be connected

Concept was taken from Neco777. Please see the website
https://github.com/Arduino-IRremote/Arduino-IRremote/issues/20

Code was modified from
https://github.com/Neco777/IRemoteModified

Arduino Library was taken from 
https://www.arduino.cc/reference/en/libraries/irremote/
or through the link
https://downloads.arduino.cc/libraries/github.com/z3t0/IRremote-3.4.0.zip
This version was updated October 8, 2021

# Installation
1. Download and install IRremote the one by Armin Joachimsmeyer
2. Click "Download ZIP"
3. Extract the downloaded zip file
4. Overwrite the files in the arduino library.

# Just look a the example
Hopefully by looking at the example **IR_Multiple.ino** you should be able to know how to use the modification. The example shows 8 IRs connected. **IR_MultipleArray** if you need to use a for loop to go through all the IRs.

# The History
There are several tutorials on how to get the code of an IR controller that is normally used for TV. A very good library was created by Ken Shirriff. You can view his website http://www.righto.com/2009/08/multi-protocol-infrared-remote-library.html that explains the concept, the circuit and the code among other things. If you install the library through the library manager it is now shown by Armin Joachimsmeyer.

The youtube channel https://www.youtube.com/watch?v=8E3ltjnbV0c by DroneBot Workshop provides excellent basic information for beginners.

If you happen to think of connecting several IR sensors you will discover that this feature is not supported by the library. There is a discussion on https://github.com/Arduino-IRremote/Arduino-IRremote/issues/20. The thread concludes with "connecting the output pins of several devices together". However, this may not do for some projects if you want to know from which sensor the signal came from. Since the output pins of the sensor are all connected, there is no way of differentiating where the signal came from.

**Multiple IR**. I used the same approach as neco777. Editing it to the current version:
I moved "irparams_struct irparams" from global state to class IRrecv. In global state I created collection of all instances of irparams_struct instead. I add new instance of irparams_struct into that collection in every constructor call of IRrecv. So every instance of IRrecv works with its own instance of irparams_struct . Inside "ISR (TIMER_INTR_NAME)", I go thru collection of irparams_struct and process values from each pin separately.

# The bug fixes/enhancements
Some issues were encountered when implementing the changes.

1. **MICROS_PER_TICK**. There was a need to update the timer interrupt used. The 50 micro seconds default is too low to be handling more than 1 remote. My testing indicated a value between 100 to 400 microseconds may be needed. This is done by defining a value for MICROS_PER_TICK. Bug fixes are done on private/IRTimer.hpp and some ir_.cpp files.

2. **RAWBUF_DATA_TYPE**. The next problem was the memory used. Since each IR has its own buffer, the memory used can grow quickly. The buffer makes use of 2 bytes (16 bits) was changed to 1 byte. 
