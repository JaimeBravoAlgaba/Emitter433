#ifndef __EMITTER433__
  #define __EMITTER433__
  
  #include <Arduino.h>
  #include <RH_ASK.h>
  #include <SPI.h> 

  // ID Direction (4bits)
  #define EMITTER_ID 0x0B // Value between 0x01 and 0x0F
  
  // Bits Per Second
  #define BPS 4000
  
  // Buffer Length
  #define BUFF_LEN 5 // [bytes]
  

  // PINOUT
  #define RX_PIN 11
  #define TX_PIN 12
  
  #define SW0 4 // Switch 0
  #define SW1 5 // Switch 1
  #define SW2 6 // Switch 2
  #define SW3 7 // Switch 3
  
  #define J0 A0 // Joystick 0
  #define J1 A1 // Joystick 1
  #define J2 A2 // Joystick 2
  #define J3 A3 // Joystick 3  

#endif
