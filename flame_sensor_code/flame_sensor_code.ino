int LED1 = 7;
int LED2 = 8;
int flame_sensor = 4;
int flame_detected;

void setup()
{
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(flame_sensor, INPUT);
}

void loop()
{
  flame_detected = digitalRead(flame_sensor);
  if (flame_detected == 1)
  {
    Serial.println("Flame detected...! take action immediately.");
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    
  }
  else if(flame_detected == 0)
  {
    Serial.println("No flame detected. stay cool");
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    
  }
}
