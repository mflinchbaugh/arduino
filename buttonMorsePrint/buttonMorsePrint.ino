//records extra button presses for some reason
const int buttonPin = 4;
int buttonState = 0;
int lastButtonState = 0;
int startTime = 0;
int endTime = 0;
int pressedTime = 0;
int idleTime = 0;
int morseArray[] = {0, 0, 0}; //why does "*"=539 ???
//int x = morseArray[1];
//int y = morseArray[2];
//int z = morseArray[1];
int count = 0;
int timer = 5000;
boolean beenPressed = false;
int slot = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);//read button state

  if (buttonState != lastButtonState) {   //if button state changed
    updateState();

    lastButtonState = buttonState;  //save button state for next round
  }
  idleTime = millis() - endTime; //calculate time since last release
  if (beenPressed && idleTime >= timer) {
    for (count = 0; count < 3; count++) {
      Serial.print(morseArray[count]); 
      morseArray[count] = (0);
    }
    slot = 0;
    Serial.println();
    endTime = millis();
    beenPressed = false;
  }
}

void updateState() {  //button was just pressed
  if (buttonState == LOW) {
    startTime = millis();  //record start time

  } else {
    endTime = millis(); //record end time
    pressedTime = endTime - startTime;  //calculate time since pressed
    beenPressed = true;
    if (50 >= pressedTime && pressedTime <= 250) {
      morseArray[slot] = 0; //assign dot
      Serial.print("dot into ");
      Serial.println(slot);
      slot++;
    }
    else if (pressedTime > 250) {
      morseArray[slot] = 1;
      Serial.print("dash into ");
      Serial.println(slot);
      slot++;
    }
    if (slot >= 3) {
      slot = 0;
    }
  }

}
