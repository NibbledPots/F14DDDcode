/*
  Tell DCS-BIOS to use a serial connection and use the default Arduino Serial
  library. This will work on the vast majority of Arduino-compatible boards,
  but you can get corrupted data if you have too many or too slow outputs
  (e.g. when you have multiple character displays), because the receive
  buffer can fill up if the sketch spends too much time updating them.
  
  If you can, use the IRQ Serial connection instead.
*/
#define DCSBIOS_DEFAULT_SERIAL

#include "DcsBios.h"
#include <Keypad.h>
/* paste code snippets from the reference documentation here */

// ^ we dont have to do that because we send the message directly

const byte ROWS = 3; // 3 rows
const byte COLS = 5; //5 columns
char keys[ROWS][COLS] = {
  {'Q', 'W', 'E', '0', '0'},
  {'R', 'T', 'Y', 'U', '0'},
  {'0', '0', 'I', 'O', 'P'},
}; // I set each switch to a letter, '0' is a fill in, indicating to me where there is no switch
byte rowPins[ROWS] = {18, 17, 16};
byte colPins[COLS] = {20, 14, 12, 11, 10};
// pins indicated by the KiCad schematic
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup() {
  DcsBios::setup();
  keypad.addEventListener(keypadEvent); // add an event listener
  keypad.setHoldTime(100); //default is 1000ms
  keypad.setDebounceTime(50);  //default is 50ms
  
}

void loop() {
  DcsBios::loop();
  char key = keypad.getKey();
}

void keypadEvent(KeypadEvent KEY){
  switch (keypad.getState()) {
  case PRESSED:
   switch(KEY) {
    case 'Q': sendDcsBiosMessage("RIO_DDD_RADAR", "1"); break;
    case 'W': sendDcsBiosMessage("RIO_DDD_IR", "1"); break;
    case 'E': sendDcsBiosMessage("RIO_DDD_IFF", "1"); break;
    case 'R': sendDcsBiosMessage("RIO_RADAR_PSTT", "1"); break;
    case 'T': sendDcsBiosMessage("RIO_RADAR_PDSTT", "1"); break;
    case 'Y': sendDcsBiosMessage("RIO_RADAR_PDSRCH", "1"); break;
    case 'I': sendDcsBiosMessage("RIO_RADAR_RWS", "1"); break;
    case 'O': sendDcsBiosMessage("RIO_RADAR_TWSAUTO", "1"); break;
    case 'P': sendDcsBiosMessage("RIO_RADAR_PULSE", "1"); break;
    case 'U': sendDcsBiosMessage("RIO_RADAR_TWSMAN", "1"); break;
   }
}

 switch (keypad.getState()){  // gives PRESSED, HOLD or RELEASED
 case RELEASED: 
   switch(KEY) { // Released KEYs or Neutral Rockers signal is sent
  case 'Q': sendDcsBiosMessage("RIO_DDD_RADAR", "0"); break;
    case 'W': sendDcsBiosMessage("RIO_DDD_IR", "0"); break;
    case 'E': sendDcsBiosMessage("RIO_DDD_IFF", "0"); break;
    case 'R': sendDcsBiosMessage("RIO_RADAR_PSTT", "0"); break;
    case 'T': sendDcsBiosMessage("RIO_RADAR_PDSTT", "0"); break;
    case 'Y': sendDcsBiosMessage("RIO_RADAR_PDSRCH", "0"); break;
    case 'I': sendDcsBiosMessage("RIO_RADAR_RWS", "0"); break;
    case 'O': sendDcsBiosMessage("RIO_RADAR_TWSAUTO", "0"); break;
    case 'P': sendDcsBiosMessage("RIO_RADAR_PULSE", "0"); break;
    case 'U': sendDcsBiosMessage("RIO_RADAR_TWSMAN", "0"); break;

   }}

}
