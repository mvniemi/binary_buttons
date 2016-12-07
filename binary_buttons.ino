//Reading buttons through a binary encoder circuit
//2016 Michael Niemi
//MIT License
//
//

void setup() {
  // put your setup code here, to run once:
  Serial.begin(112500);
  pinMode(2 , INPUT_PULLUP);
  pinMode(3 , INPUT_PULLUP);
  pinMode(4 , INPUT_PULLUP);
}

void loop() {
  Serial.println(readSequential());
  Serial.println(readDirect());
  delay(100);
}

byte readSequential(){
  byte buttonId;
  for(int i=2; i<5; i++){
    if( digitalRead(i) == 1){
      //We will "add" the value of our pin to the byte. The << shifts it to the right bit, indexed by out loop
      buttonId = buttonId | (1 << (i-2));
    }
  }

  return buttonId;
}

byte readDirect(){
  //first pin we're using is 2, shift over by 2
  byte buttonId =  PIND >> 2;
  return buttonId;
}

