#include<avr/io.h>

char val; //This character is coming from phone to the bluetotth module and then goes from bluetooth module to arduino uno
void setup() {
  Serial.begin(9600);
  DDRB |= (1 << 0); //MA CW --->PIN 8
  DDRB |= (1 << 1); //MA ACW --->PIN 9
  DDRB |= (1 << 2); //MB CW --->PIN 10
  DDRB |= (1 << 3); //MB ACW --->PIN 11
}

void loop() {

  while (Serial.available() > 0)
  {
    val = Serial.read();
    Serial.println(val);
  }

  if ( val == 'F') // Forward
  {
    PORTB |= (1 << 0); //MA CW --->PIN 8
    PORTB &= ~(1 << 1); //MA ACW --->PIN 9
    PORTB |= (1 << 2); //MB CW --->PIN 10
    PORTB &= ~(1 << 3); //MB ACW --->PIN 11

  }
  else if (val == 'B') // Backward
  {
    PORTB &= ~ (1 << 0);//MA CW --->PIN 8
    PORTB |= (1 << 1); //MA ACW --->PIN 9
    PORTB &= ~(1 << 2); //MB CW --->PIN 10
    PORTB |= (1 << 3); //MB ACW --->PIN 11
  }

  else if (val == 'L') //Left
  {
    PORTB |= (1 << 0);  //MA CW --->PIN 8
    PORTB &= ~(1 << 1); //MA ACW --->PIN 9
    PORTB &= ~(1 << 2); //MB CW --->PIN 10
    PORTB &= ~(1 << 3); //MB ACW --->PIN 11
  }
  else if (val == 'R') //Right
  {
    PORTB &= ~(1 << 0);  //MA CW --->PIN 8
    PORTB &= ~(1 << 1); //MA ACW --->PIN 9
    PORTB |= (1 << 2); //MB CW --->PIN 10
    PORTB &= ~(1 << 3); //MB ACW --->PIN 11
  }

  else if (val == 'S') //Stop
  {
    PORTB &= ~(1 << 0);  //MA CW --->PIN 8
    PORTB &= ~(1 << 1); //MA ACW --->PIN 9
    PORTB &= ~(1 << 2); //MB CW --->PIN 10
    PORTB &= ~(1 << 3); //MB ACW --->PIN 11
  }
}
