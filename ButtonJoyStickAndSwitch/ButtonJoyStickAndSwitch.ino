// Declare pins for joystick
int VRx = A0;
int VRy = A1;

// Declare pins for button
 const int blueButton = 2;
 const int redButton = 3;

// Variables for the joystick
int xPosition = 0;
int yPosition = 0;
int mapX = 0;
int mapY = 0;

// Variables for the button
int blueState = 0;
int redState = 0;

// Virtual altitiude variable
int altitude = 0;

void setup() {
  // Start serial monitor
  Serial.begin(9600);

  // Initialize joystick pins
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);

  // Initialize button pins
  pinMode(blueButton, INPUT);
  pinMode(redButton, INPUT);
}

void loop() {
  // Read joystick pins
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);

  // Re-map joystick positions
  mapX = map(xPosition, -15, 1023, -512, 512);
  mapY = map(yPosition, -13, 1023, -512, 512);

  // Read button pins
  blueState = digitalRead(blueButton);
  redState = digitalRead(redButton);

  if (blueState == HIGH) {  // If blue button is pushed, go up
    altitude += 1;
  }
  if (redState == HIGH) {   // If red button is pushed, go down
    altitude -= 1;
  }

  // Print XY position and altitude
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Altitude: ");
  Serial.println(altitude); 

  // Delay before reading
  delay(100);
}
