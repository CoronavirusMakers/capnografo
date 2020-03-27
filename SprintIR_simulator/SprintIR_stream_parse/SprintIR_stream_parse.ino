//speedy and dirty programmed by TCRobotics
//This code takes serial RX input and parse continuosly to get 
//the SprintIR CO2 ppm values
//You can use the Arduino Serial Plotter to see de values!

long co2filteredRX = 0;
long co2rawRX = 0;
char printBuffer[33];

void parseSprintIR()
{
  while(Serial.read()!='Z'){};
  co2filteredRX = Serial.parseInt();
  co2rawRX = Serial.parseInt();
  sprintf(printBuffer,"%5ld,%05ld", co2filteredRX, co2rawRX);
  Serial.println(printBuffer);

}

void setup() {
  Serial.begin(9600);
}

void loop() {
  parseSprintIR();
}
