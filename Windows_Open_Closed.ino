/*
 * Скетч для механизма открывания ПВХ окон
 * 
 * В проекте использовались следующие компоненты:
 *    Arduino UNO                                                       https://amperka.ru/product/arduino-uno
 *    Bluetooth-модуль HC-06                                            https://amperka.ru/product/hc-06-bluetooth-module
 *    H-мост (Troyka-модуль)                                            https://amperka.ru/product/troyka-h-bridge
 *    Мотор 12 мм (15 В, 80 об/мин) с передаточным соотношением 1:298   https://amperka.ru/product/motor-dc-12mm-15v-80rpm
 *    
 * Переменная val предназначена для хранения значений, принимаемых по Bluetooth;
 * Переменная SPEED - хранит в себе номер пина, по которому идёт управление скоростью вращения: LOW - не вращается, HIGH - вращается на максимум;
 * Переменная DIR - хранит в себе пин, который определяет направление вращения двигателей: LOW - против часовой стрелки, HIGH - по часовой стрелки.
 * 
 * Если приходит "0" или значения >= 3, то двигатель не вращается
 * Если приходит "1", то двигатель вращается против часовой стрелке
 * Если приходит "2", то двигатель вращается по часовой стрелке
 * 
 * Питать необходимо в диапазоне от 3,3 до 5 В и током ~1,85А.
 * 
 * v1.0 от 11.14.2022
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
