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
  Serial.begin(9600);
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  mapX = map(xPosition, -15, 1023, -512, 512);
  mapY = map(yPosition, -13, 1023, -512, 512);

  blueState = digitalRead(blueButton);
  redState = digitalRead(redButton);

  if (blueState == HIGH) {
    altitude += 1;
  }
  if (redState == HIGH) {
    altitude -= 1;
  }
  
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Altitude: ");
  Serial.println(altitude); 

  delay(100);
}
