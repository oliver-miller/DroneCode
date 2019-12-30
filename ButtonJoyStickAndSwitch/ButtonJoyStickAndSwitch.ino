// Declare pins for joystick
int VRx = A0;
int VRy = A1;

// Declare pin for button
 const int upButton = 2;

// Variables for the joystick
int xPosition = 0;
int yPosition = 0;
int mapX = 0;
int mapY = 0;

// Variable for the button
int upState = 0;

// Virtual altitiude variable
int altitude = 0;

void setup() {
  // Start serial monitor
  Serial.begin(9600);

  // Initialize joystick pins
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);

  // Initialize button pin
  pinMode(upButton, INPUT);
}

void loop() {
  // Read joystick pins
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);

  // Re-map joystick positions
  mapX = map(xPosition, -15, 1023, -512, 512);
  mapY = map(yPosition, -13, 1023, -512, 512);

  // Read button pin
  upState = digitalRead(upButton);

  if (upState == LOW) {  // If blue button is pushed, go up
    altitude += 1;
  }

  // Print XY position and altitude
  Serial.print("X:  ");
  Serial.print(mapX);
  Serial.print("  | Y: ");
  Serial.print(mapY);
  Serial.print("  | Altitude: ");
  Serial.println(altitude); 

  // Delay before reading
  delay(100);
}
