int sensorPin = A0;
int ledPin = 13;

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(sensorPin);

  float voltage = sensorValue * (5.0 / 1023.0);

  float temperature = voltage * 100.0;

  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" C");

  if (temperature > 30)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}