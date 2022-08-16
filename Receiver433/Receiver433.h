#ifndef __RECEIVER433__
  #define __RECEIVER433__
  
  #include <Arduino.h>
  #include <RH_ASK.h>
  #include <SPI.h> 

  // ID Direction (4bits)
  #define DEF_RECEIVER_ID 0x0B // Value between 0x01 and 0x0F
  
  // Bits Per Second
  #define BPS 4000
  
  // Buffer Length
  #define BUFF_LEN 5 // [bytes]
  
  // PINOUT
  #define RX_PIN 11
  #define TX_PIN 12 

  class Receiver433 : public RH_ASK
  {
    public:
      // Constructor
      Receiver433();
      Receiver433(byte id);
      Receiver433(int bps, int rx_pin, int tx_pin);
      Receiver433(byte id, int bps, int rx_pin, int tx_pin);

      // Getters
      byte getMyID();
      byte getReadID();
      uint8_t getSwitch(uint8_t index);
      uint8_t getJoystick(uint8_t index);

      // Setters
      void setID(byte newID);

      // Comms
      uint8_t listenRF();
    private:
      byte id;
      byte buff[BUFF_LEN];
      byte buff_tmp[BUFF_LEN];
  };

#endif
