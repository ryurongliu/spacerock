# SPACEROCK: Music From a Metal World

[![video here](https://img.youtube.com/vi/6xCCNXR-4S4/maxresdefault.jpg)](https://youtu.be/6xCCNXR-4S4)

All the code written for SPACEROCK can be found in this repository.  <br><br>
The main MaxMSP patch is [work.maxpat](max-js-files/work.maxpat), with all the subpatches and .js files located in the [max-js-files](max-js-files) folder.  <br><br>
The Jupyter Notebook for image extraction is [here](other_file.md), which takes an input image and outputs .txt files and Arduino code to interface with MaxMSP and the microcontrollers.  <br><br>
The microcontroller code can be found in the [arduino](arduino) folder. <br><br>
ELECTRONICS SPECS:
- [Arduino Feather ESP32](https://www.adafruit.com/product/3405), connected to an [MLX90393 magnetometer](https://www.adafruit.com/product/4022) using [magnetometer.ino](arduino/magnetometer.ino) <br>
- Arduino Uno, connected to two [NEMA-17 stepper motors](https://www.adafruit.com/product/324) using [MOTORS-REAL.ino](arduino/MOTORS-REAL.ino) <br>
- Teensy 2.0++, connected to a custom LED grid using [teensy-light-multiple.ino](arduino/teensy-light-multiple.ino)

