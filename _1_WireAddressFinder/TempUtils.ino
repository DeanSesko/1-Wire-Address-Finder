
void setTSAddr(byte sensor, byte addr[8]) {
  memcpy(tSensor[sensor], addr, 8);
  EEPROMwriteBytes(sensor * 8, addr, 8);
  Serial.println("Wrote To Memmory");
}

void getDSAddr(byte addrRet[8]){
  //Leaving stub for external functions (serial and setup) that use this function
    byte scanAddr[8];
    ow.reset_search();
    byte limit = 0;
    //Scan at most 20 sensors (In case the One Wire Search loop issue occurs)
    while (limit <= 20) {
      if (!ow.search(scanAddr)) {
        //No Sensor found, Return
        ow.reset_search();
        return;
      }
      if (
          scanAddr[0] == 0x28 ||  //DS18B20
          scanAddr[0] == 0x10     //DS18S20
         ) 
      {
        boolean found = 0;
        for (byte i = 0; i <  NUM_TS; i++) {
          boolean match = 1;
          for (byte j = 0; j < 8; j++) {
            //Try to confirm a match by checking every byte of the scanned address with those of each sensor.
            if (scanAddr[j] != tSensor[i][j]) {
              match = 0;
              break;
            }
          }
          if (match) { 
            found = 1;
            break;
          }
        }
        if (!found) {
          for (byte k = 0; k < 8; k++) addrRet[k] = scanAddr[k];
          return;
        }
      }
      limit++;
    }      
  }
  
    boolean validAddr(byte* addr) {
    for (byte i = 0; i < 8; i++) if (addr[i]) return 1;
    return 0;
  }
