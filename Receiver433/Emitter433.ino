#include "Emitter433.h"

RH_ASK askTx(BPS, RX_PIN, TX_PIN);

byte buff [BUFF_LEN] = {0x00, 0x00, 0x00, 0x00, 0x00};

void setup()
{
  askTx.init();

  // Switches pins init:
  pinMode(SW0, INPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);

  // Joysticks pins init:
  pinMode(J0, INPUT);
  pinMode(J1, INPUT);
  pinMode(J2, INPUT);
  pinMode(J3, INPUT);
}

void loop()
{
  int t0 = micros();
  
  byte b = 0x00;
  byte j = 0x10;

  // FIRST BYTE
  // High bits: SW, Low bits: ID
  
  // Swiches reading:
  b = b | (j * digitalRead(SW0)); j = j<<1;
  b = b | (j * digitalRead(SW1)); j = j<<1;
  b = b | (j * digitalRead(SW2)); j = j<<1;
  b = b | (j * digitalRead(SW3));
  
  buff[0] = b|EMITTER_ID;    // Write SW and ID

  // JOYSTICKS BYTES
  buff[1] = uint8_t(map(analogRead(J0), 0, 1023, 0, 255));
  buff[2] = uint8_t(map(analogRead(J1), 0, 1023, 0, 255));
  buff[3] = uint8_t(map(analogRead(J2), 0, 1023, 0, 255));
  buff[4] = uint8_t(map(analogRead(J3), 0, 1023, 0, 255));

  askTx.send(buff, BUFF_LEN);
  askTx.waitPacketSent();
  delay(10);
}
