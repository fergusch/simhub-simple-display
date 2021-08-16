// ***********************************
// Config options

// number of RPM LEDs (default: 5)
#define NUM_RPM_LEDS 5

// show startup animation (default: true)
#define SHOW_STARTUP_ANIMATION true

// End config options 
// ***********************************

// define pins for display segments
#define SEG_A 2
#define SEG_B 3
#define SEG_C 4
#define SEG_D 5
#define SEG_E 6
#define SEG_F 7
#define SEG_G 8

// update the 7seg display with the given gear
void showGear(int num) {
  switch (num) {
  
    case -1: // reverse
      digitalWrite(SEG_A, LOW);
      digitalWrite(SEG_B, LOW);
      digitalWrite(SEG_C, LOW);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, HIGH);
      break;
    
    case 0: // neutral
      digitalWrite(SEG_A, LOW);
      digitalWrite(SEG_B, LOW);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, HIGH);
      break;
  
    case 1:
      digitalWrite(SEG_A, LOW);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, LOW);
      break;
  
    case 2:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, LOW);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, HIGH);
      break;
  
    case 3:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, HIGH);
      break;
  
    case 4:
      digitalWrite(SEG_A, LOW);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;
  
    case 5:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, LOW);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;
  
    case 6:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, LOW);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;
  
    default: // turn the display off
      digitalWrite(SEG_A, LOW);
      digitalWrite(SEG_B, LOW);
      digitalWrite(SEG_C, LOW);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, LOW);
      break;
    
  }
}

// turn on the given number of LEDs for the RPMs
// (calculated in SHCustomProtocol.h)
void showRPM(int num) {

  for (int i = 9; i < 9+num; i++) {
    digitalWrite(i, HIGH);
  }
  for (int i = 9+num; i < 9+NUM_RPM_LEDS; i++) {
    digitalWrite(i, LOW);
  }

}

// play a startup animation
void startupAnimation() {

  for (int i = 2; i <= 8; i++) {
    digitalWrite(i, HIGH);
    delay(100);
  }

  for (int i = 9; i <= 13; i++) {
    digitalWrite(i, HIGH);
    delay(100);
  }

  for (int i = 2; i <= 8; i++) {
    digitalWrite(i, LOW);
    delay(100);
  }

  for (int i = 9; i <= 13; i++) {
    digitalWrite(i, LOW);
    delay(100);
  }
  
}
