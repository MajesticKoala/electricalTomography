#include <Wire.h>
#include <Adafruit_ADS1015.h>

// Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */
Adafruit_ADS1015 ads1;     /* Use thi for the 12-bit version */
Adafruit_ADS1015 ads2(0x4A);
Adafruit_ADS1015 ads3(0x4B);
Adafruit_ADS1015 ads4(0x49);

int pause = 500;

int r1 = 10;
  int r2 = 11;
  int r3 = 12;
  int r4 = 13;
  int r5 = A0;
  int r6 = A1;
  int r7 = A2;
  int r8 = A3;

  int relayground[8]= {r1, r2, r3, r4, r5, r6, r7, r8};

void setup(void) 
{
  Serial.begin(9600);
  
  Serial.println("Hello!");
  
  Serial.println("Getting single-ended readings from AIN0..3");
  Serial.println("ADC Range: +/- 6.144V (1 bit = 3mV/ADS1015, 0.1875mV/ADS1115)");
  
  // The ADC input range (or gain) can be changed via the following
  // functions, but be careful never to exceed VDD +0.3V max, or to
  // exceed the upper and lower limits if you adjust the input range!
  // Setting these values incorrectly may destroy your ADC!
  //                                                                ADS1015  ADS1115
  //                                                                -------  -------
  // ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV

// 5V relay
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  // Ground relay


  

  
  
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(r5, OUTPUT);
  pinMode(r6, OUTPUT);
  pinMode(r7, OUTPUT);
  pinMode(r8, OUTPUT);
  
  
  
  ads1.begin();
}

void loop(void) 
{
  Serial.println("completed loop");
  int16_t adc10, adc11, adc12, adc13, adc20, adc21, adc22, adc23, adc30, adc31, adc32, adc33, adc40, adc41, adc42, adc43;

  for(int i = 2; i<10; i++) { //loop 5V relays
    digitalWrite(i, HIGH);

    for(int j = 0; j<8; j++) { //ground loop
        digitalWrite(relayground[j], HIGH);
        delay(100);
        

        //Serial.println((i-2)*2);

          adc10 = ads1.readADC_SingleEnded(0);
          delay(100);
          adc20 = ads2.readADC_SingleEnded(0);
          delay(100);
          adc30 = ads3.readADC_SingleEnded(0);
          delay(100);
          adc40 = ads4.readADC_SingleEnded(0);
          delay(100);
          adc11 = ads1.readADC_SingleEnded(1);
          delay(100);
          adc21 = ads2.readADC_SingleEnded(1);
          delay(100);
          adc31 = ads3.readADC_SingleEnded(1);
          delay(100);
          adc41 = ads4.readADC_SingleEnded(1);
          delay(100);
          adc12 = ads1.readADC_SingleEnded(2);
          delay(100);
          adc22 = ads2.readADC_SingleEnded(2);
          delay(100);
          adc32 = ads3.readADC_SingleEnded(2);
          delay(100);
          adc42 = ads3.readADC_SingleEnded(2);
          delay(100);
          adc13 = ads1.readADC_SingleEnded(3);
          delay(100);
          adc23 = ads2.readADC_SingleEnded(3);
          delay(100);
          adc33 = ads3.readADC_SingleEnded(3);
          delay(100);
          adc43 = ads4.readADC_SingleEnded(3);
          delay(100);

          int electrode[16] = {adc13,adc12,adc11,adc10, adc23,adc22,adc21,adc20,adc33,adc32,adc31,adc30,adc43,adc42,adc41,adc40};

        Serial.print(i);
        Serial.print(" ");
        Serial.print(j);
        Serial.print(" ");
        for(int k = 0; k<16; k++) {
          Serial.print(electrode[k]*0.003);
          Serial.print(" ");
          }
          Serial.println();
    
  digitalWrite(relayground[j], LOW);
        delay(500);
  }
  digitalWrite(i, LOW);
}

}
