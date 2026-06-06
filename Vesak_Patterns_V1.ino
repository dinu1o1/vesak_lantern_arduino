// 1. Define descriptive pin names (Original 6 + 2 New Pins)
const int upGreen   = 2;  // Light 1
const int upRed     = 3;  // Light 2
const int upBlue    = 4;  // Light 3
const int downGreen = 5;  // Light 4
const int downRed   = 6;  // Light 5
const int downBlue  = 7;  // Light 6
const int upWhite   = 8;  // Light 7 (2 Relay)
const int downWhite = 9;  // Light 8 (2 Relay)

// 2. Updated array to hold all 8 active pins
const int totalLights = 8;
const int whiteLights = 2;
const int rgbLights = 6;

const int lightPins[totalLights] = {upGreen, upRed, upBlue, downGreen, downRed, downBlue, upWhite, downWhite};
const int upLights[4] = {upGreen, upRed, upBlue, upWhite};
const int downLights[4] = {downGreen, downRed, downBlue, downWhite};


void setup() {
  // Initialize all 8 pins and keep all relays OFF (HIGH) on startup
  for (int i = 0; i < totalLights; i++) {
    pinMode(lightPins[i], OUTPUT);
    digitalWrite(lightPins[i], HIGH); 
  }
}

// ---------------------------------------------------------
// CUSTOM PATTERN FUNCTIONS
// ---------------------------------------------------------

// Helper function to turn all 8 lights off quickly
void allOff() {
  for (int i = 0; i < totalLights; i++) {
    digitalWrite(lightPins[i], HIGH);
  }
}

void rgbOff(){
  for (int i = 0; i < rgbLights; i++) {
    digitalWrite(lightPins[i], HIGH);
  }
}


void colorPulse1(int loops) {
  for (int j = 0; j < loops; j++) {

    digitalWrite(upWhite, LOW);
    digitalWrite(downWhite, LOW);
    // Greens ON
    digitalWrite(upGreen, LOW); 
    digitalWrite(downGreen, LOW); 
    delay(500);
    rgbOff();
    
    // Reds ON
    digitalWrite(upRed, LOW); 
    digitalWrite(downRed, LOW); 
    delay(500);
    rgbOff();
    
    // Blues ON
    digitalWrite(upBlue, LOW); 
    digitalWrite(downBlue, LOW); 
    delay(500);
    allOff();
  }
}

void colorPulse2(int loops) {
  for (int j = 0; j < loops; j++) {
    digitalWrite(upWhite, LOW);
    digitalWrite(downWhite, LOW);
    // Greens ON
    digitalWrite(upGreen, LOW); 
    digitalWrite(downGreen, LOW); 
    delay(5000);
    rgbOff();
    
    // Reds ON
    digitalWrite(upRed, LOW); 
    digitalWrite(downRed, LOW); 
    delay(2500);
    rgbOff();
    
    // Blues ON
    digitalWrite(upBlue, LOW); 
    digitalWrite(downBlue, LOW); 
    delay(2500);
    rgbOff();
  }
}


void color2Mix(int loops) {
  for (int j = 0; j < loops; j++) {
    // 1. Magenta (Blue + Red) ON
    digitalWrite(upBlue, LOW);
    digitalWrite(upRed, LOW);
    digitalWrite(downBlue, LOW);
    digitalWrite(downRed, LOW);
    
    delay(5000); 

    // 2. INSTANT SWITCH TO: Cyan (Blue + Green) ON
    digitalWrite(upGreen, LOW);
    digitalWrite(downGreen, LOW);
    digitalWrite(upRed, HIGH);   // Turn Red OFF
    digitalWrite(downRed, HIGH); // Turn Red OFF
    
    delay(5000);

    // 3. INSTANT SWITCH TO: Yellow (Green + Red) ON
    digitalWrite(upRed, LOW);
    digitalWrite(downRed, LOW);
    digitalWrite(upBlue, HIGH);   // Turn Blue OFF
    digitalWrite(downBlue, HIGH); // Turn Blue OFF
    
    delay(5000);
    
    // 4. CLEANUP AT THE END OF THE LOOP
    digitalWrite(upGreen, HIGH);
    digitalWrite(downGreen, HIGH);
  }
  
  allOff(); 
}

