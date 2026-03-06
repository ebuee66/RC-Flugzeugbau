

const int potThrottle = A0;   // Right Joystick (Throttle)
const int potPitch = A2;      // Left Joystick (Up/Down - Pitch)
const int potRoll = A1;       // Left Joystick (Right/Left - Roll)

void setup() {
  // Initialize Serial Communication for HC-12 (Baud Rate: 9600)
  Serial.begin(9600); 
}

void loop() {
  int valThrottle = analogRead(potThrottle);
  int valPitch = analogRead(potPitch);
  int valRoll = analogRead(potRoll);

  // --- THROTTLE CALCULATION (Deadzone Logic) ---
  int mapThrottle;
  
  // If joystick is below 550 (middle/bottom), keep motor OFF
  if (valThrottle < 550) {
    mapThrottle = 1000; // Motor Stop Signal
  } else {
    // Start acceleration from 550 to 1023
    mapThrottle = map(valThrottle, 550, 1023, 1000, 2000);
  }

  // --- SERVO MAPPING (0-180 Degrees) ---
  // If directions are inverted, swap "0, 180" to "180, 0"
  int mapPitch = map(valPitch, 0, 1023, 0, 180);
  int mapRoll = map(valRoll, 0, 1023, 0, 180);

  // Data Packaging: <Throttle,Pitch,Roll>
  Serial.print("<");
  Serial.print(mapThrottle);
  Serial.print(",");
  Serial.print(mapPitch);
  Serial.print(",");
  Serial.print(mapRoll);
  Serial.println(">"); 

  delay(40); // Transmission Delay to prevent buffer overflow
}
