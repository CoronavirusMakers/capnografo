//speedy and dirty programmed by @TCRobotics
//This code outputs continuosly a simulated data from a SprintIR sensor trough serial
//You can upload this to a arduino board and conect from the serial TX to simulate a sensor
//The raw data has an 0 to 100 ppm random offset per sample, the filtered is always the same.

long ppmData[61] = {
1000,30447,33280,35414,37026,38249,39182,39900,40457,40893,41240,41519,41748,41940,42103,
42244,42369,42482,42585,42681,42771,42856,42938,43016,43092,43166,43238,43309,43378,43445,
43511,14005,11186,9066,7469,6259,5340,4635,4092,3669,3335,3068,2852,2673,2522,2392,2279,2178,
2086,2002,1923,1848,1777,1709,1644,1580,1518,1458,1398,1341,1284
};

void simulateSprintIR(long co2filteredTX, long co2rawTX)
{
  char buffer[17];
  //Simulate the protocol "Z XXXXX z XXXXX\r\n"
  sprintf(buffer,"Z %05ld z %05ld\r\n", co2filteredTX, co2rawTX);
  Serial.print(buffer);
}

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0)); //make random more random
}

void loop() {
  for(int index=0; index<61; index++)
  {
    simulateSprintIR(ppmData[index],(ppmData[index] - random(1000)));
    delay(50); //50ms delay = aprox 20Hz
  }
}