void color3Mix(int loops){
  for(int i = 0; i < loops; i++){
    digitalWrite(upRed, LOW);
    digitalWrite(upGreen, LOW);
    digitalWrite(upBlue, LOW);
    digitalWrite(downRed, LOW);
    digitalWrite(downGreen, LOW);
    digitalWrite(downBlue, LOW);
    delay(5000);
    allOff();
    digitalWrite(upWhite, LOW);
    digitalWrite(upGreen, LOW);
    digitalWrite(upBlue, LOW);
    digitalWrite(downWhite, LOW);
    digitalWrite(downGreen, LOW);
    digitalWrite(downBlue, LOW);
    delay(5000);
    allOff();
    digitalWrite(upRed, LOW);
    digitalWrite(upWhite, LOW);
    digitalWrite(upBlue, LOW);
    digitalWrite(downRed, LOW);
    digitalWrite(downWhite, LOW);
    digitalWrite(downBlue, LOW);
    delay(5000);
    allOff();
    digitalWrite(upRed, LOW);
    digitalWrite(upGreen, LOW);
    digitalWrite(upWhite, LOW);
    digitalWrite(downRed, LOW);
    digitalWrite(downGreen, LOW);
    digitalWrite(downWhite, LOW);
    delay(5000);
    allOff();
  }
}

void up_downDifferentRGB(int loops){
  // FIXED: Added the for-loop wrapper so it respects the loops argument
  for (int j = 0; j < loops; j++) {
    digitalWrite(upGreen, LOW);
    digitalWrite(downRed, LOW);
    delay(5000);
    digitalWrite(upGreen, HIGH);
    digitalWrite(downRed, HIGH);

    digitalWrite(upRed, LOW);
    digitalWrite(downBlue, LOW);
    delay(5000);
    digitalWrite(upRed, HIGH);
    digitalWrite(downBlue, HIGH);

    digitalWrite(upBlue, LOW);
    digitalWrite(downGreen, LOW);
    delay(5000);
    digitalWrite(upBlue, HIGH);
    digitalWrite(downGreen, HIGH);
  }
  allOff();
}

void firstFlash(int loops){
  // FIXED: Outer loop wrapper to respect the 'loops' configuration argument
  for (int l = 0; l < loops; l++) {
    digitalWrite(upWhite, LOW);
    digitalWrite(downWhite, LOW);
    delay(1000);

    // Flashes RGB lights 5 times while white stays on
    for(int j = 0; j < 5; j++){
      for(int i = 0; i < rgbLights; i++){
        digitalWrite(lightPins[i], LOW);
      }
      delay(500);
      for(int i = 0; i < rgbLights; i++){
        digitalWrite(lightPins[i], HIGH);
      }
      delay(250); // FIXED: Added missing delay so the "OFF" state is actually visible
    }

    digitalWrite(upWhite, HIGH);
    digitalWrite(downWhite, HIGH);
  }
  allOff();
}

void singleColors(int loops){
  // FIXED: Added the for-loop wrapper so it respects the loops argument
  for (int j = 0; j < loops; j++) {
    digitalWrite(upWhite, LOW);
    digitalWrite(downWhite, LOW);
    delay(2000);
    digitalWrite(upWhite, HIGH);
    digitalWrite(downWhite, HIGH);

    digitalWrite(upRed, LOW);
    digitalWrite(downRed, LOW);
    delay(3000);
    digitalWrite(upRed, HIGH);
    digitalWrite(downRed, HIGH);

    digitalWrite(upGreen, LOW);
    digitalWrite(downGreen, LOW);
    delay(3000);
    digitalWrite(upGreen, HIGH);
    digitalWrite(downGreen, HIGH);

    digitalWrite(upBlue, LOW);
    digitalWrite(downBlue, LOW);
    delay(3000);
    digitalWrite(upBlue, HIGH);
    digitalWrite(downBlue, HIGH);
  }
  allOff();
}

