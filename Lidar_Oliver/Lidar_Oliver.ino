/* Todo , add 4 bytes of data as a number from  array 3 to arry 6
Normale Antwort: 0x01 0x03 0x04 0x00 0x00 0 xe0 0 xa10 x 72 0 x4b
Hinweis (der Abstand in dieser Anweisung beträgt 4 Bytes, 0x00 0x00 0 xe0 0 xa1, und der Abstand ist 0 x0000e0a1, umgerechnet in 57505mm dezimal)

use link or the description
https://de.aliexpress.com/item/33035807395.html?gatewayAdapt=glo2deu
*/
/*
 * There are three serial ports on the ESP known as U0UXD, U1UXD and U2UXD.
 * 
 * U0UXD is used to communicate with the ESP32 for programming and during reset/boot.
 * U1UXD is unused and can be used for your projects. Some boards use this port for SPI Flash access though
 * U2UXD is unused and can be used for your projects.
 * 
*/
//include <HardwareSerial.h> // ist bereits teil von Arduino IDE

#define RXD1 27  // for loopback jumper these pins
#define TXD1 26

#define RXD2 16
#define TXD2 17
 int array [] = {0x01, 0x03, 0x00, 0x0f, 0x00, 0x02, 0xf4, 0x08};

void setup() 
{
    // Note the format for setting a serial port is as follows: Serial2.begin(baud-rate, protocol, RX pin, TX pin);
    Serial.begin(115200);
    
    Serial1.begin(9600, SERIAL_8N1, RXD1, TXD1);
    Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);

    Serial.println("Serial Txd is on pin: "+String(TX));
    Serial.println("Serial Rxd is on pin: "+String(RX));
}

void loop() 
{ 
  delay(3000);

  for(int i = 0;i<8;i++)
  {
     Serial2.write(array[i]);
  }
  for(int i = 0;i<8;i++)
  {
     Serial1.write(array[i]);
  }  
 
  //Choose Serial1 or Serial2 as required
  while (Serial2.available())
   {
    Serial.print((Serial2.read()), HEX);
    Serial.print(" ");
   }
   Serial.println();

while (Serial1.available())
   {
    Serial.print((Serial1.read()), HEX);
    Serial.print(" ");
   }
   Serial.println();   
}
