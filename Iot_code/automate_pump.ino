int sensor_pin = A0;       //Sensor Pin
int relay_pin = 7;         //Relay Pin

void setup()
{
  Serial.begin(9600);
  
  pinMode(sensor_pin, INPUT);
   pinMode(relay_pin, OUTPUT);
}

void loop()
{
  int sensor_data = analogRead(sensor_pin);
  Serial.print("Sensor_data:");
  Serial.print(sensor_data);
  Serial.print("\t | ");
  
  if(sensor_data > 950)
  {
    Serial.println("No moisture, Soil is dry");
    digitalWrite(relay_pin, LOW);
    
  }
  else if(sensor_data >= 400 && sensor_data <= 950)
  {
    Serial.println("There is some moisture, Soil is medium");
    digitalWrite(relay_pin, HIGH);
   
  }
  else if(sensor_data < 400)
  {
    Serial.println("Soil is wet");
    digitalWrite(relay_pin, HIGH);
   
  }

  delay(100);
}
