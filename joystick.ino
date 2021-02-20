int xaxis,yaxix,buttonState = 0;

void setup() {
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(7, INPUT_PULLUP); //set pin 2 as an input and enable the internal pull-up resistor
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  xaxis = analogRead(A0); // read X axis value [0..1023]
  Serial.print("X:");
  Serial.print(xaxis, DEC);

  yaxix = analogRead(A1); // read Y axis value [0..1023]
  Serial.print(" | Y:");
  Serial.print(yaxix, DEC);

  buttonState = digitalRead(7); // read Button state [0,1]
  Serial.print(" | Button:");
  Serial.println(buttonState, DEC);

  if(xaxis>=1 and yaxix>=1 and buttonState==1){
    
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    }
   else if(yaxix>=1 and xaxis==0){
    
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    }
    else if(xaxis>=1 and yaxix==0){
    
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    }
    else if(xaxis>=1 and yaxix>=1 and buttonState==0){
    
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    }
    

  delay(100);
}
