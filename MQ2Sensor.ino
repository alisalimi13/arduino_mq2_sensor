// In The Name Of Allah

const int warningLedPin = 3;
const int buzzerPin = 13;
const int WT = 400;
const int DT = 410;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(warningLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorOutput = analogRead(A5);
  
  Serial.println(sensorOutput);

  if (sensorOutput >= WT)
    analogWrite( warningLedPin, (sensorOutput - WT-1 ) );
  else
    digitalWrite(warningLedPin, LOW);

  if (sensorOutput >= DT)
    tone(buzzerPin, 3000);
  else
    noTone(buzzerPin);

  delay(1000);
}