void allOn(int loops){
  for(int i = 0; i < loops; i++){
    for(int j = 0; j < totalLights; j++){
      digitalWrite(lightPins[j], LOW);
    }
    delay(5000);
    allOff();
  }
}

void whiteMix(int loops){
  for(int i = 0; i < loops; i++){
    digitalWrite(upWhite, LOW);
    digitalWrite(downWhite, LOW);

    digitalWrite(downRed, LOW);
    digitalWrite(upGreen, LOW);
    delay(3000);
    rgbOff();
    digitalWrite(downGreen, LOW);
    digitalWrite(upBlue, LOW);
    delay(3000);
    rgbOff();
    digitalWrite(downBlue, LOW);
    digitalWrite(upRed, LOW);
    delay(3000);
    allOff();
  }
}

void whiteFlash(int loops){
  for(int i = 0; i < loops; i++){
    digitalWrite(upRed, LOW);
    digitalWrite(downRed, LOW);
    for(int j = 0; j < 5; j++){
      digitalWrite(upWhite, LOW);
      digitalWrite(downWhite, LOW);
      delay(250);
      digitalWrite(upWhite, HIGH);
      digitalWrite(downWhite, HIGH);
    }
    rgbOff();
    digitalWrite(upGreen, LOW);
    digitalWrite(downGreen, LOW);
    for(int j = 0; j < 5; j++){
      digitalWrite(upWhite, LOW);
      digitalWrite(downWhite, LOW);
      delay(250);
      digitalWrite(upWhite, HIGH);
      digitalWrite(downWhite, HIGH);
    }
    rgbOff();
    digitalWrite(upBlue, LOW);
    digitalWrite(downBlue, LOW);
    for(int j = 0; j < 5; j++){
      digitalWrite(upWhite, LOW);
      digitalWrite(downWhite, LOW);
      delay(250);
      digitalWrite(upWhite, HIGH);
      digitalWrite(downWhite, HIGH);
    }
    rgbOff();
  }
}

void stepUp(int loops){
  for(int i = 0; i < loops; i++){
  digitalWrite(upWhite, LOW);
  digitalWrite(downWhite, LOW);
  delay(1000);
  digitalWrite(upGreen, LOW);
  digitalWrite(downGreen, LOW);
  delay(1000);
  digitalWrite(upRed, LOW);
  digitalWrite(downRed, LOW);
  delay(1000);
  digitalWrite(upBlue, LOW);
  digitalWrite(downBlue, LOW);
  delay(3000);
  for(int j = 0; j<10; j++){
    digitalWrite(upWhite, HIGH);
    digitalWrite(downWhite, HIGH);
    delay(500);
    digitalWrite(upWhite, LOW);
    digitalWrite(downWhite, LOW);
    delay(500);
  }
  digitalWrite(upGreen, HIGH);
  digitalWrite(downGreen, HIGH);
  delay(750);
  digitalWrite(upRed, HIGH);
  digitalWrite(downRed, HIGH);
  delay(750);  
  digitalWrite(upBlue, HIGH);
  digitalWrite(downBlue, HIGH);
  delay(750);
  digitalWrite(upWhite, HIGH);
  digitalWrite(downWhite, HIGH);
  delay(500);
  allOff();
    }
}


// ---------------------------------------------------------
// MAIN RUNTIME LOOP
// ---------------------------------------------------------
void loop() {

  singleColors(3);

  stepUp(2); 

  whiteMix(3);       

  allOn(1);

  firstFlash(1);          

  up_downDifferentRGB(5); 

  allOn(1);

  colorPulse1(3);

  color2Mix(3);

  singleColors(2);

  colorPulse2(3);

  allOn(1);

  stepUp(2);

  color3Mix(2);

  whiteFlash(3);

}