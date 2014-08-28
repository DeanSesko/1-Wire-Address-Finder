#include <OneWire.h>
#include <EEPROM.h>


#define NUM_TS 9
byte tSensor[9][8];
int RunOnce = 0;
int address = 0;
byte value;
int i;
byte addr4[8] = {0, 0, 0, 0, 0, 0, 0, 0};


String MyStringBase = "0x";
 String MyString0;
// DS18S20 Temperature chip i/o
OneWire ow(10);  // on pin 10





void setup(void) {
  // initialize inputs/outputs
  // start serial port
 Serial.begin(115200);
 
}




void loop(void){
if (RunOnce == 1) { 
RunOnce = 1;
for( i = 0; i < 9; i++) {
  EEPROMwriteBytes(i * 8, addr4, 8);
       }
byte addr[8] = {0, 0, 0, 0, 0, 0, 0, 0};
getDSAddr(addr);
setTSAddr(1, addr);
getDSAddr(addr);
setTSAddr(2, addr);
getDSAddr(addr);
setTSAddr(3, addr);

}
EEPROMreadBytes(0, *tSensor, 72);
for( i = 0; i < 6; i++) {
float temp;
float tmp2;

if (validAddr(tSensor[i])){
tmp2 = getTemperature(tSensor[i]);
temp = c2f(tmp2);
Serial.print(temp);
Serial.print(",Sensor");
Serial.println(i);
delay(500);
}
       }





}

