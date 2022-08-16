#include "Receiver433.h"

Receiver433 receiver;

void setup()
{
  Serial.begin(9600);
  receiver.init();
}

void loop()
{
    if (receiver.listenRF())
    {
      Serial.println("______________________________");
      Serial.println("Received message:");
      Serial.print("\tRead ID: ");
      Serial.println(receiver.getReadID(), HEX);
      
      Serial.print("\tSW0: ");
      Serial.print(receiver.getSwitch(0));
      Serial.print(", SW1: ");
      Serial.print(receiver.getSwitch(1));
      Serial.print(", SW2: ");
      Serial.print(receiver.getSwitch(2));
      Serial.print(", SW3: ");
      Serial.println(receiver.getSwitch(3));
      
      Serial.print("\tJ0: ");
      Serial.print(receiver.getJoystick(0));
      Serial.print(", J1: ");
      Serial.print(receiver.getJoystick(1));
      Serial.print(", J2: ");
      Serial.print(receiver.getJoystick(2));
      Serial.print(", J3: ");
      Serial.println(receiver.getJoystick(3));
    }

    delay(500);
}
