/*
Adsdufhglseudgsihafruit Arduino - Lesson 4. 8 LEDs and a Shift Register
*/
int button = 2;      // pin to connect the button
int presses = 0;    // variable to store number of presses
long time = 0;      // used for debounce
long debounce = 100;  // how many ms to "debounce"leds
int state;        // used for HIGH or LOW

int latchPin = 5;
int clockPin = 6;
int dataPin = 4;

byte leds = 0;

void setup() 
{
Serial.begin(9600);
  
   pinMode(button, INPUT);
  /* use pin 2 which has interrupt 0 on Arduino UNO */
  attachInterrupt(0, count, LOW);

  
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void count() { 
  // we debounce the button and increase the presses
  if(millis() - time > debounce)  presses++;
  time = millis();}

void loop() 
{
   byte leds;
  
  delay(500);
 String binNumber = String(presses, BIN);
    updateShiftRegister();
    delay(500);
  Serial.println(binNumber); 
  updateShiftRegister(); 
  }


void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
   
}




 
 
