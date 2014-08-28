
void EEPROMreadBytes(int addr, byte bytes[], byte numBytes) {
  for (byte i = 0; i < numBytes; i++) {
    bytes[i] = EEPROM.read(addr + i);
   
   }
   
   
}
void EEPROMwriteBytes(int addr, byte bytes[], byte numBytes) {
  for (byte i = 0; i < numBytes; i++) {
    EEPROM.write(addr + i, bytes[i]);
  }
}



void Printme(byte bytes[]){
  MyString0 ="";
  
 for( i = 0; i < 8; i++) {
        MyString0 = String(MyString0 + String(bytes[i], HEX));
   

    }
   Serial.println(MyString0);
  delay(1000);
}



