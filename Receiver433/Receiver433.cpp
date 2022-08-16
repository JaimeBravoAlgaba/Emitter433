#include "Receiver433.h"

Receiver433::Receiver433() : Receiver433(DEF_RECEIVER_ID, BPS, RX_PIN, TX_PIN){}
Receiver433::Receiver433(byte id) : Receiver433(id, BPS, RX_PIN, TX_PIN){}
Receiver433::Receiver433(int bps, int rx_pin, int tx_pin) : Receiver433(DEF_RECEIVER_ID, bps, rx_pin, tx_pin){}
Receiver433::Receiver433(byte id, int bps, int rx_pin, int tx_pin) : RH_ASK(bps, rx_pin, tx_pin)
{
  this->setID(id);
}

uint8_t Receiver433::listenRF()
{  
  if(this->recv(this->buff_tmp, BUFF_LEN))
  {
    if((this->buff_tmp[0]&0x0F) == this->id)
    {
      memcpy(this->buff, this->buff_tmp, BUFF_LEN);
      return 1;
    }
  }
  return 0;
}

byte Receiver433::getReadID(){return this->buff[0]&0x0F;}

byte Receiver433::getMyID(){return this->id;}

uint8_t Receiver433::getSwitch(uint8_t index)
{
  byte b = this->buff[0];
  return (b>>(4+index))&0b00000001;
}

uint8_t Receiver433::getJoystick(uint8_t index){return uint8_t(this->buff[1+index]);}

void Receiver433::setID(byte newID){this->id = 0x0F&newID;}
