/*
 * Sketch for the mechanism of opening PVC windows
 * 
 * The following components were used in the project:
 *    Arduino UNO                                                       https://amperka.ru/product/arduino-uno
 *    HC-06 Bluetooth module                                            https://amperka.ru/product/hc-06-bluetooth-module
 *    H-bridge (Troyka-module)                                          https://amperka.ru/product/troyka-h-bridge
 *    Motor 12 mm (15 V, 80 rpm) with a gear ratio of 1:298             https://amperka.ru/product/motor-dc-12mm-15v-80rpm
 *    
 * The val variable is intended for storing values received via Bluetooth;
 * The variable SPEED - stores the pin number by which the rotation speed is controlled: LOW - does not rotate, HIGH - rotates to the maximum;
 * The DIR variable stores a pin that determines the direction of rotation of the motors: LOW - counterclockwise, HIGH - clockwise.
 * 
 * If "0" comes or values >= 3, then the engine does not rotate;
 * If "1" comes, then the motor rotates counterclockwise;
 * If "2" comes, then the engine rotates clockwise
 * 
 * It must be powered in the range from 3.3 to 5 V and with a current of ~ 1.85 A.
 * 
 * v1.0 from 11.14.2022 by Greengaraj
*/

int val, SPEED = 11, DIR = A3;

void setup()
{
  Serial.begin(9600);
  pinMode(DIR, OUTPUT); 
  pinMode(SPEED, OUTPUT);
}
void loop()
{
  if (Serial.available())
  {
    val = Serial.read();

    if ( val == '0')
    {
      digitalWrite(SPEED, LOW);
    }
    else if (val == '1')
    {
      digitalWrite(DIR, LOW);
      digitalWrite(SPEED, HIGH);
    }
    else if (val == '2')
    {
      digitalWrite(DIR, HIGH);
      digitalWrite(SPEED, HIGH);
    }
    else
    {
      digitalWrite(SPEED, LOW);
    }
  }
}
