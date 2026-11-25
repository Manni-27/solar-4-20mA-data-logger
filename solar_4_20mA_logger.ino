const int sensorPin = A0;
const float R = 250.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int adcValue = analogRead(sensorPin);
  float voltage = adcValue * (5.0 / 1023.0);
  float current_mA = (voltage / R) * 1000.0;
  float irradiance = (current_mA - 4.0) * (2000.0 / 16.0);

  if (irradiance < 0) irradiance = 0;
  if (irradiance > 2000) irradiance = 2000;

  Serial.print(voltage, 3);
  Serial.print(",");
  Serial.print(current_mA, 2);
  Serial.print(",");
  Serial.println(irradiance, 1);

  delay(1000);
}
