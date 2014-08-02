/*
  night light
*/

int LED_ON = 255;
int LED_OFF = 0;
int LEDBlue=11;
int photoResistor = 0;
int value;
int off = 400; // higher = darker
int on = 350;  // lower = lighter
int state = LED_OFF;

void setup(){
  Serial.begin(9600);
  pinMode(LEDBlue,OUTPUT);
}

void loop(){
  value = analogRead(photoResistor);

  if (state >= LED_OFF && value <= on)
    state = LED_ON;
  else if (state == LED_ON && value >= off)
    state = LED_OFF;

  // dim led if led was set on
  if (state > LED_OFF)
    state = max(state - 2, 0);

  delay(8);

  analogWrite(LEDBlue,state);
}
