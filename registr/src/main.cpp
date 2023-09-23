#include "Arduino.h"

#define CLOCK 17  //SH_CP
#define DATA 18    //DS
#define LATCH 19  //ST_CP
 
 
void setup() { 
 //настраиваем контакты на выход
 pinMode(CLOCK, OUTPUT);
 pinMode(DATA, OUTPUT);
 pinMode(LATCH, OUTPUT); 
 
 //отключаем LATCH (чтобы регистр не ждал данных)
 digitalWrite(LATCH, HIGH);
}
 
void loop() {
 //включаем LATCH (Начинаем общение)
 digitalWrite(LATCH, LOW); 
 
 //посылаем данные функцией shiftOut ( http://arduino.ru/Reference/ShiftOut )
 /*
Символ | байт
   .   | 0b00000001
   0   | 0b00000000
   1   | 0b01100000
   2   | 0b11011010
   3   | 0b11110010
   4   | 0b01100110
   5   | 0b10110110
   6   | 0b10111110
   7   | 0b11100000
   8   | 0b11111110
   9   | 0b11110110
 */
 shiftOut(DATA, CLOCK, LSBFIRST, 0b10110110); 
 
 //включаем LATCH (Начинаем общение)
 digitalWrite(LATCH, HIGH);
}