//speedy and dirty programmed by @TCRobotics
//This code outputs continuosly a simulated data from a SprintIR sensor trough serial
//You can upload this to a arduino board and conect from the serial TX to simulate a sensor
//The raw data has an 0 to 100 ppm random offset per sample, the filtered is always the same.
//You can choose between 20Hz or 50Hz sample time

int sensorHz = 20; //choose 20 or 50Hz

long ppmData20Hz[61] = {
1000,30447,33280,35414,37026,38249,39182,39900,40457,40893,41240,41519,41748,41940,42103,
42244,42369,42482,42585,42681,42771,42856,42938,43016,43092,43166,43238,43309,43378,43445,
43511,14005,11186,9066,7469,6259,5340,4635,4092,3669,3335,3068,2852,2673,2522,2392,2279,2178,
2086,2002,1923,1848,1777,1709,1644,1580,1518,1458,1398,1341,1284
};

long ppmData50Hz[151] = {
1250,30800,32028,33123,34100,34972,35752,36448,37071,37629,38128,38576,38977,39338,39662,39954,
40218,40455,40670,40865,41041,41202,41348,41482,41604,41716,41819,41915,42003,42084,42160,42231,
42298,42360,42419,42475,42527,42577,42625,42671,42715,42757,42798,42837,42875,42912,42948,42983,
43017,43050,43083,43115,43146,43177,43208,43238,43267,43296,43325,43354,43382,43410,43437,43464,
43491,43518,43545,43571,43597,43623,43648,43674,43699,43724,43749,43773,14227,13001,11908,10933,
10063,9286,8591,7971,7415,6918,6473,6073,5715,5393,5103,4842,4606,4393,4201,4026,3868,3723,3592,
3472,3361,3260,3167,3081,3001,2927,2858,2794,2733,2676,2622,2572,2523,2477,2434,2392,2351,2312,
2275,2239,2204,2169,2136,2104,2072,2041,2011,1981,1952,1923,1895,1867,1839,1812,1785,1759,1733,
1707,1681,1656,1631,1606,1581,1556,1532,1508,1484,1460,1437,1413,1390
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
  switch (sensorHz) {
    case 20:
      for(int index=0; index<61; index++)
      {
        simulateSprintIR(ppmData20Hz[index],(ppmData20Hz[index] - random(1000)));
        delay(50); //50ms delay = aprox 20Hz
      }
      break;
    case 50:
      for(int index=0; index<151; index++)
      {
        simulateSprintIR(ppmData50Hz[index],(ppmData50Hz[index] - random(1000)));
        delay(20); //20ms delay = aprox 50Hz
      }
      break;
    default:
      Serial.print("wrong frequency, please choose 20 or 50Hz");
      while(1)
      break;
  }
}
