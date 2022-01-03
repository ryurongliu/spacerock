# SPACEROCK: Music From a Metal World

An ensemble of experimental computer music instruments created for NASA's Psyche Inspired artistic internship. Each instrument is inspired by one of the science instruments on the Psyche spacecraft. It plays music according to composition information extracted from an image, and it uses its own custom 16-note scale.

## Video Demo

[![video here](https://img.youtube.com/vi/6xCCNXR-4S4/maxresdefault.jpg)](https://youtu.be/6xCCNXR-4S4)

All the code written for SPACEROCK can be found in this repository.  <br><br>
The main MaxMSP patch is [work.maxpat](max-js-files/work.maxpat), with all the subpatches and .js files located in the [max-js-files](max-js-files) folder.  <br><br>
The Jupyter Notebook for image extraction is [here](other_file.md), which takes an input image and outputs .txt files and Arduino code to interface with MaxMSP and the microcontrollers.  <br><br>
The microcontroller code can be found in the [arduino](arduino) folder. <br><br>
## Electronics Specs
- [Arduino Feather ESP32](https://www.adafruit.com/product/3405), connected to an [MLX90393 magnetometer](https://www.adafruit.com/product/4022<br>
- Arduino Uno, connected to two [NEMA-17 stepper motors](https://www.adafruit.com/product/324)<br>
- Teensy 2.0++, connected to a custom LED grid using <br><br>

## Concept

INSTRUMENTS:   

Gamma Ray/Neutron Spectrometer (GRNS): PERCUSSION. Psyche’s GRNS detects neutrons and gamma rays that are emitted due to the impact of cosmic rays and high energy particles from space. SPACEROCK’s percussive instrument uses a microphone to “detect” the sound of ball bearings sliding down a wire track and impacting several surfaces. These sounds are then processed in MaxMSP.   
   
Magnetometer: BASS. Like the Psyche spacecraft will detect the asteroid’s magnetic field with a magnetometer, SPACEROCK uses a small Arduino-compatible magnetometer to detect the magnetic field of eight suspended magnets as it moves around along a circular track. The movements of the magnetometer are encoded in the composition information from the image, and the magnetic field information is used in MaxMSP to change the pitch and timbre of the bass as the piece is played.   
   
X-Band High Gain Antenna: LEAD. Psyche will use a new form of communication technology, Deep Space Optical Communication, to send data in photon streams. This inspired SPACEROCK’s lead instrument, which shoots out beams of light as it plays each note. Composition information for this instrument includes the pitch, duration, and color of each note.   
   
Multispectral Imager: CHORDS. This instrument uses color information from the composition image to play a series of chords, and it displays the chords on an LED matrix. Sixteen chords are constructed from the sixteen most prevalent colors in the image, and then color data from randomly chosen pixels is used to determine the composition’s chord sequences, chord durations, and LED colors.   
   
PROCESS: The composition information image extraction is coded in Python. I also used an Arduino Uno to control two stepper motors for the percussion and bass, an Arduino Feather to read the magnetometer, and a Teensy++ 2.0 to control the LEDs. All the sound generation (other than percussion) and sound processing is done in MaxMSP, and the final mix was done in Logic. I used granular synthesis and delay to process the percussion sounds, and I designed different FM-based voices for the lead, chord, and bass sounds (with inspiration taken from DX7 patches). The video was edited in Premiere, and the graphics were made with Photoshop and Sketches Pro.<br><br>

## Links
[Pysche Inspired Page](https://psyche.asu.edu/gallery/spacerock-music-from-a-metal-world/)   
[Soundcloud](https://soundcloud.com/user-323936777/spacerock-music-from-a-metal-world?si=3b53e7258fcf47649aa20ee1d347a400) 

